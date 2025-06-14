#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "apple-pineapple";
    const char *first = strchr(str, 'a');

    if (first) {
        const char *second = strchr(first + 1, 'a');
        if (second) {
            int index = second - str;
            printf("yes\n");
            printf("Index of second 'a': %d", index);
        } else {
            printf("no\n");
        }
    } else {
        printf("no\n");
    }

    return 0;
}