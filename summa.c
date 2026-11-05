#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <limits.h>
int *summa_matrixes(const int *matrix_1, const int *matrix_2, int m1, int n1, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {
        printf("Складывать можно только матрицы одинаковых размеров\n");
        return NULL;
    }
    int *s = malloc((size_t)n1 * m1 * sizeof *s);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            *(s + i * n1 + j) = 0;
        }
    }
    if (s == NULL) return NULL;
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            long long temp = (long long)*(matrix_1 + i * n1 + j) + *(matrix_2 + i * n1 + j);
            if (temp > INT_MAX || temp < INT_MIN) {
                printf("При сложении появляются слишком большие числа\n");
                free(s);
                return NULL;
            }
            *(s + i * n1 + j) = (int)temp;
        }
    }
    return s;
}