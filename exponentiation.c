#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
int *exponation(const int *matrix, int m, int n, int degree) {
    if (m != n) {
        printf("Возводить в степень можно только квадратные матрицы\n");
        return NULL;
    }

    int *result = malloc(n * n * sizeof(int));
    int *time = malloc(n * n * sizeof(int));
    if (!result || !time) {
        free(result);
        free(time);
        return NULL;
    }
    for (int i = 0; i < n * n; i++) {
        *(result + i) = *(matrix + i);
    }
    for (int step = 1; step < degree; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                *(time + i * n + j) = 0;
                for (int k = 0; k < n; k++) {
                    *(time + i * n + j) = 0;
                    long long temp = (long long)*(result + i * n + k) * *(matrix + k * n + j);
                    if (temp > INT_MAX || temp < INT_MIN) {
                        printf("При сложении появляются слишком большие числа\n");
                        free(result);
                        free(time);
                        return NULL;
                    }
                    *(time + i * n + j) = (int)temp;
                
                }
            }
        }
        for (int i = 0; i < n * n; i++) {
            *(result + i) = *(time + i);
        }

    }

    free(time);
    return result;
}