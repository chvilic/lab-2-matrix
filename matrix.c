#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "utils.h"
#include <limits.h>

int *matrix_input(int *m, int *n) {
    char line[1024];
    char *p, *q;

    printf("Введите размер матрицы (m x n): ");
    if (!read_line(line, sizeof(line))) {
        printf("Ошибка формата ввода\n");
        return NULL;
    }

    long mm = strtol(line, &p, 10);
    if (p == line) {
        printf("Ошибка формата ввода\n");
        return NULL;
    }
    while (*p == ' ' || *p == '\t') p++;
    if (*p == '\0') {
        printf("Ошибка формата ввода\n");
        return NULL;
    }
    p++;                                  // skip the separator ('x')
    long nn = strtol(p, &q, 10);
    if (q == p) {
        printf("Ошибка формата ввода\n");
        return NULL;
    }
    *m = (int)mm;
    *n = (int)nn;

    int *matrix = malloc((*m) * (*n) * sizeof(int));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }

    printf("Введите элементы матрицы:\n");
    line[0] = '\0';
    p = line;
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            // skip spaces; fetch the next line when the current one is used up
            while (1) {
                while (*p == ' ' || *p == '\t') p++;
                if (*p != '\0') break;
                if (!read_line(line, sizeof(line))) {
                    printf("Ошибка ввода элемента [%d][%d]\n", i + 1, j + 1);
                    free(matrix);
                    return NULL;
                }
                p = line;
            }
            char *end;
            errno = 0;
            long long temp = strtoll(p, &end, 10);
            if (end == p) {
                printf("Ошибка ввода элемента [%d][%d]\n", i + 1, j + 1);
                free(matrix);
                return NULL;
            }
            if (errno == ERANGE || temp > INT_MAX || temp < INT_MIN) {
                printf("Вы вводите слишком большие числа\n");
                free(matrix);
                return NULL;
            }
            matrix[i * (*n) + j] = (int)temp;
            p = end;
        }
    }
    return matrix;
}
