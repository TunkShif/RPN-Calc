#include "Parser.h"

int GetPriority(char operator) {
    switch (operator) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        default: return -1;
    }
}

String *ExtractFirstNumberFromString(char *str) {
    if (str == NULL) {
        return NULL;
    }

    String *pSrcString = String_NewStringFrom(str);

    int i = 0;
    int op = 0, ed = 0;

    // Get the index of the first digit
    while (str[i] != '\0') {
        if (isdigit(str[i])) {
            op = i;
            break;
        }
        i++;
    }

    if (!isdigit(str[i + 1]) && (str[i + 1] != '.')) {
        // if the number is a single digit
        ed = op;
        // if the number has a negative or positive sign
        if (pSrcString->str[op - 1] == '-' || pSrcString->str[op - 1] == '+') {
            op--;
        }
        return String_Slice(pSrcString, op, ed);
    } else if (isdigit(str[i + 1])) {
        // if the number is has a multi-digit integer part
        while (isdigit(str[i + 1])) {
            i++;
        }

        if (!isdigit(str[i + 1]) && (str[i + 1] != '.')) {
            // if the number is a multi-digit integer
            ed = i;
        } else if (str[i + 1] == '.') {
            // if the number is a float number with multi-digit integer part
            i++;
            while (isdigit(str[i + 1])) {
                i++;
            }
            ed = i;
        }
    } else if (str[i + 1] == '.') {
        i++;
        while (isdigit(str[i + 1])) {
            i++;
        }
        ed = i;
    } else {
        return String_NewStringFrom("ERROR");
    }

    // if the number has a negative or positive sign
    if (pSrcString->str[op - 1] == '-' || pSrcString->str[op - 1] == '+') {
        op--;
    }

    // if the number ending with a dot but is not a float number
    if (pSrcString->str[ed] == '.' && !isdigit(pSrcString->str[ed + 1])) {
        ed--;
    }

    return String_Slice(pSrcString, op, ed);
}

char *PreprocessSign(char *srcString) {
    String *pTempStr = String_NewStringFrom(srcString);
    int length = strlen(srcString);
    if (srcString[0] == '-' || srcString == '+') {
        String_InsertCharAtHead(pTempStr, '0');
    }
    for (int i = 0; i < length; i++) {
        if (pTempStr->str[i] == '(' && (pTempStr->str[i + 1] == '-' || pTempStr->str[i + 1] == '+')) {
            String_InsertCharAt(pTempStr, i, '0');
        }
    }
    char *outputStr = String_ToCString(pTempStr);
    String_Free(pTempStr);
    return outputStr;
}

char *InfixToSuffix(char *srcString) {
    char baseStackSign = '#';

    if (srcString == NULL) {
        return NULL;
    }

    int length = strlen(srcString);
    LinkedStack *pOperatorStack = LinkedStack_NewStack();
    LinkedStack_Push(pOperatorStack, &baseStackSign);

    int numberLength = 0;
    String *pNumberString = NULL;
    String *pOutputString = String_NewString(DEFAULT_STRING_SIZE);

    for (int i = 0; i < length; i++) {

        if (isdigit(srcString[i])) {
            pNumberString = ExtractFirstNumberFromString(srcString + i);
            numberLength = String_GetLength(pNumberString);
            String_ConcatString(pOutputString, pNumberString->str);
            i = i + numberLength -1;
            String_AppendChar(pOutputString, ' ');
        } else if (IsOperator(srcString[i])) {
            if (srcString[i] == '(') {
                LinkedStack_Push(pOperatorStack, srcString + i);
            } else if (srcString[i] == ')') {
                while (LinkedStack_GetTopChar(pOperatorStack) != '(') {
                    String_AppendChar(pOutputString, LinkedStack_GetTopChar(pOperatorStack));
                    String_AppendChar(pOutputString, ' ');
                    LinkedStack_Pop(pOperatorStack, NoNeedToFreeData);
                }
                if (LinkedStack_GetTopChar(pOperatorStack) == '(') {
                    LinkedStack_Pop(pOperatorStack, NoNeedToFreeData);
                }
            } else {
                while (GetPriority(srcString[i]) <= GetPriority(LinkedStack_GetTopChar(pOperatorStack))) {
                    String_AppendChar(pOutputString, LinkedStack_GetTopChar(pOperatorStack));
                    String_AppendChar(pOutputString, ' ');
                    LinkedStack_Pop(pOperatorStack, NoNeedToFreeData);
                    if (LinkedStack_GetTopChar(pOperatorStack) == '#') {
                        break;
                    }
                }
                LinkedStack_Push(pOperatorStack, srcString + i);
            }
        } else if (srcString[i] == ' ') {
            continue;
        } else {
            return NULL;
        }
    }

    while (LinkedStack_GetTopChar(pOperatorStack) != '#') {
        String_AppendChar(pOutputString, LinkedStack_GetTopChar(pOperatorStack));
        String_AppendChar(pOutputString, ' ');
        LinkedStack_Pop(pOperatorStack, NoNeedToFreeData);
    }

    char *outputString = String_ToCString(pOutputString);

    LinkedStack_Free(pOperatorStack, NoNeedToFreeData);
    String_Free(pNumberString);
    String_Free(pOutputString);

    return outputString;
}