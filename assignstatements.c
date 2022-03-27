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
        } else if (count == 2) {
            if (strcmp("{", temp) != 0) {
                printf("MISSING LEFT BRACE!\n");
                return 0;
            }
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