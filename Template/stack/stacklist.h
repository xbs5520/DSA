#ifndef __STACKLIST_H
#define __STACKLIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} StackList;

void stacklist_init(StackList* s);
int stacklist_push(StackList* s, int x);
int stacklist_pop(StackList* s);
int stacklist_top(StackList* s, int* ret);
int stacklist_empty(StackList* s);

#endif //__STACKLIST_H