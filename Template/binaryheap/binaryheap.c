#include "binaryheap.h"

void heap_init(MinHeap* h)
{ 
    h->size = 0; 
}

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void down(MinHeap *h, int i)
{
    int t = i;
    int n = h->size;
    if(i * 2 <= n && h->data[i * 2] < h->data[t]) t = i * 2;
    if(i * 2 + 1 <= n && h->data[i * 2 + 1] < h->data[t]) t = i * 2 + 1;
    if(i != t){
        swap(&h->data[i], &h->data[t]);
        down(h, t);
    }
}

static void up(MinHeap *h, int i)
{
    while(i / 2 && h->data[i / 2] > h->data[i])
    {
        swap(&h->data[i / 2], &h->data[i]);
        i /= 2;
    }
}


void heap_push(MinHeap* h, int x)
{
    h->data[++h->size] = x;
    up(h, h->size);
}

void heap_pop(MinHeap* h)
{
    h->data[1] = h->data[h->size];
    h->size--;
    down(h, 1);
}
int heap_top(MinHeap* h)
{
    if(h->size > 0) return h->data[1];
    return -1;
}