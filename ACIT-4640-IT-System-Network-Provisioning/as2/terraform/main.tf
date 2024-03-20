resource "aws_vpc" "main" {
  # https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/vpc
  cidr_block           = var.vpc_cidr
  instance_tenancy     = "default"
  enable_dns_hostnames = true
}

resource "aws_subnet" "main" {

  count  = length(var.aws_availability_zones)
  vpc_id = aws_vpc.main.id

  # the cidr_block is created by taking the first two octets of the VPC IPv4 address
  # and using the third octet from the count of the subnet
  cidr_block              = var.aws_subnets[count.index]
  availability_zone       = var.aws_availability_zones[count.index]
  map_public_ip_on_launch = true

  tags = {
    Name    = "${var.project_name}_${var.aws_availability_zones[count.index]}"
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
resource "aws_route_table_association" "main" {
  count = length(aws_subnet.main)

  subnet_id      = aws_subnet.main[count.index].id
  route_table_id = aws_route_table.main.id
}

## ----------------------------------------------------------------------------
## CONFIGURE VPC SECURITY 
## ----------------------------------------------------------------------------

resource "aws_security_group" "main" {
  name        = var.security_group.name
  description = var.security_group.description
  vpc_id      = aws_vpc.main.id
  tags = {
    Name    = "${var.project_name}_${var.security_group.name}"
    Project = var.project_name
  }
}

resource "aws_vpc_security_group_ingress_rule" "main" {
  for_each = {
    for index, rule in var.security_group.ingress_rules :
    rule.rule_name => rule
  }

  description       = each.value.description
  ip_protocol       = each.value.ip_protocol
  from_port         = each.value.from_port
  to_port           = each.value.to_port
  cidr_ipv4         = each.value.cidr_ipv4
  security_group_id = aws_security_group.main.id
  tags = {
    Name    = each.value.rule_name
    Project = var.project_name
  }
}

resource "aws_vpc_security_group_egress_rule" "main" {
  for_each = {
    for index, rule in var.security_group.egress_rules :
    rule.rule_name => rule
  }

  description       = each.value.description
  security_group_id = aws_security_group.main.id
  ip_protocol       = each.value.ip_protocol
  cidr_ipv4         = each.value.cidr_ipv4
  from_port         = each.value.from_port
  to_port           = each.value.to_port

  tags = {
    Name    = "${var.project_name}_${each.value.rule_name}"
    Project = var.project_name
  }
}

## ----------------------------------------------------------------------------
## SETUP SSH KEY PAIR: LOCAL FILE AND AWS KEY PAIR
## ----------------------------------------------------------------------------

module "ssh_key" {
  source   = "./modules/aws_ssh_key_pair"
  key_name = var.ssh_key_name
}


module "ec2" {
  source       = "./modules/ec2"
  project_name = var.project_name
  ec2_count    = var.ec2_count
  ami_id       = var.ami_id
  aws_subnets  = [for subnet in aws_subnet.main : subnet.id]
  ssh_key_name = var.ssh_key_name
  ec2_type     = var.ec2_type
  vpc_security_group_ids = [aws_security_group.main.id]
}

resource "local_file" "all_vars" {
  content = <<-EOF
  ansible_ssh_private_key_file: "${abspath(module.ssh_key.priv_key_file)}"
  ansible_user: ubuntu
  EOF
  filename = abspath("${path.root}/../ansible/group_vars/all.yml")
}
