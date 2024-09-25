#ifndef HASH_H
#define HASH_H

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int studID;
    char studName[20];
    char program[20];
} Student;
 typedef enum {
    EMPTY, DELETED, OCCUPIED
} Flag;
typedef struct {
    Student data;
    Flag flag;
}Data;

typedef struct {
    Data* elems;
    int max;
    int count;
}HashTable;

bool isEmpty(HashTable ht, int pos) {
    return ht.elems[pos].flag == EMPTY;
}
bool isFull(HashTable ht, int pos) {
    while(!isEmpty(ht, pos)) {
        if (ht.elems[pos].flag == EMPTY || ht.elems[pos].flag == DELETED ) {
            return false;
        }
        pos++;
    }
}
Student createStudents(char* program, char* name, int id) {
    Student newStud;
    strcpy(newStud.program, program);
    strcpy(newStud.studName, name);
    newStud.studID = id;
    return newStud;
}

HashTable createHashTable(int max) {
    HashTable newHashTable;
    newHashTable.max = max;
    newHashTable.count = 0;
    newHashTable.elems = (Data*)calloc(sizeof(Data) , newHashTable.max);
    for (int i = 0; i < newHashTable.max; ++i) {
        newHashTable.elems[i].flag = EMPTY;
    }
    return newHashTable;
}


int getHash(Student s, int max) {
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

    return pos % max;
}

bool insert (HashTable *ht, Student s) {
    if (ht->count >= ht->max * 0.80) {
        return false;
    }
    int pos = getHash(s, ht->max);
    while (!isEmpty(*ht, pos) )
    {
        pos++;
    }
        ht->elems[pos].data = s;
        ht->elems[pos].flag = OCCUPIED;
        ht->count++;
}

void visualize(HashTable ht) {
    for (int i = 0; i < ht.max; ++i) {
        if (ht.elems[i].flag == OCCUPIED) {
            printf("%d--[%d]--%15s--%15s\n", i, ht.elems[i].data.studID, ht.elems[i].data.studName, ht.elems[i].data.program);
        } else {
            printf("%d--%s\n", i, "EMPTY");
        }
    }
}


#endif