#include <stdio.h>

enum Seasons
{
    None,
    SPRING,
    SUMMER,
    FALL,
    WINTER
};

enum Weekdays
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main()
{
    enum Weekdays wednesday = WEDNESDAY;
    enum Seasons fall = FALL;
    printf("%d\n", wednesday);
    printf("%d\n", fall);

    return 0;
}