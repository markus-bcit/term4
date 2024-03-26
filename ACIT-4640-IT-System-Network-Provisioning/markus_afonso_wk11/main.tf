provider "aws" {
  region  = "us-west-2"
}

resource "aws_dynamodb_table" "student_info_table" {
  name         = "student_info_table"
  billing_mode = "PAY_PER_REQUEST"
  hash_key     = "studentID"
  attribute {
    name = "studentID"
    type = "S"
  }
}

resource "aws_dynamodb_table_item" "student_info_item" {
  table_name = aws_dynamodb_table.student_info_table.name

  hash_key = "studentID"
  
  item = <<ITEM
{
  "studentID": {"S": "A0123456"},
  "math_grade": {"M": {"student_grade": {"S": "42F"}}},
  "student_name": {"S": "Morty Smith"}
}
ITEM
}
