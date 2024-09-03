#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "Student.h"

typedef struct node
{
    Student data;
    struct node* next;
} NodeType, *NodePtr;

typedef struct {
    NodePtr head;
    NodePtr tail;
} Queue;

Queue createQueue() {
    Queue newQ;

    newQ.head = NULL;
    newQ.tail = NULL;

    return newQ;
}

bool isEmpty(Queue q) {
    return (!q.head || !q.tail) ? true:false;
}



bool enqueue (Queue* q, Student s) {
    NodePtr newNode = malloc(sizeof(NodeType));
    newNode->data = s;
    newNode->next = NULL;
    if(isEmpty(*q)) {
        q->tail = newNode;
        q->head = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = q->tail->next;
    }

    return false;
}

bool dequeue (Queue *q) {
    NodePtr temp = NULL;
    if (!isEmpty(*q)) {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    return false;
}
Student front (Queue q) {
    return q.head->data;
}
void makeNull(Queue *q) {
    NodePtr temp = NULL;
    while(q->head != NULL && q->tail != NULL) {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
}

void display(Queue q) {
    printf("\n-------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-7s | %-6s | %-4s |\n", "First Name", "Last Name", "ID", "Sex", "Program");
    printf("-------------------------------------------------------------\n");
    while (!isEmpty(q)) {
        printf("| %-10s | %-10s | %-7d | %-6s | %-4s |\n", 
            q.head->data.studName.fname,
            q.head->data.studName.lname, 
            q.head->data.studID, 
            getSexString(q.head->data.sex), 
            getProgramString(q.head->data.program)
        );
        dequeue(&q);
    }
    printf("-------------------------------------------------------------\n");
}

#endif  