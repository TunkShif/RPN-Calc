#include <stdio.h>
#include "CLI.h"

int main(int argc, char *argv[]) {
//    if (argc == 1) {
//        CLIPrompt();
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
    char exp[50] = "(3+5.6*2)/(2+1)-3*4+5";
    char *sc = "3 5.6 2 * + 2 1 + / 3 4 * - 5 + ";
    char *s = InfixToSuffix(exp);
    puts(s);
    float result = CalculateFromSuffixExpression(s); // !!SEVERE assert debug
    printf("%.2f", result);
    return 0;
}
