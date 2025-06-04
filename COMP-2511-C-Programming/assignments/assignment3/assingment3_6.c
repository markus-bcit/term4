#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int diceRoll()
{
    return rand() % 6 + 1;
}

int diceRoller(int times)
{
    int sum = 0;
    for (int x = 0; x < times; x++)
    {
        sum += diceRoll();
    }
    return sum;
}

int main()
{
    srand(time(NULL));

    int tally[12] = {0};

    for (int x = 0; x < 36000; x++)
    {
        int hand = diceRoller(2);
        tally[hand - 2]++;
    }
    printf("Sum     |  Percentage of 36000 rolls\n");
    for (int y = 0; y < 11; y++)
    {
        printf("%d: %d      %f\n", y + 2, tally[y], ((float)tally[y] / 36000.0) * 100);
    }
    return 0;
}