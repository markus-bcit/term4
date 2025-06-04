#include <stdio.h>

int main()
{
    // -------------- //
    // printf("%c", f[6]);
    // -------------- //
    // b[4] = 1.0;
    // -------------- //
    // int g[5] = {8, 8, 8, 8, 8};
    // -------------- //
    float c[100];

    float sum = 0.0;
    for (int x = 0; x < 100; x++)
    {
        sum += c[x];
    }
    // -------------- //
    double a[11];
    double b[34];
    for (int x = 0; x < 11; x++)
        b[x] = a[x];
    // -------------- //
    float w[99];

    float min = w[0];
    float max = w[0];
    for (int x = 0; x < 99; x++)
    {
        if (w[x] < min) min = w[x];
        if (w[x] > max) max = w[x];
    }
    return 0;
}