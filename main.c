#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include <string.h>
int print_exponentiation(void);
int print_transposed(void);
int print_determinate(void);
int print_summa(void);
int print_subtraction(void);
int print_multiplication(void);
void clean_input(void) {
    char buf[100];
    fgets(buf, sizeof(buf), stdin);
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
                char flag_mode_two;
                printf("Выберите действие: сложение - 1, вычитание - 2, умножение - 3: "); 
                scanf(" %c", &flag_mode_two);
                clean_input();

                switch (flag_mode_two) {
                    case '1':
                        print_summa();
                        break;
                    case '2':
                        print_subtraction();
                        break;
                    case '3':
                        print_multiplication();
                        break;
                    default:
                        printf("Вы ввели что-то не то\n");
                        break;
                }
                break;
            default:
                printf("Вы ввели что-то не то\n");
                break;
        }

    }
    printf("До свидания\n");
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

int print_summa(void) {
    int m1, n1;
    int m2, n2;
    int *matrix_1 = matrix_input(&m1, &n1);
    if (matrix_1 == NULL) {
        return 1;
    }
    int *matrix_2 = matrix_input(&m2, &n2);
    if (matrix_2 == NULL) {
        return 1;
    }

    int *summa = summa_matrixes(matrix_1, matrix_2, m1, n1, m2, n2);
    if (summa == NULL) {
        free(summa);
        return 1;
    }
    printf("Сумма матриц:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d ", *(summa + i * n1 + j));
        }
        printf("\n");
    }
    free(matrix_1);
    free(matrix_2);
    free(summa);

}
int print_subtraction(void) {
    int m1, n1;
    int m2, n2;
    int *matrix_1 = matrix_input(&m1, &n1);
    if (matrix_1 == NULL) {
        return 1;
    }
    int *matrix_2 = matrix_input(&m2, &n2);
    if (matrix_2 == NULL) {
        return 1;
    }
    if (m1 != m2 || n1 != n2) {
        printf("Можно вводить только матрицы одинаковых размеров\n");
        return 1;
    }
    int *summa = subtraction_matrixes(matrix_1, matrix_2, m1, n1, m2, n2);
    if (summa == NULL) {
        free(summa);
        return 1;
    }
    printf("Сумма матриц:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
           printf("%d ", *(summa + i * n1 + j));
        }
        printf("\n");
    }
    free(matrix_1);
    free(matrix_2);
    free(summa);
}

int print_multiplication(void) {
    int m1, n1;
    int m2, n2;
    int *matrix_1 = matrix_input(&m1, &n1);
    if (matrix_1 == NULL) {
        return 1;
    }
    int *matrix_2 = matrix_input(&m2, &n2);
    if (matrix_2 == NULL) {
        free(matrix_1);
        return 1;
    }
    if (n1 != m2) {
        printf("Ошибка: число столбцов первой матрицы должно быть равно числу строк второй\n");
        free(matrix_1);
        free(matrix_2);
        return 1;
    }
    int *product = multiplication_matrixes(matrix_1, matrix_2, m1, n1, m2, n2);
    if (product == NULL) {
        free(matrix_1);
        free(matrix_2);
        return 1;
    }
    printf("Произведение матриц (%d x %d):\n", m1, n2);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d ", product[i * n2 + j]);
        }
        printf("\n");
    }
    free(matrix_1);
    free(matrix_2);
    free(product);
    return 0;
}