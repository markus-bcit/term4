#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    int random = rand() % 6;
    printf("%d", random + 4);
    return 0;
}