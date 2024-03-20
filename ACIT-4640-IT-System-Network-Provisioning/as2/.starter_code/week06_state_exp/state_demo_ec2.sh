#!/usr/bin/env bash
set -o nounset

declare script_dir=$(dirname "${BASH_SOURCE[0]}")
declare ec2_id_file="${script_dir}/unmanaged_ec2_id.env"

#####################################################################
# adds a new EC2 instance to the AWS environment based on the VPC Configuration
# Arguments:
#   instance_name: The name of the instance to create
# Outputs:
#   - A file named unmanaged_ec2_id.env containing the instance id
#   - The instance id is also printed to stdout
#####################################################################
function add_ec2() {
  declare script_dir=$(dirname "${BASH_SOURCE[0]}")
  source "${script_dir}/aws_resources.sh"
  declare instance_name="${1:-${PROJECT}_unmanaged}"

  declare unmanaged_id=$(aws ec2 run-instances \
    --image-id $AMI \
    --instance-type "t2.micro" \
    --count 1 \
    --key-name "${SSH_KEY}" \
    --security-group-ids "${SECURITY_GROUP}" \
    --subnet-id "${SUBNET}" \
    --tag-specifications "ResourceType=instance,Tags=[{Key=Name,Value=${instance_name}},{Key=project,Value=${PROJECT}}]" \
    --output text \
    --query 'Instances[*].InstanceId')

  echo "instance_id=\"${unmanaged_id}\"" >"${ec2_id_file}"
  echo "${unmanaged_id}"

}

#####################################################################
# uses AWS CLI to retrieve and display all AWS resources associated with a
# specific project loaded from the `PROJECT` variable loaded from the
# `aws_resources.sh` file
# Outputs:
#   - A list of all AWS resources associated with the project to stdout
#####################################################################
function show_resources() {
  declare script_dir=$(dirname "${BASH_SOURCE[0]}")
  source "${script_dir}/aws_resources.sh"
  aws resourcegroupstaggingapi get-resources --tag-filters Key=project,Values="${PROJECT}" --no-cli-pager
}

#####################################################################
# Generates the `imports.tf` file for Terraform. This file is used to
# import an EC2 instance created outside of Terraform into Terraform's
# management.
# Arguments:
#   unmanaged_id: The id of the unmanaged ec2 instance to import
# Outputs:
#   - A file named `imports.tf` containing:
#       - an import block for the unmanaged EC2 instance
#       - a resource block for the unmanaged EC2 instance with minimal
#         configuration
#       - a data resource to delete the terrafrom configuration file on destroy
#         this is done to facilitated repeated demonstrations
#####################################################################
function gen_import_tf() {
  unmanaged_id=${1:-${unmanaged_id}}

  source "${script_dir}/aws_resources.sh"
  # Generate imports.tf this should self delete the imports.tf file when
  # terrform destroy is run
  tee "${script_dir}/imports.tf" <<'EOF'


# Self reference to terraform file resource
# used to delete the imports.tf file when terraform destroy is run
resource "terraform_data" "import_file" {

  # this stores the path to the import.tf file
  input = "${path.module}/imports.tf"

  provisioner "local-exec" {
    command = "rm -f \"${self.output}\""
    when = destroy
  }
}
EOF

  # Append resource required for successful import
  tee -a "${script_dir}/imports.tf" <<EOF

import {
  # import the instance
  to = aws_instance.unmanaged
  id = "${unmanaged_id}"
}

# make resource id for the imported instance
resource "aws_instance" "unmanaged" {
  ami = "${AMI}"
  instance_type = "${INSTANCE_TYPE}"
}
EOF

}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
  # execute from the script directory
  cd "${script_dir}"
  source "${script_dir}/aws_resources.sh"

  # create infrastrucure using terraform
  terraform init
  terraform apply -auto-approve

  # add another ec2 instance to vpc on same subnet with same security group
  um_id=$(add_ec2)

  # show all AWS resources for project
  show_resources

  # show terrafrom managed resources
  terraform state list

  # Try to terraform destroy -won't complete will need force halt
  # terrafor destroy -auto-approve
  # Destroy will fail as VPC, Subnet, Security Group, and Gateway
  # all have dependencies on the unmanaged instance.

  # get the instance id from file not necessary since part of demo
  #source "${ec2_id_file}"

  # generate imports.tf
  gen_import_tf "${um_id}"

  # alternative to import block in imports.tf is to use the terraform import command
  # terraform import aws_instance.unmanaged "${um_id}"

  # The imports.tf file is defined as a data resource
  # this allows it to be deleted on destroy this is only to allow repeated demonstrations
  # The imports.tf file will register the unmanaged instance using the
  # import block and allow the unmanged instance to be managed by terraform
  # using the aws_instance resource block
  terraform apply -auto-approve

  # you can now configure the unmanaged instance using terraform
  # by editing the imports.tf file and running terraform apply

  # show terrafrom managed resources
  terraform state list

  # show all AWS resources for project
  show_resources

fi
