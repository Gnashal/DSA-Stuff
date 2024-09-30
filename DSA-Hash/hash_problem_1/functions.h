#ifndef FUNCTIONS_h
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
1. Create a function that converts a product stack into a dictionary. If similar prodct exist automatiaclly adds it into the prodQty.
2. Hash function will be based on the ID plus the first 3 characters of the product name.
3. Use 70% as the load factor for the dictionary
*/

typedef struct
{
    int prodID;
    char prodName[20];
    int prodQty;
    float prodPrice;
} Product;

typedef struct node
{
    Product prod;
    struct node *next;
} NodeType, *NodePtr, *Stack;

typedef struct
{
    NodePtr *data;
    int count;
    int max;
} ProdDict;

Product createProduct(int id, char *name, int prodQty, float price)
{
    Product newProd;
    newProd.prodID = id;
    strcpy(newProd.prodName, name);
    newProd.prodQty = prodQty;
    newProd.prodPrice = price;

    return newProd;
}

bool isEmpty(Stack s)
{
    return s == NULL;
}
bool push(Stack *s, Product data)
{
    NodePtr temp = (NodePtr)malloc(sizeof(NodeType));
    if (!temp)
    {
        return false;
    }
    temp->prod = data;
    temp->next = *s;
    *s = temp;
    return true;
}
Product pop(Stack *s)
{
    Product poppedProd = createProduct(0, "", 0, 0.0);
    if (!isEmpty(*s))
    {
        NodePtr temp = *s;
        poppedProd = (*s)->prod;
        *s = temp->next;
        free(temp);
    }
    return poppedProd;
}

bool hardPop(Stack *s)
{
    if (!isEmpty(*s))
    {
        NodePtr temp = *s;
        *s = temp->next;
        free(temp);
    }
}

Product peek(Stack s)
{
    return s->prod;
}

void initStack(Stack *s)
{
    *s = NULL;
}

void visualizeStack(Stack s)
{
    if (!isEmpty(s))
    {
        printf("STACK\n");
        printf("%10s|%15s|%10s|%10s |\n", "Product ID", "Product Name", "Prodcut Quantity", "Product Price");
        while (s)
        {
            printf("%10d|%15s|%10d|%10.2f |\n", s->prod.prodID, s->prod.prodName, s->prod.prodQty, s->prod.prodPrice);
            s = s->next;
        }
        printf("\n\n");
    }
    else
    {
        printf("\nStack is currently empty\n");
    }
}
ProdDict createDict(int max)
{
    ProdDict newDict;
    newDict.max = max;
    newDict.count = 0;
    newDict.data = (NodePtr *)malloc(sizeof(NodeType) * newDict.max);
    for (int i = 0; i < newDict.max; i++)
    {
        newDict.data[i] = NULL;
    }

    return newDict;
}

int getHash(char *name, int id, int max)
{
    int hashValue = 0;
    int cap = 5;
    for (int i = 0; i < cap; ++i)
    {
        hashValue += (int)name[i];
    }
    hashValue += id;

    return hashValue % max;
}
Product get(ProdDict *dict, char *name, int id)
{
    int pos = getHash(name, id, dict->max);
    NodePtr trav = dict->data[pos];
    for (; trav != NULL && (strcmp(trav->prod.prodName, name) != 0 || trav->prod.prodID != id); trav = trav->next)
    {
    }

    if (trav)
    {
        return trav->prod;
    }
}
bool isItThere(NodePtr *list, char *name, int id, int max)
{
    int pos = getHash(name, id, max);
    while (1)
    {
        if (strcmp((*list)->prod.prodName, name) == 0 && (*list)->prod.prodID == id)
        {
            return true;
        }
        else
        {
            break;
        }
    }
    return false;
}

bool add(ProdDict *dict, Product p)
{
    NodePtr newProd = (NodePtr)malloc(sizeof(NodeType));
    if (!newProd)
    {
        return false;
    }
    newProd->prod = p;
    newProd->next = NULL;
    int pos = getHash(p.prodName, p.prodID, dict->max);

    if (dict->count >= dict->max * 0.70)
    {
        return false;
    }

    NodePtr *trav = &(dict->data[pos]);
    while (*trav)
    {
        if (strcmp((*trav)->prod.prodName, p.prodName) == 0 && (*trav)->prod.prodID == p.prodID)
        {
            (*trav)->prod.prodQty += p.prodQty;
            return true;
        }
        trav = &(*trav)->next;
    }
    newProd->next = (*trav);
    (*trav) = newProd;
    dict->count++;
    return true;
}
bool removeInDict(ProdDict *dict, char *name, int id)
{
    int pos = getHash(name, id, dict->max);
    NodePtr temp = NULL;

    NodePtr *trav = &(dict->data[pos]);
    if (isItThere(trav, name, id, dict->max))
    {
        temp = *trav;
        *trav = (*trav)->next;
        free(temp);
        return true;
    }

    return false;
}

void vissualizeDict(ProdDict dict)
{
    printf("DICTIONARY\n");
    printf("%10s|%12s|%15s|%10s|%10s|\n", "Hash Value", "Product ID", "Product Name", "Prodcut Quantity", "Product Price");
    for (int i = 0; i < dict.max; ++i)
    {
        if (dict.data[i] != NULL)
        {
            while (dict.data[i] != NULL)
            {
                printf("%10d|%12d|%15s|%16d|%13.2f|\n", i, dict.data[i]->prod.prodID, dict.data[i]->prod.prodName, dict.data[i]->prod.prodQty, dict.data[i]->prod.prodPrice);
                dict.data[i] = dict.data[i]->next;
            }
        }
        else
        {
            printf("%10d|%10s\n", i, "NULL");
        }
    }
}

bool convertStack(Stack *s, ProdDict *d, Stack *dump)
{
    Stack dumpStack;
    initStack(&dumpStack);

    while (!isEmpty(*s))
    {
        add(d, peek(*s));
        push(&dumpStack, pop(s));
    }

    while (!isEmpty(dumpStack))
    {
        push(dump, pop(&dumpStack));
    }

    return true;
}

#endif