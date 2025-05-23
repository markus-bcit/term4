#include <stdio.h>

int main()
{
    int first;
    int second;
    int thrid;
    printf("Enter 3 nonzero ints in terms c, a, b: ");
    scanf("%d %d %d", &first, &second, & thrid);
    if (((first < 0) || (second < 0) || (thrid < 0) || (first == 0) || (second == 0) || (thrid == 0))) 
    {
        printf("Must be nonzero");
        return 0;
    }

    if (first * first == second * second + thrid * thrid) printf("Success, this is a right triangle");
    else printf("Is not a right triangle");
    return 0;
}