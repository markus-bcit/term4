#include <string.h>
#include <stdio.h>

typedef struct abc xyz;
typedef struct abc
{
    int a;
    char b[3];
    double c;
    struct abc *ptr;
};

int main()
{
    xyz newAbc;
    newAbc.a = 10;
    printf("%d", newAbc.a);
    return 0;
}