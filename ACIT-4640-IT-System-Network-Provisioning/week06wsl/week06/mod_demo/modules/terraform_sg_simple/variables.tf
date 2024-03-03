variable "name" {
  description = "The name of the security group"
}

variable "description" {
  description = "The description of the security group"
}

variable "vpc_id" {
  description = "The ID of the VPC where the security group will be created"
}

variable "ingress_from_port" {
  description = "The start port for ingress rules"
}

variable "ingress_to_port" {
  description = "The end port for ingress rules"
}

variable "ingress_protocol" {
  description = "The protocol for ingress rules (e.g., tcp, udp, icmp)"
}

variable "ingress_cidr_blocks" {
  description = "The CIDR blocks to allow for ingress traffic"
}

variable "egress_from_port" {
  description = "The start port for egress rules"
}

variable "egress_to_port" {
  description = "The end port for egress rules"
}

variable "egress_protocol" {
  description = "The protocol for egress rules (e.g., tcp, udp, icmp)"
}

variable "egress_cidr_blocks" {
  description = "The CIDR blocks to allow for egress traffic"
}