#pragma once

#include <stdint.h>

typedef struct _bm {
    uint8_t *bits;
    size_t size;
} Bitmap_t;

extern void Bitmap_init(Bitmap_t *bm, size_t sz);
extern uint8_t Bitmap_at(Bitmap_t *bm, size_t index);
extern void Bitmap_set(Bitmap_t *bm, size_t index, uint8_t set_bit);
extern void Bitmap_free(Bitmap_t *bm);
