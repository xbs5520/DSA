#ifndef __RB_H
#define __RB_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rb{
    uint8_t *buf;
    size_t  cap;    // total
    size_t  head;
    size_t  tail;
} rb_t;

static inline int rb_empty(const rb_t *q) 
{ 
    return q->head == q->tail; 
}
static inline int rb_full(const rb_t *q) 
{ 
    return ((q->tail + 1) % q->cap) == q->head; 
}
static inline size_t rb_size(const rb_t *q) 
{ 
    return (q->tail + q->cap - q->head) % q->cap; 
}
static inline size_t rb_free(const rb_t *q) 
{ 
    return q->cap - 1 - rb_size(q); 
}

// Initialize rb with external storage
// return 0 on success, -1 on invalid
int rb_init(rb_t *q, uint8_t *storage, size_t capacity);

void rb_reset(rb_t *q);

// single-byte API
// return 1 on success, 0 on full/empty
int rb_push(rb_t *q, uint8_t v);            // push to end
int rb_pop (rb_t *q, uint8_t *out);         // readfront && pop
int rb_peek(const rb_t *q, uint8_t *out);   // readfront 

// Bulk API (best-effort): returns actual count processed
size_t rb_write(rb_t *q, const uint8_t *src, size_t n);
size_t rb_read (rb_t *q, uint8_t *dst, size_t n);


#ifdef __cplusplus
}
#endif

#endif // __RB_H