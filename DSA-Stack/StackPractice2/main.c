#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    Stack stack = createStack(20);

    push(&stack, '(');
    push(&stack, ')');
    push(&stack, '{');
    push(&stack, '}');

    display(stack);

    free(stack.data);
    return 0;
}