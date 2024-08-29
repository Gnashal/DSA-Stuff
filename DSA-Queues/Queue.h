#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct  
{
    int* data;
    int max;
    int rear;
    int front;
} Queue;



Queue createQueue(int max);
bool isEmpty(Queue q);
bool isFull(Queue q);
bool enqueue(Queue *q, int data);
bool dequeue(Queue *q);
int front(Queue *q);


#endif
