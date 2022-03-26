#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "stringutils.h"
#include "parseutils.h"
#include "structs.h"
#include "assignstatements.h"
#include "datastructures.h"

static int LINE_LIMIT = 256;

int main(int argc, char *argv[]) {
    FILE *fp;

    char line[LINE_LIMIT];
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

        char *spacedLine = getSpacedVersionOf(strippedLine);

        if (isScalarDefinition(spacedLine)) {
            parseScalarDefinition(spacedLine);
        } else if (isMatrixDefinition(spacedLine)) {
            parseMatrixDefinition(spacedLine);
        } else if (isVectorDefinition(spacedLine)) {
            parseVectorDefinition(spacedLine);
        } else if (isVectorAssignment(spacedLine)) {
            parseVectorAssignment(spacedLine);
        } else if (isMatrixAssignment(spacedLine)) {
            parseMatrixAssignment(spacedLine);
        }


    }
    fclose(fp);
    return (0);
}
