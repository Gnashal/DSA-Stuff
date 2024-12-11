#include "functions.h"

int main()
{
    Tree bst;
    initTree(&bst);

    char op;
    int x, k;

    printf("Enter operations:\n");
    while (scanf(" %c", &op))
    {
        if (op == '0')
            break; 
        switch (op)
        {
        case '+': 
            scanf("%d", &x);
            insert(&bst, x);
            break;
        case '-': // Delete
            scanf("%d", &x);
            deleteNode(&bst, x);
            break;
        default:
            printf("Invalid operation\n");
        }
    }
    printf("Minimum Element: %d\n", findMin(&bst));
    printf("Maximum Element: %d\n", findMax(&bst));

    freeTree(&bst);

    return 0;
}