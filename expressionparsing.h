//
// Created by hp on 28.03.2022.
//

#ifndef MATLANGPROJECT_EXPRESSIONPARSING_H
#define MATLANGPROJECT_EXPRESSIONPARSING_H


char* convertIntegerToChar(int N);

int isNumber(char* arr) ;

int *transposeVector(int *vec);

int **transposeMatrix(int **mat);

int *addScalarToVector(int sca , int *vec);

int *subtractScalarFromVector(int sca , int *vec);

int *multiplyScalarWithVector(int sca , int *vec);

int **addScalarToMatrix(int sca , int **mat);

int **subtractScalarFromMatrix(int sca , int **mat);

int **multiplyScalarWithMatrix(int sca , int **mat);

int *vectorAddition(int *vec1 , int *vec2);

int *vectorSubtraction(int *vec1 , int *vec2);

int *vectorMultiplication(int *vec1 , int *vec2);

int **matrixAddition(int **mat1 , int **mat2);

int **matrixSubtraction(int **mat1 , int **mat2);

int **matrixMultiplication(int **mat1 , int **mat2);


char* expressionParsing(char* infix_exp);


#endif //MATLANGPROJECT_EXPRESSIONPARSING_H
