#include <stdio.h>
#include <math.h>

void printHundredTimes(char character)
{
    for (int x = 1; x <= 100; x++)
    {
        printf("%c\n", character);
    }
}

int main()
{
    char character;
    scanf("%c", &character);
    printHundredTimes(character);
    return 0;
}