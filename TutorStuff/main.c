#include <stdio.h>
#include <stdlib.h>
void display(int *arr, int size)
{
    printf("{");
    for (int i = 0; i < size; ++i)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

void getReverse(int *source, int *destination, int source_size)
{
    int count = 0;
    for (int i = source_size - 1; i >= 0; --i)
    {
        destination[count] = source[i];
        count++;
    }
}

int main()
{
    // Declared an array and initialized values inside
    int arr[6] = {1, 3, 6, 34, 7, 8};
    display(arr, 6);
    // REVERSING ARRAY
    int reversedArr[6];
    getReverse(arr, reversedArr, 6);
    display(reversedArr, 6);
    // SORTING
    return 0;
}
