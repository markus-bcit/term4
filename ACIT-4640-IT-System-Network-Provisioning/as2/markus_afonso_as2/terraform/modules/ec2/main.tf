
resource "aws_instance" "ec2_instance" {
  count         = var.ec2_count
  ami           = var.ami_id
  instance_type = var.ec2_type
  key_name      = var.ssh_key_name
  subnet_id     = var.aws_subnets[count.index]
  vpc_security_group_ids = var.vpc_security_group_ids
  tags = {
    Project = var.project_name
    Name = join("_", [var.tags, count.index])
  }
}

