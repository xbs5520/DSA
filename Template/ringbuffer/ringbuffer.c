#include "ringbuffer.h"

static inline size_t wrap_add(size_t idx, size_t add, size_t cap)
{
    idx += add; 
    if (idx >= cap) idx -= cap; 
    return idx;
}
static inline size_t wrap_inc(size_t idx, size_t cap)
{ 
    return wrap_add(idx, 1, cap); 
}

int rb_init(rb_t *q, uint8_t *storage, size_t capacity)
{
    if (!q || !storage || capacity < 2) return -1;
    q->buf = storage; 
    q->cap = capacity; 
    q->head = 0; 
    q->tail = 0;
    return 0;
}

void rb_reset(rb_t *q)
{ 
    if (q) q->head = q->tail = 0;
}

int rb_push(rb_t *q, uint8_t val)
{
    if (rb_full(q)) return 0;
    q->buf[q->tail] = val;
    q->tail = wrap_inc(q->tail, q->cap);
    return 1;
}

int rb_pop(rb_t *q, uint8_t *out){
    if (rb_empty(q)) return 0;
    if (out) *out = q->buf[q->head];
    q->head = wrap_inc(q->head, q->cap);
    return 1;
}

int rb_peek(const rb_t *q, uint8_t *out)
{
    if (rb_empty(q)) return 0;
    if (out) *out = q->buf[q->head];
    return 1;
}

size_t rb_write(rb_t *q, const uint8_t *src, size_t n)
{
    size_t w = 0;
    while (w < n && !rb_full(q))
    {
        q->buf[q->tail] = src[w++];
        q->tail = wrap_inc(q->tail, q->cap);
    }
    return w;
}

size_t rb_read(rb_t *q, uint8_t *dst, size_t n)
{
    size_t r = 0;
    while (r < n && !rb_empty(q))
    {
        if (dst) dst[r] = q->buf[q->head];
        q->head = wrap_inc(q->head, q->cap);
        ++r;
    }
    return r;
}