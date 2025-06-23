#include <stdio.h>

int IsLength(char *array, int target)
{
    int count = 0;
    for (int x = 0; array[x] != '\0'; x++)
    {
        if (array[x] != '\0')
            count++;
    }

    return count == target ? 0 : 1;
}

int IsAllNumbers(char *array)
{
    for (int x = 1; array[x] != '\0'; x++)
    {
        if ((array[x] < '0') || (array[x] > '9'))
            return 1;
    }

    return 0;
}

int IsStartingWithA(char *array)
{
    if ((array[0] != 'A') && array[0] != 'a') return 1;
    return 0;
}

int main()
{
    char input[11] = "";
    int error;
    const char valid[] = "valid";
    const char invalid[] = "invalid";

    scanf("%s", input);

    int size = IsLength(input, 9);
    int digits = IsAllNumbers(input);
    int first = IsStartingWithA(input);

    if (first)
    {
        printf("%s", invalid);
        return 0;
    }
    if (size)
    {
        printf("%s", invalid);
        return 0;
    }
    if (digits)
    {
        printf("%s", invalid);
        return 0;
    }
    printf("%s", valid);
    return 0;
}