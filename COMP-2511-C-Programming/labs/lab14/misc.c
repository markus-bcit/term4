#include <stdio.h>

struct card
{
    char *face;
    char *suit;
};

struct card aCard;

int main()
{
    struct card deck[10];

    printf("%c\n", *((*deck).face));

    printf("%c\n", *(deck[3].face));

    printf("%c\n", *(deck->face));

    printf("%c\n", *(*(deck + 3).face));
}