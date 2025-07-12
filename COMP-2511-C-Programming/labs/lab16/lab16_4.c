#include <stdio.h>

typedef struct record record;
struct record{
    char name[20];
    int age;
}; 


int main()
{
    record records[3] = {{"Sam", 25}, {"Tom", 30}, {"Kim", 16}};
    const char filename[] = "out1.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
        return 1;
    fwrite(records, sizeof(record), 3, fp);
    fclose(fp);
    return 0;
}