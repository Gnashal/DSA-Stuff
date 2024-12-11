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
        if (op == 'S')
            break; // Stop input
        switch (op)
        {
        case '+': // Insert
            scanf("%d", &x);
            insert(&bst, x);
            break;
        case '-': // Delete
            scanf("%d", &x);
            deleteNode(&bst, x);
            break;
        case 'O': // Find k-th smallest
            scanf("%d", &k);
            int result = findKthSmallestElem(&bst, k);
            if (result == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("%d\n", result);
            }
            break;
        default:
            printf("Invalid operation\n");
        }
    }

    freeTree(&bst);

    return 0;
}