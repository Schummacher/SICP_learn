#ifndef SORT_LIST_H
#define SORT_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _list
{
    int data;
    struct _list *next;
} list;

int list_ref(list *head, int n);
int length(list *head);
list *append(list *head1, list *head2);
void print_list(list *head);
void list_insert(list *head, int *data, int num);
int last_pair(list *head);

#endif //SORT_LIST_H
