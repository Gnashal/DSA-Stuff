#ifndef MY_STACK_H
#define MY_STACK_H

#define MAX 10
typedef struct 
{
    int data[MAX];
    int count;
} Stack;

Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
void display(Stack s);
bool push(Stack *s, int data);
bool pop(Stack *s);
int peek (Stack s);

#endif