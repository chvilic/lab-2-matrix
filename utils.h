#ifndef UTILS_H
#define UTILS_H

int *matrix_input(int *m, int *n);
int *transpose_flat(const int *matrix, int m, int n);
int *exponation(const int *matrix, int m, int n, int degree);
double gaussDeterminant(const int *matrix, int m, int n);
int *summa_matrixes(const int *matrix_1, const int *matrix_2, int m1, int n1, int m2, int n2);
int *subtraction_matrixes(const int *matrix_1, const int *matrix_2, int m1, int n1, int m2, int n2);
int read_line(char *buf, int size);
int *multiplication_matrixes(const int *matrix_1, const int *matrix_2, int m1, int n1, int m2, int n2);
#endif