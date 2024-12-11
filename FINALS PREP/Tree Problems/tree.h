#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void displayTree(struct Node *node)
{
    if (node != NULL)
    {
        displayTree(node->left);
        printf("%d ", node->value);
        displayTree(node->right);
    }
}

struct Node *insert(struct Node *node, int value)
{
    if (!node)
    {
        return createNode(value);
    }
    struct Node *curr = node;
    struct Node *parent = NULL;
    while (curr)
    {
        parent = curr;

        if (value < curr->value)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (value < parent->value)
    {
        parent->left = createNode(value);
    }
    else
    {
        parent->right = createNode(value);
    }

    return node;
}

struct Node *search(struct Node *node, int value)
{
    struct Node *curr = node;
    while (curr && curr->value != value)
    {
        if (value < curr->value)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return curr;
}

#endif