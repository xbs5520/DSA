#ifndef __BITMAP64_H
#define __BITMAP64_H

#include <stdint.h>
#include <stdio.h>

typedef uint64_t bitmap64;

void mark(bitmap64* bm, int i);
int is_marked(bitmap64 bm, int i);
typedef void (*missing_cb)(int idx);
void foreach_missing(bitmap64 bm, int total, missing_cb cb);
int all_received(bitmap64 bm, int total);

#endif