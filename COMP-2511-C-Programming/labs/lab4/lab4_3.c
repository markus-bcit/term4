#include <stdio.h>

long Factorial(long res)
{
    if (res == 0) return 1;
    return res * Factorial(res - 1);
}
int main()
{
    long ten = 10;
    long result = Factorial(ten);
    printf("%ld", result);
    return 0;
}