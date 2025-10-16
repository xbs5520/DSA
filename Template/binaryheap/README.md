# Binary Heap (C, Min-Heap)

Simple binary heap (min-heap) implementation in C, using a fixed-size array.

## API

### Min-Heap Version (`binaryheap.h`/`binaryheap.c`)
- `void heap_init(MinHeap* h)`
- `void heap_push(MinHeap* h, int x)`
- `void heap_pop(MinHeap* h)`
- `int heap_top(MinHeap* h)`

## Notes
- The heap uses 0-based indexing.
- Fixed capacity (`MAXN`), no dynamic resizing.
- `heap_push` inserts an element and maintains the min-heap property.
- `heap_pop` removes the minimum element (root) and maintains the heap.
- `heap_top` returns the minimum element (root).
- For max-heap, reverse the comparison in `up` and `down`.

