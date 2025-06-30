#include <stdio.h>

int main()
{
    int n = 7;
    printf("%d\n", n & 11);
    printf("%d\n", n | 0x1001);
    printf("%d", n ^ 0x1111);
    
    return 0;
}