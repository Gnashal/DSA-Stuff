#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define MAX 16
#define SIZE 16
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef char String[16];

typedef struct
{
    String city;
    int zip;
} Address;

typedef struct
{
    int id;
    String name;
    Address add;
} Person;

typedef struct
{
    Person *personList;
    int max;
    int count;
} PersonList, StackAList, PersonCloseDict;

typedef struct
{
    Person list[MAX];
    int front;
    int rear;
} QueueAList;

typedef struct node
{
    Person p;
    struct node *link;
} NodeType, *NodePtr, *StackLList;

typedef struct
{
    NodePtr list[SIZE];
    int count;
} PersonOpenDict;

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
    newPerson.add = address;
    newPerson.id = id;
    strcpy(newPerson.name, name);

    return newPerson;
}
PersonList createPersonList(int max)
{
    PersonList newList;
    newList.count = 0;
    newList.max = max;
    newList.personList = (Person *)malloc(sizeof(Person) * newList.max);

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

int hash(int id)
{
    int hashed = 0;
    for (int i = 0; i < sizeof(id) * 4; ++i)
    {
        hashed += (id >> i) & 1;
    }

    return hashed % SIZE;
}

bool insert(PersonOpenDict *d, Person p)
{

    if (d->count > SIZE * 0.80)
    {
        return false;
    }
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (!newNode)
    {
        return false;
    }
    newNode->p = p;
    newNode->link = NULL;
    int pos = hash(p.id);
    if (d->list[pos] == NULL)
    {
        d->list[pos] = newNode;
        d->count++;
        return true;
    }

    NodePtr trav = d->list[pos];
    while (trav->link != NULL)
    {
        trav = trav->link;
    }
    newNode->link = trav->link;
    trav->link = newNode;
    d->count++;
    return true;
}

String *getNames(PersonOpenDict d, String city)
{
    String temp[100];
    int index = 0, pos;
    NodePtr trav;
    for (int i = 1; i <= 100; ++i)
    {
        pos = hash(i);
        trav = d.list[pos];
        while (trav != NULL)
        {
            if (trav->p.id == i && strcmp(trav->p.add.city, city) == 0)
            {
                strcpy(temp[index++], trav->p.name);
            }
            trav = trav->link;
        }
    }

    String *names = (String *)malloc(sizeof(String) * (index + 1));
    if (names)
    {
        memcpy(names, temp, sizeof(String) * index);
        strcpy(names[index], "");
    }

    return names;
}

void initStack(StackLList *s)
{
    *s = NULL;
}

bool isStackEmpty(StackLList s)
{
    return s == NULL;
}

bool push(StackLList *s, Person p)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (!newNode)
    {
        return false;
    }
    newNode->p = p;
    newNode->link = *s;
    *s = newNode;
    return true;
}
Person pop(StackLList *s)
{
    Person popped;
    Person dummy = {0, ""};
    if (!isStackEmpty(*s))
    {
        popped = (*s)->p;
        NodePtr holder = *s;
        *s = (*s)->link;
        free(holder);
        return popped;
    }
    return dummy;
}
bool hardPop(StackLList *s)
{
    if (!isStackEmpty(*s))
    {
        NodePtr holder = *s;
        *s = (*s)->link;
        free(holder);
        return true;
    }
    return false;
}
Person peek(StackLList s)
{
    return s->p;
}

void displayStack(StackLList s)
{
    StackLList temp;
    initStack(&temp);
    printf("\nStack L List: \n\n");
    while (!isStackEmpty(s))
    {
        Person p = peek(s);
        printf("ID: %d \nName: %s \nCity: %s \nZip: %d\n\n", p.id, p.name,
               p.add.city, p.add.zip);
        push(&temp, pop(&s));
    }
    while (!isStackEmpty(temp))
    {
        push(&s, peek(temp));
        hardPop(&temp);
    }
}

// TODO: code the rest of problem 3 and apply the solution I made earlier
// though this time, try to implement an array for Queues
QueueAList createAQueue()
{
    QueueAList newAQ;
    newAQ.front = 0;
    newAQ.rear = -1;
    return newAQ;
}
bool isQueueEmpty(QueueAList *q)
{
    return (q->rear + 1) % MAX == q->front;
}
bool isQueueFull(QueueAList *q)
{
    return (q->rear + 2) % MAX == q->front;
}
bool enqueue(QueueAList *q, Person p)
{
    if (!isQueueFull(q))
    {
        q->rear = (q->rear + 1) % MAX;
        q->list[q->rear] = p;
        return true;
    }
    return false;
}

bool dequeue(QueueAList *q)
{
    if (!isQueueEmpty(q))
    {
        q->front = (q->front + 1) % MAX;
        return true;
    }
    return false;
}
Person front(QueueAList q)
{
    return q.list[q.front];
}

void stackToQueue(StackLList *s, QueueAList *q)
{
    PersonCloseDict cd;
    cd.max = 16;
    for (int i = 0; i < cd.max; ++i)
    {
        cd.personList[i].id = -1;
    }
    int pos;
    StackLList temp = NULL;
    NodePtr holder = NULL;

    while (*s != NULL)
    {
        pos = hash((*s)->p.id);

        if (cd.personList[pos].id == -1 || cd.personList[pos].id == -2)
        {
            cd.personList[pos] = (*s)->p;

            if (!isQueueFull(q))
            {
                enqueue(q, (*s)->p);
            }
            else
            {
                return;
            }
        }
        else
        {
            continue;
        }

        // Move current node to temp stack
        holder = *s;
        *s = holder->link;
        holder->link = temp;
        temp = holder;
    }

    // Rebuilding original stack from temp
    while (temp != NULL)
    {
        holder = temp;
        temp = temp->link;
        holder->link = *s;
        *s = holder;
    }
}

void displayQueues(QueueAList q)
{
    QueueAList temp = createAQueue();
    while (!isQueueEmpty(&q))
    {
        Person p = front(q);
        printf("ID: %d \nName: %s \nCity: %s \nZip: %d\n\n", p.id, p.name,
               p.add.city, p.add.zip);
        enqueue(&temp, p);
        dequeue(&q);
    }

    while (!isQueueEmpty(&temp))
    {
        Person p = front(temp);
        enqueue(&q, p);
        dequeue(&temp);
    }
}
#endif