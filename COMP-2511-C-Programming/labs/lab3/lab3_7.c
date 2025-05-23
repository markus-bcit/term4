#include <stdio.h>

void printer(double number)
{
    printf("%d %f %f", (int)number, number, (float)number);
}

int main()
{
    double number;
    scanf("%lf", &number);
    printer(number);
    return 0;
}