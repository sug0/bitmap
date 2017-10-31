#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "matrix.h"

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

void Matrix_init(Matrix_t *bmm, size_t sz)
{
    assert (sz > 1);

    bmm->size = sz;
    bmm->bits = calloc(calc_bytes(sz * sz), sizeof(uint8_t));

    if (!bmm->bits) {
        perror("calloc");
        exit(1);
    }
}

inline uint8_t Matrix_at(Matrix_t *bmm, size_t i, size_t j)
{
    assert (i < bmm->size);

    size_t index = (i * bmm->size) + j;
    uint8_t *bits = &bmm->bits[calc_index(index)];
    index %= 8;

    return (1 << index) & *bits;
}

inline void Matrix_set(Matrix_t *bmm, size_t i, size_t j, uint8_t set_bit)
{
    assert (i < bmm->size);

    size_t index = (i * bmm->size) + j;
    uint8_t *bits = &bmm->bits[calc_index(index)];
    index %= 8;

    *bits = (set_bit) ? (1 << index) | *bits
                      : ~(1 << index) & *bits;
}

inline void Matrix_free(Matrix_t *bmm)
{
    free(bmm->bits);
}
