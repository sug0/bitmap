# Bitmap

A bitmap is a data structure that implements an array of booleans in a very
memory efficient way; albeit the time complexity of this implementation
isn't constant, given the fact cpu registers will store the same bytes in
them for a prolonged period of time with accesses restricted to the
same memory region, this data structure often outperforms others with
better time complexity.

# API

```c
typedef struct _bm {
    uint8_t *bits;
    size_t max_index;
} Bitmap_t;

extern void Bitmap_init(Bitmap_t *bm, size_t sz);
extern uint8_t Bitmap_at(Bitmap_t *bm, size_t index);
extern void Bitmap_set(Bitmap_t *bm, size_t index, uint8_t set_bit);
extern void Bitmap_free(Bitmap_t *bm);
```

# Example usage

```c
#include <stdio.h>
#include <bitmap.h>

int main(void)
{
    Bitmap_t bm;

    /* initialize bitmap with 8 spaces */
    Bitmap_init(&bm, 8);

    /* set the first bit */
    Bitmap_set(&bm, 0, 1);

    /* set the third bit */
    Bitmap_set(&bm, 2, 1);

    /* set the last bit */
    Bitmap_set(&bm, 7, 1);

    /* print set bits */
    for (int i = 0; i < 8; i++)
        putchar((Bitmap_at(&bm, i)) ? '1' : '0');

    putchar('\n');

    /* free the allocated space in memory */
    Bitmap_free(&bm);

    return 0;
}
```
