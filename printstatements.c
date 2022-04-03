//
// Created by aesh on 3/27/2022.
//

#include <string.h>
#include <stdio.h>
#include "printstatements.h"
#include "datastructures.h"
#include "structs.h"

int isPrintIdStatement(char *line) {
    char *cpy = strdup(line);
    char *temp = strtok(cpy, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }

    if (getLinkedListSize(head) != 4)
        return 0;
    if (strcmp(getNodeData(head, 0), "print") != 0)
        return 0;
    if (strcmp(getNodeData(head, 1), "(") != 0)
        return 0;
    char *identifier = getNodeData(head, 2);
    if (!isVariableNameAlreadyUsed(identifier))
        return 0;
    if (strcmp(getNodeData(head, 3), ")") != 0)
        return 0;

    return 1;
}

int isPrintSepStatement(char *line) {
    char *cpy = strdup(line);
    char *temp = strtok(cpy, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    if (getLinkedListSize(head) != 3)
        return 0;
    if (strcmp(getNodeData(head, 0), "printsep") != 0)
        return 0;
    if (strcmp(getNodeData(head, 1), "(") != 0)
        return 0;
    if (strcmp(getNodeData(head, 2), ")") != 0)
        return 0;

    return 1;
}

int parsePrintIdStatement(char *line, FILE *file) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    char *identifier = getNodeData(head, 2);
    if (isVariableScalar(identifier)) {
        struct Scalar *scalar = findScalarById(identifier);
        fprintf(file,"printf(\"%%f\", %s)\n;", scalar->id);
        fprintf(file,"\n");
        return 1;
    }
    if (isVariableVector(identifier)) {
        struct Vector *vector = findVectorById(identifier);
        char *code = "for (int i = 0; i < %d; i++) {\n\tprintf(\"%%f\\n\",%s[i]);\n}\n";
        fprintf(file,code, vector->size, vector->id);
        return 1;
    }
    if (isVariableMatrix(identifier)) {
        struct Matrix *matrix = findMatrixById(identifier);
        char *code = "for (int i = 0; i < %d; i++) {\n\tfor (int j = 0; j < %d; j++) "
                     "{\n\t\tprintf(\"%%f\\n\", %s[i][j]);\n\t}\n}\n";
        fprintf(file,code, matrix->rowSize, matrix->columnSize, matrix->id);
        return 1;
    }
    return 0;
}

int parsePrintSepStatement(char *line, FILE *file) {
    fprintf(file,"printf(\"----------\\n\");\n");
    return 1;
}