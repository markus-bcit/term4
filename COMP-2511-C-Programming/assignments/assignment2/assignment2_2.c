#include <stdio.h>

int isPrime(int number)
{

    if ((number % 2 == 0) || (number % 3 == 0)|| (number % 5 == 0) || (number % 7 == 0)) return 1;
    return 0;
}

int main()
{
    int number;
    int result;

    printf("Enter an integer:");
    scanf("%d", &number);
    
    result = isPrime(number);

    if (result)
    {
        printf("%d is NOT a prime number", number);
        return 0;
    }
    printf("%d is a prime number", number);
    return 0;
}