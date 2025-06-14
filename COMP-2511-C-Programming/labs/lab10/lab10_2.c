#include <stdio.h>
#include <string.h>

int main()
{
    printf("Az vs. aZ: %s\n", strcmp("Az", "aZ") > 0 ? "Az" : "aZ");
    printf("ABCDEF vs. a: %s\n", strcmp("ABCDEF", "a") > 0 ? "ABCDEF" : "a");
    printf("sushi-roll vs. unagi: %s\n", strcmp("sushi-roll", "unagi") > 0 ? "sushi-roll" : "unagi");
    return 0;
}