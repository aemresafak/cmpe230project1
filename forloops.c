//
// Created by aesh on 4/3/2022.
//

#include "forloops.h"
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "datastructures.h"
#include "structs.h"
#include "expressionparsing.h"
#include "stringutils.h"

int isSingleForLoop(char *line) {
    char copiedLine[1024];
    strcpy(copiedLine, line);
    char *temp = strtok(copiedLine, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    if (strcmp(getNodeData(head, 0), "for") != 0)
        return 0;
    if (strcmp(getNodeData(head, 1), "(") != 0)
        return 0;
    if (isVariableScalar(getNodeData(head, 2)) != 1)
        return 0;
    if (strcmp(getNodeData(head, 3), "in") != 0)
        return 0;

    return 1;

}

int isDoubleForLoop(char *line) {
    char copiedLine[1024];
    strcpy(copiedLine, line);
    char *temp = strtok(copiedLine, " \n");
    struct Node *head = createNode(temp);
    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    if (strcmp(getNodeData(head, 0), "for") != 0)
        return 0;
    if (strcmp(getNodeData(head, 1), "(") != 0)
        return 0;
    if (isVariableScalar(getNodeData(head, 2)) != 1)
        return 0;
    if (strcmp(getNodeData(head, 3), ",") != 0)
        return 0;
    if (isVariableScalar(getNodeData(head, 4)) != 1)
        return 0;
    if (strcmp(getNodeData(head, 5), "in") != 0)
        return 0;
    return 1;
}

int parseSingleForLoop(char *line) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);

    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    char *identifier = getNodeData(head, 2);
    char *expr1 = malloc(1024);
    expr1[0] = 0;
    char *expr2 = malloc(1024);
    expr2[0] = 0;
    char *expr3 = malloc(1024);
    expr3[0] = 0;
    int index = 4;
    if (getLinkedListSize(head) < 11)
        return 0;

    while (index < getLinkedListSize(head)) {
        if (strcmp(getNodeData(head, index), ":") == 0) {
            index++;
            break;
        } else {
            strcat(expr1, getNodeData(head, index));
            index++;
        }
    }
    while (index < getLinkedListSize(head)) {
        if (strcmp(getNodeData(head, index), ":") == 0) {
            index++;
            break;
        } else {
            strcat(expr2, getNodeData(head, index));
            index++;
        }
    }

    while (index < getLinkedListSize(head)) {
        if (strcmp(getNodeData(head, index), ")") == 0) {
            index++;
            break;
        } else {
            strcat(expr3, getNodeData(head, index));
            index++;
        }
    }

    char *expr1Parsed;
    struct node_for_dll *node1 = NULL;
    char *exprDeblanked = deblank(expr1);
    if (expressionParsing(exprDeblanked, &node1)) {
        if (!(node1->is_scalar)) {
            return 0;
        }
        expr1Parsed = node1->data;
    } else
        return 0;

    char *expr2Parsed;
    struct node_for_dll *node2 = NULL;
    char *expr2Deblanked = deblank(expr2);
    if (expressionParsing(expr2Deblanked, &node2)) {
        if (!(node2->is_scalar)) {
            return 0;
        }
        expr2Parsed = node2->data;
    } else
        return 0;
    char *expr3Parsed;
    struct node_for_dll *node3 = NULL;
    char *expr3Deblanked = deblank(expr3);
    if (expressionParsing(expr3Deblanked, &node3)) {
        if (!(node3->is_scalar)) {
            return 0;
        }
        expr3Parsed = node1->data;
    } else
        return 0;

    if (strcmp(getNodeData(head, getLinkedListSize(head) - 1), "{") != 0)
        return 0;

    printf("for ( %s = %s ; %s <= %s; %s += %s) {\n", identifier, expr1Parsed,
           identifier, expr2Parsed, identifier, expr3Parsed);

    return 1;

}

