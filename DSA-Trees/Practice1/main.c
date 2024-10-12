#include <stdio.h>
#include <stdlib.h>
#include "trees.h"
int main()
{
    NodePtr tree;
    initTree(&tree);

    for (int i = 1; i <= 15; ++i)
    {
        if (!populateTree(&tree, (rand() * i) % 100))
        {
            return 0;
        }
    }
    printf("Pre Order: ");
    preOrder(tree);
    printf("\n");
    printf("In Order: ");
    inOrder(tree);
    printf("\n");
    printf("Post Order: ");
    postOrder(tree);
    printf("\n");
    printf("Breadth First Search: ");
    bfs(tree);
    freeTreeNode(tree);
    tree = NULL;
    return 0;
}