#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    int* data;
    int count;
    int max;
} Stack;

Stack createStack(int max) {
    Stack newS;

    newS.count = 0;
    newS.max = max;
    newS.data = (int*)malloc(sizeof(int) * newS.max);

    return newS;
}

bool isEmpty (Stack s) {
    return s.count == 0;
}

bool isFull(Stack s) {
    return s.count >= s.max;
}

bool push (Stack* s, int data) {
    if(!isFull(*s)) {
        s->data[s->count++] = data;
        return true;
    } 
    printf("Stack Overflow\n");

    return false;
}

int pop (Stack *s) {
    int popppedData;
    if(!isEmpty(*s)) {
        popppedData = s->data[s->count - 1];
        s->count--;
    }
    return popppedData;
}

int peek(Stack s) {
    if (!isEmpty(s)) {
        return s.data[s.count - 1];
    }

    return -1;
}

bool makeNUll(Stack* s) {
    int* temp = (int*)malloc(sizeof(int) * s->max);
    int i = 0;
    while(!isEmpty(*s)) {
        temp[i++] = pop(s);
    }

    free(temp);
}

int getMiddle (Stack* s) {
    if (isEmpty(*s)) {
        printf("Stack is empty\n");
        return -1;
    }

    Stack tempStack = createStack(s->max);
    Stack copyStack = *s;
    int middleIndex = copyStack.max / 2;
    for (int i = 0; i < middleIndex; ++i) {
        push(&tempStack, pop(&copyStack));
    }
    int middle = peek(copyStack);

    makeNUll(&tempStack);
    makeNUll(&copyStack);

    return middle;
    
}

void displayStack(Stack s) {
    Stack tempS = createStack(s.count);
    if (!isEmpty(s)) {
        printf("{");
    
        printf("%d", peek(s));
        push(&tempS, pop(&s));

        while (!isEmpty(s)) {
            printf(", %d", peek(s));
            push(&tempS, pop(&s));
        }
        printf("}\n");

        memcpy(s.data, tempS.data, sizeof(int) * s.count);
        makeNUll(&tempS);
    } else {
        printf("The stack is currently empty:(\n");
        return;
    }
}





#endif
