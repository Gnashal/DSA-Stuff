#include <stdio.h>
#include "trees.h"

int main()
{
    TreeNodePtr root;
    initTree(&root);
    printf("INSERTION: \n");
    Weapon weapons[] = {
        createWeapon(1, 50, 100, "Sword"),
        createWeapon(2, 60, 80, "Axe"),
        createWeapon(3, 40, 120, "Bow"),
        createWeapon(4, 70, 90, "Spear"),
        createWeapon(5, 55, 110, "Dagger"),
        createWeapon(6, 80, 75, "Mace"),
        createWeapon(7, 65, 95, "Crossbow"),
        createWeapon(8, 45, 130, "Staff"),
        createWeapon(9, 85, 60, "Halberd"),
        createWeapon(10, 75, 85, "Scythe")};
    int numWeapons = sizeof(weapons) / sizeof(weapons[0]);

    // Insert weapons into the tree
    for (int i = 0; i < numWeapons; i++)
    {
        insertNode(&root, weapons[i]);
        inorderTraversal(root);
        printf("\n");
    }
    // Display the tree using inorder traversal
    // printf("\nInorder traversal of weapons in the tree:\n");

    // Search for a weapon
    int search_id = 1;
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
    // Deleting a node
    printf("\nDELETION: \n");
    inorderTraversal(root);
    printf("\n");
    for (int i = 1; i <= 9; ++i)
    {
        if (deleteNode(&root, i))
        {
            inorderTraversal(root);
            printf("\n");
        }
        else
        {
            printf("deletion failed");
        }
    }

    // Free the tree
    freeTree(root);

    printf("\nTree Freed!\n");

    return 0;
}
