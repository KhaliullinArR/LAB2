#include <cstdio>
#include <locale.h>
#include "Matrix_h.h"
#pragma warning (disable : 4996)


int main(int argc, char* argv[])
{
    double** a = 0, ** b = 0;
    int ma, na, mb, nb;
    double a_mult, b_mult;
    FILE* out;

    setlocale(LC_ALL, "rus");

    if ((out = fopen("output.txt", "w")) == NULL)
    {
        printf("Невозможно открыть файл для записи\n");
        return 0;
    }


    if (argc < 2)
    {
        printf("Недостаточно параметров!\n");
        return 1;
    }

    MatrixInput(a, &na, &ma, argv[1]);
    if (!a)
        return 1;
    MatrixInput(a, &nb, &mb, argv[2]);
    if (!b)
        return 1;

    if (isZero(a, na, ma))
        a_mult = 0;
    else
        a_mult = MatrixMultiply(a, na, ma);

    if (isZero(b, nb, mb))
        b_mult = 0;
    else
        b_mult = MatrixMultiply(b, nb, mb);

    fprintf(out, "Исходные данные:\n\nМассив A:\n");
    if (!MatrixOutput(a, na, ma, out))
        return 1;

    fprintf(out, "Исходные данные:\n\nМассив B:\n");
    if (!MatrixOutput(b, nb, mb, out))
        return 1;

    if (a_mult == 0 && b_mult == 0) {
        fprintf(out, "В матрицах A и 'B' все элементы равны нулю.");
    }
    else if (a_mult == 0) {
        fprintf(out, "В матрице A все элементы равны нулю.\n");
        fprintf(out, "Кол-во положительных элементов в каждой строке матрицы B:\n");
        PositiveElemsOutput(a, na, ma, out);

    }
    else if (b_mult == 0) {
        fprintf(out, "В матрице 'B' все элементы равны нулю.\n");
        fprintf(out, "Кол-во положительных элементов в каждой строке матрицы A:\n");
        PositiveElemsOutput(b, nb, mb, out);
    }
    else if (a_mult > b_mult) {
        fprintf(out, "В матрице A произведение элементов больше чем произведение элементов матрицы 'B', которые соответсвенно равны %g и %g\n", a_mult, b_mult);
        fprintf(out, "Кол-во положительных элементов в каждой строке матрицы A:\n");
        PositiveElemsOutput(a, na, ma, out);
    }
    else if (a_mult < b_mult) {
        fprintf(out, "В матрице 'B' произведение элементов больше чем произведение элементов матрицы A, которые соответсвенно равны %g и %g\n", b_mult, a_mult);
        fprintf(out, "Кол-во положительных элементов в каждой строке матрицы B:\n");
        PositiveElemsOutput(b, nb, mb, out);
    }
    else if (a_mult == b_mult) {
        fprintf(out, "В матрице 'B' произведение элементов больше равно произведению элементов матрицы A, которые соответсвенно равны %g и %g\n", b_mult, a_mult);
        fprintf(out, "Кол-во положительных элементов в каждой строке матрицы B:\n");
        PositiveElemsOutput(b, nb, mb, out);
        fprintf(out, "Кол-во положительных элементов в каждой строке матрицы A:\n");
        PositiveElemsOutput(a, na, ma, out);
    }


    fclose(out);

    DeleteMatrix(a, na, ma);
    DeleteMatrix(b, nb, mb);

    fclose(out);


}