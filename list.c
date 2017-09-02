#include <stdlib.h>

typedef struct _list
{
    int data;
    struct _list *next;
} list;

int list_ref(list *head, int n)
{
    if(n == 0)
        return head->data;
    else
        return list_ref(head->next, n - 1);
}

int length(list *head)
{
    if(head->next == NULL)
        return 1;
    else
        return 1 + length(head->next);
}

list *append(list *head1, list *head2)
{
    list *ptr;
    ptr = head1;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head2;
    return head1;
}

void print_list(list *head)
{
    while(head->next != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}

void insert(list *head, int *data, int num)
{
    list *ptr;
    while(head->next != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    for (int i = 0; i < num; ++i)
    {
        ptr = malloc(sizeof(list));
        head->next = ptr;
        head = head->next;
        head->data = *(data + i);
    }
    head->next = 0;
}

int last_pair(list *head)
{
    if(head->next != 0)
        last_pair(head->next);
    else
        return head->data;
}
