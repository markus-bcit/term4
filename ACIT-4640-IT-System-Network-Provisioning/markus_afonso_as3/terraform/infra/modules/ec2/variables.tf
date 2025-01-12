
variable "project_name" {
  description = "Project name"
  type        = string
}

variable "ec2_type" {
  description = "AWS region"
  type        = string
}


variable "ssh_key_name" {
  description = "AWS SSH key name"
  type        = string

}

variable "ami_id" {
  description = "AMI ID"
}

variable "aws_subnet_public" {
  description = "Public subnet ID where the EC2 instance will be launched"
  type        = string
}

variable "vpc_security_group_public" {
  description = "Security group ID for the public EC2 instance"
  type        = list(string)
}

variable "aws_subnet_private" {
  description = "Private subnet ID where the EC2 instance will be launched"
  type        = string
}

variable "vpc_security_group_private" {
  description = "Security group ID for the private EC2 instance"
  type        = list(string)
}

variable "tags" {
  description = "tags for ec2s"
  default = "bun"
}
