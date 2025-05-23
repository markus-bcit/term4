#include <stdio.h>
#include <math.h>

void logAndPrint(int first, int second)
{
    printf("%f", log10(first + second));
}

int main()
{
    int first;
    int second;
    scanf("%d %d", &first, &second);
    logAndPrint(first, second);
    return 0;
}