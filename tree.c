#include <stdio.h>
#include <stdlib.h>

typedef struct _tree
{
    int data;
    struct _tree *son;
    struct _tree *daughter;
}tree;

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
