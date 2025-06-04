#include <stdio.h>

int main() {
    char data[100] = "";
    scanf("%s", data);
    data[2] = '?';
    printf("%s", data);

    return 0;
}