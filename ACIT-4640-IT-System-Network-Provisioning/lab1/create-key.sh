aws ec2 create-key-pair \
    --key-name key-pair \
    --key-type ed25519 \
    --key-format pem \
    --query "KeyMaterial" \
    --output text > key-pair.pem
