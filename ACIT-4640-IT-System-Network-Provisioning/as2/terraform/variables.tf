variable "aws_region" {
  description = "AWS region"
  type        = string
  default     = "us-west-2"
}
variable "ec2_type" {
  description = "AWS region"
  type        = string
  default     = "t2.micro"
}

variable "aws_availability_zones" {
  description = "AWS availability zones"
  type        = list(string)
  default     = ["us-west-2a", "us-west-2b"]
}
variable "ec2_count" {
  description = "count of ec2s"
  type        = number
  default     = 2
}
variable "project_name" {
  description = "Project name"
  type        = string
  default     = "acit4640_as2"
}

variable "vpc_cidr" {
  description = "VPC CIDR written in CIDR notation, must have a 16 bit netmask"
  default     = "10.0.0.0/16"
  type        = string
}

variable "aws_subnets" {
  description = "VPC CIDR written in CIDR notation, must have a 16 bit netmask"
  type        = list(string)
  default     = ["10.0.1.0/24", "10.0.2.0/24"]
}

variable "default_route" {
  description = "Default route"
  default     = "0.0.0.0/0"
  type        = string
}


variable "ssh_key_name" {
  description = "AWS SSH key name"
  type        = string
  default     = "acit4640_as2_key"

}

variable "ami_id" {
  description = "AMI ID"
  default     = "ami-03839f1dba75bb628"

}

variable "security_group" {
  description = "configuration for security group"
  type = object({
    name        = string
    description = string
    egress_rules = list(object(
      {
        description = string
        ip_protocol = string
        from_port   = number
        to_port     = number
        cidr_ipv4   = string
        rule_name   = string
      }
    ))
    ingress_rules = list(object(
      {
        description = string
        ip_protocol = string
        from_port   = number
        to_port     = number
        cidr_ipv4   = string
        rule_name   = string
      }
    ))
  })
  default = {
    name        = "sg_count_dyn_inv"
    description = "Allows ssh, web, and intra-vpc ingress access and all egress"
    ingress_rules = [
      {
        description = "allow ssh from everywhere"
        ip_protocol = "tcp"
        from_port   = 22
        to_port     = 22
        cidr_ipv4   = "0.0.0.0/0"
        rule_name   = "allow ssh"
      },
      {
        description = "allow http from everywhere"
        ip_protocol = "tcp"
        from_port   = 80
        to_port     = 80
        cidr_ipv4   = "0.0.0.0/0"
        rule_name   = "allow http"
      },
    ]
    egress_rules = [
      {
        description = "allow all egress traffic"
        ip_protocol = "-1"
        from_port   = null
        to_port     = null
        cidr_ipv4   = "0.0.0.0/0"
        rule_name   = "allow_all_egress"
      }
    ]
  }
}