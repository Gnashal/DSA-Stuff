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
    while (curr > 0 && data > bh->data[(curr - 1) / 2]) {
        parent = (curr - 1) / 2;
        bh->data[curr] = bh->data[parent];
        curr = parent;
    }
    bh->data[curr] = data;
    bh->count++;
    return true;
}
bool removeInHeap(BinaryHeap* bh) {
    int curr = bh->count;
    int lastInserted = bh->data[--(bh->count)];
    bh->data[0] = lastInserted;
    int index =  0;
    while (index < curr) {
        int left = (2*index) + 1, right = 2 * index + 2;
        int larger = index;


        if (larger < bh->count && bh->data[left] > bh->data[larger]) {
            larger = left;
        }
        if (larger < bh->count && bh->data[right] > bh->data[larger]) {
            larger = right;
        }
        if (larger == index) {
            break;
        }
        int temp = bh->data[index];
        bh->data[index] = bh->data[larger];
        bh->data[larger] = temp;

        index = larger;
    }
}
void display(BinaryHeap bh) {
    for (int i = 0; i < bh.count; ++i) {
        printf("%d", bh.data[i]);
        if (i < bh.count - 1) {
            printf(", ");
        }
    }
    printf("\n");
}


#endif