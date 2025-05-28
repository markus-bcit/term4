#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int x = 0; x < 10; x++)
    {
        printf("Value: %d Index: %d \n", a[x], x);
    }
    return 0;
}