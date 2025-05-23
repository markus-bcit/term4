#include <stdio.h>

int Reverser(int num)
{
    if (num == 0) return;
    printf("%d", num % 10);
    Reverser(num / 10);
}
int main()
{
    int num;
    scanf("%d", &num);
    Reverser(num);
    return 0;
}