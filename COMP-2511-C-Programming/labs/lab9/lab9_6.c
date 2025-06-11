#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[] = "123 456 789";
    int a;
    int b;
    int c;
    char s[100];
    sscanf(string, "%d%d%d", &a, &b, &c);
    sprintf(s, "The result is %d", a + b + c);
    printf("%s", s);
    return 0;
}