#include <stdio.h>

int main()
{
    char name[100] = "";
    scanf("%s", name);
    for (int i = 1; i < 100; i++)
    {
        if (name[i] == '\0') break;
        printf("%c", name[i]);
    }
    return 0;
}