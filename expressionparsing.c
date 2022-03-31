//
// Created by hp on 28.03.2022.
//

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "infixtopostfix.h"
#include "structs.h"

char* convertIntegerToChar(int N)
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

int isNumber(char* arr) {

    int i;
    int len = strlen(arr);

    for (i = 0; i < len; i++)
    {
        if (!isdigit(arr[i]))
        {
            return 0;
        }
    }

    return 1;
}

double *transposeVector(double *vec)
{
    return NULL;
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

char* expressionParsing(char* infix_exp)
{
    struct node_for_dll* head = (struct node_for_dll*)malloc(sizeof(struct node_for_dll));

    strcpy(head->data , "");

    head->prev = NULL;
    head->next = NULL;


    infixToPostfix(infix_exp , &head);

    struct node_for_dll* node = head;


    while(node != NULL)
    {
        if(strlen(node->data) == 2 && node->data[0] == 't' && node->data[1] == 'r')
        {
            struct node_for_dll* prev = node->prev;
            char temp_string[1024] = "";

            struct node_for_dll* new_node = (struct node_for_dll*)malloc(sizeof(struct node_for_dll));

            if(isNumber(prev->data))
            {
                strcat(temp_string , prev->data);
            }
            else if(isVariableScalar(prev->data))
            {
                strcat(temp_string , prev->data);
            }
            else if(prev->is_scalar == 1)
            {
                strcat(temp_string , prev->data);

                new_node->is_scalar = 1;
            }
            else if(isVariableVector(prev->data) || prev->is_vector == 1)
            {
                strcat(temp_string , "transposeVector(");
                strcat(temp_string , prev->data);
                strcat(temp_string , ")");

                new_node->is_vector = 1;

                int size;
                if(prev->is_vector == 1)
                {
                   size = prev->size;
                }
                else
                {
                    size = findVectorById(prev->data)->size;
                }

                new_node->size = size;
            }
            else if(isVariableMatrix(prev->data) || prev->is_matrix == 1)
            {
                strcat(temp_string , "transposeMatrix(");
                strcat(temp_string , prev->data);
                strcat(temp_string , ")");

                new_node->is_matrix = 1;

                int row_size , column_size;
                if(prev->is_matrix == 1)
                {
                    row_size = prev->row_size;
                    column_size = prev->column_size;
                }
                else
                {
                    row_size = findMatrixById(prev->data)->rowSize;
                    column_size = findMatrixById(prev->data)->columnSize;
                }

                new_node->row_size = row_size;
                new_node->column_size = column_size;
            }

            else
            {
                printf("ERROR\n");

                return "";
            }


            prev->prev->next = new_node;
            new_node->prev = prev->prev;


            node = node->next;
            new_node->next = node;
            node->prev = new_node;


        }
        else if(strlen(node->data) == 4 && node->data[0] == 's' && node->data[1] == 'q' &&
                node->data[2] == 'r' == node->data[3] == 't')
        {

            struct node_for_dll* prev = node->prev;

            char temp_string[1024] = "";

            struct node_for_dll* new_node = (struct node_for_dll*)malloc(sizeof(struct node_for_dll));

            if(isNumber(prev->data) || isVariableScalar(prev->data) || prev->is_scalar == 1)
            {
                strcat(temp_string , "sqrt(");
                strcat(temp_string , prev->data);
                strcat(temp_string , ")");

                new_node->is_scalar = 1;
            }
            else
            {
                printf("ERROR\n");

                return "";
            }

            prev->prev->next = new_node;
            new_node->prev = prev->prev;


            node = node->next;
            new_node->next = node;
            node->prev = new_node;

        }

        else if(isOperator(node->data[0]))
        {
            struct node_for_dll* first = node->prev->prev;
            struct node_for_dll* second = node->prev;

            char temp_string[1024] = "";

            struct node_for_dll* new_node = (struct node_for_dll*)malloc(sizeof(struct node_for_dll));

            if(node->data[0] == '+')
            {
                if((isNumber(first->data) || isVariableScalar(first->data) || first->is_scalar) &&
                (isNumber(second->data) || isVariableScalar(second->data) || second->is_scalar))
                {

                    strcat(temp_string , "(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , "+");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_scalar = 1;
                }
                else if((isNumber(first->data) || isVariableScalar(first->data) || first->is_scalar) &&
                        (isVariableVector(second->data) || second->is_vector))
                {

                    strcat(temp_string , "addScalarToVector(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;

                    int size;
                    if(second->is_vector == 1)
                    {
                        size = second->size;
                    }
                    else
                    {
                        size = findVectorById(second->data)->size;
                    }

                    new_node->size = size;

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                (isNumber(second->data) || isVariableScalar(second->data) || second->is_scalar))
                {

                    strcat(temp_string , "addScalarToVector(");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;

                    int size;
                    if(first->is_vector == 1)
                    {
                        size = first->size;
                    }
                    else
                    {
                        size = findVectorById(first->data)->size;
                    }

                    new_node->size = size;

                }
                else if((isNumber(first->data) || isVariableScalar(first->data) || first-> is_scalar) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {

                    strcat(temp_string , "addScalarToMatrix(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_matrix = 1;

                    int row_size , column_size;
                    if(second->is_matrix == 1)
                    {
                        row_size = second->row_size;
                        column_size = second->column_size;
                    }
                    else
                    {
                        row_size = findMatrixById(second->data)->rowSize;
                        column_size = findMatrixById(second->data)->columnSize;
                    }

                    new_node->row_size = row_size;
                    new_node->column_size = column_size;

                }
                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isNumber(second->data) || isVariableScalar(second->data) || second->is_matrix))
                {

                    strcat(temp_string , "addScalarToMatrix(");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    new_node->is_matrix = 1;

                    int row_size , column_size;
                    if(first->is_matrix == 1)
                    {
                        row_size = first->row_size;
                        column_size = first->column_size;
                    }
                    else
                    {
                        row_size = findMatrixById(first->data)->rowSize;
                        column_size = findMatrixById(first->data)->columnSize;
                    }

                    new_node->row_size = row_size;
                    new_node->column_size = column_size;

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                (isVariableVector(second->data) || second->is_vector))
                {
                    int size1;
                    if(first->is_vector == 1)
                    {
                        size1 = first->size;
                    }
                    else
                    {
                        size1 = findVectorById(first->data)->size;
                    }

                    int size2;
                    if(second->is_vector == 1)
                    {
                        size2 = second->size;
                    }
                    else
                    {
                        size2 = findVectorById(second->data)->size;
                    }

                    if(size1 != size2)
                    {
                        printf("ERROR\n");

                        return "";
                    }

                    strcat(temp_string , "vectorAddition(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;
                    new_node->size = size1;

                }

                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isVariableVector(second->data) || second->is_vector))
                {

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {

                }
                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {
                    int row_size1 , column_size1;
                    if(first->is_matrix == 1)
                    {
                        row_size1 = first->row_size;
                        column_size1 = first->column_size;
                    }
                    else
                    {
                        row_size1 = findMatrixById(first->data)->rowSize;
                        column_size1 = findMatrixById(first->data)->columnSize;
                    }

                    int row_size2 , column_size2;
                    if(second->is_matrix == 1)
                    {
                        row_size2 = second->row_size;
                        column_size2 = second->column_size;
                    }
                    else
                    {
                        row_size2 = findMatrixById(second->data)->rowSize;
                        column_size2 = findMatrixById(second->data)->columnSize;
                    }

                    if(row_size1 != row_size2 || column_size1 != column_size2)
                    {
                        printf("ERROR\n");

                        return "";
                    }

                    else
                    {
                        strcat(temp_string , "matrixAddition(");
                        strcat(temp_string , first->data);
                        strcat(temp_string , ",");
                        strcat(temp_string , second->data);
                        strcat(temp_string , ")");

                        new_node->is_matrix = 1;

                        new_node->row_size = row_size1;
                        new_node->column_size = row_size2;
                    }
                }
                else
                {
                    printf("ERROR\n");

                    return "";
                }
            }
            else if(node->data == '-')
            {
                if((isNumber(first->data) || isVariableScalar(first->data) || first->is_scalar) &&
                   (isNumber(second->data) || isVariableScalar(second->data) || second->is_scalar))
                {

                    strcat(temp_string , "(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , "-");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_scalar = 1;
                }
                else if((isNumber(first->data) || isVariableScalar(first->data) || first->is_scalar) &&
                        (isVariableVector(second->data) || second->is_vector))
                {

                    strcat(temp_string , "subtractScalarFromVector(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;

                    int size;
                    if(second->is_vector == 1)
                    {
                        size = second->size;
                    }
                    else
                    {
                        size = findVectorById(second->data)->size;
                    }

                    new_node->size = size;

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                        (isNumber(second->data) || isVariableScalar(second->data) || second->is_scalar))
                {

                    strcat(temp_string , "subtractScalarFromVector(");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;

                    int size;
                    if(first->is_vector == 1)
                    {
                        size = first->size;
                    }
                    else
                    {
                        size = findVectorById(first->data)->size;
                    }

                    new_node->size = size;

                }
                else if((isNumber(first->data) || isVariableScalar(first->data) || first-> is_scalar) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {

                    strcat(temp_string , "subtractScalarFromMatrix(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_matrix = 1;

                    int row_size , column_size;
                    if(second->is_matrix == 1)
                    {
                        row_size = second->row_size;
                        column_size = second->column_size;
                    }
                    else
                    {
                        row_size = findMatrixById(second->data)->rowSize;
                        column_size = findMatrixById(second->data)->columnSize;
                    }

                    new_node->row_size = row_size;
                    new_node->column_size = column_size;

                }
                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isNumber(second->data) || isVariableScalar(second->data) || second->is_matrix))
                {

                    strcat(temp_string , "subtractScalarFromMatrix(");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    new_node->is_matrix = 1;

                    int row_size , column_size;
                    if(first->is_matrix == 1)
                    {
                        row_size = first->row_size;
                        column_size = first->column_size;
                    }
                    else
                    {
                        row_size = findMatrixById(first->data)->rowSize;
                        column_size = findMatrixById(first->data)->columnSize;
                    }

                    new_node->row_size = row_size;
                    new_node->column_size = column_size;

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                        (isVariableVector(second->data) || second->is_vector))
                {
                    int size1;
                    if(first->is_vector == 1)
                    {
                        size1 = first->size;
                    }
                    else
                    {
                        size1 = findVectorById(first->data)->size;
                    }

                    int size2;
                    if(second->is_vector == 1)
                    {
                        size2 = second->size;
                    }
                    else
                    {
                        size2 = findVectorById(second->data)->size;
                    }

                    if(size1 != size2)
                    {
                        printf("ERROR\n");

                        return "";
                    }

                    strcat(temp_string , "vectorSubtraction(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;
                    new_node->size = size1;

                }

                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isVariableVector(second->data) || second->is_vector))
                {

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {

                }
                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {
                    int row_size1 , column_size1;
                    if(first->is_matrix == 1)
                    {
                        row_size1 = first->row_size;
                        column_size1 = first->column_size;
                    }
                    else
                    {
                        row_size1 = findMatrixById(first->data)->rowSize;
                        column_size1 = findMatrixById(first->data)->columnSize;
                    }

                    int row_size2 , column_size2;
                    if(second->is_matrix == 1)
                    {
                        row_size2 = second->row_size;
                        column_size2 = second->column_size;
                    }
                    else
                    {
                        row_size2 = findMatrixById(second->data)->rowSize;
                        column_size2 = findMatrixById(second->data)->columnSize;
                    }

                    if(row_size1 != row_size2 || column_size1 != column_size2)
                    {
                        printf("ERROR\n");

                        return "";
                    }

                    else
                    {
                        strcat(temp_string , "matrixSubtraction(");
                        strcat(temp_string , first->data);
                        strcat(temp_string , ",");
                        strcat(temp_string , second->data);
                        strcat(temp_string , ")");

                        new_node->is_matrix = 1;

                        new_node->row_size = row_size1;
                        new_node->column_size = row_size2;
                    }
                }
                else
                {
                    printf("ERROR\n");

                    return "";
                }
            }
            else
            {

                if((isNumber(first->data) || isVariableScalar(first->data) || first->is_scalar) &&
                   (isNumber(second->data) || isVariableScalar(second->data) || second->is_scalar))
                {

                    strcat(temp_string , "(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , "*");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_scalar = 1;
                }
                else if((isNumber(first->data) || isVariableScalar(first->data) || first->is_scalar) &&
                        (isVariableVector(second->data) || second->is_vector))
                {

                    strcat(temp_string , "multiplyScalarWithVector(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;

                    int size;
                    if(second->is_vector == 1)
                    {
                        size = second->size;
                    }
                    else
                    {
                        size = findVectorById(second->data)->size;
                    }

                    new_node->size = size;

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                        (isNumber(second->data) || isVariableScalar(second->data) || second->is_scalar))
                {

                    strcat(temp_string , "multiplyScalarWithVector(");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;

                    int size;
                    if(first->is_vector == 1)
                    {
                        size = first->size;
                    }
                    else
                    {
                        size = findVectorById(first->data)->size;
                    }

                    new_node->size = size;

                }
                else if((isNumber(first->data) || isVariableScalar(first->data) || first-> is_scalar) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {

                    strcat(temp_string , "multiplyScalarWithMatrix(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_matrix = 1;

                    int row_size , column_size;
                    if(second->is_matrix == 1)
                    {
                        row_size = second->row_size;
                        column_size = second->column_size;
                    }
                    else
                    {
                        row_size = findMatrixById(second->data)->rowSize;
                        column_size = findMatrixById(second->data)->columnSize;
                    }

                    new_node->row_size = row_size;
                    new_node->column_size = column_size;

                }
                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isNumber(second->data) || isVariableScalar(second->data) || second->is_matrix))
                {

                    strcat(temp_string , "multiplyScalarWithMatrix(");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    new_node->is_matrix = 1;

                    int row_size , column_size;
                    if(first->is_matrix == 1)
                    {
                        row_size = first->row_size;
                        column_size = first->column_size;
                    }
                    else
                    {
                        row_size = findMatrixById(first->data)->rowSize;
                        column_size = findMatrixById(first->data)->columnSize;
                    }

                    new_node->row_size = row_size;
                    new_node->column_size = column_size;

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                        (isVariableVector(second->data) || second->is_vector))
                {
                    int size1;
                    if(first->is_vector == 1)
                    {
                        size1 = first->size;
                    }
                    else
                    {
                        size1 = findVectorById(first->data)->size;
                    }

                    int size2;
                    if(second->is_vector == 1)
                    {
                        size2 = second->size;
                    }
                    else
                    {
                        size2 = findVectorById(second->data)->size;
                    }

                    if(size1 != size2)
                    {
                        printf("ERROR\n");

                        return "";
                    }

                    strcat(temp_string , "vectorMultiplication(");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    new_node->is_vector = 1;
                    new_node->size = size1;

                }

                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isVariableVector(second->data) || second->is_vector))
                {

                }
                else if((isVariableVector(first->data) || first->is_vector) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {

                }
                else if((isVariableMatrix(first->data) || first->is_matrix) &&
                        (isVariableMatrix(second->data) || second->is_matrix))
                {
                    int row_size1 , column_size1;
                    if(first->is_matrix == 1)
                    {
                        row_size1 = first->row_size;
                        column_size1 = first->column_size;
                    }
                    else
                    {
                        row_size1 = findMatrixById(first->data)->rowSize;
                        column_size1 = findMatrixById(first->data)->columnSize;
                    }

                    int row_size2 , column_size2;
                    if(second->is_matrix == 1)
                    {
                        row_size2 = second->row_size;
                        column_size2 = second->column_size;
                    }
                    else
                    {
                        row_size2 = findMatrixById(second->data)->rowSize;
                        column_size2 = findMatrixById(second->data)->columnSize;
                    }

                    if(column_size1 != row_size2)
                    {
                        printf("ERROR\n");

                        return "";
                    }

                    else
                    {
                        strcat(temp_string , "matrixMultiplication(");
                        strcat(temp_string , first->data);
                        strcat(temp_string , ",");
                        strcat(temp_string , second->data);
                        strcat(temp_string , ")");

                        new_node->is_matrix = 1;

                        new_node->row_size = row_size1;
                        new_node->column_size = row_size2;
                    }
                }
                else
                {
                    printf("ERROR\n");

                    return "";
                }

            }


            first->prev->next = new_node;
            new_node->prev = first->prev;


            node = node->next;
            new_node->next = node;
            node->prev = new_node;
        }

        else
        {
            node = node->next;
        }

    }

    return head->next->data;

}