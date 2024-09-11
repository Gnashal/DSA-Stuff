#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string.h>
#include <stdbool.h>

int* createArray(int size) {
    int* newArr = malloc(sizeof(int) * size);
    return newArr;
}

int findMax(int* arr, int size) {
    int max = 0;
    for (int i = 0;  i < size; ++i) {
        max = (max > arr[i]) ? max:arr[i];
    }

    return max;
}

int findMin(int* arr, int size) {
    int min = arr[0];
    for (int i = 1;  i < size; ++i) {
        min = (min < arr[i]) ? min:arr[i];
    }

    return min;
}

int calcAvg(int* arr, int size) {
    int avg = 0;
    int count = 0, sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
        count++;
    }
    avg = sum / count;


    return avg;
}

void reverseArray(int* arr, int size) {
    int temp[size];
    int index = 0;
    for (int i = size - 1; i >= 0; --i) {
        temp[index++] = arr[i];
    }   
    memcpy(arr, temp, sizeof(int) * size);
    // destination, source, size by raw bytes
}




bool searchForElems(int* arr, int size, int elems) {
    int i;
    for (i = 0; i < size; ++i) {
       if (arr[i] == elems) {
            return true;
       } 
    }
    return false;
}

void display(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("\n\n");
}

#endif