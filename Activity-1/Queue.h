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

Student dequeue (Queue *q) {
    NodePtr temp = NULL;
    Student value;
    value = q->head->data;
    if (!isEmpty(*q)) {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    if (!q->head) {
        q->tail = NULL;
    }
    return value;
}
Student front (Queue q) {
    return q.head->data;
}

Student next (Queue q) {
    return q.head->next->data;
}
void makeNull(Queue *q) {
    NodePtr temp = NULL;
    while(q->head != NULL && q->tail != NULL) {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
}

// Function to compare the "Stduent" struct with another
bool compareNames(Name name1, Name name2) {
    return strcmp(name1.fname, name2.fname) == 0 && strcmp(name1.lname, name2.lname) == 0;
}

bool compareStudents(Student s1, Student s2) {
    if (s1.studID != s2.studID) return false;
    if (!compareNames(s1.studName, s2.studName)) return false;
    if (s1.sex != s2.sex) return false;
    if (s1.program != s2.program) return false;
    return true;
}


bool compareNamesByValue(Name name1, Name name2) {  
    if (strcmp(name1.fname, name2.fname) == 0) {
        return strcmp(name1.lname, name2.lname) > 0;
    }
    return strcmp(name1.fname, name2.fname) > 0;
}

void display(Queue q) {
    printf("\n-------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-7s | %-6s | %-4s |\n", "First Name", "Last Name", "ID", "Sex", "Program");
    printf("-------------------------------------------------------------\n");
    while (!isEmpty(q) && q.head) {
        printf("| %-10s | %-10s | %-7d | %-6s | %-4s |\n", 
            q.head->data.studName.fname,
            q.head->data.studName.lname, 
            q.head->data.studID, 
            getSexString(q.head->data.sex), 
            getProgramString(q.head->data.program)
        );
       
       q.head = q.head->next;
    }
    printf("-------------------------------------------------------------\n");
}

int getQueueSize (Queue q) {
    int size = 0;
    while (!isEmpty(q) && q.head) {
        size++;
        q.head = q.head->next;
    }
    return size;
}

Name* getStudent (Queue q, char* program, char* sex) {
    int size = getQueueSize(q);
    Name temp[size + 1];
    int index = 0;
    while (!isEmpty(q) && q.head)
    {
        if (strcmp(getProgramString(q.head->data.program), program) == 0 && 
        strcmp(getSexString(q.head->data.sex), sex ) == 0) {
            strcpy(temp[index].fname, q.head->data.studName.fname);
            strcpy(temp[index].lname, q.head->data.studName.lname);
            index++;
        }

        q.head = q.head->next;
    }
    strcpy(temp[index].fname, "");
    strcpy(temp[index].lname, "");

    Name* names = malloc(sizeof(Name) * (index + 1));
    if (names) {
        memcpy(names, temp, sizeof(Name) * (index + 1));
    }
    return names;
}

void swap_now (NodePtr a, NodePtr b) {
    Student temp = a->data;
    a->data =b->data;
    b->data = temp;
}
  
void sort (Queue *q) {
    if (isEmpty(*q)) return;

    NodePtr last = NULL;
    NodePtr curr;
    bool isSwapped;

    do {
        isSwapped = false;
        curr = q->head;

        while (curr->next != last) {
            if (compareNamesByValue(curr->data.studName, curr->next->data.studName)) {
            swap_now(curr, curr->next);
            isSwapped = true;

            }
        curr = curr->next;
        }
        last = curr;

    } while (isSwapped);

}

bool insertSorted (Queue *q, Student data) {
  Queue tempQ = createQueue();

  while (!isEmpty(*q) && q->head->data.studID < data.studID) 
  {
    enqueue(&tempQ, dequeue(q));
  }
  enqueue(&tempQ, data);

  while(!isEmpty(tempQ)) {
    enqueue(q, dequeue(&tempQ)); 
  }
  return true;
  
}
#endif  