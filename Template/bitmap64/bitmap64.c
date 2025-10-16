#include "bitmap64.h"
// 64-bit reassembly bitmap: mark & missing iterator

// mark i received
void mark(bitmap64* bm, int i) 
{
    *bm |= (1ULL << i);
}

// check i is marked
int is_marked(bitmap64 bm, int i) 
{
    return (bm >> i) & 1;
}

// foreach missing
void foreach_missing(bitmap64 bm, int total, missing_cb cb) 
{
    for (int i = 0; i < total; ++i) 
    {
        if (!((bm >> i) & 1)) cb(i);
    }
}

// check all received
int all_received(bitmap64 bm, int total) 
{
    return bm == ((total == 64) ? ~0ULL : ((1ULL << total) - 1));
}
