#include <stdio.h>

size_t in_between(const int data[], size_t length, int val_1, int val_2)
{
    int count = 0;
    for (int x = 0; x < length; x++)
    {
        if (data[x] >= val_1 && data[x] <= val_2) count++;
    }
    return count;
}
int main()
{
    int data[4] = {1, 2, 3, 4};
    printf("%d", in_between(data, 4, 2, 3));
    return 0;
}