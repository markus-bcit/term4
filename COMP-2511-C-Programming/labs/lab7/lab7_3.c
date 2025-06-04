#include <stdio.h>

int main()
{
    int n = 0;
    int *p = &n; 
    printf("%d\n%d", *p, p);
}