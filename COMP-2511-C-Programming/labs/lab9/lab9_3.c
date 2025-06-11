#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[100];
    scanf("%s", input);

    for (int x = 0; input[x] != '\0'; x++ )
    {
        if (islower(input[x]))
        {
            input[x] = toupper(input[x]);
        }
    }
    printf("%s", input);

    return 0;
}