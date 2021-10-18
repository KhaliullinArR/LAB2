#include <iostream>
#include "Constants_h.h"
#pragma warning(disable : 4996)
double MatrixMultiply(double a[][nmax], int const* n, int const* m) {
    int num = 0;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++) {
            if (a[i][j] == 0)num++;
        }
    if (num == *m * *n) return 0;

    double s = 1;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++) {
            if (a[i][j] != 0)s *= a[i][j];
        }
    return s;
}

int PositiveElemsInRow(double a[], int const* m) {
    int num = 0;
    for (int i = 0; i < *m; i++)
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


int ResultsProcessing(double a[][nmax], double b[][nmax], int const* na, int const* ma, int const* nb, int const* mb, double a_mult, double b_mult) {

    FILE* file;
    const char* out = "output.txt";

    if ((file = fopen(out, "w")) == NULL)
    {
        printf("Невозможно открыть файл для записи\n");
        return 0;
    }

    fprintf(file, "Исходные данные:\n\nМассив A:\n");


    for (int i = 0; i < *na; i++) {
        for (int j = 0; j < *ma; j++)
            fprintf(file, "%-6g ", a[i][j]);
        fprintf(file, "\n");
    }

    fprintf(file, "\n");

    fprintf(file, "Массив B :\n");

    for (int i = 0; i < *nb; i++) {
        for (int j = 0; j < *mb; j++)
            fprintf(file, "%-6g ", b[i][j]);
        fprintf(file, "\n");
    }

    fprintf(file, "\n");

    if (a_mult == 0 && b_mult == 0) {
        fprintf(file, "В матрицах A и 'B' все элементы равны нулю.");
    }
    else if (a_mult == 0) {
        fprintf(file, "В матрице A все элементы равны нулю.\n");
        fprintf(file, "Кол-во положительных элементов в каждой строке матрицы B:\n");
        for (int i = 0; i < *nb; i++) {
            fprintf(file, "%3d - строка: %2d\n", i + 1, PositiveElemsInRow(b[i], mb));
        }

    }
    else if (b_mult == 0) {
        fprintf(file, "В матрице 'B' все элементы равны нулю.\n");
        fprintf(file, "Кол-во положительных элементов в каждой строке матрицы A:\n");
        for (int i = 0; i < *na; i++) {
            fprintf(file, "%3d - строка: %2d\n", i + 1, PositiveElemsInRow(a[i], ma));
        }
    }
    else if (a_mult > b_mult) {
        fprintf(file, "В матрице A произведение элементов больше чем произведение элементов матрицы 'B', которые соответсвенно равны %g и %g\n", a_mult, b_mult);
        fprintf(file, "Кол-во положительных элементов в каждой строке матрицы A:\n");
        for (int i = 0; i < *na; i++) {
            fprintf(file, "%3d - строка: %2d\n", i + 1, PositiveElemsInRow(a[i], ma));
        }
    }
    else if (a_mult < b_mult) {
        fprintf(file, "В матрице 'B' произведение элементов больше чем произведение элементов матрицы A, которые соответсвенно равны %g и %g", b_mult, a_mult);
        fprintf(file, "Кол-во положительных элементов в каждой строке матрицы B:\n");
        for (int i = 0; i < *nb; i++) {
            fprintf(file, "%3d - строка: %2d\n", i + 1, PositiveElemsInRow(b[i], mb));
        }
    }
    else if (a_mult == b_mult) {
        fprintf(file, "В матрице 'B' произведение элементов больше равно произведению элементов матрицы A, которые соответсвенно равны %g и %g", b_mult, a_mult);
        fprintf(file, "Кол-во положительных элементов в каждой строке матрицы B:\n");
        for (int i = 0; i < *nb; i++) {
            fprintf(file, "%3d - строка: %2d\n", i + 1, PositiveElemsInRow(b[i], mb));
        }
        fprintf(file, "Кол-во положительных элементов в каждой строке матрицы A:\n");
        for (int i = 0; i < *na; i++) {
            fprintf(file, "%3d - строка: %2d\n", i + 1, PositiveElemsInRow(a[i], ma));
        }
    }
    fclose(file);
    return 1;
}