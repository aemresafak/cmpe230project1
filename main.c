#include <stdio.h>

static int EMPTY_STRING = -1;
static int NON_EMPTY_STRING = 0;
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
    while (fgets(line, 80, fp) != NULL) {

        printf("%s", line);
    }
    fclose(fp);
    return (0);
}