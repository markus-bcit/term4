#include <stdio.h>

int difference(int data[], size_t length)
{
    int max = data[0];
    int min = data[0];

    for (int x = 0; x < length; x++)
    {
        if (data[x] > max)
        {
            max = data[x];
        }
        if (data[x] < min)
        {
            min = data[x];
        }
    };
    return max - min;
}

int main()
{
    int data[5] = {12, 32, 1543, 1351, 150};
    printf("Difference between highest and lowest: %d", difference(data, 5));
}