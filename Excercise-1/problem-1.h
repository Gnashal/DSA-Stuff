#ifndef PROBLEM_1_H
#define PROBLEM_1_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    char fname[30];
    char lname[30];
} Name;

typedef struct {
    Name* elems;
    int max;
    int front;
    int rear;
} NQueue;

Name createName(char* fname, char* lname) {
  Name newName;
  strcpy(newName.fname, fname);
  strcpy(newName.lname,lname);

  return newName;
} 

void initNQueue(NQueue *nq, int max) {
  nq->max = max;
  nq->front = 0;
  nq->rear = -1;
  nq->elems = (Name*)malloc(sizeof(Name) * max);
}
bool isEmpty(NQueue nq) {
  return (nq.rear + 1) % nq.max == nq.front;
}
bool isFull(NQueue nq) {
  return (nq.rear + 2) % nq.max == nq.front;
}
void displayQueue(NQueue nq) {
  if (isEmpty(nq)) {
    printf("Queue is empty\n");
    return;
  }

  int front = nq.front;
    printf("||   %-10s  ||%-10s     ||\n", "First Name", "Last Name");
    printf("||--------------------------------||\n");
  while (1) {
    printf("||   %-10s  || %-10s    ||\n", nq.elems[front].fname, nq.elems[front].lname);
    if (front == nq.rear) {
      break;
    }
    front= (front + 1) % nq.max;
  }
}

bool enqueue(NQueue *nq, Name n) {
    if (isFull(*nq)) {
        return false;  
    }
    nq->rear = (nq->rear + 1) % nq->max;  
    nq->elems[nq->rear] = n;

    return true;
}
bool dequeue(NQueue *nq) {
    if (isEmpty(*nq)) {
        return false; 
    }

    if (nq->rear == nq->front) {  
        nq->front = 0;
        nq->rear = -1;  
    } else {
        nq->front = (nq->front + 1) % nq->max;  
    }

    return true;
}
Name front(NQueue nq) {
  return nq.elems[nq.front];
}

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString) {
  int queueSize = (nq->rear >= nq->front) ? (nq->rear - nq->front + 1) : (nq->max - nq->front + nq->rear + 1);
   Name* names = malloc(sizeof(Name) * (queueSize + 1));
  int size = 0;
  int front_curr = nq->front;
  while (1) {
    if (strcmp(nq->elems[front_curr].lname, filterString) == 0) {
    names[size++] = nq->elems[front_curr];
      dequeue(nq);
    }

    if (front_curr == nq->rear) {
      break;
    }

    front_curr = (front_curr + 1) % nq->max;
  }

  strcpy(names[size].fname, "");
  strcpy(names[size].lname, "");

  return names;

}

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n);

#endif