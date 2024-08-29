#ifndef QUEUE_H
#define QUEUE_H

typedef struct  
{
    int* data;
    int max;
    int rear;
    int front;
} Queue;

Queue createQueue(int max) {
    Queue newQ;

    newQ.max = max;
    newQ.rear = 0;
    newQ.front = 1;

    
}



#endif
