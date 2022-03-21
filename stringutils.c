//
// Created by aesh on 3/21/2022.
//

#include <malloc.h>
#include <string.h>
#include "stringutils.h"

static int EMPTY_STRING = 1;
static int NON_EMPTY_STRING = 0;
static int LINE_LIMIT = 256;

int isEmptyString(const char *str, int size) {
    int state = EMPTY_STRING;
    for (int i = 0; i < size; i++) {
        if (str[i] == '\0')
            break;
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            state = NON_EMPTY_STRING;
            break;
        }
    }
    return state;
}

int getSizeOfString(char *string) {
    int size = 0;
    while (1) {
        if (string[size] == '\0') {
            size++;
            break;
        } else {
            size++;
        }
    }
    return size;
}

char *strippedString(char *str, int size) {
    char *_str = malloc(LINE_LIMIT * 1);
    int startingPointerIndex = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            startingPointerIndex = i;
            break;
        }
    }
    strcpy(_str, str + startingPointerIndex);
    int sizeOfString = getSizeOfString(_str);
    // get the first character before \0
    for (int i = sizeOfString - 2; i > 0; i--) {
        if (_str[i] == ' ' || _str[i] == '\t') {
            _str[i] = '\0';
        } else {
            break;
        }
    }
    return _str;
}

int isCommentLine(char *str) {
    if (str[0] == '#')
        return 1;
    else
        return 0;
}

int startsWith(const char *source, const char *with, int sizeOfWith) {
    int starts = 1;
    for (int i = 0; i < sizeOfWith; i++) {
        if (source[i] != with[i]) {
            starts = 0;
            break;
        }
    }
    return starts;
}

int isScalarDefinition(const char *string) {
    if (startsWith(string, "scalar ", 7)) {
        return 1;
    } else
        return 0;
}

int isMatrixDefinition(const char *string) {
    if (startsWith(string, "matrix ", 7)) {
        return 1;
    } else
        return 0;
}

int isVectorDefinition(const char *string) {
    if (startsWith(string, "vector ", 7)) {
        return 1;
    } else
        return 0;
}

char* stripSingleTrailingNewLineCharacter(char* string) {
    int size = getSizeOfString(string);
    if (string[size-2]=='\n') {
        string[size-2]='\0';
    }
    return string;
}

int endsWith(char* string, char ch) {
    int size = getSizeOfString(string);
    if (string[size-2] == ch)
        return 1;
    else
        return 0;
}

char* stripFromEnd(char* string, char ch) {
    int size = getSizeOfString(string);
    string[size-2] = '\0';
    return string;
}
