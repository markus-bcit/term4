#include <stdio.h>
#include <math.h>

float printAndAbs(float number)
{
    printf("%f", number);
    return fabs(number);
}

int main()
{
    float number;
    scanf("%f", &number);
    float blah = printAndAbs(number);
    printf("%f", blah);
    return 0;
}