#include "definitionstatements.h"
#include "stringutils.h"
#include "structs.h"
#include "datastructures.h"
//
// Created by aesh on 3/21/2022.
//

int parseScalarDefinition(char *line, FILE *file) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    if (getLinkedListSize(head) != 2) {
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
    fprintf(file, "double %s = 0;\n", identifier);
    return 1;
}

int parseVectorDefinition(char *line, FILE *file) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);

    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }

    if (getLinkedListSize(head) != 5) {
        return 0;
    }
    char *identifier = getNodeData(head, 1);
    if (!isAlphaNumeric(identifier)) {
        return 0;
    }

    if (isVariableNameAlreadyUsed(identifier)) {
        return 0;
    }

    if (strcmp(getNodeData(head, 2), "[") != 0) {
        return 0;
    }

    if (!containsOnlyNumbers(getNodeData(head, 3))) {
        return 0;
    }
    int size = strtol(getNodeData(head, 3), NULL, 10);

    if (strcmp(getNodeData(head, 4), "]") != 0) {
        return 0;
    }

    struct Vector *vector = malloc(sizeof(struct Vector));
    vector->id = identifier;
    vector->size = size;
    appendToVectors(vector);
    char *code = "double* %s = (double*) malloc(%d * sizeof (double));\n";
    fprintf(file, code, identifier, size);
    initializeSingleDimensionalArray(identifier, size, file);
    return 1;
}


int parseMatrixDefinition(char *line, FILE *file) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);

    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }

    if (getLinkedListSize(head) != 7) {
        return 0;
    }

    char *identifier = getNodeData(head, 1);
    if (!isAlphaNumeric(identifier)) {
        return 0;
    }

    if (isVariableNameAlreadyUsed(identifier)) {
        return 0;
    }

    if (strcmp(getNodeData(head, 2), "[") != 0) {
        return 0;
    }

    if (!containsOnlyNumbers(getNodeData(head, 3))) {
        return 0;
    }

    int rowSize = strtol(getNodeData(head, 3), NULL, 10);

    if (strcmp(getNodeData(head, 4), ",") != 0) {
        return 0;
    }

    if (!containsOnlyNumbers(getNodeData(head, 5))) {
        return 0;
    }

    int columnSize = strtol(getNodeData(head, 5), NULL, 10);

    if (strcmp(getNodeData(head, 6), "]") != 0) {
        return 0;
    }

    struct Matrix *matrix = malloc(sizeof(struct Matrix));
    matrix->id = identifier;
    matrix->rowSize = rowSize;
    matrix->columnSize = columnSize;
    appendToMatrices(matrix);
    char *code =
            "double** %s = (double**)malloc(%d * sizeof(double*));\n"
            "    for (int _i = 0; _i < %d; _i++)\n"
            "        %s[_i] = (double*)malloc(%d * sizeof(double));\n";
    fprintf(file, code, identifier, rowSize, rowSize, identifier, columnSize);
    initializeMatrix(identifier, rowSize, columnSize, file);
    return 1;
}

void initializeSingleDimensionalArray(char *identifier, int size, FILE *file) {
    char *code = "for (int i = 0; i < %d; i++) {\n%s[i] = 0;\n}\n";
    fprintf(file, code, size, identifier);
}

void initializeMatrix(char *identifier, int rowSize, int columnSize, FILE *file) {
    char *code = "for (int i = 0; i < %d; i++) {\n"
                 "    for (int j = 0; j < %d; j++) {\n"
                 "        %s[i][j] = 0;\n    }\n"
                 "}\n";
    fprintf(file, code, rowSize, columnSize, identifier);
}