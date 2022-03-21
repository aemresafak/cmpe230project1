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
 * @return 1 if successfull 0 if syntax error
 */
int parseScalarDefinition(char* line);
#endif //MATLANGPROJECT_PARSEUTILS_H
