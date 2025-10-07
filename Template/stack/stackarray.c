#include "stackarray.h"

void stack_init(StackArray* s) 
{
    s->top = 0;
}

int stack_push(StackArray* s, int x) 
{
    if (s->top == MAXN) return 0; // overflow
    s->data[s->top++] = x;
    return 1;
}

int stack_pop(StackArray* s) 
{
    if (s->top == 0) return 0; // underflow
    s->top--;
    return 1;
}

int stack_top(StackArray* s, int* ret) 
{
    if (s->top == 0) return 0; // empty
    *ret = s->data[s->top - 1];
    return 1;
}

int stack_empty(StackArray* s) 
{
    return s->top == 0;
}