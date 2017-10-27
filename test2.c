#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bitmap.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 1;

    uint64_t capacity = strtoul(argv[1], NULL, 10);

    if (capacity == 0)
        return 2;

    Bitmap_t *bm[capacity];

    for (int i = 0; i < capacity; i++) {
        bm[i] = malloc(sizeof(Bitmap_t));
        Bitmap_init(bm[i], capacity);
    }

    for (int i = 0; i < capacity; i++) {
        Bitmap_free(bm[i]);
        free(bm[i]);
    }

    return 0;
}
