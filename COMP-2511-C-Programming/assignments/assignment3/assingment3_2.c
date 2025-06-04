#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coinFlip()
{
    return rand() % 2;
}

int main()
{
    srand(time(NULL));

    int heads = 0;
    int tails = 0;

    for (int x = 0; x < 100; x++)
    {
        if (coinFlip()) heads++;
        else tails++;
    }

    printf("Heads: %d\nTails: %d", heads, tails);
    return 0;
}