#include <stdio.h>

int triangle(int rows) {
    if (rows <= 0) {
        return 0;
    } else {
        return rows + triangle(rows - 1);
    }
}

int main() {
    int rows;
    printf("Rows: ");
    scanf("%d", &rows);
    printf("Blocks: %d\n", triangle(rows));
    return 0;
}