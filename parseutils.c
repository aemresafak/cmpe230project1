#include "parseutils.h"
#include "stringutils.h"
//
// Created by aesh on 3/21/2022.
//

int parseScalarDefinition(char* line) {
    char *lexemeIdentifier;
    int count = 0;
    char* temp = strtok(line, " ");
    while (temp != NULL) {
        lexemeIdentifier = temp;
        temp = strtok(NULL, " ");
        count++;
    }
    if (count >= 3) {
        printf("ERROR PARSING SCALAR!!!");
        return 0;
    }
    stripSingleTrailingNewLineCharacter(lexemeIdentifier);
    printf( "int %s = 0;\n", lexemeIdentifier);
    return 1;


}