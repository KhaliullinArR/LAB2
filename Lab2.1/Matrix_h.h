#ifndef MATRIX_H
#define MATRIX_H

#include "Constants_h.h"

double MatrixMultiply(double[][nmax], int const*, int const*);
int MatrixInput(double[][nmax], int*, int*, const char*);
int OutputMatrix(double[][nmax], int, int, FILE*);
bool isZero(double a[][nmax], int, int);
void PositiveElemsOutput(double[][nmax], int, int, FILE*);
#endif // !MATRIX_H

