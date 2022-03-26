#include "parseutils.h"
#include "stringutils.h"
#include "structs.h"
#include "datastructures.h"
//
// Created by aesh on 3/21/2022.
//

int parseScalarDefinition(char *line) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    if (getLinkedListSize(head) != 2) {
        printf("SCALAR DEFINITION ERROR!\n");
        return 0;
    }
    char *identifier = getNodeData(head, 1);
    if (!isAlphaNumeric(identifier)) {
        return 0;
    }
    if (isVariableNameAlreadyUsed(identifier)) {
        return 0;
    }
    struct Scalar *scalar = malloc(sizeof(struct Scalar));
    scalar->id = identifier;
    appendToScalars(scalar);
    printf("float %s = 0;\n", identifier);
    return 1;
}

int parseVectorDefinition(char *line) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);

    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }

    if (getLinkedListSize(head) != 5) {
        printf("ERROR PARSING VECTOR DEFINITION\n");
        return 0;
    }
    char *identifier = getNodeData(head, 1);
    if (!isAlphaNumeric(identifier)) {
        return 0;
    }

    if(isVariableNameAlreadyUsed(identifier)) {
        return 0;
    }

    if (strcmp(getNodeData(head, 2), "[") != 0) {
        printf("MISSING LEFT BRACKET!\n");
        return 0;
    }

    if (!containsOnlyNumbers(getNodeData(head, 3))) {
        printf("VECTOR SIZE IS NOT NUMERIC!\n");
        return 0;
    }
    int size = strtol(getNodeData(head, 3), NULL, 10);

    if (strcmp(getNodeData(head, 4), "]") != 0) {
        printf("MISSING RIGHT BRACE!\n");
        return 0;
    }

    struct Vector *vector = malloc(sizeof(struct Vector));
    vector->id = identifier;
    vector->size = size;
    appendToVectors(vector);
    printf("float %s[%d];\n", identifier, size);
    initializeSingleDimensionalArray(identifier, size);
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
    struct Matrix *matrix = malloc(sizeof(struct Matrix));
    matrix->id = lexemeIdentifier;
    matrix->rowSize = strtol(rowSize, NULL, 10);
    matrix->columnSize = strtol(columnSize, NULL, 10);
    appendToMatrices(matrix);
    printf("int %s[%s][%s];\n", lexemeIdentifier, rowSize, columnSize);
    initializeMatrix(lexemeIdentifier, rowSize, columnSize);
    return 1;
}

void initializeSingleDimensionalArray(char *identifier, int size) {
    char *code = "for (int i = 0; i < %d; i++) {\n%s[i] = 0f;\n}\n";
    printf(code, size, identifier);
}

void initializeMatrix(char *identifier, char *rowSize, char *columnSize) {
    char *code = "for (int i = 0; i < %s; i++) {\n"
                 "    for (int j = 0; j < %s; j++) {\n"
                 "        %s[i][j] = 0\n    }\n"
                 "}\n";
    printf(code, rowSize, columnSize, identifier);
}