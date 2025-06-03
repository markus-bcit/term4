#include <stdio.h>

int swap(int *m, int *n)
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
