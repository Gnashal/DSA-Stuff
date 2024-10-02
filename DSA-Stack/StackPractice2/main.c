#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    Stack stack = createStack(20);

    char brackets[] = {"((}{)"};


    if (checkValidity(&stack, brackets)) {
        printf("valid\n");
    } else {
        printf("not valid\n");
    }


    display(stack);

    free(stack.data);
    return 0;
}