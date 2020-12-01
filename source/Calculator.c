#include "../include/Calculator.h"

float CalculateFromSuffixExpression(char *str) {
    int length = strlen(str);
    float *pTempResult = (float *) malloc(sizeof(float));
    float *pTempOperandA = (float *) malloc(sizeof(float));
    float *pTempOperandB = (float *) malloc(sizeof(float));

    String *pTempStr = NULL;
    String *pStr = String_NewStringFrom(str);

    if (String_GetCharAt(pStr, length - 1) != ' ') {
        String_AppendChar(pStr, ' ');
        length = String_GetLength(pStr);
    }

    GenericStack *pNumberStack = Stack_NewStack(DEFAULT_STACK_INIT_SIZE, sizeof(float));

    int op = 0, ed;
    for (int i = 0; i < length; i++) {
        if (pStr->str[i] == ' ') {
            ed = i;
            pTempStr = String_Slice(pStr, op, ed - 1);
            if (IsValidNumber(pTempStr->str)) {
                *pTempResult = ConvertStringToFloat(pTempStr->str);
                Stack_Push(pNumberStack, pTempResult);
            } else if (String_IsSingleChar(pTempStr)) {
                char ch = pTempStr->str[0];
                Stack_PopTo(pNumberStack, pTempOperandA);
                Stack_PopTo(pNumberStack, pTempOperandB);
                switch (ch) {
                    case '+':
                        *pTempResult = *pTempOperandA + *pTempOperandB;
                        break;
                    case '-':
                        *pTempResult = *pTempOperandB - *pTempOperandA;
                        break;
                    case '*':
                        *pTempResult = *pTempOperandA * *pTempOperandB;
                        break;
                    case '/':
                        if (*pTempOperandA == 0) {
                            return NAN;
                        }
                        *pTempResult = *pTempOperandB / *pTempOperandA;
                        break;
                    default:
                        break;
                }
                Stack_Push(pNumberStack, pTempResult);
            }
            i = ed;
            op = ed + 1;
        }
        String_Free(pTempStr);
        pTempStr = NULL;
    }

    Stack_PopTo(pNumberStack, pTempResult);
    float result = *pTempResult;

    Stack_Free(pNumberStack);
    String_Free(pTempStr);
    free(pTempResult);
    free(pTempOperandA);
    free(pTempOperandB);
    pTempResult = NULL;
    pTempOperandA = NULL;
    pTempOperandB = NULL;

    return result;
}