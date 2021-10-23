#ifndef MATRIX_H
#define MATRIX_H


double MatrixMultiply(double** , int const*, int const*);
int PositiveElemsInRow(double* , int);
void MatrixInput(double**& , int*, int*, const char*);
int MatrixOutput(double**, int, int, FILE* file);
bool ZeroCheck(double**, int, int);
void PositiveElemsOutput(double**, int, int, FILE*);
#endif 


