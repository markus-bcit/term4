#include <stdio.h>

void my_concat(const char *a, const char *b, char* c)
{
    int lengthOfA = 0;
    int lengthOfB = 0;
    for (; a[lengthOfA]; lengthOfA++);
    for (; b[lengthOfB]; lengthOfB++);
    
    for (int x = 0; x < lengthOfA; x++)
        c[x] = a[x];
    
    for (int x = 0; x < lengthOfB; x++)
        c[lengthOfA + x] = b[x];
    
    c[lengthOfA + lengthOfB] = '\0'; 
}

int main()
{
    char a[100] = "sentence 1";
    char b[100] = "SENTENCE 2";
    char c[100] = "";
    my_concat(a, b, c);
    printf("%s", c);
    return 0;
}