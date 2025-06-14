#include <stdio.h>

int main()
{
    int number1;
    int number2;
    int number3;

    scanf("%d %d %d", &number1, &number2, &number3);

    printf("%10d%10d%10d\n", number1, number2, number3);
    printf("%-6d%-6d%-6d", number1, number2, number3);

    return 0;
}