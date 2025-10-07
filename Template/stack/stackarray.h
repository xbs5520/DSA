#ifndef __STACKARRAY_H
#define __STACKARRAY_H
#define MAXN 100

typedef struct {
    int data[MAXN];
    int top; // 指向下一个可插入位置
} StackArray;


void stack_init(StackArray* s);
int stack_push(StackArray* s, int x);
int stack_pop(StackArray* s);
int stack_top(StackArray* s, int* ret);
int stack_empty(StackArray* s);

#endif //__STACKARRAY_H