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
    int originalPos = pos;
    do {
        if (ht.elems[pos].flag == EMPTY || ht.elems[pos].flag == DELETED ) {
            return false;
        }
        pos = (pos + 1) % ht.max;
    } while(pos != originalPos);
    return true;
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
    int pos = getHash(s, ht->max);
    int originalPos = pos;
    if (!isFull(*ht, pos) && ht->count < ht->max * 0.80) {
        while (!isEmpty(*ht, pos) )
        {
            pos = (pos + 1) % ht->max;
        }
            ht->elems[pos].data = s;
            ht->elems[pos].flag = OCCUPIED;
            ht->count++;
            return true;
    } 
        ht->max *= 2;
        ht->elems = realloc(ht->elems,sizeof(Data) * (ht->max));
        for (int i = ht->count; i < ht->max; ++i) {
            ht->elems[i].flag = EMPTY;
        }
    

    return false;
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