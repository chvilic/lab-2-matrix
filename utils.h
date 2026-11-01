#ifndef UTILS_H
#define UTILS_H

int *matrix_input(int *m, int *n);
int *transpose_flat(const int *matrix, int m, int n);
int *exponation(const int *matrix, int m, int n, int degree);
void clean_input(void);
double gaussDeterminant(const int *matrix, int m, int n);
#endif