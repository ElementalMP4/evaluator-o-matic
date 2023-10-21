#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void initOperandStack(OperandStack *stack)
{
    stack->array = NULL;
    stack->capacity = 0;
    stack->size = 0;
}

void pushOperand(OperandStack *stack, double item)
{
    if (stack->size == stack->capacity)
    {
        stack->capacity++;
        stack->array = (double *)realloc(stack->array, stack->capacity * sizeof(double));
    }
    stack->array[stack->size] = item;
    stack->size++;
}

double popOperand(OperandStack *stack)
{
    if (stack->size > 0)
    {
        stack->size--;
        return stack->array[stack->size];
    }
    else
    {
        fprintf(stderr, "OperandStack is empty\n");
        exit(1);
    }
}

void freeOperandStack(OperandStack *stack)
{
    free(stack->array);
    stack->array = NULL;
    stack->capacity = 0;
    stack->size = 0;
}

void initTokenStack(TokenStack *stack)
{
    stack->array = NULL;
    stack->capacity = 0;
    stack->size = 0;
}

void pushToken(TokenStack *stack, char *item)
{
    if (stack->size == stack->capacity)
    {
        stack->capacity++;
        stack->array = (char **)realloc(stack->array, stack->capacity * sizeof(char *));
    }
    stack->array[stack->size] = item;
    stack->size++;
}

char *popToken(TokenStack *stack)
{
    if (stack->size > 0)
    {
        stack->size--;
        return stack->array[stack->size];
    }
    else
    {
        fprintf(stderr, "TokenStack is empty\n");
        exit(1);
    }
}

void freeTokenStack(TokenStack *stack)
{
    free(stack->array);
    stack->array = NULL;
    stack->capacity = 0;
    stack->size = 0;
}

bool isTokenStackEmpty(TokenStack *stack)
{
    return stack->size == 0;
}
