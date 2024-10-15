#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct 
{
    int* data;
    int max;
    int count;
} BinaryHeap;

BinaryHeap createHeap(int size) {
    BinaryHeap bh;
    bh.max = size;
    bh.data = (int*)malloc(sizeof(int) * bh.max);
    bh.count = 0;
    return bh;
}

bool insert(BinaryHeap* bh, int data) {
    int curr = bh->count,  parent;
    while (curr > 0 && data > bh->data[parent]) {
        parent = (curr - 1) / 2;
        bh->data[curr] = bh->data[parent];
        curr = parent;
    }
    bh->data[curr] = data;
    bh->count++;
    return true;
}
bool remove(BinaryHeap* bh) {

}
void display(BinaryHeap bh) {
    for (int i = 0; i < bh.count; ++i) {
        printf("%d ", bh.data[i]);
        if (i < bh.count - 1) {
            printf(", ");
        }
    }
}


#endif