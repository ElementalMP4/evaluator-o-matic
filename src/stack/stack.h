#include <stdbool.h>

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

typedef struct
{
    double *array;
    int capacity;
    int size;
} OperandStack;

typedef struct
{
    char **array;
    int capacity;
    int size;
} TokenStack;

void initOperandStack(OperandStack *stack);
void pushOperand(OperandStack *stack, double item);
double popOperand(OperandStack *stack);
void freeOperandStack(OperandStack *stack);

void initTokenStack(TokenStack *stack);
void pushToken(TokenStack *stack, char *item);
char *popToken(TokenStack *stack);
void freeTokenStack(TokenStack *stack);
bool isTokenStackEmpty(TokenStack *stack);

#endif