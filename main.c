#include <stdio.h>
#include <malloc.h>
#include <string.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "DanglingPointer"
static int EMPTY_STRING = 1;
static int NON_EMPTY_STRING = 0;
static int LINE_LIMIT = 256;

/**
 * Check if given string is empty
 * @param str string to check
 * @param size size of the string
 * @return -1 if empty 0 otherwise
 */
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

/**
 * Get the size of string
 * @param string
 * @return size of the string including \0 character
 */
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

/**
 * Strips a non empty string from trailing and preceding white spaces
 * @param str string to be stripped
 * @param size size of the string
 * @return pointer to stripped string
 */
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

/**
 * Check if a line is a comment line
 * @param str line to check
 * @return 1 if comment line 0 otherwise
 */
int isCommentLine(char *str) {
    if (str[0] == '#')
        return 1;
    else
        return 0;
}
/**
 * Check if a string starts with a word
 * @param source string to check if starts with a word
 * @param with word to check against
 * @param sizeOfWith size of with
 * @return 1 if source starts with with else 0
 */
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


/**
 * Check if the line is a scalar definition
 * @param string line to check
 * @param size line of the size
 * @return 1 if scalar definition 0 otherwise
 */
int isScalarDefinition(const char *string, int size) {
    if (startsWith(string, "scalar ", 7)) {
        return 1;
    } else
        return 0;
}

/**
 * Check if a line is a matrix definition
 * @param string line to check for
 * @param size size of the line
 * @return 1 if matrix definition 0 otherwise
 */
int isMatrixDefinition(const char *string, int size) {
    if (startsWith(string, "matrix ", 7)) {
        return 1;
    } else
        return 0;
}

/**
 * Check if a line is vector definition
 * @param string line to check for
 * @param size size of the line
 * @return 1 if vector definition 0 otherwise
 */
int isVectorDefinition(const char *string, int size) {
    if (startsWith(string, "vector ", 7)) {
        return 1;
    } else
        return 0;
}


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
            printf("this is a comment line!\n");
            continue;
        }

        if (isScalarDefinition(strippedLine, LINE_LIMIT)) {
            printf("is scalar definiton!\n");
        } else if (isMatrixDefinition(strippedLine, LINE_LIMIT))
            printf("MATRIX!!\n");
        else if (isVectorDefinition(strippedLine, LINE_LIMIT))
            printf("VECTOR!!\n");

        printf(strippedLine);


        free(strippedLine);
    }
    fclose(fp);
    return (0);
}
