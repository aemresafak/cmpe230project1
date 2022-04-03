#include <malloc.h>
#include<string.h>
#include<stdio.h>
#include <math.h>

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

double **transposeVector(double *vec , int size)
{
    int i = 0 , j = 0;

    int row = 1;
    int column = size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));


    for (j = 0; j < column; j++) {
        new_mat[0][j] = vec[j];
    }


    return new_mat;
}

double **transposeMatrix(double **mat , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

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


double *addScalarToVector(double sca , double *vec , int v_size)
{
    int i = 0;
    int size = v_size;

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec[i] + sca;
    }

    return new_vec;

}

double *subtractScalarFromVector(double sca , double *vec , int v_size)
{
    int i = 0;
    int size = v_size;

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec[i] - sca;
    }

    return new_vec;
}

double *subtractVectorFromScalar(double sca , double *vec , int v_size)
{
    int i = 0;
    int size = v_size;

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = sca - vec[i];
    }

    return new_vec;
}

double *multiplyScalarWithVector(double sca , double *vec , int v_size)
{
    int i = 0;
    int size = v_size;

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec[i] * sca;
    }

    return new_vec;
}

double **addScalarToMatrix(double sca , double **mat , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat[i][j] + sca;

    return new_mat;

}

double **subtractScalarFromMatrix(double sca , double **mat , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat[i][j] - sca;

    return new_mat;
}

double **subtractMatrixFromScalar(double sca , double **mat , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = sca - mat[i][j];

    return new_mat;
}

double **multiplyScalarWithMatrix(double sca , double **mat , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat[i][j] * sca;

    return new_mat;
}

double *vectorAddition(double *vec1 , double *vec2 , int v_size)
{
    int i = 0;
    int size = v_size;

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec1[i] + vec2[i];
    }

    return new_vec;
}

double *vectorSubtraction(double *vec1 , double *vec2 , int v_size)
{
    int i = 0;
    int size = v_size;

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec1[i] - vec2[i];
    }

    return new_vec;
}

double *vectorMultiplication(double *vec1 , double *vec2 , int v_size)
{
    int i = 0;
    int size = v_size;

    double *new_vec = (double*) malloc(size * sizeof(double));

    for(i = 0 ; i < size ; i++)
    {
        new_vec[i] = vec1[i] * vec2[i];
    }

    return new_vec;
}

double **matrixAddition(double **mat1 , double **mat2 , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat1[i][j] + mat2[i][j];

    return new_mat;
}

double **matrixSubtraction(double **mat1 , double **mat2  , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat1[i][j] - mat2[i][j];

    return new_mat;
}

double **matrixMultiplication(double **mat1 , double **mat2 , int row_size1 , int column_size1 , int row_size2 , int column_size2)
{
    int i = 0 , j = 0 , k = 0;

    int row1 = row_size1;
    int column1 = column_size1;

    int row2 = row_size2;
    int column2 = column_size2;

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

double **addVectorToMatrix(double *vec1 , double **mat1 , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat1[i][j] + vec1[i];

    return new_mat;
}

double **subtractVectorFromMatrix(double *vec1 , double **mat1  , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = mat1[i][j] - vec1[i];

    return new_mat;
}

double **subtractMatrixFromVector(double *vec1 , double **mat1 , int row_size , int column_size)
{
    int i = 0 , j = 0;

    int row = row_size;
    int column = column_size;

    double** new_mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
        new_mat[i] = (double*)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            new_mat[i][j] = vec1[i] - mat1[i][j];

    return new_mat;
}

int main() {
double** A = (double**)malloc(3 * sizeof(double*));
    for (int _i = 0; _i < 3; _i++)
        A[_i] = (double*)malloc(3 * sizeof(double));
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        A[i][j] = 0;
    }
}
double* x = (double*) malloc(3 * sizeof (double));
for (int i = 0; i < 3; i++) {
x[i] = 0;
}
double* y = (double*) malloc(3 * sizeof (double));
for (int i = 0; i < 3; i++) {
y[i] = 0;
}
double r = 0;
double i = 0;
A[0][0] = 0.500000;
A[0][1] = 0.000000;
A[0][2] = 0.500000;
A[1][0] = 0.000000;
A[1][1] = 0.000000;
A[1][2] = 0.500000;
A[2][0] = 0.500000;
A[2][1] = 1.000000;
A[2][2] = 0.000000;
x[0] = 1.000000;
x[1] = 1.000000;
x[2] = 1.000000;
for ( i = 1 ; i <= 10; i += 1) {
    for (int _i = 0; _i < 3; _i++) {
        y[_i] = matrixMultiplication(A,transposeMatrix(transposeVector(x,3),1,3),3,3,3,1)[_i][0];
    }
r = sqrt(matrixMultiplication(transposeVector(vectorSubtraction(y,x,3),3),transposeMatrix(transposeVector(vectorSubtraction(y,x,3),3),1,3),1,3,3,1)[0][0]);
printf("%f\n", r);
for (int __i = 0; __i < 3; __i++) {
                x[__i] = y[__i];
            }
}
printf("----------\n");
for (int i = 0; i < 3; i++) {
	printf("%f\n",x[i]);
}
return 0;

}