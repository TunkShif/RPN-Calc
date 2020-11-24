#include <stdio.h>
#include "structures/String.h"
#include "CLI.h"

int main(int argc, char *argv[]) {
//    if (argc == 1) {
//        PromptLoop();
//    } else if (argc == 3) {
//        if (strcmp(argv[1], "-e") == 0) {
//            char *exp = InfixToSuffix(argv[2]);
//            if (exp == NULL) {
//                puts(INVALID_EXPRESSION_MESSAGE);
//            } else {
//                float result = CalculateFromSuffixExpression(exp);
//                printf("%s = %.2f", argv[2], result);
//            }
//        }
//    } else {
//        puts("WRONG COMMAND!");
//    }

    char *exp = PreprocessSign("+9-(-9+7)*(-3)");
    puts(exp);
    return 0;
}
