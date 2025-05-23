#include <stdio.h>

int main()
{
    float pi = 3.14159;
    float radius;
    printf("Enter a radius: ");
    scanf("%f", &radius);
    printf("Diameter: %f\n", 2 * radius);
    printf("Circumference: %f\n", 2 * pi * radius);
    printf("Area: %f\n", pi * radius * radius);

    return 0;
}