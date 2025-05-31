#include <stdio.h>

void nonStart(char first[], char second[])
{
    int firstLength = 0;
    while (first[firstLength] != '\0') firstLength++;

    int secondLength = 0;
    while (first[secondLength] != '\0') secondLength++;

    for (int x = 1; x < firstLength; x ++)
    {
        printf("%c", first[x]);
    }
    for (int y = 1; y < secondLength; y ++)
    {
        printf("%c", second[y]);
    }
}

int main()
{
    char wordOne[100] = "";
    char wordTwo[100] = "";
    scanf("%s", wordOne);
    scanf("%s", wordTwo);
    nonStart(wordOne, wordTwo);
    return 0;
}