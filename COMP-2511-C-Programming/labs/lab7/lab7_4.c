#include <stdio.h>

int main() {
    int data[] = {11, 12, 13};
    int *p = &data[0];

    *(p + 1) = 60;       
    printf("%d\n", *(p + 1));

    return 0;
}