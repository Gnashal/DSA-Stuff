#ifndef HASH_H
#define HASH_H
#define MAX 20
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



typedef struct 
{
    int studID;
    char studName[20];
    char program[20];
} Student;
typedef struct node{
    Student stud;
    struct node * next;
} Node, *NodePtr;

typedef struct 
{
    NodePtr elems[MAX];
    int count;
} HashTable;

Student createStudents(char* program, char* name, int id) {
    Student newStud;
    strcpy(newStud.program, program);
    strcpy(newStud.studName, name);
    newStud.studID = id;
    return newStud;
}

bool isEmpty(HashTable ht, int pos) {
    return ht.elems[pos] == NULL;
}

void initHashTable(HashTable *hash) {
    hash->count = 0;
    for (int i = 0; i < MAX; ++i) {
        hash->elems[i] = NULL;
    }
}

int getHash(Student s) {
    // TODO: Get the hash based on the summation of the first 3 letters of the name plus the letters in the program and must be able to return a value from 0 - 19.
    int i = 0;
    int j = 0;
    int pos = 0;
    for (; j < strlen(s.program);++j) {
        if (i < 3) {
            pos += s.studName[i];
            ++i;
        }
        pos += s.program[j];
    }

    return pos % MAX;
}
bool insert(HashTable * ht, Student s) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->stud = s;
    NodePtr holder = NULL;
    int pos = getHash(s);

      if (ht->elems[pos] == NULL || ht->elems[pos]->stud.studID > s.studID) {
        newNode->next = ht->elems[pos];
        ht->elems[pos] = newNode;
        return true;
    }

    NodePtr curr = ht->elems[pos];
    // NodePtr prev = NULL;
    while (curr->next != NULL && curr->stud.studID < s.studID) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;

    return true;
}

// bool insertSorted(NodePtr* head, Student s) {
//     NodePtr newNode = (NodePtr)malloc(sizeof(Node));
//     newNode->next = NULL;
//     newNode->stud = s;
//     NodePtr holder = NULL;

//       if (*head == NULL || (*head)->stud.studID > s.studID) {
//         newNode->next = *head;
//         *head = newNode;
//         return true;
//     }
//     NodePtr curr = *head;
//     // NodePtr prev = NULL;
//     while (curr->next != NULL && curr->stud.studID < s.studID) {
//         curr = curr->next;
//     }
//     newNode->next = curr->next;
//     curr->next = newNode;

//     return true;
// }   

// bool deleteHash(HashTable *ht, Student s) {

// }

void visualize(HashTable ht) {
    for (int i = 0; i < MAX; ++i) {
        if (ht.elems[i] != NULL) {
            while (ht.elems[i] != NULL) {
            printf("%d--[%d]--%15s--%15s\n", i, ht.elems[i]->stud.studID, ht.elems[i]->stud.studName, ht.elems[i]->stud.program);
            ht.elems[i] = ht.elems[i]->next;
            }
        } else {
            printf("%d--%s\n", i, "NULL");
        }
    }
}



#endif
