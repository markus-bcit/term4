#include <stdio.h>
#include <math.h>

void sinAndPrint(float x)
{
    printf("%f", 2 * sin(x) * cos(x));
}

int main()
{
    float x;
    scanf("%f", &x);
    sinAndPrint(x);
    return 0;
}