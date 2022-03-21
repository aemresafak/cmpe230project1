#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "stringutils.h"
#include "parseutils.h"

static int LINE_LIMIT = 256;

int main(int argc, char *argv[]) {
    FILE *fp;
    FILE *outputFile;
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
            printf("this is a comment line!\n");
            continue;
        }

        if (isScalarDefinition(strippedLine, LINE_LIMIT)) {
            parseScalarDefinition(strippedLine);
        } else if (isMatrixDefinition(strippedLine, LINE_LIMIT))
            printf("MATRIX!!\n");
        else if (isVectorDefinition(strippedLine, LINE_LIMIT)) {
            printf("VECTOR!!\n");
            parseVectorDefinition(strippedLine);
        }


        free(strippedLine);
    }
    fclose(fp);
    return (0);
}
