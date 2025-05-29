#include <stdio.h>

size_t count_even(const int data [][7], const size_t n)
{
    int count = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < 7; y++)
        {
            if (data[x][y] % 2 == 0) count++;
        }
    }
    return count;
}

int main()
{
int data[4][10] = {
    {1, 3, 4, 99, 99, 99, 99},
    {3, 4, 4, 99, 99, 99, 99},
    {1, 6, 4, 99, 99, 99, 99}
};    printf("%d", count_even(data, 3));
    return 0;
}