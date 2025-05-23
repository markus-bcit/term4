#include <stdio.h>

int main()
{
    int first;
    int second;
    int third;
    int forth;
    int fifth;
    printf("Enter five numbers: \n");
    scanf("%d %d %d %d %d", &first, &second, &third, &forth, &fifth);
    if (first > second && first > third && first > forth && first > fifth) printf("Largest: %d\n", first);
    if (second > first && second > third && second > forth && second > fifth) printf("Largest: %d\n", second);
    if (third > first && third > second && third > forth && third > fifth) printf("Largest: %d\n", third);
    if (forth > first && forth > second && forth > third && forth > fifth) printf("Largest: %d\n", forth);
    if (fifth > first && fifth > second && fifth > third && fifth > forth) printf("Largest: %d\n", fifth);

    if (first < second && first < third && first < forth && first < fifth) printf("Smallest: %d\n", first);
    if (second < first && second < third && second < forth && second < fifth) printf("Smallest: %d\n", second);
    if (third < first && third < second && third < forth && third < fifth) printf("Smallest: %d\n", third);
    if (forth < first && forth < second && forth < third && forth < fifth) printf("Smallest: %d\n", forth);
    if (fifth < first && fifth < second && fifth < third && fifth < forth) printf("Smallest: %d\n", fifth);
    return 0;
}