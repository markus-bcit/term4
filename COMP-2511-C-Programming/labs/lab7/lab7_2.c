#include <stdio.h>

int main()
{
    int n = 0;
    int *p = &n; 
    scanf("%d", p);
    printf("%d", n);
}