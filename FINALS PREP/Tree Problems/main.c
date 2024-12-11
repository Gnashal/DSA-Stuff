#include <stdio.h>
#include "tree.h"

int main(void) {
    struct Node* root = NULL;
    struct Node* root2 = NULL;
    int testCase;

    printf("Enter test case number (1 or 2): ");
    scanf("%d", &testCase);

    switch (testCase) {
        case 1: {
            // Test Case 1
            root = insert(root, 3);
            root = insert(root, 5);
            root = insert(root, 8);
            root = insert(root, 1);
            root = insert(root, 6);
            root = insert(root, 4);
            root = insert(root, 7);
            root = insert(root, 8);

            printf("Elements of the first tree:\n");
            displayTree(root);

            if (search(root, 10) != NULL) {
                printf("\n10 exists\n");
            } else {
                printf("\n10 does not exist\n");
            }
            break;
        }
        case 2: {
            // Test Case 2
            root2 = insert(root2, 10);
            root2 = insert(root2, 8);
            root2 = insert(root2, -1);
            root2 = insert(root2, 3);
            root2 = insert(root2, 12);
            root2 = insert(root2, 55);
            root2 = insert(root2, 2);
            root2 = insert(root2, 100);

            printf("Elements of the second tree:\n");
            displayTree(root2);

            if (search(root2, 100) != NULL) {
                printf("\n100 exists\n");
            } else {
                printf("\n100 does not exist\n");
            }
            break;
        }
        default: {
            printf("Invalid test case number.\n");
            break;
        }
    }

    // Free the allocated memory for both trees (if necessary)
    // freeTree(root);
    // freeTree(root2);

    return 0;
}