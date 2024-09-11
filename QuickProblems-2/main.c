#include <stdio.h>
#include <stdlib.h>


int getMax(int x, int y);
int findMax(int *, int size);
int main () {
    int arr[10];

    for (int i = 0; i < 10; ++i) {
        arr[i] = i + rand() % 1000;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d", arr[i]);
        if (i < 9) {
            printf(", ");
        }
    }
    printf("\n");

    int max = findMax(arr, 10);

    printf("%d\n", max);
    return 0;
}
int getMax(int x, int y) {
    return (x > y) ? x:y;
}
int findMax(int *arr, int size) {
    int max = 0;
    for (int i = 0; i < size; ++i) {
        max = getMax(max, arr[i]);
    }
    return max;
}