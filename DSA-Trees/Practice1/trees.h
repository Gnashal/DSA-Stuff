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

typedef struct
{
    NodePtr *data;
    int front;
    int rear;
    int max;
} Queue;

Queue createQueue(int max)
{
    Queue newQ;
    newQ.max = max;
    newQ.data = malloc(sizeof(NodePtr) * newQ.max);
    newQ.front = 0;
    newQ.rear = -1;

    return newQ;
}

bool isQueueEmpty(Queue *q)
{
    return (q->rear + 1) % q->max == q->front;
}
bool isQueueFull(Queue *q)
{
    return (q->rear + 2) % q->max == q->front;
}

void initTree(NodePtr *t)
{
    *t = NULL;
}
bool insert(NodePtr *t, int data)
{
    NodePtr newNode = malloc(sizeof(NodeType));
    if (!newNode)
    {
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

void preOrder(NodePtr t)
{
    if (t == NULL)
    {
        return;
    }

    printf("%d ", t->data);
    preOrder(t->left);
    preOrder(t->right);
}
void inOrder(NodePtr t)
{
    if (t)
    {
        inOrder(t->left);
        printf("%d ", t->data);
        inOrder(t->right);
    }
    return;
}
void postOrder(NodePtr t)
{
    if (t)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ", t->data);
    }
    return;
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

void bfs(NodePtr t)
{
    if (!t)
    {
        return;
    }
    Queue queue = createQueue(100);
    queue.rear = (queue.rear + 1) % queue.max;
    queue.data[queue.rear] = t;

    while (!isQueueEmpty(&queue))
    {
        NodePtr curr = queue.data[queue.front];
        queue.front = (queue.front + 1) % queue.max;
        printf("%d ", curr->data);
        if (curr->left)
        {
            queue.rear = (queue.rear + 1) % queue.max;
            queue.data[queue.rear] = curr->left;
        }
        if (curr->right)
        {
            queue.rear = (queue.rear + 1) % queue.max;
            queue.data[queue.rear] = curr->right;
        }
    }
}

#endif