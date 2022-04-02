//
// Created by aesh on 4/2/2022.
//

#ifndef MATLANGPROJECT_INDEXEDASSIGNMENTS_H
#define MATLANGPROJECT_INDEXEDASSIGNMENTS_H


/**
 * return 1 if line is of form a[expr] = expr
 * @param line
 * @return
 */
int isIndexedVectorAssignment(char* line);

/**
 * Return 1 if successfully parsed 0 otherwise
 * @param line
 * @return
 */
int parseIndexedVectorAssignment(char* line);
#endif //MATLANGPROJECT_INDEXEDASSIGNMENTS_H
