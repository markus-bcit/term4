variable "vpc_main_id" {
  description = "VPC id"
  type        = string
}
variable "vpc_cidr" {
  description = "VPC cidr"
  type        = string
}
variable "project_name" {
  description = "Project name"
  type        = string
  default     = "acit4640_as2"
}

variable "vpc_security_group_public" {
  description = "Configuration for public security group"
  type = object({
    name        = string
    description = string
    egress_rules = list(object({
      description = string
      ip_protocol = string
      from_port   = number
      to_port     = number
      cidr_ipv4   = string
      rule_name   = string
    }))
    ingress_rules = list(object({
      description = string
      ip_protocol = string
      from_port   = number
      to_port     = number
      cidr_ipv4   = string
      rule_name   = string
    }))
  })
  default = {
    name        = "sg_count_dyn_inv"
    description = "Allows SSH, HTTP, and intra-VPC ingress access and all egress"
    ingress_rules = [
      {
        description = "allow SSH from everywhere"
        ip_protocol = "tcp"
        from_port   = 22
        to_port     = 22
        cidr_ipv4   = "0.0.0.0/0"
        rule_name   = "allow_ssh"
      },
      {
        description = "allow HTTP from everywhere"
        ip_protocol = "tcp"
        from_port   = 80
        to_port     = 80
        cidr_ipv4   = "0.0.0.0/0"
        rule_name   = "allow_http"
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

variable "vpc_security_group_private" {
  description = "Configuration for private security group"
  type = object({
    name        = string
    description = string
    egress_rules = list(object({
      description = string
      ip_protocol = string
      from_port   = number
      to_port     = number
      cidr_ipv4   = string
      rule_name   = string
    }))
    ingress_rules = list(object({
      description = string
      ip_protocol = string
      from_port   = number
      to_port     = number
      cidr_ipv4   = string
      rule_name   = string
    }))
  })
  default = {
    name        = "sg_count_dyn_inv"
    description = "Allows SSH from anywhere, HTTP from within only the VPC"
    ingress_rules = [
      {
        description = "allow SSH from everywhere"
        ip_protocol = "tcp"
        from_port   = 22
        to_port     = 22
        cidr_ipv4   = "0.0.0.0/0"
        rule_name   = "allow_ssh"
      },
      {
        description = "allow HTTP from VPC"
        ip_protocol = "tcp"
        from_port   = 80
        to_port     = 80
        cidr_ipv4   = "10.0.0.0/16"
        rule_name   = "allow_http_from_vpc"
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
