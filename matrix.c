#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include "utils.h"

int *matrix_input(int *m, int *n) {
    char x;

    printf("Введите размер матрицы (m x n): ");
    if (scanf("%d %c %d", m, &x, n) != 3 || *m <= 0 || *n <= 0 || x != 'x') {
        clean_input();
        clearerr(stdin);
        printf("Ошибка формата ввода\n");
        return NULL;
    }

    int *matrix = malloc((*m) * (*n) * sizeof(int));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }

    int choice;
    printf("Выберите способ заполнения, 1 - ввести вручную, 2 - сгенерировать автоматически\n");
    scanf("Ваш выбор:");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        clean_input();
        clearerr(stdin);
        printf("Ошибка выбора\n");
        free(matrix);
        return NULL;
    }
    clean_input();

    if (choice == 1) {
        printf("Введите элементы матрицы:\n");
        for (int i = 0; i < *m; i++) {
            for (int j = 0; j < *n; j++) {
                long long temp;
                if (scanf("%lld", &temp) != 1) {
                    printf("Ошибка ввода элемента [%d][%d]\n", i + 1, j + 1);
                    clean_input();
                    clearerr(stdin);
                    free(matrix);
                    return NULL;
                }
                if (temp > INT_MAX || temp < INT_MIN) {
                    printf("Вы вводите слишком большие числа\n");
                    clean_input();
                    clearerr(stdin);
                    free(matrix);
                    return NULL;
                }
                matrix[i * (*n) + j] = (int)temp;
            }
        }
        int c;
        int extra_found = 0;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (!isspace(c)) extra_found = 1;
        }
        if (extra_found) {
            printf("\nОшибка: Вы ввели больше значений, чем нужно (%d элементов)\n",
                   (*m) * (*n));
            free(matrix);
            return NULL;
        }
    } else {

        int range;
        printf("Введите максимальное значение (по модулю) для элементов: ");
        if (scanf("%d", &range) != 1 || range <= 0) {
            clean_input();
            clearerr(stdin);
            printf("Некорректный диапазон\n");
            free(matrix);
            return NULL;
        }
        clean_input();
        if (range > 1000 || range < -1000) {
            printf("Пожалуйста, вводите менее большие числа\n");
            clean_input();
            clearerr(stdin);
            printf("Некорректный диапазон\n");
            free(matrix);
            return NULL;
        }
        for (int i = 0; i < *m; i++) {
            for (int j = 0; j < *n; j++) {
                int sign;
                if (rand() % 2) {
                    sign = 1;
                } else {
                    sign = -1;
                }
                matrix[i * (*n) + j] = sign * (rand() % range);
            }
        }


        printf("Сгенерированная матрица:\n");
        for (int i = 0; i < *m; i++) {
            for (int j = 0; j < *n; j++) {
                printf("%5d ", matrix[i * (*n) + j]);
            }
            printf("\n");
        }
    }

    return matrix;
}