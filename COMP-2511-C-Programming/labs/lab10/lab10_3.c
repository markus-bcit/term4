#include <stdio.h>
#include <string.h>

int main()
{
    const char *string = "apple-pineapple";
    char character = 'a';

    printf("%d", strchr(string, character));

    return 0;
}