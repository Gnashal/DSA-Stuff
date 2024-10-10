#ifndef TREES_H
#define TREES_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr;

void initTree(NodePtr *t)
{
    t = NULL;
}
bool populateTree(NodePtr *t, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (!newNode)
    {
        return false;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    NodePtr *trav = t;

    while (*trav != NULL)
    {
        if (newNode->data >= (*trav)->data)
        {
            if ((*trav)->right == NULL)
            {
                (*trav)->right = newNode;
                return true;
            }
            else
            {
                *trav = (*trav)->right;
            }
        }
        else if (newNode->data < (*trav)->data)
        {
            if ((*trav)->left == NULL)
            {
                (*trav)->left = newNode;
                return true;
            }
            else
            {
                *trav = (*trav)->left;
            }
        }
    }
    *trav = newNode;
    return true;
}

void preOrder(NodePtr t)
{
    if (t == NULL)
    {
        return;
    }

    printf("%d, ", t->data);
    preOrder(t->left);
    preOrder(t->right);
}
void freeTreeNode(NodePtr t)
{
    if (t == NULL)
    {
        return;
    }
    freeTreeNode(t->left);
    freeTreeNode(t->right);
    free(t);
}

#endif