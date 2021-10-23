#include <cstdio>
#include <locale.h>
#include "Matrix_h.h"
#pragma warning (disable : 4996)


int main(int argc, char* argv[])
{
    double a[nmax][nmax], b[nmax][nmax];
    int ma, na, mb, nb;
    double a_mult, b_mult;
    FILE* out;

    setlocale(LC_ALL, "rus");

    if ((out = fopen("output.txt", "w")) == NULL)
    {
        printf("���������� ������� ���� ��� ������\n");
        return 0;
    }


    if (argc < 2)
    {
        printf("������������ ����������!\n");
        return 1;
    }

    if (!MatrixInput(a, &na, &ma, argv[1]))
        return 1;
    if (!MatrixInput(b, &nb, &mb, argv[2]))
        return 1;

    if (isZero(a, na, ma))
        a_mult = 0;
    else
        a_mult = MatrixMultiply(a, na, ma);

    if (isZero(b, nb, mb))
        b_mult = 0;
    else
        b_mult = MatrixMultiply(b, nb, mb);

    fprintf(out, "�������� ������:\n\n������ A:\n");
    if (!OutputMatrix(a, na, ma, out))
        return 1;

    fprintf(out, "�������� ������:\n\n������ B:\n");
    if (!OutputMatrix(b, nb, mb, out))
        return 1;

    if (a_mult == 0 && b_mult == 0) {
        fprintf(out, "� �������� A � 'B' ��� �������� ����� ����.");
    }
    else if (a_mult == 0) {
        fprintf(out, "� ������� A ��� �������� ����� ����.\n");
        fprintf(out, "���-�� ������������� ��������� � ������ ������ ������� B:\n");
        PositiveElemsOutput(a, na, ma, out);

    }
    else if (b_mult == 0) {
        fprintf(out, "� ������� 'B' ��� �������� ����� ����.\n");
        fprintf(out, "���-�� ������������� ��������� � ������ ������ ������� A:\n");
        PositiveElemsOutput(b, nb, mb, out);
    }
    else if (a_mult > b_mult) {
        fprintf(out, "� ������� A ������������ ��������� ������ ��� ������������ ��������� ������� 'B', ������� ������������� ����� %g � %g\n", a_mult, b_mult);
        fprintf(out, "���-�� ������������� ��������� � ������ ������ ������� A:\n");
        PositiveElemsOutput(a, na, ma, out);
    }
    else if (a_mult < b_mult) {
        fprintf(out, "� ������� 'B' ������������ ��������� ������ ��� ������������ ��������� ������� A, ������� ������������� ����� %g � %g\n", b_mult, a_mult);
        fprintf(out, "���-�� ������������� ��������� � ������ ������ ������� B:\n");
        PositiveElemsOutput(b, nb, mb, out);
    }
    else if (a_mult == b_mult) {
        fprintf(out, "� ������� 'B' ������������ ��������� ������ ����� ������������ ��������� ������� A, ������� ������������� ����� %g � %g\n", b_mult, a_mult);
        fprintf(out, "���-�� ������������� ��������� � ������ ������ ������� B:\n");
        PositiveElemsOutput(b, nb, mb, out);
        fprintf(out, "���-�� ������������� ��������� � ������ ������ ������� A:\n");
        PositiveElemsOutput(a, na, ma, out);
    }


    /*if (!ResultsProcessing(a, b, &na, &ma, &nb, &mb, a_mult, b_mult))
        return 1;*/
    fclose(out);

}