#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

Queue createQueue(int max) {
   Queue newQ;

    newQ.max = max;
    newQ.rear = 0;
    newQ.front = 1;

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
        q->front = (q->front + 2) % q->max;
        
    }
    
}
int front(Queue *q);


