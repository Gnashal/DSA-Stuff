#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node, *NodePtr, *Tree;

void initTree(NodePtr *t)
{
    *t = NULL;
}

bool insert(NodePtr *t, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Malloc Failed\n");
        return false;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    NodePtr *trav = t;
    while (*trav != NULL)
    {
        if (data >= (*trav)->data)
        {
            trav = &(*trav)->right;
        }
        else
        {
            trav = &(*trav)->left;
        }
    }
    *trav = newNode;
    return true;
}

Tree findSuccessor(Tree t)
{
    if (!t)
    {
        return NULL;
    }
    while (t->left)
    {
        t = t->left;
    }
    return t;
}

bool deleteNode(Tree *t, int search)
{
    if (!*t)
    {
        return false;
    }
    if (search > (*t)->data)
    {
        return deleteNode(&(*t)->right, search);
    }
    else if (search < (*t)->data)
    {
        return deleteNode(&(*t)->left, search);
    }
    else
    {
        if (!(*t)->left && !(*t)->right)
        {
            free(*t);
            *t = NULL;
        }
        else if (!(*t)->left || !(*t)->right)
        {
            NodePtr temp = *t;
            *t = ((*t)->left) ? (*t)->left : (*t)->right;
            free(temp);
        }  
        else
        {
            NodePtr temp = findSuccessor((*t)->right);
            (*t)->data = temp->data;
            return deleteNode(&(*t)->right, temp->data);
        }
        return true;
    }
}
void inOrder(Tree root, int *k, int *result)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, k, result);
    (*k)--;
    if (*k == 0)
    {
        *result = root->data;
        return;
    }
    inOrder(root->right, k, result);
}

int findKthSmallestElem(Tree *root, int k)
{
    int result = -1;
    inOrder(*root, &k, &result);
    return result;
}

void freeTree(Tree *root)
{
    if (*root == NULL)
    {
        return;
    }
    freeTree(&(*root)->left);  // Free the left subtree
    freeTree(&(*root)->right); // Free the right subtree
    free(*root);               // Free the current node
    *root = NULL;              // Set the pointer to NULL for safety
}

#endif