#include <stdio.h>

int main()
{
    int data[3] = {11, 12, 13};
    int *p = data[0]; 
    *p + 1 = 60;
    printf("%d", p);
}