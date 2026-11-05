#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *multiplication_matrixes(const int *matrix_1, const int *matrix_2, int m1, int n1, int m2, int n2) {
    if (n1 != m2) {
        printf("Ошибка: число столбцов первой матрицы должно быть равно числу строк второй\n");
        return NULL;
    }
    
    int *result = malloc(m1 * n2 * sizeof(int));
    if (!result) {
        return NULL;
    }

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            long long summa = 0;
            
            for (int r = 0; r < n1; r++) {
                summa += (long long)*(matrix_1 + i * n1 + r) * *(matrix_2 + r * n2 + j);
                
                if (summa > INT_MAX || summa < INT_MIN) {
                    printf("\nОшибка: при умножении получаются слишком большие числа\n");
                    free(result);
                    return NULL;
                }
            }
            *(result + i * n2 + j) = (int)summa;
        }
    }

    return result; 
}