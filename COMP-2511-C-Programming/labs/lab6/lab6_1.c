#include <stdio.h>

double mean (const int data[], size_t length)
{
    int sum = 0;
    for (int x = 0; x < length; x++)
    {
        sum += data[x];
    }
    return (float)sum / length;
}
int main()
{
    int data[4] = {5,5,5,4};
    printf("%f", mean(data, 4));
    return 0;
}