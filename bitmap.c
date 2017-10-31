#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bitmap.h"

static inline size_t calc_bytes(uint64_t x)
{
    size_t bytes = 1;

    while (x > bytes * 8)
        bytes++;

    return bytes;
}

static inline size_t calc_index(uint64_t x)
{
    size_t index = 0;

    while (index < x / 8)
        index++;

    return index;
}

void Bitmap_init(Bitmap_t *bm, size_t sz)
{
    assert (sz > 0);

    bm->size = sz;
    bm->bits = calloc(calc_bytes(sz), sizeof(uint8_t));

    if (!bm->bits) {
        perror("calloc");
        exit(1);
    }
}

inline uint8_t Bitmap_at(Bitmap_t *bm, size_t index)
{
    assert (index < bm->size);
    uint8_t *bits = &bm->bits[calc_index(index)];
    index %= 8;
    return (1 << index) & *bits;
}

inline void Bitmap_set(Bitmap_t *bm, size_t index, uint8_t set_bit)
{
    assert (index < bm->size);

    uint8_t *bits = &bm->bits[calc_index(index)];
    index %= 8;

    *bits = (set_bit) ? (1 << index) | *bits
                      : ~(1 << index) & *bits;
}

inline void Bitmap_free(Bitmap_t *bm)
{
    free(bm->bits);
}
