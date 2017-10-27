#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "bitmap.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 1;

    uint64_t capacity = strtoul(argv[1], NULL, 10);

    if (capacity == 0)
        return 2;

    Bitmap_t bm;
    uint64_t rand_val;

    srand(time(NULL));
    Bitmap_init(&bm, capacity);

    for (int i = 0; i < capacity; i++) {
        rand_val = rand() % 100;
        
        if (rand_val > 80)
            Bitmap_set(&bm, i, 1);
    }

    for (int i = 0; i < capacity; i++)
        printf("%d: %s\n", i, Bitmap_at(&bm, i) ? "set" : "not set");

    Bitmap_free(&bm);

    return 0;
}
