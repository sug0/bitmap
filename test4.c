#include <stdio.h>
#include "matrix.h"

int main(void)
{
    Matrix_t m;

    Matrix_init(&m, 3);

    Matrix_set(&m, 0, 2, 1);

    printf("%c\n", (Matrix_at(&m, 0, 2)) ? '1' : '0');
    printf("%c\n", (Matrix_at(&m, 1, 1)) ? '1' : '0');
    printf("%c\n", (Matrix_at(&m, 2, 0)) ? '1' : '0');

    Matrix_free(&m);

    return 0;
}
