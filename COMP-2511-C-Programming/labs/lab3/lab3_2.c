#include <stdio.h>

int Compare(int firstNumber, int secondNumber)
{
    if (firstNumber < secondNumber) return firstNumber;
    return secondNumber;
}

int main()
{
    int firstNumber;
    int secondNumber;
    scanf("%d %d", &firstNumber, &secondNumber);
    int blah = Compare(firstNumber, secondNumber);
    printf("%d", blah);
    return 0;
}