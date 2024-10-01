#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    char *data;
    int max;
    int count;
} Stack;

Stack createStack(int max)
{
    Stack newStack;
    newStack.max = max;
    newStack.count = 0;
    newStack.data = malloc(sizeof(char) * newStack.max);
    return newStack;
}

bool isEmpty(Stack s)
{
    return s.count == 0;
}
bool isFull(Stack s)
{
    return s.count == s.max;
}

bool push(Stack *s, char c)
{
    if (!isFull(*s))
    {
        s->data[s->count++] = c;
        return true;
    }

    return false;
}

char pop(Stack *s)
{
    char popped;
    if (!isEmpty(*s))
    {
        popped = s->data[s->count];
        --(s->count);
    }
    return popped;
}

char peek(Stack s)
{
    return s.data[s.count];
}

void display(Stack s)
{
    for (int i = 0; i < s.count; ++i)
    {
        printf("%c", s.data[i]);
        if (i < s.count - 1)
        {
            printf(" ");
        }
    }
}

#endif
