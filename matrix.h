#pragma once

#include <stdint.h>

typedef struct _bmm {
    uint8_t *bits;
    size_t size;
} Matrix_t;

extern void Matrix_init(Matrix_t *bmm, size_t sz);
extern uint8_t Matrix_at(Matrix_t *bmm, size_t i, size_t j);
extern void Matrix_set(Matrix_t *bmm, size_t i, size_t j, uint8_t set_bit);
extern void Matrix_free(Matrix_t *bmm);
