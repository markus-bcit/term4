#include <stdio.h>

void reverse(int numbers[], size_t length)
{
    for (int x = 0; x < length / 2; x++) {
        int tmp = numbers[x];
        numbers[x] = numbers[length - x - 1];
        numbers[length - x - 1] = tmp;
    }
}

int main()
{
    int input[5] = {1, 2, 3, 4, 5};
    reverse(input, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", input[i]);
    }
    return 0;
}