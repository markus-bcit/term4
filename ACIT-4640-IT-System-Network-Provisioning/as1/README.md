ACIT 4640 IT System-Network Provisioning Assignment 1 

Markus Afonso Set C

Single Command:
```bash
aws ec2 describe-vpcs --output yaml --query 'Vpcs' && aws ec2 describe-route-tables --output yaml --query 'RouteTables' && aws ec2 describe-internet-gateways --output yaml --query 'InternetGateways' && aws ec2 describe-security-groups --output yaml --query 'SecurityGroups' && aws ec2 describe-instances --output yaml --query 'Reservations[*].Instances[*]'
```