#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[100];
    scanf("%s", input);
    int x = 0;
    for (; input[x] != '\0'; x++)
    {
        if (!isdigit(input[x]) && x != 0)
        {
            printf("no");
            return 0;
        }
    };
    if (x != 9)
    {
        printf("no");
        return 0;
    }

    if ((input[0] != 'a') && (input[0] != 'A'))
    {
        printf("no");
        return 0;
    }
    printf("yes");
    return 0;
}