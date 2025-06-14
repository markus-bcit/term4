#include <stdio.h>

void addtwo(int  *array1, int *array2, int *array3, size_t size)
{
    for (int x = 0; x < size; x++)
    {
        array3[x] = array1[x] + array2[x]; 
    }
}

int main()
{
    int array1[] = {1,2,3,4,5};
    int array2[] = {1,2,3,4,5};
    int array3[5];
    addtwo(array1, array2, array3, 5);
    for (int x = 0; x < 5; x++)
    {
        printf("%d\n", array3[x]);
    }
    return 0; 
}