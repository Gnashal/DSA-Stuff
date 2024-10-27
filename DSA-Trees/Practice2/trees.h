#ifndef TREES_H
#define TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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
TreeNodePtr findSuccessor(TreeNodePtr root)
{
    if (!root)
        return NULL;
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
bool deleteNode(TreeNodePtr *root, int search_id)
{
    if (!root)
    {
        return false;
    }
    if (search_id < (*root)->data.weapon_id)
    {
        return deleteNode(&(*root)->left, search_id);
    }
    else if (search_id > (*root)->data.weapon_id)
    {
        return deleteNode(&(*root)->right, search_id);
    }
    else
    {
        if (!(*root)->left && !(*root)->right)
        {
            free(*root);
            *root = NULL;
        }
        else if (!(*root)->left || !(*root)->right)
        {
            TreeNodePtr temp = *root;
            *root = (*root)->left ? (*root)->left : (*root)->right;
            free(temp);
        }
        else
        {
            TreeNodePtr temp = findSuccessor((*root)->right);
            (*root)->data = temp->data;
            return deleteNode(&(*root)->right, temp->data.weapon_id);
        }
        return true;
    }
}
void displayWeapons(TreeNodePtr t)
{
    printf("Weapon ID: %d\n", t->data.weapon_id);
    printf("Name: %s\n", strupr(t->data.name));
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