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

int *transposeVector(int *vec)
{
    return NULL;
}

int **transposeMatrix(int **mat)
{
    return NULL;
}


int *addScalarToVector(int sca , int *vec)
{
    return NULL;
}

int *subtractScalarFromVector(int sca , int *vec)
{
    return NULL;
}

int *multiplyScalarWithVector(int sca , int *vec)
{
    return NULL;
}

int **addScalarToMatrix(int sca , int **mat)
{
    return NULL;
}

int **subtractScalarFromMatrix(int sca , int **mat)
{
    return NULL;
}

int **multiplyScalarWithMatrix(int sca , int **mat)
{
    return NULL;
}

int *vectorAddition(int *vec1 , int *vec2)
{
    return NULL;
}

int *vectorSubtraction(int *vec1 , int *vec2)
{
    return NULL;
}

int *vectorMultiplication(int *vec1 , int *vec2)
{
    return NULL;
}

int **matrixAddition(int **mat1 , int **mat2)
{
    return NULL;
}

int **matrixSubtraction(int **mat1 , int **mat2)
{
    return NULL;
}

int **matrixMultiplication(int **mat1 , int **mat2)
{
    return NULL;
}

char* expressionParsing(char* infix_exp)
{
    struct node_for_dll* head = (struct node_for_dll*)malloc(sizeof(struct node_for_dll));

    strcpy(head->data , "");

    head->prev = NULL;
    head->next = NULL;


    infixToPostfix(infix_exp , &head);

    struct node_for_dll* node = head;

    char result[1024] = "";

    while(node->next != NULL)
    {
        if(strlen(node->data) == 2 && node->data[0] == 't' && node->data[1] == 'r')
        {
            struct node_for_dll* prev = node->prev;

            if(isNumber(prev->data))
            {
                strcat(result , prev->data);
            }
            else if(isVariableScalar(prev->data))
            {
                strcat(result , prev->data);
            }
            else if(isVariableVector(prev->data))
            {
                char temp_string[1024] = "transposeVector(";
                strcat(temp_string , prev->data);
                strcat(temp_string , ")");

                strcat(result , temp_string);
            }
            else if(isVariableMatrix(prev->data))
            {
                char temp_string[1024] = "transposeMatrix(";
                strcat(temp_string , prev->data);
                strcat(temp_string , ")");

                strcat(result , temp_string);
            }

            else
            {
                printf("ERROR\n");

                return "";
            }

            struct node_for_dll* new_node = (struct node_for_dll*)malloc(sizeof(struct node_for_dll));

            strcpy(new_node->data , result);

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

            if(isNumber(prev->data))
            {
                char temp_string[1024] = "sqrt(";
                strcat(temp_string , prev->data);
                strcat(temp_string , ")");

                strcat(result , temp_string);
            }
            else if(isVariableScalar(prev->data))
            {
                char temp_string[1024] = "sqrt(";
                strcat(temp_string , prev->data);
                strcat(temp_string , ")");

                strcat(result , temp_string);
            }
            else
            {
                printf("ERROR\n");

                return "";
            }

            struct node_for_dll* new_node = (struct node_for_dll*)malloc(sizeof(struct node_for_dll));

            strcpy(new_node->data , result);

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

            if(node->data[0] == '+')
            {
                if((isNumber(first->data) || isVariableScalar(first->data)) &&
                (isNumber(second->data) || isVariableScalar(second->data)))
                {
                    char temp_string[1024] = "(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , "+");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);
                }
                else if((isNumber(first->data) || isVariableScalar(first->data)) &&
                isVariableVector(second->data))
                {

                    char temp_string[1024] = "addScalarToVector(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if(isVariableVector(first->data) &&
                (isNumber(second->data) || isVariableScalar(second->data)))
                {

                    char temp_string[1024] = "addScalarToVector(";
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if((isNumber(first->data) || isVariableScalar(first->data)) &&
                        isVariableMatrix(second->data))
                {

                    char temp_string[1024] = "addScalarToMatrix(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if(isVariableMatrix(first->data) &&
                        (isNumber(second->data) || isVariableScalar(second->data)))
                {

                    char temp_string[1024] = "addScalarToMatrix(";
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if(isVariableVector(first->data) && isVariableVector(second->data))
                {

                    char temp_string[1024] = "vectorAddition(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }

                else if(isVariableMatrix(first->data) && isVariableVector(second->data))
                {

                }
                else if(isVariableVector(first->data) && isVariableMatrix(second->data))
                {

                }
                else if(isVariableMatrix(first->data) && isVariableMatrix(second->data))
                {
                    if(findMatrixById(first->data)->columnSize != findMatrixById(second->data)->rowSize)
                    {
                        printf("ERROR\n");
                    }
                    else
                    {
                        char temp_string[1024] = "matrixAddition(";
                        strcat(temp_string , first->data);
                        strcat(temp_string , ",");
                        strcat(temp_string , second->data);
                        strcat(temp_string , ")");

                        strcat(result , temp_string);
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
                if((isNumber(first->data) || isVariableScalar(first->data)) &&
                   (isNumber(second->data) || isVariableScalar(second->data)))
                {
                    char temp_string[1024] = "(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , "-");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);
                }
                else if((isNumber(first->data) || isVariableScalar(first->data)) &&
                        isVariableVector(second->data))
                {

                    char temp_string[1024] = "subtractScalarFromVector(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if(isVariableVector(first->data) &&
                        (isNumber(second->data) || isVariableScalar(second->data)))
                {

                    char temp_string[1024] = "subtractScalarFromVector(";
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if((isNumber(first->data) || isVariableScalar(first->data)) &&
                        isVariableMatrix(second->data))
                {

                    char temp_string[1024] = "subtractScalarFromMatrix(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if(isVariableMatrix(first->data) &&
                        (isNumber(second->data) || isVariableScalar(second->data)))
                {

                    char temp_string[1024] = "subtractScalarFromMatrix(";
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }

                else if(isVariableVector(first->data) && isVariableVector(second->data))
                {

                    char temp_string[1024] = "vectorSubtraction(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }

                else if(isVariableMatrix(first->data) && isVariableVector(second->data))
                {

                }
                else if(isVariableVector(first->data) && isVariableMatrix(second->data))
                {

                }
                else if(isVariableMatrix(first->data) && isVariableMatrix(second->data))
                {
                    if((findMatrixById(first->data)->rowSize != findMatrixById(second->data)->rowSize)
                    && (findMatrixById(first->data)->columnSize != findMatrixById(second->data)->columnSize))
                    {
                        printf("ERROR\n");

                        return "";
                    }
                    else
                    {
                        char temp_string[1024] = "matrixSubtraction(";
                        strcat(temp_string , first->data);
                        strcat(temp_string , ",");
                        strcat(temp_string , second->data);
                        strcat(temp_string , ")");

                        strcat(result , temp_string);
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

                if((isNumber(first->data) || isVariableScalar(first->data)) &&
                   (isNumber(second->data) || isVariableScalar(second->data)))
                {
                    char temp_string[1024] = "(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , "*");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);
                }
                else if((isNumber(first->data) || isVariableScalar(first->data)) &&
                        isVariableVector(second->data))
                {

                    char temp_string[1024] = "multiplyScalarWithVector(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if(isVariableVector(first->data) &&
                        (isNumber(second->data) || isVariableScalar(second->data)))
                {

                    char temp_string[1024] = "multiplyScalarWithVector(";
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if((isNumber(first->data) || isVariableScalar(first->data)) &&
                        isVariableMatrix(second->data))
                {

                    char temp_string[1024] = "multiplyScalarWithMatrix(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }
                else if(isVariableMatrix(first->data) &&
                        (isNumber(second->data) || isVariableScalar(second->data)))
                {

                    char temp_string[1024] = "multiplyScalarWithMatrix(";
                    strcat(temp_string , second->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , first->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }

                else if(isVariableVector(first->data) && isVariableVector(second->data))
                {

                    char temp_string[1024] = "vectorMultiplication(";
                    strcat(temp_string , first->data);
                    strcat(temp_string , ",");
                    strcat(temp_string , second->data);
                    strcat(temp_string , ")");

                    strcat(result , temp_string);

                }

                else if(isVariableMatrix(first->data) && isVariableVector(second->data))
                {

                }
                else if(isVariableVector(first->data) && isVariableMatrix(second->data))
                {

                }
                else if(isVariableMatrix(first->data) && isVariableMatrix(second->data))
                {
                    if(findMatrixById(first->data)->columnSize != findMatrixById(second->data)->rowSize)
                    {
                        printf("ERROR\n");

                        return "";
                    }
                    else
                    {
                        char temp_string[1024] = "matrixMultiplication(";
                        strcat(temp_string , first->data);
                        strcat(temp_string , ",");
                        strcat(temp_string , second->data);
                        strcat(temp_string , ")");

                        strcat(result , temp_string);
                    }
                }
                else
                {
                    printf("ERROR\n");

                    return "";

                }

            }

            struct node_for_dll* new_node = (struct node_for_dll*)malloc(sizeof(struct node_for_dll));

            strcpy(new_node->data , result);

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

    return result;

}