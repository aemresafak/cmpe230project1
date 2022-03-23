//
// Created by aesh on 3/23/2022.
//

#include <string.h>
#include "initializers.h"
#include "structs.h"

int isVectorMatrixInitialization(char *line) {
    char copiedLine[256];
    strcpy(copiedLine, line);
    int count = 0;
    char *lexemeIdentifier;
    char *equalSign;
    char *leftBrace;
    char *temp = strtok(copiedLine, " ");
    while (temp != NULL) {
        if (count == 0) {
            lexemeIdentifier = temp;
        } else if (count == 1) {
            equalSign = temp;
        } else if (count == 2) {
            leftBrace = temp;
        }
        count++;
        temp = strtok(NULL, " ");
    }
    if (strcmp(equalSign, "=") == 0 && strcmp(leftBrace, "{") == 0 &&
        isVariableNameAlreadyUsedInMatrixOrVector(lexemeIdentifier)) {
        return 1;
    }
    return 0;

}