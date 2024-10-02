#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/*


In a collection of votes in an array list of Persons.
Get all the voters living in a specific city and store them into a Stack Linked List
*/

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
    Person data;
    struct node *next;
} *NodePtr, NodeType, *StackList;

Address createAddress(char *city, int zip)
{
    Address newAdd;
    strcpy(newAdd.city, city);
    newAdd.zip = zip;

    return newAdd;
}
Person createPerson(int id, char *name, Address address)
{
    Person newPerson;
    newPerson.address = address;
    newPerson.id = id;
    strcpy(newPerson.name, name);

    return newPerson;
}
PersonList createPersonList(int max)
{
    PersonList newList;
    newList.count = 0;
    newList.max = max;
    newList.personList = malloc(sizeof(Person) * newList.max);

    return newList;
}

bool addPerson(PersonList *list, Person p)
{
    if (list->count <= list->max)
    {
        list->personList[list->count] = p;
        (list->count)++;
        return true;
    }
    return false;
}

void initStack(StackList *s)
{
    *s = NULL;
}

bool isEmpty(StackList s)
{
    return s == NULL;
}

bool push(StackList *s, Person p)
{
    NodePtr newNode = malloc(sizeof(NodeType));
    newNode->next = *s;
    newNode->data = p;

    if (newNode)
    {
        *s = newNode;
    }
    else
    {
        return false;
    }
    return true;
}
bool pop(StackList *s)
{
    NodePtr holder = *s;
    if (!isEmpty(*s))
    {
        *s = (*s)->next;
        free(holder);
        return true;
    }
    return false;
}
Person peek(StackList s)
{
    if (!isEmpty(s))
    {
        return s->data;
    }
}
void getVoters(PersonList voters, char *city, StackList *s)
{
    for (int i = 0; i < voters.max; ++i)
    {
        if (strcmp(voters.personList[i].address.city, city) == 0)
        {
            NodePtr newNode = malloc(sizeof(NodeType));
            if (!newNode)
            {
                return;
            }
            // Giga chad way
            newNode->data = voters.personList[i];
            newNode->next = *s;
            *s = newNode;
            // Un-comment code below for ez
            // push(s, voters.personList[i]);
        }
    }
}

#endif