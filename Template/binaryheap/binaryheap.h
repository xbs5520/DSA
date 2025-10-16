#ifndef __BINARY_HEAP_H
#define __BINARY_HEAP_H

#define MAXN 1000
typedef struct {
    int data[MAXN];
    int size;
} MinHeap;

void heap_init(MinHeap* h);
void heap_push(MinHeap* h, int x);
void heap_pop(MinHeap* h);
int heap_top(MinHeap* h);


#endif //__BINARY_HEAP_H