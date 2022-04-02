//
// Created by hp on 28.03.2022.
//

#ifndef MATLANGPROJECT_INFIXTOPOSTFIX_H
#define MATLANGPROJECT_INFIXTOPOSTFIX_H

struct Stack
{
    int top;
    char array[1024][50];
};

struct node_for_dll {
    char data[50];
    struct node_for_dll* next;
    struct node_for_dll* prev;

    int is_scalar;
    int is_vector;
    int is_matrix;

    int size;
    int row_size;
    int column_size;


};



int isEmpty(struct Stack* stack);

void pop(struct Stack* stack);

void push(struct Stack* stack, char op[]);

int Prec(char ch);

int isOperator(char ch);

void append(struct node_for_dll** head_ref, char* new_data);

int infixToPostfix(char* exp , struct node_for_dll** head_ref);


#endif //MATLANGPROJECT_INFIXTOPOSTFIX_H
