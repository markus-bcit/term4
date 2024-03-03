# -----------------------------------------------------------------------------
# ACIT 4640 IT System-Network Provisioning Assignment 1
# Markus Afonso 
# Set C
# 
# -----------------------------------------------------------------------------
terraform {
  required_providers {
    aws = {
      source  = "hashicorp/aws"
      version = "~> 5.0"
    }
  }
}

# -----------------------------------------------------------------------------
# Define variables for use in main terraform module (aka this file)
# Reference: https://developer.hashicorp.com/terraform/language/values/locals
# Tutorial: https://developer.hashicorp.com/terraform/tutorials/configuration-language/locals
# -----------------------------------------------------------------------------
locals {
  base_cidr_block   = "10.0.0.0/16"
  public_subnet_cidr_block = "10.0.1.0/24"
  private_subnet_cidr_block = "10.0.2.0/24"
  project_name      = "acit4640_as1"
  availability_zone = "us-west-2a"
  ssh_key_name      = "acit4640_as1_key"
}

# -----------------------------------------------------------------------------
# Configure the AWS provider 
# Language Reference: https://developer.hashicorp.com/terraform/language/providers
# AWS Reference: https://registry.terraform.io/providers/hashicorp/aws/latest/docs
# -----------------------------------------------------------------------------
provider "aws" {
  region = "us-west-2"
  profile = "default"
  # https://registry.terraform.io/providers/hashicorp/aws/latest/docs#default_tags-configuration-block
  default_tags {
    tags = {
      Project = "${local.project_name}"
    }
  }
}

resource "aws_vpc" "main" {
  # https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/vpc
  cidr_block           = local.base_cidr_block
  instance_tenancy     = "default"
  enable_dns_hostnames = true
}

resource "aws_subnet" "public" {
  # Reference: https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/subnet
  vpc_id                  = aws_vpc.main.id
  cidr_block              = local.public_subnet_cidr_block
  availability_zone       = local.availability_zone
  map_public_ip_on_launch = true
}

resource "aws_subnet" "private" {
  # Reference: https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/subnet
  vpc_id                  = aws_vpc.main.id
  cidr_block              = local.private_subnet_cidr_block
  availability_zone       = local.availability_zone
  map_public_ip_on_launch = false
}

resource "aws_internet_gateway" "main" {
  # https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/internet_gateway
  vpc_id = aws_vpc.main.id
}

resource "aws_route_table" "main" {
  # https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/route_table
  vpc_id = aws_vpc.main.id

  tags = {
    Name = "main-route"
  }
}

resource "aws_route" "default_route" {
  # https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/route
  route_table_id         = aws_route_table.main.id
  destination_cidr_block = "0.0.0.0/0"
  gateway_id             = aws_internet_gateway.main.id
}

resource "aws_route_table_association" "main" {
  subnet_id      = aws_subnet.public.id
  route_table_id = aws_route_table.main.id
}

# ############# security group public ####################

resource "aws_security_group" "public" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/security_group
  name        = "${local.project_name}_public_sg"
  description = "allow all outbound traffic and ssh and http in from everywhere"
  vpc_id      = aws_vpc.main.id

}

resource "aws_vpc_security_group_ingress_rule" "http_public_in" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/vpc_security_group_ingress_rule
  description       = "allow HTTP in form everyehere"
  security_group_id = aws_security_group.public.id
  ip_protocol       = "tcp"
  from_port         = 80
  to_port           = 80
  cidr_ipv4         = "0.0.0.0/0"
}

resource "aws_vpc_security_group_ingress_rule" "ssh_public_in" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/vpc_security_group_ingress_rule 
  description       = "allow ssh from everywhere"
  security_group_id = aws_security_group.public.id
  ip_protocol       = "tcp"
  from_port         = 22
  to_port           = 22
  cidr_ipv4         = "0.0.0.0/0"
}


resource "aws_vpc_security_group_egress_rule" "http_public_e" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/vpc_security_group_egress_rule 
  description       = "allow ssh out everywhere"
  security_group_id = aws_security_group.public.id
  ip_protocol       = "tcp"
  from_port         = 80
  to_port           = 80
  cidr_ipv4         = "0.0.0.0/0"
}

resource "aws_vpc_security_group_egress_rule" "ssh_public_e" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/vpc_security_group_egress_rule 
  description       = "allow ssh from everywhere"
  security_group_id = aws_security_group.public.id
  ip_protocol       = "tcp"
  from_port         = 22
  to_port           = 22
  cidr_ipv4         = "0.0.0.0/0"
}
# ############# security group private ####################

resource "aws_security_group" "private" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/security_group
  name        = "${local.project_name}_private_sg"
  description = "allow ssh and http in from only the vpc"
  vpc_id      = aws_vpc.main.id

}

resource "aws_vpc_security_group_egress_rule" "ssh_private_e" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/vpc_security_group_egress_rule
  # make this open to everything from everywhere
  description       = "allow ssh out"
  security_group_id = aws_security_group.private.id
  ip_protocol       = "tcp"
  from_port         = 22
  to_port           = 22
  cidr_ipv4         = aws_vpc.main.cidr_block
}

resource "aws_vpc_security_group_egress_rule" "http_private_e" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/vpc_security_group_egress_rule
  # make this open to everything from everywhere
  description       = "allow http out"
  security_group_id = aws_security_group.private.id
  ip_protocol       = "tcp"
  from_port         = 80
  to_port           = 80
  cidr_ipv4         = aws_vpc.main.cidr_block
}

resource "aws_vpc_security_group_ingress_rule" "ssh_private_in" {
  # https://registry.terraform.io/providers/-/aws/latest/docs/resources/vpc_security_group_ingress_rule 
  # ssh and http in from everywhere
  description       = "allow ssh in from subnet"
  security_group_id = aws_security_group.private.id
  ip_protocol       = "tcp"
  from_port         = 22
  to_port           = 22
  cidr_ipv4         = aws_vpc.main.cidr_block
}

resource "aws_vpc_security_group_ingress_rule" "http_private_in" {
  description       = "allow http in from subnet"
  security_group_id = aws_security_group.private.id
  ip_protocol       = "tcp"
  from_port         = 80
  to_port           = 80
  cidr_ipv4         = aws_vpc.main.cidr_block

}


# -----------------------------------------------------------------------------
# Setup ssh keys 
# -----------------------------------------------------------------------------
# Generate local ssh key pair 
resource "terraform_data" "ssh_key_pair" {
  # https://developer.hashicorp.com/terraform/language/resources/terraform-data

  # This stores the path to the private key 
  input = "${path.module}/${local.ssh_key_name}.pem"

  provisioner "local-exec" {
    # https://developer.hashicorp.com/terraform/language/resources/provisioners/local-exec
    command = "ssh-keygen -C \"${local.ssh_key_name}\" -f \"${path.module}/${local.ssh_key_name}.pem\" -m PEM -t ed25519 -N ''"
    
    # https://developer.hashicorp.com/terraform/language/resources/provisioners/syntax#creation-time-provisioners
    when    = create
  }

  provisioner "local-exec" {
    # glob expressions don't work - need to delete each file individually
    command = "rm -f \"${self.output}\" \"${self.output}.pub\""

    # https://developer.hashicorp.com/terraform/language/resources/provisioners/syntax#destroy-time-provisioners
    when = destroy

  }
}

# -----------------------------------------------------------------------------
# Get local ssh key pair file
# -----------------------------------------------------------------------------
# Get the public key from a local file which is assumed to be in the same
# directory as the terraform file
data "local_file" "ssh_pub_key" {
# https://registry.terraform.io/providers/hashicorp/local/latest/docs/data-sources/file
# https://developer.hashicorp.com/terraform/language/expressions/references#filesystem-and-workspace-info
  filename = "${path.module}/${local.ssh_key_name}.pem.pub"

  # depends_on is used to ensure that the local key reading the local file
  depends_on = [terraform_data.ssh_key_pair]

}

# -----------------------------------------------------------------------------
# Create AWS key from local key file
# -----------------------------------------------------------------------------
# The resource below assumes that we have created a local key pair but
# haven't imported it to AWS yet. From the docs: 
# "Currently this resource requires an existing user-supplied key pair. 
# This key pair's public key will be registered with AWS to allow logging-in to
# EC2 instances." 
resource "aws_key_pair" "ssh_key_pair" {
# https://registry.terraform.io/providers/-/aws/latest/docs/resources/key_pair
  key_name   = local.ssh_key_name
  public_key = data.local_file.ssh_pub_key.content

  # depends_on is used to ensure that the local key is created before the AWS
  # key pair is "imported"
  # https://developer.hashicorp.com/terraform/language/meta-arguments/depends_on
  depends_on = [terraform_data.ssh_key_pair]
}

# -----------------------------------------------------------------------------
# Get the most recent ami for Ubuntu 22.04
# -----------------------------------------------------------------------------
data "aws_ami" "ubuntu" {
# https://registry.terraform.io/providers/hashicorp/aws/latest/docs/data-sources/ami
  most_recent = true
  # this is the owner id for Canonical - the publisher of Ubuntu
  owners = ["099720109477"]

  filter {
    name = "name"
    # This is a glob expression - the * is a wildcard - that matches  the most
    # recent Ubuntu 23.04 image x86 64-bit server image
    values = ["ubuntu/images/hvm-ssd/ubuntu-lunar-23.04-amd64-server-*"]
  }
}

resource "aws_instance" "public" {
# https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/instance
  instance_type = "t2.micro"
  ami           = data.aws_ami.ubuntu.id

  key_name               = local.ssh_key_name 
  vpc_security_group_ids = [aws_security_group.public.id]
  subnet_id              = aws_subnet.public.id
  user_data              = file("${path.module}/ec2_host_setup.sh")

}

resource "aws_instance" "private" {
# https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/instance
  instance_type = "t2.micro"
  ami           = data.aws_ami.ubuntu.id

  key_name               = local.ssh_key_name
  vpc_security_group_ids = [aws_security_group.private.id]
  subnet_id              = aws_subnet.private.id

}


# output public ip address of the instance
output "instance_public_ip" {
  value = aws_instance.public.public_dns
}

output "instance_private_ip" {
  value = aws_instance.private.private_ip
} 