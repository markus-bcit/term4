#include <stdio.h>

int largest(double data[], size_t length)
{
    double max = data[0];
    int max_index = 0;
    for (int x = 0; x < length; x++)
    {
        if (data[x] > max)
        {
            max = data[x];
            max_index = x;
        }
    };
    return max_index;
}

int main()
{
    double data[5] = {1.2, 3.2, 15.43, 135.1, 15.0};
    printf("Index of highest: %d", largest(data, 5));
}