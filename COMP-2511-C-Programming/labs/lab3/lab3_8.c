#include <stdio.h>
#include <math.h>

void compareAndPrint(double first, double second)
{
    if (fabs(first) >= fabs(second)) printf("%f", first);
    else printf("%f", second);
}

int main()
{
    double first;
    double second;
    scanf("%lf %lf", &first, &second);
    compareAndPrint(first, second);
    return 0;
}