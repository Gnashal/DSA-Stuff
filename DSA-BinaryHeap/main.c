#include "maxheap.h"

int main () {
    BinaryHeap heap = createHeap(20);
    for (int i = 0; i < 20; ++i) {
        insert(&heap, i + 1);
    }
    display(heap);
    free(heap.data);
    return 0;
}