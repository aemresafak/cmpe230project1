#include "definitionstatements.h"
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
    printf("double %s = 0;\n", identifier);
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
    printf("double %s[%d];\n", identifier, size);
    initializeSingleDimensionalArray(identifier, size);
    return 1;
}


int parseMatrixDefinition(char *line) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);

    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }

    if (getLinkedListSize(head) != 7) {
        printf("ERROR PARSING MATRIX DEFINITION\n");
        return 0;
    }

    char* identifier = getNodeData(head, 1);
    if (!isAlphaNumeric(identifier)) {
        return 0;
    }

    if (isVariableNameAlreadyUsed(identifier)) {
        return 0;
    }

    if (strcmp(getNodeData(head, 2), "[") != 0) {
        printf("MISSING LEFT BRACKET\n");
        return 0;
    }

    if (!containsOnlyNumbers(getNodeData(head, 3))) {
        printf("SIZE IS NOT NUMERIC!\n");
        return 0;
    }

    int rowSize = strtol(getNodeData(head, 3), NULL, 10);

    if (strcmp(getNodeData(head, 4), ",") != 0) {
        printf("MISSING COMMA \n");
        return 0;
    }

    if (!containsOnlyNumbers(getNodeData(head, 5))) {
        printf("SIZE IS NOT NUMERIC!\n");
        return 0;
    }

    int columnSize = strtol(getNodeData(head, 5), NULL, 10);

    if (strcmp(getNodeData(head, 6), "]") != 0) {
        printf("MISSING RIGHT BRACKET \n");
        return 0;
    }

    struct Matrix *matrix = malloc(sizeof(struct Matrix));
    matrix->id = identifier;
    matrix->rowSize = rowSize;
    matrix->columnSize = columnSize;
    appendToMatrices(matrix);
    printf("double %s[%d][%d];\n", identifier, rowSize, columnSize);
    initializeMatrix(identifier, rowSize, columnSize);
    return 1;
}

void initializeSingleDimensionalArray(char *identifier, int size) {
    char *code = "for (int i = 0; i < %d; i++) {\n%s[i] = 0;\n}\n";
    printf(code, size, identifier);
}

void initializeMatrix(char *identifier, int rowSize, int columnSize) {
    char *code = "for (int i = 0; i < %d; i++) {\n"
                 "    for (int j = 0; j < %d; j++) {\n"
                 "        %s[i][j] = 0;\n    }\n"
                 "}\n";
    printf(code, rowSize, columnSize, identifier);
}