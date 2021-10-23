#include <iostream>
#pragma warning(disable : 4996)

int PositiveElemsInARow(double *a, int na) {
    int num = 0;

    for (int i = 0; i < na; i++) {
        if (a[i] > 0) num++;
    }

    return num;
}

bool isZeroInARoW(double *a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)return false;
    }
    return true;
}

bool isZero(double **a, int n, int m) {
    bool zero = true;
    for (int i = 0; i < n; i++)
        zero = zero && isZeroInARoW(a[i], m);
    return zero;
}


double MultiplyInARow(double *a, int n) {
    double s = 1;
    for (int i = 0; i < n; i++)
        if (a[i] != 0)s *= a[i];
    return s;
}


double MatrixMultiply(double **a, int n, int m) {
    double s = 1;
    for (int i = 0; i < n; i++)
        s *= MultiplyInARow(a[i], m);
    return s;
}


void PositiveElemsOutput(double **a, int n, int m, FILE* out) {
    for (int i = 0; i < n; i++) {
        fprintf(out, "%3d - строка: %2d\n", i + 1, PositiveElemsInARow(a[i], m));
    }
    return;
}


void DeleteMatrix(double** a, int n, int m) {
    for (int i = 0; i < n; i++)
        delete[] * (a + i);
    delete[] a;

    a = 0;
}


void MatrixInput(double**& a, int* n, int* m, const char* fname) {
    FILE* file;

    if ((file = fopen(fname, "r")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", fname);
        a = 0;
        return;
    }
    if (fscanf(file, "%d%d", n, m) < 2)
    {
        printf("Ошибка чтения из файла '%s'\n", fname);
        fclose(file);
        a = 0;
        return;
    }
    if (*m < 0 || *n < 0)
    {
        printf("Количество строк и столбцов матрицы должны быть больше 1!\n");
        a = 0;
        return;
    }

    try {
        a = new double* [*n];
        for (int i = 0; i < *n; i++) {
            try {
                a[i] = new double[*m];
            }
            catch (std::bad_alloc) {
                printf("Не достаточно памяти для выделения массива в файле %s.", fname);
                a = 0;
                return;
            }
        }



        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *m; j++)
                if (fscanf(file, "%lf", a[i] + j) < 1) {
                    printf("Ошибка чтения из файла '%s'\n", fname);
                    fclose(file);
                    a = 0;
                    return;
                }
    }
    catch (std::bad_alloc) {
        printf("Не достаточно памяти для выделения массива в файле %s.", fname);
        a = 0;
        return;
    }
    fclose(file);

    return;
}


int MatrixOutput(double** a, int n, int m, FILE* file) {


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fprintf(file, "%-6g ", a[i][j]);
        fprintf(file, "\n");
    }

    fprintf(file, "\n");

    return 0;
}