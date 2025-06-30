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
