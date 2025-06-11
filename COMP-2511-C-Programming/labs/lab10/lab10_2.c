#include <stdio.h>
#include <string.h>

int main()
{
    

    printf("Az vs. aZ: %d\n", strcmp("Az", "aZ"));
    printf("ABCDEF vs. a: %d\n", strcmp("ABCDEF", "a"));
    printf("sushi-roll vs. unagi: %d\n", strcmp("sushi-roll", "unagi"));

    return 0;
}