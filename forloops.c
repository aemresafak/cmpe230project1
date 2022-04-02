//
// Created by aesh on 4/3/2022.
//

#include "forloops.h"
#include <string.h>
#include <malloc.h>
#include "datastructures.h"
#include "structs.h"

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
    if (isVariableScalar(getNodeData(head,2)) != 1)
        return 0;
    if (strcmp(getNodeData(head,3),"in"))
        return 0;

    return 1;

}

int parseSingleForLoop(char* line) {
    char *temp = strtok(line, " \n");
    struct Node *head = createNode(temp);

    while (temp != NULL) {
        temp = strtok(NULL, " \n");
        appendToLinkedList(head, temp);
    }
    char *identifier = getNodeData(head, 0);
    char* expr1 = malloc(1024);
    char* expr2 = malloc(1024);
    char* expr3 = malloc(1024);


}
