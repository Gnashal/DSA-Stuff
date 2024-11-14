#include "maxheap.h"

int main()
{
    BinaryHeap heap = createHeap(21);
    for (int i = 0; i < 20; ++i)
    {
        insert(&heap, rand() * i % 100);
    }
    display(heap);
    printf("After removing: \n");
    for (int i = 0; i < 20; ++i)
    {
        removeInHeap(&heap);
        display(heap);
    }
    printf("Testing heapify max: \n");
    int arr[10] = {1, 56, 69, 40, 12, 422, 23, 2, 90, 71};
    displayArray(arr, 10);
    build_max_heap(arr, 10);
    displayArray(arr, 10);

    printf("Testing finding nth largest number in unsorted array: \n");
    int arr2[10] = {1, 56, 69, 40, 12, 422, 23, 2, 90, 71};
    displayArray(arr2, 10);
    int elem = findNthLargestElement(arr, 10, 4);
    printf("%d\n", elem);
    printf("Testing a specific condition: \n");
    int arr3[10] = {1, 2, 23, 40, 12, 422, 69, 56, 90, 71};
    for (int i = 0; i < 10; ++i)
    {
        insert(&heap, arr3[i]);
        display(heap);
    }
    printf("Testing the removal: \n");
    for (int i = 1; i < 10; ++i)
    {
        removeInHeap(&heap);
        display(heap);
    }
    freeHeap(&heap);
    return 0;
}