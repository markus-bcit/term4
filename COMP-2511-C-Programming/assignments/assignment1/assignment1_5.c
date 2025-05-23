#include <stdio.h>

int main()
{
    int max = 0;

    for (int x = 0; x < 10; x++)
    {
        int input;
        printf("Enter a positive int: ");
        scanf("%d", &input);
        if (input < 0)
        {
            printf("Cannot be negative");
            return 0;
        }
        if (input > max) max = input;
    }
    printf("Max number is: %d", max);
}