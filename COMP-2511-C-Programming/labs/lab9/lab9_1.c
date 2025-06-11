#include <stdio.h>

int main()
{
    char input[100];
    scanf("%s", input);

    for (int x = 0; input[x] != '\0'; x++ )
    {
        if (('a' <= input[x]) && ('z' >= input[x]))
        {
            input[x] = input[x] - ('a' - 'A');
        }
    }
    printf("%s", input);

    return 0;
}