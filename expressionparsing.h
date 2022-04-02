//
// Created by hp on 28.03.2022.
//

#ifndef MATLANGPROJECT_EXPRESSIONPARSING_H
#define MATLANGPROJECT_EXPRESSIONPARSING_H


char* convertIntegerToChar(int N);

int isNumber(char* arr) ;

double **transposeVector(double *vec);

double **transposeMatrix(double **mat);

double *addScalarToVector(double sca , double *vec);

double *subtractScalarFromVector(double sca , double *vec);

double *subtractVectorFromScalar(double sca , double *vec);

double *multiplyScalarWithVector(double sca , double *vec);

double **addScalarToMatrix(double sca , double **mat);

double **subtractScalarFromMatrix(double sca , double **mat);

double **subtractMatrixFromScalar(double sca , double **mat);

double **multiplyScalarWithMatrix(double sca , double **mat);

double *vectorAddition(double *vec1 , double *vec2);

double *vectorSubtraction(double *vec1 , double *vec2);

double *vectorMultiplication(double *vec1 , double *vec2);

double **matrixAddition(double **mat1 , double **mat2);

double **matrixSubtraction(double **mat1 , double **mat2);

double **matrixMultiplication(double **mat1 , double **mat2);

double **addVectorToMatrix(double *vec1 , double **mat1);

double **subtractVectorFromMatrix(double *vec1 , double **mat1);

double **subtractMatrixFromVector(double *vec1 , double **mat1);


int* expressionParsing(char* infix_exp , struct node_for_dll** result);
/*
 * In case of an error , it returns 0
 * If there is no error , it returns 1 and updates result array to correct expression
 *
*/

#endif //MATLANGPROJECT_EXPRESSIONPARSING_H
