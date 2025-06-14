#include <stdio.h>
#include <string.h>

int main() {
    int array1[] = {1,2,3,4,5,6,7,8,9,0};
    int array2[10];

    memcpy(array2, array1, sizeof(array1));

    for (int x = 0; x < 10; x++) {
        printf("%d", array2[x]);
    }

    return 0;
}
