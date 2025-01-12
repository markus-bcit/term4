resource "aws_vpc" "main" {
  # https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/vpc
  cidr_block           = var.vpc_cidr
  instance_tenancy     = "default"
  enable_dns_hostnames = true
}

resource "aws_subnet" "public" {

  vpc_id = aws_vpc.main.id

  # the cidr_block is created by taking the first two octets of the VPC IPv4 address
  # and using the third octet from the count of the subnet
  cidr_block              = var.aws_subnet_public
  map_public_ip_on_launch = true
  availability_zone = "us-west-2a"

  tags = {
    Name    = "${var.project_name}_${var.aws_availability_zones}"
    Project = var.project_name
  }
}


resource "aws_subnet" "private" {

  vpc_id = aws_vpc.main.id

  # the cidr_block is created by taking the first two octets of the VPC IPv4 address
  # and using the third octet from the count of the subnet
  cidr_block              = var.aws_subnet_private
  map_public_ip_on_launch = true
  availability_zone = "us-west-2a"

  tags = {
    Name    = "${var.project_name}_${var.aws_availability_zones}"
    Project = var.project_name
  }
}

resource "aws_internet_gateway" "main" {

  vpc_id = aws_vpc.main.id

  tags = {
    Name    = var.project_name
    Project = var.project_name
  }
}

resource "aws_route_table" "main" {
  vpc_id = aws_vpc.main.id

  route {
    cidr_block = var.default_route
    gateway_id = aws_internet_gateway.main.id
  }

  tags = {
    Name    = var.project_name
    Project = var.project_name
  }
}

# Associate the route table with all of the subnets
resource "aws_route_table_association" "public" {

  subnet_id      = aws_subnet.public.id
  route_table_id = aws_route_table.main.id
}
resource "aws_route_table_association" "private" {

  subnet_id      = aws_subnet.private.id
  route_table_id = aws_route_table.main.id
}

## ----------------------------------------------------------------------------
## CONFIGURE VPC SECURITY 
## ----------------------------------------------------------------------------

module "security_groups" {
  source = "./modules/sg"
  vpc_main_id          = aws_vpc.main.id
  project_name         = var.project_name
  vpc_security_group_public = var.vpc_security_group_public
  vpc_security_group_private = var.vpc_security_group_private
  vpc_cidr             = var.vpc_cidr
}

## ----------------------------------------------------------------------------
## SETUP SSH KEY PAIR: LOCAL FILE AND AWS KEY PAIR
## ----------------------------------------------------------------------------

module "ssh_key" {
  source   = "./modules/aws_ssh_key_pair"
  key_name = var.ssh_key_name
}


module "ec2_instances" {
  source = "./modules/ec2"

  project_name             = var.project_name
  ami_id                   = var.ami_id
  ec2_type                 = var.ec2_type
  ssh_key_name             = var.ssh_key_name
  aws_subnet_public        = aws_subnet.public.id
  vpc_security_group_public = [module.security_groups.public_security_group_id]
  aws_subnet_private       = aws_subnet.private.id
  vpc_security_group_private = [module.security_groups.private_security_group_id]
}


resource "local_file" "all_vars" {
  content = <<-EOF
  ansible_ssh_private_key_file: "${abspath(module.ssh_key.priv_key_file)}"
  ansible_user: ubuntu
  EOF
  filename = abspath("${path.root}/../../ansible/group_vars/all.yml")
}
