#include <stdio.h>
#include <math.h>

void printDifference(double first, double second)
{
    if (first > second) printf("%f", first - second);
    else if (first  == second) printf("0");
    else printf("%f", second - first);
}

int main()
{
    double first;
    double second;
    scanf("%lf %lf", &first, &second);
    printDifference(first, second);
    return 0;
}