#include "../include/CLI.h"

void PrintBar(int n) {
    for (int i = 0; i < n; i++) {
        putchar('=');
    }
    putchar('\n');
}

void PrintLogo(void) {
    char *logo = "____________ _   _        _____       _      \n"
                 "| ___ \\ ___ \\ \\ | |      /  __ \\     | |     \n"
                 "| |_/ / |_/ /  \\| |______| /  \\/ __ _| | ___ \n"
                 "|    /|  __/| . ` |______| |    / _` | |/ __|\n"
                 "| |\\ \\| |   | |\\  |      | \\__/\\ (_| | | (__ \n"
                 "\\_| \\_\\_|   \\_| \\_/       \\____/\\__,_|_|\\___|";
    puts(logo);
}

void PromptLoop(void) {
    bool flag = true;
    bool hasQuitSign = false;
    float result = 0;
    char tempString[MAX_INPUT_NUMBER] = {'\0'};
    char *currentExpression = NULL;
    String *pStr = String_NewString(MAX_INPUT_NUMBER);

    PrintLogo();
    puts(WELCOME_MESSAGE);
    PrintBar(50);

    while (flag) {
        printf(PROMPT_MESSAGE);
        gets(tempString);
        String_SetValue(pStr, tempString);
        hasQuitSign = String_HasChar(pStr, 'q') || String_HasChar(pStr, EOF);

        if (hasQuitSign) {
            flag = false;
        } else {
            currentExpression = InfixToSuffix(pStr->str);
            if (currentExpression == NULL) {
                puts(INVALID_EXPRESSION_MESSAGE);
                PrintBar(50);
            } else {
                result = CalculateFromSuffixExpression(currentExpression);
                printf("Result: %.2f\n", result);
                PrintBar(50);
            }
        }
    }

    free(currentExpression);
    currentExpression = NULL;
    String_Free(pStr);
    puts("BYE~");
}

void CalcFromFile(char *filePath) {
    Status *pStatus = NULL;
    pStatus = FileTraverseLines(filePath, CalcCallBack);
    if (pStatus->code == ERROR) {
        puts("WRONG");
    }
}

Status *CalcCallBack(char *str) {
    char *resultFilePath = "result.txt";
    char *exp = InfixToSuffix(str);
    float result = 0;
    if (exp == NULL) {
        return Status_CustomFailedMsg("ERROR: Invalid Expression");
    }
    result = CalculateFromSuffixExpression(exp);
    FILE *fp = fopen(resultFilePath, "a+");
    fprintf(fp, "%.2f\n", result);
    fclose(fp);
    return Status_ActionSucceeded();
}
