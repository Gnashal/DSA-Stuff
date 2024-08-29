#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MyStack.h"

Stack createStack() {
    Stack newS;
    
    newS.count = 0;
    
    return newS;
}


bool isEmpty(Stack s) {
    return s.count == 0;
}

bool isFull(Stack s) {
    return s.count >= MAX;
}

void display(Stack s) {
    printf("{");
    for (int i = 0; i < s.count; ++i) {
        printf("%d", s.data[i]);
        if (i < s.count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

bool push(Stack *s, int data) {
    if (!isFull(*s)) {
        s->data[s->count++] = data;
        return true;
    }
    
    return false;
}
bool pop(Stack *s) {
    if (!isEmpty(*s)) {
        (s->count)--;
        return true;
    }
    return false;
}
int peek (Stack s) {
    return s.data[s.count - 1];
}
