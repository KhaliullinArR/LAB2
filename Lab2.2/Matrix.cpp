#include <iostream>
#pragma warning(disable : 4996)


//void PositiveElemsOutput(double **a, int na, int ma, FILE* out) {
//    for (int i = 0; i < na; i++) {
//        fprintf(out, "%3d - ??????: %2d\n", i + 1, PositiveElemsInRow(a[i], ma));
//    }
//}

bool isZero(double **a, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0)return false;
        }
    return true;
}

double MatrixMultiply(double **a, int n, int m) {
    double s = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0)s *= a[i][j];
        }
    return s;
}

void PositiveElemsOutput(double **a, int n, int m, FILE* out) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (a[i][j] > 0)num++;
        fprintf(out, "%3d - ??????: %2d\n", i + 1, num);
        num = 0;
    }
    return;
}


void DeleteMatrix(double** a, int n, int m) {
    for (int i = 0; i < n; i++)
        delete[] * (a + i);
    delete[] a;

    a = 0;
}


void MatrixInput(double **&a, int* n, int* m, const char* fname) {
    FILE* file;

    if ((file = fopen(fname, "r")) == NULL)
    {
        printf("?????????? ??????? ???? '%s'\n", fname);
        a = 0;
        return;
    }
    if (fscanf(file, "%d%d", n, m) < 2)
    {
        printf("?????? ?????? ?? ????? '%s'\n", fname);
        fclose(file);
        a = 0;
        return;
    }
    if (*m < 0 || *n < 0 )
    {
        printf("?????????? ????? ? ???????? ??????? ?????? ???? ?????? 1!\n");
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
                printf("?? ?????????? ?????? ??? ????????? ??????? ? ????? %s.", fname);
                a = 0;
                return;
            }
        }
    


    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (fscanf(file, "%lf", a[i]+j) < 1){
                printf("?????? ?????? ?? ????? '%s'\n", fname);
                fclose(file);
                a = 0;
                return;
            }
    }
    catch (std::bad_alloc) {
        printf("?? ?????????? ?????? ??? ????????? ??????? ? ????? %s.", fname);
        a = 0;
        return;
    }
    fclose(file);

    return;
}


int MatrixOutput(double **a,int n, int m, FILE* file) {


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fprintf(file, "%-6g ", a[i][j]);
        fprintf(file, "\n");
    }

    fprintf(file, "\n");

    return 0;
}