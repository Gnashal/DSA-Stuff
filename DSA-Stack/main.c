#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.c"


int main () {
    Stack stack1 = createStack();
    
    
   
    printf("INPUT: \n");
    for (int i = 0; i < 10; ++i) {
        push(&stack1, i + 1);
    }
    display(stack1);
    
    
    
    return 0;
}