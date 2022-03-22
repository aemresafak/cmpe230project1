//
// Created by aesh on 3/23/2022.
//

#ifndef MATLANGPROJECT_STRUCTS_H
#define MATLANGPROJECT_STRUCTS_H
const int MAX_VARIABLE_COUNT = 1024;
struct Vector {
    char* id;
    int size;
};

struct Scalar {
    char* id;
};

struct Matrix {
    char* id;
    int rowSize;
    int columnSize;
};
struct Vector vectors[MAX_VARIABLE_COUNT];
struct Scalar scalars[MAX_VARIABLE_COUNT];
struct Matrix matrices[MAX_VARIABLE_COUNT];
#endif //MATLANGPROJECT_STRUCTS_H
