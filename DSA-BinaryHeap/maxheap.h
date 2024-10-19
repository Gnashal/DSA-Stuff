#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct
{
    int *data;
    int max;
    int count;
} BinaryHeap;

BinaryHeap createHeap(int size)
{
    BinaryHeap bh;
    bh.max = size;
    bh.data = (int *)malloc(sizeof(int) * bh.max);
    bh.count = 0;
    return bh;
}

bool insert(BinaryHeap *bh, int data)
{
    if (bh->count >= bh->max)
        return false;
    int curr = bh->count, parent;
    while (curr > 0 && data > bh->data[(curr - 1) / 2])
    {
        parent = (curr - 1) / 2;
        bh->data[curr] = bh->data[parent];
        curr = parent;
    }
    bh->data[curr] = data;
    bh->count++;
    return true;
}
bool removeInHeap(BinaryHeap *bh)
{
    if (bh->count == 0)
        return false;
    --(bh->count);
    int index = 0;
    int larger = index;
    while (index < bh->count)
    {
        int left = (2 * index) + 1;
        if (left > bh->count || left + 1 > bh->count)
        {
            break;
        }
        larger = (bh->data[left] > bh->data[left + 1]) ? left : left + 1;
        bh->data[index] = bh->data[larger];
        index = larger;
    }
    bh->data[index] = bh->data[bh->count];
    return true;
}
void display(BinaryHeap bh)
{
    printf("{");
    for (int i = 0; i < bh.count; ++i)
    {
        printf("%d", bh.data[i]);
        if (i < bh.count - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}
void displayArray(int *arr, int size)
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
bool heapify_max(int *arr, int size, int index)
{
    int left, larger;
    int root = arr[index];
    while (true)
    {
        left = (index * 2) + 1;
        if (left >= size)
        {
            break;
        }
        if (left + 1 < size && arr[left + 1] > arr[left])
        {
            larger = left + 1;
        }
        else
        {
            larger = left;
        }
        if (root >= arr[larger])
        {
            break;
        }
        arr[index] = arr[larger];
        index = larger;
    }
    arr[index] = root;
    return true;
}
bool build_max_heap(int *arr, int size)
{
    for (int i = (size / 2) - 1; i >= 0; --i)
    {
        heapify_max(arr, size, i);
    }
}
void freeHeap(BinaryHeap *bh)
{
    free(bh->data);
    bh->data = NULL;
    bh->count = 0;
    bh->max = 0;
}

#endif