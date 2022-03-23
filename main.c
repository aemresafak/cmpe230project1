#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "stringutils.h"
#include "parseutils.h"
#include "structs.h"
#include "assignstatements.h"

static int LINE_LIMIT = 256;

int main(int argc, char *argv[]) {
    FILE *fp;


    char line[80];
    /** Open file for reading Filename is given on the command line */
    if (argc != 2) {
        printf("Give filename as command line argument\n");
        return (1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Cannot open %s\n", argv[1]);
        return (1);
    }


    while (fgets(line, LINE_LIMIT, fp) != NULL) {
        if (isEmptyString(line, LINE_LIMIT)) {
            continue;
        }
        char *strippedLine = strippedString(line, LINE_LIMIT);

        if (isCommentLine(strippedLine)) {
            continue;
        }

        if (isScalarDefinition(strippedLine)) {
            parseScalarDefinition(strippedLine);
        } else if (isMatrixDefinition(strippedLine)) {
            parseMatrixDefinition(strippedLine);
        } else if (isVectorDefinition(strippedLine)) {
            parseVectorDefinition(strippedLine);
        } else if (isVectorAssignment(strippedLine)) {
            parseVectorAssignment(strippedLine);
        } else if (isMatrixAssignment(strippedLine)) {
            parseMatrixAssignment(strippedLine);
        }


    }
    printArraySizes();
    fclose(fp);
    return (0);
}
