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
        popped = s->data[--(s->count)];
        return popped;
    }
    return '\0';
}

char peek(Stack s)
{
    if (!isEmpty(s))
    {
        return s.data[s.count - 1];
    }
    return '\0';
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

bool findParity(char current, char top) {
     return !((current == '}' && top != '{') ||
             (current == ')' && top != '(') ||
             (current == ']' && top != '['));
 }

bool checkValidity(Stack *s, char *c) {
    for (int i = 0; c[i] != '\0'; ++i) {
        char current = c[i];
        if (current == '{' || current == '(' || current == '[') {
            push(s, current);
        } else if (current == '}' || current == ')' || current == ']'){
            if (isEmpty(*s)) {
                return false;
            }
            char top = pop(s);
            if (!findParity(current, top)) {
                return false;
            }
        }
    }

    return isEmpty(*s);
   
}

#endif
