#include <stdio.h>

int main()
{
    int *ptr = malloc(10);
    ptr = realloc(ptr, 20);
    free(ptr);
    ptr = NULL;
    return 0;
}