#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addToFinalArr(int *finalArr, int *count, int size, int data)
{
    if (*count >= size)
    {
        return;
    }
    int curr = *count, parent;

    while (curr > 0 && data < finalArr[(curr - 1) / 2])
    {
        parent = (curr - 1) / 2;
        finalArr[curr] = finalArr[parent];
        curr = parent;
    }
    finalArr[curr] = data;
    (*count)++;
}

int dequeue(int *arr, int *size)
{
    int last = arr[*size - 1];
    --(*size);
    int index = 0;
    int dequeuedVal = arr[0];
    int lesser = index;
    while (index < *size)
    {
        int left = (2 * index) + 1;
        if (left >= *size)
        {
            break;
        }

        if (left + 1 < *size && arr[left + 1] < arr[left])
        {
            lesser = left + 1;
        }
        else
        {
            lesser = left;
        }
        if (last <= arr[lesser])
        {
            break;
        }
        arr[index] = arr[lesser];
        index = lesser;
    }
    arr[index] = last;
    return dequeuedVal;
}

int main()
{
    int n, totalSize = 0;
    printf("Enter the number of sorted arrays: ");
    scanf("%d", &n);
    int **arrays = (int **)malloc(sizeof(int *) * n);
    int *arraySizes = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        printf("Enter the size for sorted array %d: ", i + 1);
        scanf("%d", &arraySizes[i]);

        arrays[i] = (int *)malloc(sizeof(int) * arraySizes[i]);
        printf("Enter the elemens of sorted array %d: ", i + 1);
        for (int j = 0; j < arraySizes[i]; ++j)
        {
            scanf("%d", &arrays[i][j]);
        }
        totalSize += arraySizes[i];
    }
    int sizeF = totalSize;
    int totalCount = 0;
    int *finalArr = (int *)malloc(sizeof(int) * totalSize);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < arraySizes[i]; ++j)
        {
            addToFinalArr(finalArr, &totalCount, totalSize, arrays[i][j]);
        }
    }

    int *mergedArr = malloc(sizeof(int) * totalSize);
    for (int i = 0; i < totalSize; ++i)
    {
        mergedArr[i] = dequeue(finalArr, &sizeF);
    }
    printf("The merged sorted array is: ");
    for (int i = 0; i < totalSize; ++i)
    {
        printf("%d", mergedArr[i]);
        if (i < totalSize - 1)
        {
            printf(", ");
        }
    }
    printf("\n");

    for (int i = 0; i < n; ++i)
    {
        free(arrays[i]);
    }
    free(arrays);
    free(arraySizes);
    free(finalArr);
    free(mergedArr);

    return 0;
}