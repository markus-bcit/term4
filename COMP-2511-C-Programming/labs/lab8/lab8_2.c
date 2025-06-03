#include <stdio.h>

void max_min( int x, int y, int* pmin, int* pmax)
{
    int tmp = *m;
    *m = *n;
    *n = tmp;

    return *m > *n ? *m : *n;
}

int main(void)
{
    int m = 22, n = 11;
    printf("%d", swap(&m, &n)); /*should print 22*/
    printf("%d", m);            /*should print 11*/
}
