#include <iostream>
#include "Constants_h.h"
#pragma warning(disable : 4996)

void PositiveElemsOutput(double a[][nmax], int na, int ma, FILE* out) {
    for (int i = 0; i < na; i++) {
        fprintf(out, "%3d - строка: %2d\n", i + 1, PositiveElemsInRow(a[i],ma));
    }
}

bool ZeroCheck(double a[][nmax], int n, int m) {
    int num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0)num++;
        }
    if (num == m * n) return true;
    return false;
}

double MatrixMultiply(double a[][nmax], int const* n, int const* m) {
    double s = 1;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++) {
            if (a[i][j] != 0)s *= a[i][j];
        }
    return s;
}

int PositiveElemsInRow(double a[], int m) {
    int num = 0;
    for (int i = 0; i < m; i++)
        if (a[i] > 0)num++;
    return num;
}


int MatrixInput(double a[][nmax], int* n, int* m, const char* fname) {
    FILE* file;

    if ((file = fopen(fname, "r")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", fname);
        return 0;
    }
    if (fscanf(file, "%d%d", n, m) < 2)
    {
        printf("Ошибка чтения из файла '%s'\n", fname);
        fclose(file);
        return 0;
    }
    if (*m < 0 || *m > nmax || *n < 0 || *n > nmax)
    {
        printf("Количество строк и столбцов матрицы должны быть от 1 до %d!\n", nmax);
        return 0;
    }
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (fscanf(file, "%lf", *(a + i) + j) < 1)
            {
                printf("Ошибка чтения из файла '%s'\n", fname);
                fclose(file);
                return 0;
            }
    fclose(file);

    return 1;
}


int OutputMatrix(double a[][nmax], int n, int m, FILE* file) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (fprintf(file, "%-6g ", a[i][j]) < 1) {
                printf("Невозможно записать в файл output.txt!");
                return 0;
            }
        fprintf(file, "\n");
    }

    return 1;
}