#include "CLI.h"

void PrintBar(int n) {
    for (int i = 0; i < n; i++) {
        putchar('=');
    }
    putchar('\n');
}

void CLIPrompt(void) {
    bool hasQuitSign = false;
    float result = 0;
    char tempString[MAX_INPUT_NUMBER] = {'\0'};
    char *currentExpression = NULL;
    String *pStr = String_NewString(MAX_INPUT_NUMBER);

    puts(WELCOME_MESSAGE);
    PrintBar(50);
    printf(PROMPT_MESSAGE);

    gets(tempString);
    String_SetValue(pStr, tempString);
    hasQuitSign = String_HasChar(pStr, 'q');

    if (hasQuitSign) {
        return;
    } else {
        currentExpression = InfixToSuffix(pStr->str);
        if (currentExpression == NULL) {
            puts(INVALID_EXPRESSION_MESSAGE);
        } else {
            result = CalculateFromSuffixExpression(currentExpression);
            printf("Result: %.2f", result);
        }
    }
}

//void PromptLoop(void) {
//    bool flag = true;
//    bool hasQuitSign = false;
//    float result = 0;
//    char tempString[MAX_INPUT_NUMBER] = {'\0'};
//    char *currentExpression = NULL;
//    String *pStr = String_NewString(MAX_INPUT_NUMBER);
//
//    puts(WELCOME_MESSAGE);
//    PrintBar(30);
//
//    while (flag) {
//        printf(PROMPT_MESSAGE);
//        gets(tempString);
//        String_SetValue(pStr, tempString);
//        hasQuitSign = String_HasChar(pStr, 'q') || String_HasChar(pStr, EOF);
//
//        if (hasQuitSign) {
//            flag = false;
//        } else {
//            currentExpression = InfixToSuffix(pStr->str);
//            if (currentExpression == NULL) {
//                puts(INVALID_EXPRESSION_MESSAGE);
//            } else {
//                result = CalculateFromSuffixExpression(currentExpression);
//                printf("Result: %.2f\n", result);
//                PrintBar(30);
//            }
//        }
//    }
//
//    puts("BYE~");
//}
