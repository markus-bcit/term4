variable "ec2_count" {
  description = "count of ec2s"
  type        = number
}
variable "project_name" {
  description = "Project name"
  type        = string
}

variable "ec2_type" {
  description = "AWS region"
  type        = string
}
variable "aws_subnets" {
  description = "VPC CIDR written in CIDR notation, must have a 16 bit netmask"
  type        = list(string)
}


variable "ssh_key_name" {
  description = "AWS SSH key name"
  type        = string

}

variable "ami_id" {
  description = "AMI ID"
}

variable "vpc_security_group_ids" {
  description = "SGs for ec2s"
  type        = list(string)
}
variable "tags" {
  description = "tags for ec2s"
  default = "bun"
}
