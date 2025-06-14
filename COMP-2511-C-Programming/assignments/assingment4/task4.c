#include <stdio.h>

void copy_arr(double source[], double target[], size_t size)
{
    for (int x = 0; x < size; x++)
    {
        target[x] = source[x];
    }
}

void copy_ptr(double *source, double *target, size_t size)
{
    for (int x = 0; x < size; x++)
    {
        target[x] = source[x];
    }
}

int main()
{
    double source[] = {1.1, 2.2, 3.3, 4.4, 5.5}; // assuming it should be "3.3" and not "3.3."
    double target1[5];
    double target2[5];
    copy_arr(source, target1, 5);
    copy_ptr(source, target2, 5); // assuming this should be target2 and not target1

    for (int x = 0; x < 5; x++)
    {
        printf("%f\n", target1[x]);
    }

    for (int x = 0; x < 5; x++)
    {
        printf("%f\n", target2[x]);
    }

    return 0;
}