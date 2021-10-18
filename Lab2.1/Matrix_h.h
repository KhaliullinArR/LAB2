#ifndef MATRIX_H
#define MATRIX_H

#include "Constants_h.h"

double MatrixMultiply(double[][nmax], int const*, int const*);
int PositiveElemsInRow(double[], int const*);
int MatrixInput(double[][nmax], int*, int*, const char*);
int ResultsProcessing(double[][nmax], double[][nmax], int const*, int const*, int const*, int const*, double, double);

#endif // !MATRIX_H

