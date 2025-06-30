#include <stdio.h>
#include <string.h>

union student_info
{
    char name[20];
    char gender;
    int age;
};

struct student
{
    union student_info name;
    union student_info gender;
    union student_info age;
};

int main()
{
    struct student s1;
    strcpy(s1.name.name, "Jenny Simpson");
    s1.gender.gender = 'F';
    s1.age.age = 26;
    
    return 0;
}