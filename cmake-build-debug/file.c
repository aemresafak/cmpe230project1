#include <malloc.h>
#include<string.h>
#include<stdio.h>

int choose(int a , int b , int c , int d)
{
    if(a == 0)
    {
        return b;
    }
    else if(a > 0)
    {
        return c;
    }

    return d;
}char* convertIntegerToChar(int N)
{
    int m = N;
    int digit = 0;
    while (m) {

        digit++;

        m /= 10;
    }

    char* arr;

    char arr1[digit];

    arr = (char*)malloc(digit);

    int index = 0;
    while (N) {

        arr1[++index] = N % 10 + '0';

        N /= 10;
    }

    int i;
    for (i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }

    arr[i] = '\0';

    return (char*)arr;
}

double **transposeVector(double *vec)
{
    int i = 0 , j = 0;

    int row = 1;
    int column = sizeof vec / sizeof vec[0];

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));


    for (j = 0; j < column; j++) {
        new_mat[0][j] = vec[j];
    }


    return new_mat;
}

double **transposeMatrix(double **mat)
{
    int i = 0 , j = 0;

    int row = sizeof(mat) / sizeof(mat[0]);
    int column = sizeof(mat[0]) / sizeof(mat[0][0]);

    double** new_mat = (double**)malloc(column * sizeof(double*));
    for (i = 0; i < column; i++)
        new_mat[i] = (double*)malloc(row * sizeof(double));

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            new_mat[j][i] = mat[i][j];
        }
    }

    return new_mat;
}


double *addScalarToVector(double sca , double *vec)
{
    int i = 0;
    int size = sizeof vec / sizeof vec[0];

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec[i] + sca;
    }

    return new_vec;

}

double *subtractScalarFromVector(double sca , double *vec)
{
    int i = 0;
    int size = sizeof vec / sizeof vec[0];

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec[i] - sca;
    }

    return new_vec;
}

double *subtractVectorFromScalar(double sca , double *vec)
{
    int i = 0;
    int size = sizeof vec / sizeof vec[0];

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = sca - vec[i];
    }

    return new_vec;
}

double *multiplyScalarWithVector(double sca , double *vec)
{
    int i = 0;
    int size = sizeof vec / sizeof vec[0];

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec[i] * sca;
    }

    return new_vec;
}

double **addScalarToMatrix(double sca , double **mat)
{
    int i = 0 , j = 0;

    int row = sizeof(mat) / sizeof(mat[0]);
    int column = sizeof(mat[0]) / sizeof(mat[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat[i][j] + sca;

    return new_mat;

}

double **subtractScalarFromMatrix(double sca , double **mat)
{
    int i = 0 , j = 0;

    int row = sizeof(mat) / sizeof(mat[0]);
    int column = sizeof(mat[0]) / sizeof(mat[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat[i][j] - sca;

    return new_mat;
}

double **subtractMatrixFromScalar(double sca , double **mat)
{
    int i = 0 , j = 0;

    int row = sizeof(mat) / sizeof(mat[0]);
    int column = sizeof(mat[0]) / sizeof(mat[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = sca - mat[i][j];

    return new_mat;
}

double **multiplyScalarWithMatrix(double sca , double **mat)
{
    int i = 0 , j = 0;

    int row = sizeof(mat) / sizeof(mat[0]);
    int column = sizeof(mat[0]) / sizeof(mat[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat[i][j] * sca;

    return new_mat;
}

double *vectorAddition(double *vec1 , double *vec2)
{
    int i = 0;
    int size = sizeof vec1 / sizeof vec1[0];

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec1[i] + vec2[i];
    }

    return new_vec;
}

double *vectorSubtraction(double *vec1 , double *vec2)
{
    int i = 0;
    int size = sizeof vec1 / sizeof vec1[0];

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec1[i] - vec2[i];
    }

    return new_vec;
}

double *vectorMultiplication(double *vec1 , double *vec2)
{
    int i = 0;
    int size = sizeof vec1 / sizeof vec1[0];

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec1[i] * vec2[i];
    }

    return new_vec;
}

double **matrixAddition(double **mat1 , double **mat2)
{
    int i = 0 , j = 0;

    int row = sizeof(mat1) / sizeof(mat1[0]);
    int column = sizeof(mat1[0]) / sizeof(mat1[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat1[i][j] + mat2[i][j];

    return new_mat;
}

double **matrixSubtraction(double **mat1 , double **mat2)
{
    int i = 0 , j = 0;

    int row = sizeof(mat1) / sizeof(mat1[0]);
    int column = sizeof(mat1[0]) / sizeof(mat1[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat1[i][j] - mat2[i][j];

    return new_mat;
}

double **matrixMultiplication(double **mat1 , double **mat2)
{
    int i = 0 , j = 0 , k = 0;

    int row1 = sizeof(mat1) / sizeof(mat1[0]);
    int column1 = sizeof(mat1[0]) / sizeof(mat1[0][0]);

    int row2 = sizeof(mat2) / sizeof(mat2[0]);
    int column2 = sizeof(mat2[0]) / sizeof(mat2[0][0]);

    double** new_mat = (double**)malloc(row1 * sizeof(double*));
    for (i = 0; i < row1; i++)
        new_mat[i] = (double*)malloc(column2 * sizeof(double));


    for (i = 0; i < row1; i++) {
        for (j = 0; j < column2; j++) {
            new_mat[i][j] = 0;
        }
    }

    for (i = 0; i < row1; i++) {
        for (j = 0; j < column2; j++) {
            for (k = 0; k < column1; k++) {
                new_mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return new_mat;
}

double **addVectorToMatrix(double *vec1 , double **mat1)
{
    int i = 0 , j = 0;

    int row = sizeof(mat1) / sizeof(mat1[0]);
    int column = sizeof(mat1[0]) / sizeof(mat1[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat1[i][j] + vec1[i];

    return new_mat;
}

double **subtractVectorFromMatrix(double *vec1 , double **mat1)
{
    int i = 0 , j = 0;

    int row = sizeof(mat1) / sizeof(mat1[0]);
    int column = sizeof(mat1[0]) / sizeof(mat1[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat1[i][j] - vec1[i];

    return new_mat;
}

double **subtractMatrixFromVector(double *vec1 , double **mat1)
{
    int i = 0 , j = 0;

    int row = sizeof(mat1) / sizeof(mat1[0]);
    int column = sizeof(mat1[0]) / sizeof(mat1[0][0]);

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = vec1[i] - mat1[i][j];

    return new_mat;
}int main() {
double A[4][4];
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        A[i][j] = 0;
    }
}
double x[4];
for (int i = 0; i < 4; i++) {
x[i] = 0;
}
double xy2[4];
for (int i = 0; i < 4; i++) {
xy2[i] = 0;
}
double s = 0;
A[0][0] = 0.000000;
A[0][1] = 1.000000;
A[0][2] = 2.000000;
A[0][3] = 3.000000;
A[1][0] = 4.000000;
A[1][1] = 5.000000;
A[1][2] = 6.000000;
A[1][3] = 7.000000;
A[2][0] = 8.000000;
A[2][1] = 9.000000;
A[2][2] = 1.000000;
A[2][3] = 1.000000;
A[3][0] = 1.000000;
A[3][1] = 2.000000;
A[3][2] = 3.000000;
A[3][3] = 4.000000;
x[0] = 1.000000;
x[1] = 1.000000;
x[2] = 1.000000;
x[3] = 1.000000;
xy2[0] = 2.000000;
xy2[1] = 1.000000;
xy2[2] = 3.000000;
xy2[3] = 1.000000;
