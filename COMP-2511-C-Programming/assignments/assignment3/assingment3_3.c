#include <stdio.h>

void printer(char character, int times, int lines)
{
    for (int x = 0; x < lines; x++)
    {
        for (int y = 0; y < times; y++)
        {
            printf("%c", character);
        };
        printf("\n");
    };
}

int main()
{
    char character = '\0';
    int times = 0;
    int lines = 0;
    printf("Enter a character: ");
    scanf("%c", &character);
    printf("Enter how many times: ");
    scanf("%d", &times);
    printf("Enter how many lines: ");
    scanf("%d", &lines);
    printer(character, times, lines);
}
