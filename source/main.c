#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Lexer.h"
#include "../include/Calculator.h"
#define MAX_INPUT_LENGTH 100
#define WELCOME_MESSAGE        "Input an expression, type q to quit"
#define PROMPT_MESSAGE         ">>> "
#define CANT_OPEN_FILE_MESSAGE "ERROR: Cannot open the given file! Exiting...\n"
#define BATCH_DONE_MESSAGE     "INFO: Calculation has been done, check the result.txt file!\n"
#define HELP_INFO              "Calculator Help\n" \
                               "Calc                 Enter the REPL\n" \
                               "    -e <expression>  Calculate from the given expression\n" \
                               "    -f <path>        Calculate from the given text file\n"
#define DEBUG 0

#if DEBUG
int main(int argc, char **argv) {
//    Token *token = Token_Tokenize("(-1+2*3)-sin(2*3)\n");
    Token *token = Token_Tokenize("2+3^(3-1)+6\n");
    Token *new = InfixToSuffix(token);
    Token_Print(new);
    printf("\n");
    double result = CalculateFromSuffix(new);
    printf("%.2lf", result);
    Token_Free(new);
    return 0;
}
#else
int main(int argc, char **argv) {
    double result;
    Token *pToken = NULL;
    char tempString[MAX_INPUT_LENGTH] = {'\0'};

    if (argc == 1) {
        bool flag = true;
        puts(WELCOME_MESSAGE);

        while (flag) {
            printf(PROMPT_MESSAGE);
            scanf("%s", tempString);
            if (tempString[0] == 'q') {
                flag = false;
                continue;
            } else {
                pToken = Token_Tokenize(tempString);
                if (pToken != NULL) {
                    result = CalculateFromSuffix(InfixToSuffix(pToken));
                    printf("%.2lf\n", result);
                } else {
                    fprintf(stderr, INVALID_EXPRESSION_MESSAGE);
                    exit(EXIT_FAILURE);
                }
            }
        }
    } else if (argc == 3 && strcmp(argv[1], "-e") == 0) {
        pToken = Token_Tokenize(argv[2]);
        if (pToken != NULL) {
            result = CalculateFromSuffix(InfixToSuffix(pToken));
            printf("%.2lf\n", result);
        } else {
            fprintf(stderr, INVALID_EXPRESSION_MESSAGE);
            exit(EXIT_FAILURE);
        }
    } else if (argc == 3 && strcmp(argv[1], "-f") == 0) {
        FILE *pFileRead = fopen(argv[2], "r");
        FILE *pFileWrite = fopen("result.txt", "a");

        if (pFileRead != NULL && pFileWrite != NULL) {
            while (!feof(pFileRead)) {
                fgets(tempString, MAX_INPUT_LENGTH, pFileRead);
                if (tempString[0] != '\n') {
                    if (tempString[strlen(tempString) - 1] == '\n') {
                        tempString[strlen(tempString) - 1] = '\0';
                    }
                    pToken = Token_Tokenize(tempString);
                    if (pToken != NULL) {
                        result = CalculateFromSuffix(InfixToSuffix(pToken));
                        fprintf(pFileWrite, "%s=%.2lf\n", tempString, result);
                    } else {
                        fprintf(stderr, INVALID_EXPRESSION_MESSAGE);
                        exit(EXIT_FAILURE);
                    }
                }
            }
            puts(BATCH_DONE_MESSAGE);
        } else {
            fprintf(stderr, CANT_OPEN_FILE_MESSAGE);
            exit(EXIT_FAILURE);
        }
        fclose(pFileRead);
        fclose(pFileWrite);
    } else {
        printf(HELP_INFO);
    }
    Token_Free(pToken);
    return 0;
}
#endif