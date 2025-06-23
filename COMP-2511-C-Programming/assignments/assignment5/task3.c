#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000];
    char *tokens[1000];
    int count = 0;

    printf("Enter one line of text:\n");
    fgets(text, sizeof(text), stdin);

    size_t len = strlen(text);
    text[len - 1] = '\0';

    char *token = strtok(text, " ");
    while (token != NULL && count < 100)
    {
        tokens[count] = token;
        token = strtok(NULL, " ");
        count++;
    }

    for (int x = count - 1; x >= 0; x--)
    {
        printf("%s ", tokens[x]);
    }

    return 0;
}
