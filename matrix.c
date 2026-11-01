#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <limits.h>
int *matrix_input(int *m, int *n) {
    char x;
    
    printf("Введите размер матрицы (m x n): ");
    if (scanf("%d %c %d", m, &x, n) != 3) {
        clean_input();
        printf("Ошибка формата ввода\n");
        return NULL;
    }

    int *matrix = malloc((*m) * (*n) * sizeof(int));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            long long temp;
            if (scanf("%lld", &temp) != 1) {
                printf("Ошибка ввода элемента [%d][%d]\n", i + 1, j + 1);
                clean_input();
                free(matrix);
                return NULL;
            }
            if (temp > INT_MAX || temp < INT_MIN) {
                    printf("Вы вводите слишком большие числа\n");
                    clean_input();
                    free(matrix);
                    return NULL;
                }
            matrix[i * (*n) + j] = (int)temp; 
        }
    }
    return matrix;
}