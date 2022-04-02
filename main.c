#include <stdio.h>
#include "stringutils.h"
#include "definitionstatements.h"
#include "assignstatements.h"
#include "printstatements.h"
#include "expressionparsing.h"
#include "infixtopostfix.h"
#include "indexedassignments.h"
#include "forloops.h"

static int ERROR = 0;
static int LINE_LIMIT = 256;
static int lineCount = 0;
int hasPendingRightBracket = 0;
int canPutRightBracket = 0;

int parseLine(char *line);

int main(int argc, char *argv[]) {
    FILE *fp;
    FILE * out = fopen("file.c","w");
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
    int errorOccured = 0;
    while (fgets(line, LINE_LIMIT, fp) != NULL) {
        if (parseLine(line) == ERROR) {
            errorOccured = 1;
            break;
        }
    }
    if (!errorOccured) {
        if (hasPendingRightBracket) {
            printf("Error (Line %d)\n", lineCount);
            return -1;
        }
    }
    fprintf(out, "ahmet emre");
    fclose(fp);
    return (0);
}

int parseLine(char *line) {
    if (isEmptyString(line, LINE_LIMIT)) {
        return 1;
    }
    char *strippedLine = strippedString(line, LINE_LIMIT);
    if (isCommentLine(strippedLine)) {
        lineCount++;
        return 1;
    }


    char *spacedLine = getSpacedVersionOf(strippedLine);

    if (isScalarDefinition(spacedLine)) {
        if (parseScalarDefinition(spacedLine, NULL) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isMatrixDefinition(spacedLine)) {

        if (parseMatrixDefinition(spacedLine, NULL) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isVectorDefinition(spacedLine)) {

        if (parseVectorDefinition(spacedLine, NULL) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isVectorAssignment(spacedLine)) {

        if (parseVectorAssignment(spacedLine, NULL) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isMatrixAssignment(spacedLine)) {

        if (parseMatrixAssignment(spacedLine, NULL) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isPrintSepStatement(spacedLine)) {

        if (parsePrintSepStatement(spacedLine) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isPrintIdStatement(spacedLine)) {
        if (parsePrintIdStatement(spacedLine) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isScalarAssignment(spacedLine)) {

        if (parseScalarAssignment(spacedLine) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isIndexedVectorAssignment(spacedLine)) {

        if (parseIndexedVectorAssignment(spacedLine) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isIndexedMatrixAssignment(spacedLine)) {

        if (parseIndexedMatrixAssignment(spacedLine) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
    } else if (isSingleForLoop(spacedLine)) {
        if (parseSingleForLoop(spacedLine, NULL) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
        hasPendingRightBracket++;
        canPutRightBracket++;
    } else if (strcmp(strippedLine, "}") == 0 || strcmp(strippedLine, "}\n") == 0) {
        if (canPutRightBracket != 1) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
        printf("}\n");
        hasPendingRightBracket--;
        canPutRightBracket--;
    } else if (isDoubleForLoop(spacedLine)) {
        if (parseDoubleForLoop(spacedLine, NULL) == ERROR) {
            printf("Error (Line %d)\n", lineCount);
            return 0;
        }
        hasPendingRightBracket++;
        canPutRightBracket++;
    } else {
        printf("Error (Line %d)\n", lineCount);
        return 0;
    }
    lineCount++;
    return 1;
}