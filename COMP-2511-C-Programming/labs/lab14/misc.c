#include <stdio.h>

int main()
{
    int m = 1, n = 2;
    int *p = &m;
    int *q = &n;
    *q = *p;
    ++n;
    m--;
    printf("%d %d", *p, *q);
}