#include "parseutils.h"
#include "stringutils.h"
//
// Created by aesh on 3/21/2022.
//

int parseScalarDefinition(char *line) {
    char *lexemeIdentifier;
    int count = 0;
    char *temp = strtok(line, " ");
    while (temp != NULL) {
        lexemeIdentifier = temp;
        temp = strtok(NULL, " ");
        count++;
    }
    if (count != 2) {
        printf("ERROR PARSING SCALAR!!!");
        return 0;
    }
    stripSingleTrailingNewLineCharacter(lexemeIdentifier);
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
    printf("int %s[%s];\n", lexemeIdentifier, size);
    initializeSingleDimensionalArray(lexemeIdentifier, size);
    return 1;
}

void initializeSingleDimensionalArray(char *identifier, char *size) {
    char *code = "for (int i = 0; i < %s; i++) {\n%s[i] = 0;\n}\n";
    printf(code, size, identifier);
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
    printf("int %s[%s][%s];\n", lexemeIdentifier, rowSize, columnSize);
    initializeMatrix(lexemeIdentifier, rowSize, columnSize);
    return 1;
}

void initializeMatrix(char *identifier, char *rowSize, char* columnSize) {
    char* code = "for (int i = 0; i < %s; i++) {\n"
                 "    for (int j = 0; j < %s; j++) {\n"
                 "        %s[i][j] = 0\n    }\n"
                 "}\n";
    printf(code, rowSize, columnSize, identifier);
}