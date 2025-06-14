#include <stdio.h>

void mymax(double *array1, size_t length, int *index)
{
    double max = array1[0];
    for (int x = 0; x < length; x++) 
    {
        if (array1[x] > max)
        {
            max = array1[x];
            *index = x;
        }
    }
}

int main()
{
    double array1[] = {1.0, 2.3, 3.4, 2.4, 2.0};
    int index = 0;

    mymax(array1, sizeof(array1) / sizeof(array1[0]), &index);
    printf("%d", index);

    return 0;
}
