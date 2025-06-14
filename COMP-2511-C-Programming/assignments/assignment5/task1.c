#include <stdio.h>
#include <string.h>

void shiftFirst(char *array, size_t length)
{
    for (int i = 0; array[i] != '\0'; i++) {
        array[i] = array[i + 1];
    }
}

void leadingSpaces(char *array, size_t length)
{

    if (array[0] == ' ')
    {
        shiftFirst(array, length);
        leadingSpaces(array, length);
    }
}

void lowerCase(char *array, size_t length)
{
    for (int x = 0; array[x] != '\0'; x++)
    {
        if ((array[x] >= 'A') && (array[x] <= 'Z'))
        {
            array[x] = array[x] + ('a' - 'A');
        }
    }
}

void UpperCase(char *array, size_t length)
{
    for (int x = 0; array[x] != '\0'; x++)
    {
        if ((array[x] >= 'a') && (array[x] <= 'z'))
        {
            array[x] = array[x] - ('a' - 'A');
        }
    }
}

int main()
{
    char text[100] = "";
    printf("Enter one line of text:\n");
    fgets(text, sizeof(text), stdin);
    size_t len = strlen(text);
    text[len - 1] = '\0';
    leadingSpaces(text, strlen(text));
    lowerCase(text, strlen(text));
    printf("%s\n", text);
    UpperCase(text, strlen(text));
    printf("%s", text);
    return 0;
}