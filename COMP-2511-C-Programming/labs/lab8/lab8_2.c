#include <stdio.h>

void max_min(int x, int y, int* pmin, int* pmax)
{
    if (x > y)
    {
        *pmax = x;
        *pmin = y;
        return;
    }
    *pmax = y;
    *pmin = x;
}

int main(void)
{
    int x = 22;
    int y = 11;
    int pmin;
    int pmax;
    printf("%d %d\n", pmax, pmin);
    max_min(x, y, &pmin, &pmax);
    printf("%d %d", pmax, pmin);
}
