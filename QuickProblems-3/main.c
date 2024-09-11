#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main () {
    int size  = 10;
    int *arr = createArray(size);

    for (int i = 0; i < size; ++i) {
        arr[i] = i + rand() % 100;
    }
    display(arr, size);
    int min, max;
    max = findMax(arr, size);
    min = findMin(arr, size);

    printf("THE MAX NUMBER IS: %d\n", max);
    printf("THE MIN NUMBER IS: %d\n\n", min);

    int avg = calcAvg(arr, size);
    printf("THE AVERAGE IS: %d\n", avg);

    reverseArray(arr, size);
    display(arr, size);

    int search = 57;
    if (searchForElems(arr, size, search)) {
        printf("THE SEARCHED FOR ELEMENT %d is found!\n", search);
    } else {
        printf("THE SEARCHED FOR ELEMENT %d is not found!\n", search);
    }

    return 0;
}