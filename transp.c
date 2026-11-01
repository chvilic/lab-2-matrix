#include <stdlib.h>


int *transpose_flat(const int *matrix, int m, int n) {
    int *t = malloc((size_t)n * m * sizeof *t);
    if (t == NULL) return NULL;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(t + i * m + j) = *(matrix + j * n + i);
        }
    }
    return t;
}