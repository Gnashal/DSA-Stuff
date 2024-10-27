#ifndef TREES_H
#define TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Weapon structure
typedef struct Weapon
{
    int weapon_id;
    int atk_dmg;
    int durability;
    char name[30];
} Weapon;

// TreeNode structure that holds a Weapon
typedef struct TreeNode
{
    Weapon data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *TreeNodePtr;

// Function prototypes
Weapon createWeapon(int weapon_id, int atk_dmg, int durability, const char *name)
{
    Weapon newWeapon;
    newWeapon.weapon_id = weapon_id;
    newWeapon.atk_dmg = atk_dmg;
    newWeapon.durability = durability;
    strcpy(newWeapon.name, name);

    return newWeapon;
}
void initTree(TreeNodePtr *t)
{
    *t = NULL;
}
// Default insertion is by weapon_id
bool insertNode(TreeNodePtr *root, Weapon data)
{
    TreeNodePtr newNode = (TreeNodePtr)malloc(sizeof(TreeNode));
    if (!newNode)
    {
        return false;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    TreeNodePtr *trav = root;
    while (*trav)
    {
        if (data.weapon_id >= (*trav)->data.weapon_id)
        {
            trav = &(*trav)->right;
        }
        else
        {
            trav = &(*trav)->left;
        }
    }
    *trav = newNode;
    return true;
}
// Finding a weapon via weapon_id
Weapon searchTree(TreeNodePtr *root, int weapon_id)
{
    Weapon found;
    TreeNodePtr *trav = root;

    while (*trav)
    {
        if ((*trav)->data.weapon_id == weapon_id)
        {
            found = (*trav)->data;
            break;
        }

        if (weapon_id >= (*trav)->data.weapon_id)
        {
            trav = &(*trav)->right;
        }
        else
        {
            trav = &(*trav)->left;
        }
    }

    return found;
}
void displayWeapons(TreeNodePtr t)
{
    printf("Weapon ID: %d\n", t->data.weapon_id);
    printf("Name: %s\n", t->data.name);
    printf("Attack Damage: %d\n", t->data.atk_dmg);
    printf("Durability: %d\n\n", t->data.durability);
}
void inorderTraversal(TreeNodePtr root)
{
    if (root)
    {
        inorderTraversal(root->left);
        displayWeapons(root);
        inorderTraversal(root->right);
    }
    return;
}
void freeTree(TreeNodePtr root)
{
    if (root)
    {
        freeTree(root->left);
        free(root);
        freeTree(root->right);
    }
    return;
}

#endif