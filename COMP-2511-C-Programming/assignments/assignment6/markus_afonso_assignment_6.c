#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record record;
struct record
{
    char id[10];
    int score;
};

int GetCommand(char character[])
{
    if ((character[0] == '0') && (character[1] == '\0'))
        return 0;
    if (atoi(character) == 0)
        return -5;
    return atoi(character);
}

int isValidCommand(char character[])
{
    if (GetCommand(character) <= -5)
        return 0;
    return 1;
}

int IsLength(char *array, int target)
{
    int count = 0;
    for (int x = 0; array[x] != '\0'; x++)
    {
        if (array[x] != '\0')
            count++;
    }
    return count == target ? 1 : 0;
}

int IsAllNumbers(char *array, int SkipFirst)
{
    for (int x = SkipFirst ? 1 : 0; array[x] != '\0'; x++)
    {
        if ((array[x] < '0') || (array[x] > '9'))
            return 0;
    }
    return 1;
}

int IsStartingWithA(char *array)
{
    if ((array[0] != 'A') && array[0] != 'a')
        return 0;
    return 1;
}

int IsValidStudentId(char *id)
{
    if (!IsStartingWithA(id))
        return 0;
    if (!IsAllNumbers(id, 1))
        return 0;
    if (!IsLength(id, 9))
        return 0;
    return 1;
}
int IsValidScore(char *score)
{
    if (IsAllNumbers(score, 0))
    {
        int intScore = atoi(score);
        if (intScore >= 0 && intScore <= 100)
            return 1;
    }
    return 0;
}
int GetInput(char *input, char prompt[], int (*check)(char *), int NegativeOneCheck)
{
    do
    {
        fprintf(stdout, prompt);
        if (scanf("%s", input) != 1)
        {
            return 1;
        }
        while (getchar() != '\n')
            ;

        if (NegativeOneCheck && (strcmp(input, "-1") == 0))
            return 1;
    } while (!check(input));
    return 0;
}

void CreateRecord(record *records)
{
    char studentNumber[10];
    char score[4];

    if (GetInput(studentNumber, "Enter a valid student number: ", IsValidStudentId, 1))
        return;
    if (GetInput(score, "Enter a valid score: ", IsValidScore, 1))
        return;

    int intScore = atoi(score);

    for (int x = 0; x < 1000; x++)
    {
        if (records[x].id[0] == '\0')
        {
            strcpy(records[x].id, studentNumber);
            records[x].score = intScore;
            break;
        }
    }
}
int RecordCount(record *records)
{
    int count = 0;
    for (; records[count].id[0] != '\0';)
        count++;
    return count;
}
void UpdateRecord(record *records, int recordIndex)
{
    int index = recordIndex - 1;

    if (index < 0 || records[index].id[0] == '\0')
        return;

    char studentNumber[10];
    char score[4];

    fprintf(stderr, "%d %s %d\n", recordIndex, records[index].id, records[index].score);

    if (GetInput(studentNumber, "Enter a valid student number: ", IsValidStudentId, 1))
        return;
    if (GetInput(score, "Enter a valid score: ", IsValidScore, 1))
        return;

    int intScore = atoi(score);
    strcpy(records[index].id, studentNumber);
    records[index].score = intScore;
}
int sortScore(const void *a, const void *b)
{
    const record *p = (const record *)a;
    const record *q = (const record *)b;
    return q->score - p->score;
}

int sortId(const void *a, const void *b)
{
    const record *p = (const record *)a;
    const record *q = (const record *)b;
    return strcmp(p->id, q->id);
}

void PrintRecords(record *records, int (*sortFunc)(const void *, const void *), const size_t size)
{
    int count = RecordCount(records);

    if (sortFunc == NULL)
    {
        for (int x = 0; x < count; x++)
        {
            fprintf(stderr, "%d %s %d\n", x + 1, records[x].id, records[x].score);
        }
    }
    else
    {
        record copy[count];
        memcpy(copy, records, count * sizeof(record));

        qsort(copy, count, sizeof(record), sortFunc);

        for (int x = 0; x < count; x++)
        {
            fprintf(stderr, "%d %s %d\n", x + 1, copy[x].id, copy[x].score);
        }
    }
}
int main()
{
    char command[10] = "";
    record records[1000] = {0};

    do
    {
        GetInput(command, "Enter a command: ", isValidCommand, 0);
        int intCommand = GetCommand(command);

        if (intCommand > 0)
            UpdateRecord(records, intCommand);

        if (intCommand == 0)
            PrintRecords(records, NULL, RecordCount(records));

        if (intCommand == -1)
            CreateRecord(records);

        if (intCommand == -2)
            PrintRecords(records, sortId, RecordCount(records));

        if (intCommand == -3)
            PrintRecords(records, sortScore, RecordCount(records));

        if (intCommand == -4)
            return 0;

    } while (1);

    return 0;
}