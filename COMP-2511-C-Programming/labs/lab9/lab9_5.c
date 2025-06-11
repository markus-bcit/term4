#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[100];

    fgets(input, 100, stdin);

    for (int x = 0; input[x] != '\0'; x++)
    {
        printf("%c%c%c", input[x], input[x], input[x]);
    }

    return 0;
}