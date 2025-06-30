#include <string.h>
#include <stdio.h>

struct abc
{
    int a;
    char b[3];
    double c;
};

int main()
{
    struct abc xyz;
    printf("%d", sizeof(xyz));
    return 0;
}