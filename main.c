#include <stdio.h>
#include "stringutils.h"
#include "definitionstatements.h"
#include "assignstatements.h"
#include "printstatements.h"
#include "expressionparsing.h"
#include "infixtopostfix.h"

static int ERROR = 0;
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
    int lineCount = 0;
    while (fgets(line, LINE_LIMIT, fp) != NULL) {
        if (isEmptyString(line, LINE_LIMIT)) {
            continue;
        }
        char *strippedLine = strippedString(line, LINE_LIMIT);

        if (isCommentLine(strippedLine)) {
            lineCount++;
            continue;
        }

        char *spacedLine = getSpacedVersionOf(strippedLine);
        if (isScalarDefinition(spacedLine)) {
            if (parseScalarDefinition(spacedLine) == ERROR) {
                printf("Error (Line %d)\n", lineCount);
                return -1;
            }
        } else if (isMatrixDefinition(spacedLine)) {
            if (parseMatrixDefinition(spacedLine) == ERROR) {
                printf("Error (Line %d)\n", lineCount);
                return -1;
            }
        } else if (isVectorDefinition(spacedLine)) {
            if (parseVectorDefinition(spacedLine) == ERROR) {
                printf("Error (Line %d)\n", lineCount);
                return -1;
            }
        } else if (isVectorAssignment(spacedLine)) {
            if (parseVectorAssignment(spacedLine) == ERROR) {
                printf("Error (Line %d)\n", lineCount);
                return -1;
            }
        } else if (isMatrixAssignment(spacedLine)) {
            if (parseMatrixAssignment(spacedLine) == ERROR) {
                printf("Error (Line %d)\n", lineCount);
                return -1;
            }
        } else if (isPrintSepStatement(spacedLine)) {
            if (parsePrintSepStatement(spacedLine) == ERROR) {
                printf("Error (Line %d)\n", lineCount);
                return -1;
            }
        } else if (isPrintIdStatement(spacedLine)) {
            if (parsePrintIdStatement(spacedLine) == ERROR) {
                printf("Error (Line %d)\n", lineCount);
                return -1;
            }
        }

        lineCount++;
    }
    fclose(fp);
    return (0);
}
