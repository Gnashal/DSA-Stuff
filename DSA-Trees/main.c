#include <stdio.h>
#include <stdlib.h>
#include "trees.h"
int main()
{
    NodePtr tree;
    initTree(&tree);

    for (int i = 0; i < 15; ++i)
    {
        if (!populateTree(&tree, (rand() * i) % 100))
        {
            return 0;
        }
    }
    preOrder(tree);
    freeTreeNode(tree);
    tree = NULL;
    return 0;
}