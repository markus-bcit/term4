#include <stdio.h>
#include <string.h>

void printBigger(const char *one, const char *two)
{
    if (strlen(one) > strlen(two))
    {
        printf("%s", one);
        return;
    }
    printf("%s", two);
}

int main() {
    const char one[] = "This should be bigger than two";
    const char two[] = "This should be smaller";

    printBigger(one, two);
    return 0;
}
