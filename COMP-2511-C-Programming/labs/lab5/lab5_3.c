#include <stdio.h>

int main()
{
    char name[100] = "";
    scanf("%s", name);
    
    int length = 0;
    while (name[length] != '\0') length++;

    for (int i = 1; i < length - 1; i++)
    {
        printf("%c", name[i]);
    }
    return 0;
}