#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "./evaluator/evaluator.h"
#include "./parser/parser.h"

int countStrings(char **input) {
    int count = 0;
    while (input[count] != NULL) {
        count++;
    }
    return count;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("You need to specify at least one token\n");
        return 1;
    }

    char **parsed = infixToRpn(argv, argc);
    int token_count = countStrings(parsed);

    printf("RPN: ");

    for (int i = 0; i < token_count; i++) {
        printf("%s ", parsed[i]);
    }

    printf("\n");

    double result = evaluateExpression(token_count, parsed );
    printf("Result: %lf\n", result);

    return 0;
}