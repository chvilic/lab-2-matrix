#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include <string.h>
int print_exponentiation(void);
int print_transposed(void);
int print_determinate(void);
void clean_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
int main() {
    system("chcp 65001");
    char flag[10];
    char flag_mode;

    while (1) {
        printf("Введите '0' чтобы выйти, '1' чтобы продолжить: "); 
        int fscan = scanf(" %9s", &flag);
        clean_input();

        if (strcmp(flag, "0") == 0) {
            break;
        }
        if (strcmp(flag, "1") != 0) {
            printf("Вы ввели что-то не то\n");
            continue;
        }

        printf("Нажмите '1' если будете работать с одной матрицей, и '2' если с двумя: "); 
        scanf(" %c", &flag_mode);
        clean_input();

        switch(flag_mode) {
            case '1': {
                char flag_mode_one;
                printf("Выберите действие: транспонирование - 1, степень - 2, определитель - 3: "); 
                scanf(" %c", &flag_mode_one);
                clean_input();

                switch (flag_mode_one) {
                    case '1':
                        print_transposed();
    
                        break;
                    case '2':
                        print_exponentiation();
                        break;
                    case '3':
                        print_determinate();
                        break;
                    default:
                        printf("Вы ввели что-то не то\n");
                        break;
                }
                break;
            }
            case '2':
                printf("Я такое пока не умею\n");
                break;
            default:
                printf("Вы ввели что-то не то\n");
                break;
        }

    }
    printf("Bye\n");
    return 0;
}
int print_transposed(void) {
    int m, n;

    int *matrix = matrix_input(&m, &n);
    if (matrix == NULL) {
        return 1;
    }
    int *transposed = transpose_flat(matrix, m, n);
    if (transposed == NULL) {
        free(matrix);
        return 1;
    }
    printf("\nТранспонированная матрица (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", transposed[i * m + j]);
        }
        printf("\n");
    }
    free(matrix);
    free(transposed);
}
int print_exponentiation(void) {
    int m, n;
    int degree;

    int *matrix = matrix_input(&m, &n);
    if (matrix == NULL) {
        return 1;
    }

    printf("Введите степень: ");
    if (scanf("%d", &degree) != 1) {
        printf("Вы ввели не число\n");
        clean_input();
        free(matrix);
        return 1;
    }
    clean_input();

    int *exp = exponation(matrix, m, n, degree);
    if (exp == NULL) {
        free(matrix);
        return 1;
    }

    printf("Матрица, возведенная в степень:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", exp[i * n + j]);
        }
        printf("\n");
    }

    free(matrix);
    free(exp);
    return 0;
}

int print_determinate(void) {
    int m, n;

    int *matrix = matrix_input(&m, &n);
    if (matrix == NULL) {
        return 1;
    }
    if (m != n) {
        printf("Ошибка: определитель существует только для квадратных матриц!\n");
        free(matrix);
        return 0;
    }

    double det = gaussDeterminant(matrix, m, n);

    printf("\nОпределитель матрицы: %.0f\n", det);

    free(matrix);
    return 0;
}