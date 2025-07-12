#include <stdio.h>

int main()
{
    const char filename[] = "salutation.txt";
    char content[1000] = "";

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 1;

    while (fgets(content, sizeof(content), fp) != NULL)
    {
        printf("%s", content);
    }

    fclose(fp);
    return 0;
}