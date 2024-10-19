#include "maxheap.h"

int main()
{
    BinaryHeap heap = createHeap(21);
    for (int i = 0; i < 20; ++i)
    {
        insert(&heap, i + 1);
    }
    display(heap);
    removeInHeap(&heap);
    printf("After removing once: \n");
    display(heap);

    printf("Testing heapify_max: \n");
    int arr[10] = {1, 56, 69, 40, 12, 422, 23, 2, 90, 71};
    displayArray(arr, 10);
    build_max_heap(arr, 10);
    displayArray(arr, 10);

    freeHeap(&heap);
    return 0;
}