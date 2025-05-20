#include <stdio.h>
#include <math.h>



int main()
{
    int firstNumber;
    int secondNumber;
    scanf("%d %d", &firstNumber, &secondNumber);
    int blah = Compare(firstNumber, secondNumber);
    printf("%d", blah);
    return 0;
}