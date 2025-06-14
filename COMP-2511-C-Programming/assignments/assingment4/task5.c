#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double average(double *source, size_t size)
{
    double sum = 0.0;
    for (int x = 0; x < size; x++)
    {
        sum += source[x];
    }
    return sum / size;
}

double depthAverage(double source[][6], size_t height, size_t width)
{
    double sum = 0.0;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            sum += source[x][y];
        }
    }
    return sum / (height * width);
}

double depthSmallest(double source[][6], size_t height, size_t width)
{
    double smallest = source[0][0];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            if (source[x][y] < smallest)
                smallest = source[x][y];
        }
    }
    return smallest;
}

void setup(double data[3][6])
{
    for (int x = 0; x < 3; x++)
    {
        printf("Enter six double numbers for set %d (in the form '1.1 1.2 ...' ): \n", x);
        char line[100];
        fgets(line, sizeof(line), stdin);
        char *token = strtok(line, " ");

        for (int y = 0; y < 6 && token != NULL; y++)
        {
            data[x][y] = atof(token);
            token = strtok(NULL, " ");
        }
    }
}

int main()
{
    double data[3][6] = {0.0};

    setup(data);

    double average1 = average(data[0], sizeof(data[0]) / sizeof(data[0][0]));
    double average2 = average(data[1], sizeof(data[0]) / sizeof(data[0][0]));
    double average3 = average(data[2], sizeof(data[0]) / sizeof(data[0][0]));
    printf("\nAverage of set 1: %f\n", average1);
    printf("Average of set 2: %f\n", average2);
    printf("Average of set 3: %f\n", average3);

    double average4 = depthAverage(data, sizeof(data) / sizeof(data[0]), sizeof(data[0]) / sizeof(data[0][0]));
    printf("Total Average: %f\n", average4);

    double smallest = depthSmallest(data, sizeof(data) / sizeof(data[0]), sizeof(data[0]) / sizeof(data[0][0]));
    printf("Smallest number: %f\n", smallest);

    return 0;
}