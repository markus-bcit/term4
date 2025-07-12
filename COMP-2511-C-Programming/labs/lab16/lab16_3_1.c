#include <stdio.h>

int main()
{
    const char filename[] = "salutation.txt";
    char content[100] = "";
    fgets(content, 100, stdin);
    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
        return 1;
    fprintf(fp, "%s", content);
    fclose(fp);
    return 0;
}