//
// Created by aesh on 3/23/2022.
//

#ifndef MATLANGPROJECT_ASSIGNSTATEMENTS_H
#define MATLANGPROJECT_ASSIGNSTATEMENTS_H

/**
 *
 * @param line
 * @return 1 if vector assignment 0 otherwise
 */
int isVectorAssignment(char* line);

/**
 *
 * @param line
 * @return 1 if matrix assignment 0 otherwise.
 */
int isMatrixAssignment(char* line);

/**
 * Parse the matrix assignment
 * @param line
 * @return 1 if successful 0 otherwise
 */
int parseMatrixAssignment(char* line);

/**
 *
 * @param line
 * @return 1 if successful 0 otherwise
 */
int parseVectorAssignment(char* line);

#endif //MATLANGPROJECT_ASSIGNSTATEMENTS_H
