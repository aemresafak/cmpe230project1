cmake_minimum_required(VERSION 3.21)
project(MatlangProject C)

set(CMAKE_C_STANDARD 99)

add_executable(MatlangProject main.c stringutils.h stringutils.c parseutils.h parseutils.c structs.h structs.c assignstatements.c assignstatements.h)
