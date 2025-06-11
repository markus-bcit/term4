#include <stdio.h>

void my_concat( const char *a, const char *b, char* c)
{
    int lengthOfA = 0;
    int lengthOfB = 0;
    for (; a[lengthOfA]; lengthOfA++);
    for (; b[lengthOfB]; lengthOfB++);

    for (int x = 0; x < lengthOfA; x++)
    {
        c[x] = a[x];
    }
    for (int x = lengthOfA; x < lengthOfA + lengthOfB; x++)
    {
        c[x] = b[lengthOfB = x];
    }
}

int main()
{

    return 0;
}