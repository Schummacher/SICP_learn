//
// Created by schummacher on 2017/9/3.
//

#ifndef SORT_TREE_H
#define SORT_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _tree
{
    int data;
    struct _tree *son;
    struct _tree *daughter;
}tree;

int tree_count(tree *root);
tree *creat_root(int data);
tree *creat_leaves(int data);
int tree_print(tree *root);
void tree_print_2(tree *root);
void tree_insert(int data,tree *root);
void insert_arr(int *data, tree *root, int length);


#endif //SORT_TREE_H
