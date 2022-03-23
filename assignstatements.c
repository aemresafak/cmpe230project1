//
// Created by aesh on 3/23/2022.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "assignstatements.h"
#include "structs.h"
#include "stringutils.h"

int isVectorAssignment(char *line) {
    char copiedLine[256];
    strcpy(copiedLine, line);
    int count = 0;
    char *lexemeIdentifier;
    char *equalSign;
    char *temp = strtok(copiedLine, " ");
    while (temp != NULL) {
        if (count == 0) {
            lexemeIdentifier = temp;
        } else if (count == 1) {
            equalSign = temp;
            break;
        }
        count++;
        temp = strtok(NULL, " ");
    }
    if (isVariableVector(lexemeIdentifier) == 1 && strcmp(equalSign, "=") == 0)
        return 1;
    else
        return 0;
}

int isMatrixAssignment(char *line) {
    char copiedLine[256];
    strcpy(copiedLine, line);
    int count = 0;
    char *lexemeIdentifier;
    char *equalSign;
    char *temp = strtok(copiedLine, " ");
    while (temp != NULL) {
        if (count == 0) {
            lexemeIdentifier = temp;
        } else if (count == 1) {
            equalSign = temp;
            break;
        }
        count++;
        temp = strtok(NULL, " ");
    }
    if (isVariableMatrix(lexemeIdentifier) == 1 && strcmp(equalSign, "=") == 0)
        return 1;
    else
        return 0;
}

int parseMatrixAssignment(char *line) {
    int count = 0;
    char *lexemeIdentifier;
    struct Matrix *matrix;
    int values[1024];
    int valueCount;
    int valueIndex = 0;
    int flagEncounteredRightBrace = 0;
    char *temp = strtok(line, " \n");
    while (temp != NULL) {
        if (count == 0) {
            lexemeIdentifier = temp;
            matrix = findMatrixById(lexemeIdentifier);
            valueCount = matrix->columnSize * matrix->rowSize;
        } else if (count > 2) {
            if (strcmp(temp, "}") == 0) {
                flagEncounteredRightBrace = 1;
                break;
            }
            if (!containsOnlyNumbers(temp)) {
                printf("ASSIGNMENT MUST CONTAIN ONLY CONSTANTS\n");
                return 0;
            }
            values[valueIndex] = strtol(temp, NULL, 10);
            valueIndex++;
        }
        count++;
        temp = strtok(NULL, " \n");
    }
    if (!flagEncounteredRightBrace) {
        printf("MISSING RIGHT BRACE\n");
        return 0;
    }
    if (count != (valueCount + 3)) {
        printf("ERROR PARSING MATRIX ASSIGNMENT\n");
        return 0;
    }


    int newCount = 0;
    for (int i = 0; i < matrix->rowSize; i++) {
        for (int j = 0; j < matrix->columnSize; j++) {
            printf("%s[%d][%d] = %d;\n", matrix->id, i, j, values[newCount]);
            newCount++;
        }
    }


    return 1;
}

int parseVectorAssignment(char* line) {
    int count = 0;
    char *lexemeIdentifier;
    struct Vector *vector;
    int values[1024];
    int valueCount;
    int valueIndex = 0;
    int flagEncounteredRightBrace = 0;
    char *temp = strtok(line, " \n");
    while (temp != NULL) {
        if (count == 0) {
            lexemeIdentifier = temp;
            vector = findVectorById(lexemeIdentifier);
            valueCount = vector->size;
        } else if (count > 2) {
            if (strcmp(temp, "}") == 0) {
                flagEncounteredRightBrace = 1;
                break;
            }
            if (!containsOnlyNumbers(temp)) {
                printf("ASSIGNMENT MUST CONTAIN ONLY CONSTANTS\n");
                return 0;
            }
            values[valueIndex] = strtol(temp, NULL, 10);
            valueIndex++;
        }
        count++;
        temp = strtok(NULL, " \n");
    }
    if (!flagEncounteredRightBrace) {
        printf("MISSING RIGHT BRACE\n");
        return 0;
    }
    if (count != (valueCount + 3)) {
        printf("ERROR PARSING VECTOR ASSIGNMENT\n");
        return 0;
    }


    for (int i = 0; i < valueCount; i++) {
        printf("%s[%d] = %d;\n", lexemeIdentifier, i, values[i]);
    }


    return 1;
}