#include <stdio.h>

int main()
{
    int first;
    int second;
    printf("Enter two numbers: \n");
    scanf("%d %d", &first, &second);
    printf("Sum: %d\n", first + second);
    printf("Product: %d\n", first * second);
    printf("Difference: %d\n", first - second);
    printf("Quotient: %d\n", first / second);
    printf("Remainder: %d\n", first % second);

    return 0;
}