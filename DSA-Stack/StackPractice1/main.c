#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int main () {
    Stack mainStack = createStack(10);
    Stack dumpStack = createStack(10);

    for (int i = 0; !isFull(mainStack); ++i) {
        push(&mainStack, (rand() & 100) + i);
    }
    printf("Main stack: \n");
    displayStack(mainStack);
    
   while (!isEmpty(mainStack))
   {
    push(&dumpStack, pop(&mainStack));
    }
   printf("Main stack: ");
   displayStack(mainStack);
   printf("Dump stack: \n");
   displayStack(dumpStack);
    
    // for (int i = 0; i < mainStack.max; ++i) {
    //     printf("%d ", mainStack.data[i]);
    // }
    // printf("\n");
   int middle = getMiddle(&dumpStack);
   printf("The middle of the stack is: %d\n", middle);
    return 0;
}