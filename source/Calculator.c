#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../include/Calculator.h"
#include "../include/Stack.h"
#include "../include/LinkedStack.h"

int GetPriority(TokenType type) {
    switch (type) {
        case LPAREN:
            return 1;
        case ADD:
        case MINUS:
            return 2;
        case MUL:
        case DIV:
            return 3;
        case POS:
        case NEG:
        case SIN:
        case COS:
        case ASIN:
        case ACOS:
        case LOG:
        case SQRT:
            return 4;
        default:
            return 0;
    }
}

bool IsUnaryOperator(TokenType type) {
    switch (type) {
        case POS:
        case NEG:
        case SIN:
        case COS:
        case LOG:
        case SQRT:
        case ASIN:
        case ACOS:
            return true;
        default:
            return false;
    }
}

double ConvertStringToFloat(const char *str) {
    int i = 0;
    double value = 0;
    while (str[i] != '\0' && str[i] != '.') {
        value = value * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '\0') {
        return value;
    } else if (str[i++] == '.') {
        double weight = 0.1;
        while (str[i] != '\0') {
            value = value + (str[i] - '0') * weight;
            weight = weight / 10;
            i++;
        }
    }
    return value;
}

Token *InfixToSuffix(Token *token) {
    Token head;
    head.next = NULL;
    Token *pOutput = &head;
    Token *pCurrent = token;
    Token *pTemp = NULL;

    // create a stack base token
    Token base = {BASE, "#", NULL};

    LinkedStack *pOperatorStack = LinkedStack_NewStack();
    LinkedStack_Push(pOperatorStack, &base);

    while (pCurrent != NULL) {
        if (pCurrent->type == NUM) {
            pOutput = Token_NewToken(pOutput, NUM, pCurrent->value, strlen(pCurrent->value));
        } else if (pCurrent->type == LPAREN) {
            LinkedStack_Push(pOperatorStack, pCurrent);
        } else if (pCurrent->type == RPAREN) {
            while (((Token *) LinkedStack_GetTop(pOperatorStack))->type != LPAREN) {
                pTemp = (Token *) LinkedStack_Pop(pOperatorStack, FreeData);
                pOutput = Token_NewToken(pOutput, pTemp->type, pTemp->value, strlen(pTemp->value));
            }
            LinkedStack_Pop(pOperatorStack, FreeData);
        } else {
            while (GetPriority(pCurrent->type) <= GetPriority(((Token *) LinkedStack_GetTop(pOperatorStack))->type)) {
                pTemp = (Token *) LinkedStack_Pop(pOperatorStack, FreeData);
                pOutput = Token_NewToken(pOutput, pTemp->type, pTemp->value, strlen(pTemp->value));
                if (((Token *) LinkedStack_GetTop(pOperatorStack))->type == BASE) {
                    break;
                }
            }
            LinkedStack_Push(pOperatorStack, pCurrent);
        }
        pCurrent = pCurrent->next;
    }

    while (((Token *) LinkedStack_GetTop(pOperatorStack))->type != BASE) {
        pTemp = (Token *) LinkedStack_Pop(pOperatorStack, FreeData);
        pOutput = Token_NewToken(pOutput, pTemp->type, pTemp->value, strlen(pTemp->value));
    }

    return head.next;
}

double CalculateFromSuffix(Token *token) {
    Stack *pNumberStack = Stack_NewStack(DEFAULT_STACK_INIT_SIZE, sizeof(double));
    Token *pCurrent = token;
    double *pTempResult = (double *) malloc(sizeof(double));
    double *pTempNumberA = (double *) malloc(sizeof(double));
    double *pTempNumberB = (double *) malloc(sizeof(double));

    while (pCurrent != NULL) {
        if (pCurrent->type == NUM) {
            *pTempResult = ConvertStringToFloat(pCurrent->value);
            Stack_Push(pNumberStack, pTempResult);
        } else {
            if (pCurrent->type == ADD) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                Stack_PopTo(pNumberStack, pTempNumberA);
                *pTempResult = *pTempNumberA + *pTempNumberB;
            } else if (pCurrent->type == MINUS) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                Stack_PopTo(pNumberStack, pTempNumberA);
                *pTempResult = *pTempNumberA - *pTempNumberB;
            } else if (pCurrent->type == MUL) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                Stack_PopTo(pNumberStack, pTempNumberA);
                *pTempResult = *pTempNumberA * *pTempNumberB;
            } else if (pCurrent->type == DIV) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                Stack_PopTo(pNumberStack, pTempNumberA);
                if (*pTempNumberB == 0) {
                    fprintf(stderr, DIVISION_BY_ZERO_MESSAGE);
                    exit(EXIT_FAILURE);
                }
                *pTempResult = *pTempNumberA / *pTempNumberB;
            } else if (pCurrent->type == POS) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                *pTempResult = *pTempNumberB;
            } else if (pCurrent->type == NEG) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                *pTempResult = - (*pTempNumberB);
            } else if (pCurrent->type == SIN) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                *pTempResult = sin(*pTempNumberB);
            } else if (pCurrent->type == COS) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                *pTempResult = cos(*pTempNumberB);
            } else if (pCurrent->type == ASIN) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                *pTempResult = asin(*pTempNumberB);
            } else if (pCurrent->type == ACOS) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                *pTempResult = acos(*pTempNumberB);
            } else if (pCurrent->type == LOG) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                if (*pTempNumberB < 0) {
                    fprintf(stderr, DOMAIN_ERROR_MESSAGE);
                    exit(EXIT_FAILURE);
                }
                *pTempResult = log(*pTempNumberB);
            } else if (pCurrent->type == SQRT) {
                Stack_PopTo(pNumberStack, pTempNumberB);
                if (*pTempNumberB < 0) {
                    fprintf(stderr, DOMAIN_ERROR_MESSAGE);
                    exit(EXIT_FAILURE);
                }
                *pTempResult = sqrt(*pTempNumberB);
            }
            Stack_Push(pNumberStack, pTempResult);
        }
        *pTempResult = 0;
        *pTempNumberA = 0;
        *pTempNumberB = 0;
        pCurrent = pCurrent->next;
        if (pCurrent != NULL) {
            if (Stack_GetLength(pNumberStack) == 1 && !IsUnaryOperator(pCurrent->type) && pCurrent->type != NUM) {
                fprintf(stderr, INVALID_EXPRESSION_MESSAGE);
                exit(EXIT_FAILURE);
            }
        }
    }

    Stack_PopTo(pNumberStack, pTempResult);
    double result = *pTempResult;

    free(pTempResult);
    free(pTempNumberA);
    free(pTempNumberB);
    Stack_Free(pNumberStack);
    return result;
}

void FreeData() {
    return;
}
