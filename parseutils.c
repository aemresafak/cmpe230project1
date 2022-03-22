#include "parseutils.h"
#include "stringutils.h"
#include "structs.h"
//
// Created by aesh on 3/21/2022.
//

int parseScalarDefinition(char *line) {
    char *lexemeIdentifier;
    int count = 0;
    char *temp = strtok(line, " \n");
    while (temp != NULL) {
        lexemeIdentifier = temp;
        temp = strtok(NULL, " \n");
        count++;
    }
    if (count != 2) {
        printf("ERROR PARSING SCALAR!!!");
        return 0;
    }
    if (isVariableNameAlreadyUsed(lexemeIdentifier)) {
        printf("SCALAR NAME ALREADY USED!\n");
        return 0;
    }
    struct Scalar* scalar = malloc(sizeof(struct Scalar));
    scalar->id = lexemeIdentifier;
    appendToScalars(scalar);
    printf("int %s = 0;\n", lexemeIdentifier);
    return 1;
}

int parseVectorDefinition(char *line) {
    char *lexemeIdentifier;
    char *size;
    int count = 0;
    char *temp = strtok(line, " ");
    while (temp != NULL) {
        if (count == 1)
            lexemeIdentifier = temp;
        else if (count == 2)
            size = temp;

        temp = strtok(NULL, " [\n");
        count++;
    }
    if (count != 3) {
        printf("ERROR PARSING VECTOR\n");
        return 0;
    }
    if (!endsWith(size, ']')) {
        printf("Size needs to end with ]\n");
        return 0;
    }
    size = stripFromEnd(size, ']');
    if (!containsOnlyNumbers(size)) {
        printf("SIZE MUST BE INTEGER.\n");
        return 0;
    }
    if (isVariableNameAlreadyUsed(lexemeIdentifier)) {
        printf("VECTOR NAME ALREADY USED!\n");
        return 0;
    }
    struct Vector *vector = malloc(sizeof(struct Vector));
    vector->id = lexemeIdentifier;
    vector->size = strtol(size, NULL, 10);
    appendToVectors(vector);
    printf("int %s[%s];\n", lexemeIdentifier, size);
    initializeSingleDimensionalArray(lexemeIdentifier, size);
    return 1;
}


int parseMatrixDefinition(char *line) {
    char *lexemeIdentifier;
    int count = 0;
    char *rowSize;
    char *columnSize;
    char *temp = strtok(line, " ");
    while (temp != NULL) {
        if (count == 1) {
            lexemeIdentifier = temp;
        } else if (count == 2) {
            rowSize = temp;
        } else if (count == 3) {
            columnSize = temp;
        }
        temp = strtok(NULL, " [\n,");
        count++;
    }
    if (count != 4) {
        printf("ERROR PARSING MATRIX\n");
        return 0;
    }
    if (!endsWith(columnSize, ']')) {
        printf("MATRIX NEEDS TO END WITH ]\n");
        return 0;
    }

    stripFromEnd(columnSize, ']');
    int areBothSizesInteger = containsOnlyNumbers(columnSize) && containsOnlyNumbers(rowSize);
    if (areBothSizesInteger != 1) {
        printf("COLUMN AND ROW SIZE MUST BE INTEGER.\n");
        return 0;
    }
    if (isVariableNameAlreadyUsed(lexemeIdentifier)) {
        printf("MATRIX NAME ALREADY USED!\n");
        return 0;
    }
    struct Matrix* matrix = malloc(sizeof(struct Matrix));
    matrix->id = lexemeIdentifier;
    matrix->rowSize = strtol(rowSize, NULL, 10);
    matrix->columnSize = strtol(columnSize, NULL, 10);
    appendToMatrices(matrix);
    printf("int %s[%s][%s];\n", lexemeIdentifier, rowSize, columnSize);
    initializeMatrix(lexemeIdentifier, rowSize, columnSize);
    return 1;
}

void initializeSingleDimensionalArray(char *identifier, char *size) {
    char *code = "for (int i = 0; i < %s; i++) {\n%s[i] = 0;\n}\n";
    printf(code, size, identifier);
}

void initializeMatrix(char *identifier, char *rowSize, char *columnSize) {
    char *code = "for (int i = 0; i < %s; i++) {\n"
                 "    for (int j = 0; j < %s; j++) {\n"
                 "        %s[i][j] = 0\n    }\n"
                 "}\n";
    printf(code, rowSize, columnSize, identifier);
}