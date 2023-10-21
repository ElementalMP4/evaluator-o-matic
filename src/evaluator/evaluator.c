#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../stack/stack.h"
#include "../evaluator/evaluator.h"
#include "../operator/operator.h"

double evaluateExpression(int argc, char **argv)
{
    OperandStack stack;
    initOperandStack(&stack);

    int token_count = argc;
    for (int token_index = 0; token_index < token_count; token_index++)
    {
        char *token = argv[token_index];

        double result_d, op_a, op_b;
        char *end_ptr;
        result_d = strtod(token, &end_ptr);

        if (*end_ptr == '\0')
        {
            pushOperand(&stack, result_d);
        }
        else
        {
            switch (*token)
            {
            case EXPONENT:
                op_a = popOperand(&stack);
                op_b = popOperand(&stack);
                pushOperand(&stack, pow(op_b, op_a));
                break;
            case DIVIDE:
                op_a = popOperand(&stack);
                op_b = popOperand(&stack);
                pushOperand(&stack, op_b / op_a);
                break;
            case ADD:
                op_a = popOperand(&stack);
                op_b = popOperand(&stack);
                pushOperand(&stack, op_a + op_b);
                break;
            case MULTIPLY:
                op_a = popOperand(&stack);
                op_b = popOperand(&stack);
                pushOperand(&stack, op_a * op_b);
                break;
            case SUBTRACT:
                op_a = popOperand(&stack);
                op_b = popOperand(&stack);
                pushOperand(&stack, op_b - op_a);
                break;
            default:
                printf("Invalid token %s\n", token);
                exit(1);
            }
        }
    }

    if (stack.size > 1)
    {
        printf("Too many operands\n");
        exit(1);
    }

    double result = popOperand(&stack);
    freeOperandStack(&stack);
    return result;
}