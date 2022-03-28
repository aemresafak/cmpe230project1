//
// Created by hp on 28.03.2022.
//

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
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

    return -1;
}

struct Vector *transposeVector(struct Vector* vector)
{

    return NULL;
}

struct Matrix *transposeMatrix(struct Matrix* matrix)
{

    return NULL;
}


void expressionParsing(char* infix_exp , struct Scalar* scalar_result , struct Vector* vector_result , struct Matrix* matrix_result)
{
    struct node_for_dll* head = NULL;

    infixToPostfix(infix_exp , &head);

    struct node_for_dll* node = head;

    int scalar_count = 1;
    int vector_count = 1;
    int matrix_count = 1;

    while(node->next != NULL)
    {
        if(strlen(node->data) == 2 && node->data[0] == 't' && node->data[1] == 'r')
        {
            struct node_for_dll* prev = node->prev;

            if(isNumber(prev->data))
            {

            }
            else if(isVariableScalar(prev->data))
            {

            }
            else if(isVariableVector(prev->data))
            {

            }
            else
            {

            }

        }
        else if(strlen(node->data) == 4 && node->data[0] == 's' && node->data[1] == 'q' &&
                node->data[2] == 'r' == node->data[3] == 't')
        {

            struct node_for_dll* prev = node->prev;

            if(isNumber(prev->data))
            {

            }
            else
            {

            }


        }

        else if(isOperator(node->data[0]))
        {

        }

        else
        {
            node = node->next;
        }



    }
}