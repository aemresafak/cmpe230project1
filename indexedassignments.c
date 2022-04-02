//
// Created by aesh on 4/2/2022.
//

#include "indexedassignments.h"
#include "datastructures.h"
#include "structs.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "infixtopostfix.h"
#include "expressionparsing.h"
#include "stringutils.h"

int isIndexedVectorAssignment(char *line) {

    char copiedLine[1024];
    strcpy(copiedLine, line);
    char *temp = strtok(copiedLine, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    if (getLinkedListSize(head) < 6)
        return 0;
    char *identifier = getNodeData(head, 0);
    if (!isVariableVector(identifier))
        return 0;
    if (strcmp(getNodeData(head, 1), "[") != 0)
        return 0;
    int rightBraceIndex = -1;
    for (int i = 2; i < getLinkedListSize(head); i++) {
        if (strcmp(getNodeData(head, i), "]") == 0) {
            rightBraceIndex = i;
            break;
        }
    }
    if (rightBraceIndex == -1)
        return 0;
    if (strcmp(getNodeData(head, rightBraceIndex + 1), "=") != 0) {
        return 0;
    }
    return 1;
}

int parseIndexedVectorAssignment(char *line) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    char *identifier = getNodeData(head, 0);
    char *expression = malloc(1024);
    expression[0] = 0;
    int index = 2;
    while (1) {
        if (strcmp(getNodeData(head, index), "]") == 0) {
            break;
        }
        strcat(expression, getNodeData(head, index));
        index++;
    }

    struct node_for_dll *pNodeForDll = NULL;
    char *deblankedExpr = deblank(expression);
    char *indexResult;
    if (expressionParsing(deblankedExpr, &pNodeForDll)) {
        if (pNodeForDll->is_scalar != 1) {
            return 0;
        }
        indexResult = pNodeForDll->data;
    }
    char *expression2 = malloc(1024);
    expression2[0] = 0;
    for (int i = index + 2; i < getLinkedListSize(head); i++) {
        strcat(expression2, getNodeData(head, i));
    }
    char *deblankedExpr2 = deblank(expression2);
    struct node_for_dll *pNodeForDll2 = NULL;
    char *result;
    if (expressionParsing(deblankedExpr2, &pNodeForDll2)) {
        if (pNodeForDll2->is_scalar != 1) {
            return 0;
        }
        result = pNodeForDll2->data;
    }

    printf("%s[%s]=%s",identifier,indexResult, result);

    return 1;
}

