#include <stdio.h>

int minimum(const int data[][10], const size_t n)
{
    int min = data[0][0];
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            if (data[x][y] < min) min = data[x][y];
        }
    }
    return min;
}

int main()
{
int data[4][10] = {
    {1, 3, 4, 99, 99, 99, 99, 99, 99, 99},
    {3, 4, 4, 99, 99, 99, 99, 99, 99, 99},
    {1, 6, 4, 99, 99, 99, 99, 99, 99, 99}
};    printf("%d", minimum(data, 3));
    return 0;
}