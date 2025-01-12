resource "aws_security_group" "public" {
  name        = var.vpc_security_group_public.name
  description = var.vpc_security_group_public.description
  vpc_id      = var.vpc_main_id
  tags = {
    Name    = "${var.project_name}_${var.vpc_security_group_public.name}"
    Project = var.project_name
  }
}

resource "aws_security_group" "private" {
  name        = var.vpc_security_group_private.name
  description = var.vpc_security_group_private.description
  vpc_id      = var.vpc_main_id
  tags = {
    Name    = "${var.project_name}_${var.vpc_security_group_private.name}"
    Project = var.project_name
  }
}

resource "aws_vpc_security_group_ingress_rule" "public" {
  for_each = {
    for index, rule in var.vpc_security_group_public.ingress_rules :
    rule.rule_name => rule
  }

  description       = each.value.description
  ip_protocol       = each.value.ip_protocol
  from_port         = each.value.from_port
  to_port           = each.value.to_port
  cidr_ipv4         = each.value.cidr_ipv4
  security_group_id = aws_security_group.public.id
  tags = {
    Name    = each.value.rule_name
    Project = var.project_name
  }
}

resource "aws_vpc_security_group_egress_rule" "public" {
  for_each = {
    for index, rule in var.vpc_security_group_public.egress_rules :
    rule.rule_name => rule
  }

  description       = each.value.description
  security_group_id = aws_security_group.public.id
  ip_protocol       = each.value.ip_protocol
  cidr_ipv4         = each.value.cidr_ipv4
  from_port         = each.value.from_port
  to_port           = each.value.to_port

  tags = {
    Name    = "${var.project_name}_${each.value.rule_name}"
    Project = var.project_name
  }
}

resource "aws_vpc_security_group_ingress_rule" "private" {
  for_each = {
    for index, rule in var.vpc_security_group_private.ingress_rules :
    rule.rule_name => rule
  }

  description       = each.value.description
  ip_protocol       = each.value.ip_protocol
  from_port         = each.value.from_port
  to_port           = each.value.to_port
  cidr_ipv4         = each.value.cidr_ipv4
  security_group_id = aws_security_group.private.id
  tags = {
    Name    = each.value.rule_name
    Project = var.project_name
  }
}

resource "aws_vpc_security_group_egress_rule" "private" {
  for_each = {
    for index, rule in var.vpc_security_group_private.egress_rules :
    rule.rule_name => rule
  }

  description       = each.value.description
  security_group_id = aws_security_group.private.id
  ip_protocol       = each.value.ip_protocol
  cidr_ipv4         = each.value.cidr_ipv4
  from_port         = each.value.from_port
  to_port           = each.value.to_port

  tags = {
    Name    = "${var.project_name}_${each.value.rule_name}"
    Project = var.project_name
  }
}
