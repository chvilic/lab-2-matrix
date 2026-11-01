#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

double gaussDeterminant(const int *matrix, int m, int n) {
    if (m != n) {
        printf("Возводить в степень можно только квадратные матрицы\n");
        return 0.0;
    }
    int *result = malloc(n * n * sizeof(int));
    if (!result) {
        free(result);
        return 0.0;
    }
    for (int i = 0; i < n * n; i++) {
        *(result + i) = *(matrix + i);
    }
    for (int k = 0; k < n - 1; k++) {
        if (*(result + k * n + k) == 0) {
            continue;
        }
        for (int i = k + 1; i < n; i++) {
            int factor = *(result + i * n + k) / *(result + k * n + k);
            for (int j = k; j < n; j++) {
                *(result + i * n + j) -= factor * *(result + k * n + j);
            }
        }
    }
    int res = 1;
    for (int i = 0; i < n; i++) {
        res *= *(result + i * n + i);
    }
    free(result);
    return res;
}