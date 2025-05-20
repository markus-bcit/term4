#include <stdio.h>

void NumberPrint(int number)
{
    printf("%d", number * 3);
    return;
}

int main()
{
    int number;
    scanf("%d", &number);
    NumberPrint(number);
    return 0;
}