#include <stdio.h>

int integerPower(int base, int exponent)
{
    int sum = 1;
    for (; exponent > 0; exponent--)
    {
        sum = sum * base;
    }
    return sum;
}

int checkPositiveNonZero(int number)
{
    if (number < 0)
        return 1;
    if (number == 0)
        return 1;
    return 0;
}

int main()
{
    int base;
    int exponent;
    int error;

    printf("Enter an integer base: ");
    scanf("%d", &base);
    printf("Enter a positive integer exponent: ");
    scanf("%d", &exponent);

    error = checkPositiveNonZero(exponent);
    if (error)
    {
        printf("Invalid integer.");
        return error;
    }

    printf("%d", integerPower(base, exponent));
    return 0;
}