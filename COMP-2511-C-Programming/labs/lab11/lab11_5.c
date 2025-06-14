#include <stdio.h>

int main()
{
    int a;
    int b;
    float c;
    scanf("%d %x %f", &a, &b, &c);
    printf("%#o,%#o,%#o\n", a, b, (int)c);
    printf("%#x,%#x,%#x\n", a, b, (int)c);
    printf("%.2f,%.2f,%.2f\n", a * 1.0, b* 1.0, c* 1.0);

    return 0;
}