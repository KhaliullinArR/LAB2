#ifndef MATRIX_H
#define MATRIX_H


double MatrixMultiply(double** , int, int);
//int PositiveElemsInRow(double* , int);
void MatrixInput(double**& , int*, int*, const char*);
int MatrixOutput(double**, int, int, FILE* file);
bool isZero(double**, int, int);
void PositiveElemsOutput(double**, int, int, FILE*);
void DeleteMatrix(double**, int, int);
#endif 


