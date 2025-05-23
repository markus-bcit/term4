#include <stdio.h>

void divider(int first, int second)
{
    printf("%f", (double)first / second);
}

int main()
{
    int first;
    int second;
    scanf("%d %d", &first, &second);
    divider(first, second);
    return 0;
}