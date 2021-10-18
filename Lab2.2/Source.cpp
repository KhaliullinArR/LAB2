#include <cstdio>
#include <locale.h>
#include "Matrix_h.h"
#pragma warning (disable : 4996)


int main(int argc, char* argv[])
{
    double **a=0, **b=0;
    int ma, na, mb, nb;
    double a_mult, b_mult;
    setlocale(LC_ALL, "rus");

    if (argc < 2){
        printf("Недостаточно параметров!\n");
        return 1;
    }

    if (!MatrixInput(a, &na, &ma, argv[1]))
        return 1;
    if (!MatrixInput(b, &nb, &mb, argv[2]))
        return 1;

    a_mult = MatrixMultiply(a, &na, &ma);
    b_mult = MatrixMultiply(b, &nb, &mb);

    if (!ResultsProcessing(a, b, &na, &ma, &nb, &mb, a_mult, b_mult))
        return 1;

    for (int i = 0; i < na; i++)
        delete[] * (a + i);
    delete[] a;

    a = 0;

    for (int i = 0; i < nb; i++)
        delete[] * (b + i);
    delete[] b;

    b = 0;

    

}