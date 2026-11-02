#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int *multiplication_matrixes(const int *matrix_1, const int *matrix_2, int m1, int n1, int m2, int n2) {
    if (n1 != m1) {
        printf("Можно перемножать матрицы (m x n и k x l), только если n = k");
        return NULL;
    }
    int *result = malloc(m1 * n2 * sizeof(int));
    int *time = malloc(m1 * n2 * sizeof(int));
    if (!result || !time) {
        free(result);
        free(time);
        return NULL;
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            int summa = 0;
            *(result + i * m1 + j) = 0;
            for (int r = 0; r < n1; r++) {
                summa += *(matrix_1 + i * m1 + r) * *(matrix_2 + r * m2 + j);
            }
            *(result + i * m1 + j) += summa;
        }
    }

    return result;
}