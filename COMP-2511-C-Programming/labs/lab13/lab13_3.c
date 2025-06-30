#include <string.h>
#include <stdio.h>

struct student
{
    char firstname[20];
    char lastname[20];
    int age;
};

int main()
{
    struct student s1, s2;
    struct student *s2ptr = &s2;

    s1.age = 33;
    strcpy(s1.firstname, "Rupert");
    strcpy(s1.lastname, "Grint");

    s2ptr -> age = 31;
    strcpy(s2ptr -> firstname, "Emma");
    strcpy((*s2ptr).lastname, "Watson");

    printf("%s", s2ptr -> firstname);
    return 0;
}