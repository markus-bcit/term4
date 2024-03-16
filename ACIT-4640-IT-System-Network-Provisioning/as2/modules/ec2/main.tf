
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