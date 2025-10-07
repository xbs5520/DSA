#include "stacklist.h"

void stacklist_init(StackList* s) 
{
    s->head = NULL;
}

int stacklist_push(StackList* s, int x) 
{
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) return 0; // malloc fail
    n->val = x;
    n->next = s->head;
    s->head = n;
    return 1;
}

int stacklist_pop(StackList* s) 
{
    if (!s->head) return 0; // underflow
    Node* tmp = s->head;
    s->head = s->head->next;
    free(tmp);
    return 1;
}

int stacklist_top(StackList* s, int* ret) 
{
    if (!s->head) return 0; // empty
    *ret = s->head->val;
    return 1;
}

int stacklist_empty(StackList* s) 
{
    return s->head == NULL;
}