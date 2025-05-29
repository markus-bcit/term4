#include <stdio.h>
#include <math.h>

int max_abs(const int data[], size_t length)
{
    int max = data[0];
    for (int x = 1; x < length; x++)
    {
        if (abs(data[x]) > abs(max)) max = data[x];
    }
    return max;
}
int main()
{
    // int data[4] = {5, -6, 5, 4};
    // printf("%d", max_abs(data, 4));
    int a = -1, b = 0;

    printf("%d", ++a || --b);
    printf("%d", 0 && 1);

    return 0;
}