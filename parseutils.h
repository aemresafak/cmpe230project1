//
// Created by aesh on 3/21/2022.
//

#ifndef MATLANGPROJECT_PARSEUTILS_H
#define MATLANGPROJECT_PARSEUTILS_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/**
 * Parse the scalar definition and output to file
 * @param line line to parse
 * @param size size of the line
 * @param f file to output
 * @return 1 if successful 0 if syntax error
 */
int parseScalarDefinition(char *line);

/**
 * Parse the vector definition and output
 * @param line vector definition line to parse
 * @return 1 if successful 0 if error
 */
int parseVectorDefinition(char *line);

/**
 * Create c code to initialize single dimensional array with 0's
 * @param identifier
 * @param size
 */
void initializeSingleDimensionalArray(char *identifier, char *size);

/**
 * Parse the given matrix definition
 * @param line
 * @return 1 if successful 0 otherwise
 */
int parseMatrixDefinition(char *line);

/**
 * Initialize given matrix with 0's
 * @param identifier name of the matrix
 * @param rowSize row size of matrix
 * @param columnSize column size of matrix
 */
void initializeMatrix(char *identifier, char *rowSize, char* columnSize);
#endif //MATLANGPROJECT_PARSEUTILS_H
