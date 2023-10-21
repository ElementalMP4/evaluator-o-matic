#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "../stack/stack.h"
#include "../operator/operator.h"

int getPrecedence(char *token)
{
    switch (*token)
    {
    case SUBTRACT:
    case ADD:
        return 1;
    case MULTIPLY:
    case DIVIDE:
        return 2;
    case EXPONENT:
        return 3;
    default:
        return 0;
    }
}

char **infixToRpn(char **input, int numTokens)
{
    char **output = (char **)malloc(numTokens * sizeof(char *));
    TokenStack stack;
    initTokenStack(&stack);
    int outputIndex = 0;

    for (int i = 1; i < numTokens; i++)
    {
        char *token = input[i];
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            output[outputIndex] = token;
            outputIndex++;
        }
        else if (strcmp(token, "(") == 0)
        {
            pushToken(&stack, token);
        }
        else if (strcmp(token, ")") == 0)
        {
            while (!isTokenStackEmpty(&stack) && strcmp(stack.array[stack.size - 1], "(") != 0)
            {
                output[outputIndex] = popToken(&stack);
                outputIndex++;
            }
            if (!isTokenStackEmpty(&stack) && strcmp(stack.array[stack.size - 1], "(") == 0)
            {
                popToken(&stack);
            }
        }
        else
        {
            while (!isTokenStackEmpty(&stack) && getPrecedence(token) <= getPrecedence(stack.array[stack.size - 1]))
            {
                output[outputIndex] = popToken(&stack);
                outputIndex++;
            }
            pushToken(&stack, token);
        }
    }

    while (!isTokenStackEmpty(&stack))
    {
        output[outputIndex] = popToken(&stack);
        outputIndex++;
    }

    freeTokenStack(&stack);

    return output;
}