//
// Created by aesh on 3/27/2022.
//

#ifndef MATLANGPROJECT_PRINTSTATEMENTS_H
#define MATLANGPROJECT_PRINTSTATEMENTS_H

/**
 * Return 1 if statement is of form print(id) else 0
 */
int isPrintIdStatement(char* line);

/**
 * Return 1 if line is of form printsep() else 0
 */
int isPrintSepStatement(char* line);

/**
 * parse the statement
 * @param line
 * @return 1 if succesfull 0 otherwise
 */
int parsePrintIdStatement(char *line, FILE *file);

/**
 * parse print sep statement
 * @param line
 * @return 1 if successful 0 otherwise
 */
int parsePrintSepStatement(char *line, FILE *file);
#endif //MATLANGPROJECT_PRINTSTATEMENTS_H
