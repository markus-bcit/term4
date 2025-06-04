#include <stdio.h>

int main() {
    int m = 11, n = 22;
    int *p = &m;  // p points to m
    int *q = &n;  // q points to n

    p = q;
    *p = *q + 1;  // m = 22 + 1 → m = 23
    *q = *p - 2;  // n = 23 - 2 → n = 21

    printf("%d %d", *p, *q); 
    return 0;
}