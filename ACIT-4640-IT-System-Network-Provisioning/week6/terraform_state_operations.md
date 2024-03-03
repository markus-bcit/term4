## state exercise

Using the starter Terraform configuration provided below. Remove one of the EC2 instances with the `state rm` command. After removing the EC2 instance try to destroy the rest of your infrastructure. What problems did you encounter?
![[Pasted image 20240213171842.png]]
After identifying the problem destroy your infrastructure. 
![[Pasted image 20240213165721.png]]

Comment out the "aws_instance" resource in main.tf file and recreate your infrastructure with a new `terraform apply`. When your infrastructure has been provisioned add a new EC2 instance with the AWS CLI. Get the values needed for this command using terraform commands. The `terraform console` command might be a good option.

Create the EC2 instance
```bash
aws ec2 run-instances \
--image-id ami-04eed88b1a6b28477 \
--count 1 \
--instance-type t2.micro \
--subnet-id subnet-02ac944b3a6ece50b \
--security-group-ids sg-0f558e87698efcc9c \
--key-name AWS_Key
```

Add tags (replace i-0... with your "InstanceId" value)
```bash
aws ec2 create-tags \
    --resources i-0a73bea0e22513657 \
    --tags Key=Name,Value=ubuntu-server
```

![[Pasted image 20240213171551.png]]
![[Pasted image 20240213171625.png]]

When your new EC2 instance has been created use an im