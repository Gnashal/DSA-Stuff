#include <stdio.h>
#include "trees.h"

int main()
{
    TreeNodePtr root;
    initTree(&root);

    // Create some Weapon instances
    Weapon sword = createWeapon(1, 50, 100, "Sword");
    Weapon axe = createWeapon(2, 60, 80, "Axe");
    Weapon bow = createWeapon(3, 40, 120, "Bow");

    // Insert weapons into the tree
    insertNode(&root, sword);
    insertNode(&root, axe);
    insertNode(&root, bow);

    // Display the tree using inorder traversal
    printf("Inorder traversal of weapons in the tree:\n");
    inorderTraversal(root);

    // Search for a weapon
    int search_id = 2;
    Weapon foundWeapon = searchTree(&root, search_id);
    if (foundWeapon.weapon_id != -1)
    {
        printf("\nWeapon with ID %d found:\n", search_id);
        displayWeapons(&(TreeNode){foundWeapon, NULL, NULL});
    }
    else
    {
        printf("\nWeapon with ID %d not found.\n", search_id);
    }

    // Free the tree
    freeTree(root);
    printf("Tree Freed!\n");

    return 0;
}
