#include <stdio.h>

void printSquare(int side) {
    for (int x = 0; x < side; x++) {     
        for (int y = 0; y < side; y++) { 
            printf("* ");
        }
        printf("\n"); 
    }
}

int main() {
    int side;
    printf("Enter the length of the square: ");
    scanf("%d", &side);
    printSquare(side);
    return 0;
}