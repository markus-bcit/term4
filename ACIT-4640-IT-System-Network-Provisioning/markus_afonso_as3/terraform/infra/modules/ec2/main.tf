resource "aws_instance" "ec2_instance_public" {
  ami           = var.ami_id
  instance_type = var.ec2_type
  key_name      = var.ssh_key_name
  subnet_id     = var.aws_subnet_public
  vpc_security_group_ids = var.vpc_security_group_public
  tags = {
    Project = var.project_name
    Name = "frontend"
  }
}

resource "aws_instance" "ec2_instance_private" {
  ami           = var.ami_id
  instance_type = var.ec2_type
  key_name      = var.ssh_key_name
  subnet_id     = var.aws_subnet_private
  vpc_security_group_ids = var.vpc_security_group_private
  tags = {
    Project = var.project_name
    Name = "backend"
  }
}

