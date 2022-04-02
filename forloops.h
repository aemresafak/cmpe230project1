//
// Created by aesh on 4/3/2022.
//

#ifndef MATLANGPROJECT_FORLOOPS_H
#define MATLANGPROJECT_FORLOOPS_H
/**
 * Return 1 if line is a single dimensional -no nested- for loop 0 otherwise
 * @param line
 * @return
 */
int isSingleForLoop(char* line);

/**
 * return 1 if successfully parsed 0 otherwise
 * @param line
 * @return
 */
int parseSingleForLoop(char* line);
#endif //MATLANGPROJECT_FORLOOPS_H
