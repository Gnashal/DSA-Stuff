#include "maxheap.h"

int main () {
    BinaryHeap heap = createHeap(21);
    for (int i = 0; i < 20; ++i) {
        insert(&heap, i + 1);
    }
    display(heap);
    removeInHeap(&heap);
    printf("After removing once: \n");
    display(heap);
    freeHeap(&heap);
    return 0;
}