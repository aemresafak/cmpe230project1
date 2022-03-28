//
// Created by hp on 28.03.2022.
//

#ifndef MATLANGPROJECT_EXPRESSIONPARSING_H
#define MATLANGPROJECT_EXPRESSIONPARSING_H


char* convertIntegerToChar(int N);

int isNumber(char* arr) ;

struct Vector *transposeVector(struct Vector* vector);

struct Matrix *transposeMatrix(struct Matrix* matrix);

void expressionParsing(char* infix_exp , struct Scalar* scalar_result , struct Vector* vector_result , struct Matrix* matrix_result);


#endif //MATLANGPROJECT_EXPRESSIONPARSING_H
