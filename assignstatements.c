//
// Created by aesh on 3/23/2022.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "assignstatements.h"
#include "structs.h"
#include "stringutils.h"
#include "datastructures.h"

int isVectorAssignment(char *line) {
    char copiedLine[256];
    strcpy(copiedLine, line);

    char *temp = strtok(copiedLine, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    char *identifier = getNodeData(head, 0);
    char *token = getNodeData(head, 1);

    if (isVariableVector(identifier) == 1 && strcmp(token, "=") == 0)
        return 1;
    else
        return 0;
}

int isMatrixAssignment(char *line) {
    char copiedLine[256];
    strcpy(copiedLine, line);
    char *temp = strtok(copiedLine, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    char *identifier = getNodeData(head, 0);
    char *token = getNodeData(head, 1);

    if (isVariableMatrix(identifier) && (strcmp(token, "=") == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int parseMatrixAssignment(char *line) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);

    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }

    char *identifier = getNodeData(head, 0);
    struct Matrix *matrix = findMatrixById(identifier);

    int expectedSize = 4 + matrix->columnSize * matrix->rowSize;
    if (getLinkedListSize(head) != expectedSize) {
        printf("ERROR PARSING MATRIX ASSIGNMENT!\n");
        return 0;
    }

    if (strcmp(getNodeData(head, 1), "=") != 0) {
        printf("MISSING =\n");
        return 0;
    }

    if (strcmp(getNodeData(head, 2), "{") != 0) {
        printf("MISSING LEFT BRACKET\n");
        return 0;
    }

    for (int i = 3; i < expectedSize - 1; i++) {
        if (!containsOnlyNumbers(getNodeData(head, i))) {
            printf("ELEMENT NOT NUMBER\n");
            return 0;
        }
    }

    if (strcmp(getNodeData(head, getLinkedListSize(head) - 1), "}") != 0) {
        printf("MISSING RIGHT BRACKET!\n");
        return 0;
    }


    int index = 3;
    for (int i = 0; i < matrix->rowSize; i++) {
        for (int j = 0; j < matrix->columnSize; j++) {
            int value = strtol(getNodeData(head, index), NULL, 10);
            printf("%s[%d][%d] = %d;\n", matrix->id, i, j, value);
            index++;
        }
    }


    return 1;
}

int parseVectorAssignment(char *line) {
    char *temp = strtok(line, " \n");
    struct Node* head = createNode(temp);

    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }

    char *identifier = getNodeData(head,0);
    struct Vector *vector = findVectorById(identifier);
    int expectedSize = 4 + vector->size;
    if (getLinkedListSize(head) != expectedSize) {
        printf("ERROR PARSING VECTOR ASSIGNMENT\n");
        return 0;
    }
    if (strcmp(getNodeData(head,2), "{") != 0) {
        printf("MISSING LEFT BRACE!");
        return 0;
    }

    for (int i = 3; i < expectedSize - 1; i++) {
        if (!containsOnlyNumbers(getNodeData(head,i))) {
            printf("ELEMENT NOT NUMBER!\n");
            return 0;
        }
    }

    if (strcmp(getNodeData(head, getLinkedListSize(head)-1),"}") != 0) {
        printf("MISSING RIGHT BRACKET\n");
        return 0;
    }
    int valueIndex = 3;
    for (int i = 0; i < vector->size; i++) {
        int value = strtol(getNodeData(head, valueIndex), NULL , 10);
        printf("%s[%d] = %d;\n", identifier, i, value);
        valueIndex++;
    }


    return 1;
}