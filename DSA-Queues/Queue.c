#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

Queue createQueue(int max) {
   Queue newQ;

    newQ.max = max;
    newQ.rear = 0;
    newQ.front = 1;
    newQ.data = malloc(sizeof(int) * newQ.max);

    return newQ;
}

bool isEmpty(Queue q) {
    return (q.rear + 1) % q.max == q.front;
}
bool isFull(Queue q) {
    return (q.rear + 2) % q.max == q.front;
}
bool enqueue(Queue *q, int data) {
    if (!isFull(*q)) {
        q->rear = (q->rear + 1) % q->max;
        q->data[q->rear] = data;
        return true;
    }
    return false;
}
bool dequeue(Queue *q) {
    if (!isEmpty(*q))
    {
        q->front = (q->front + 1) % q->max;
        return true;
    }
    return false;
}
int front(Queue *q) {
    return q->data[q->front];
}

void display (Queue *q) {
    if (isEmpty(*q)) {
        printf("Empty Queue");
        return;
    }

    int front = q->front;
    printf("{");
    while (1) {
        printf("%d", q->data[front]);
        if (front < q->max - 1) {
            printf(", ");
        } 
        if (front == q->rear) {
            break;
        }
        front = (front + 1) % q->max;
    }
    printf("}\n");
}   


