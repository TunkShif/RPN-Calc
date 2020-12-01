#include <stdio.h>
#include "../include/CLI.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        PromptLoop();
    } else if (argc == 3) {
        if (strcmp(argv[1], "-e") == 0) {
            char *exp = InfixToSuffix(argv[2]);
            if (exp == NULL) {
                puts(INVALID_EXPRESSION_MESSAGE);
            } else {
                float result = CalculateFromSuffixExpression(exp);
                printf("%s = %.2f", argv[2], result);
            }
        } else if (strcmp(argv[1], "-f") == 0) {
            CalcFromFile(argv[2]);
        }
    } else {
        puts("WRONG COMMAND!");
    }
    return 0;
}
