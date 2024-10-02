#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char city[20];
    int zip;
} Address;

typedef struct 
{
    int id;
    char name[16];
    Address address;
} Person;

typedef struct 
{
    Person *personList;
    int max;
    int count;
} PersonList;

typedef struct node
{
    PersonList data;
    struct node *next;
}*NodePtr, NodeType, *StackList;


Address createAddress(char* city, int zip);
Person createPerson(int id, char* name, Address address) {
    Person newPerson;
    newPerson.address = address;
    newPerson.id = id;
    strcpy(newPerson.name, name);
}
void initStack(StackList* s, int max) {
    (*s)->next = NULL;
    (*s)->data.max = max;
    (*s)->data.personList = (Person*)malloc(sizeof(Person) * (*s)->data.max);
}


void getVoters(PersonList voters, char* city, StackList* cityVoters);
bool push();
bool pop();
bool peek();





#endif 