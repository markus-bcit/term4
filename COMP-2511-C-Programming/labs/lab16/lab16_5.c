#include <stdio.h>
#include <string.h>

typedef struct record record;
struct record{
    char name[20];
    int age;
}; 


int main()
{
    record records[3] = {0};
    const char filename[] = "out1.txt";
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL)
        return 1;
    fread(records, sizeof(record), 3, fp);
    records[0].age = 26;
    strcpy(records[2].name, "Kimmy");
    rewind(fp);
    fwrite(records, sizeof(record), 3, fp);
    fclose(fp);
    return 0;
}