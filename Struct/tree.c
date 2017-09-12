//
// Created by schummacher on 2017/9/3.
//

#include "tree.h"

int tree_count(tree *root)
{
    if(root->daughter == 0 && root->son == 0)
        return 1;
    else if(root->daughter != 0 && root->son != 0)
        return 1 + tree_count(root->son) + tree_count(root->daughter);
    else if(root->daughter == 0 && root->son != 0)
        return 1 + tree_count(root->son);
    else if(root->daughter != 0 && root->son == 0)
        return 1 + tree_count(root->daughter);
}

tree *creat_root(int data)
{
    tree *p = malloc(sizeof(tree));
    p->son = NULL;
    p->daughter = NULL;
    p->data = data;
    return p;
}

tree *creat_leaves(int data)
{
    tree *p = malloc(sizeof(tree));
    p->son = NULL;
    p->daughter = NULL;
    p->data = data;
    return p;
}

int tree_print(tree *root)
{
    if(root->daughter == 0 && root->son == 0)
    {
        printf("%d ", root->data);
    }
    else if(root->daughter != 0 && root->son != 0)
    {
        printf("%d ", root->data);
        tree_print(root->son);
        tree_print(root->daughter);
    }
    else if(root->daughter == 0 && root->son != 0)
    {
        printf("%d ", root->data);
        tree_print(root->son);
    }
    else if(root->daughter != 0 && root->son == 0)
    {
        printf("%d ", root->data);
        tree_print(root->daughter);
    }
}

void tree_print_2(tree *root)
{
    if(root)
    {
        tree_print_2(root->son);
        tree_print_2(root->daughter);
        printf("%d ", root->data);
    }
}

void tree_insert(int data,tree *root)
{
    if(data < root->data)
    {
        if(root->son == NULL)
        {
            root->son = creat_leaves(data);
        }
        else
            tree_insert(data, root->son);
    }
    else
    {
        if(root->daughter == NULL)
        {
            root->daughter =creat_leaves(data);
        }
        else
            tree_insert(data, root->daughter);
    }
}

void insert_arr(int *data, tree *root, int length)
{
    for (int i = 0; i < length; i++)
    {
        tree_insert(*(data + i), root);
    }
}
