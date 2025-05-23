
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        int random = rand() % 6;
        printf("%d ", random + 1);
    }
    return 0;
}
