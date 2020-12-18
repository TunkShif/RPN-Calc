#include "../include/Lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Token *Token_NewToken(Token *pCurrent, TokenType type, char *start, int length) {
    Token *pToken = calloc(1, sizeof(Token));
    if (pToken == NULL) {
        return NULL;
    }
    pToken->type = type;
    memset(pToken->value, '\0', MAX_TOKEN_LENGTH);
    memcpy(pToken->value, start, length);
    pCurrent->next = pToken;
    return pToken;
}

Token *Token_Tokenize(char *str) {
    Token head;
    head.next = NULL;
    Token *pCurrent = &head;

    int i = 0;

    while (str[i] != '\0') {
        if (isspace(str[i])) {
            i++;
            continue;
        } else if (str[i] == '+') {
            if (i == 0 || str[i - 1] == '(') {
                pCurrent = Token_NewToken(pCurrent, POS, str + i, 1);
            } else {
                pCurrent = Token_NewToken(pCurrent, ADD, str + i, 1);
            }
        } else if (str[i] == '-') {
            if (i == 0 || str[i - 1] == '(') {
                pCurrent = Token_NewToken(pCurrent, NEG, str + i, 1);
            } else {
                pCurrent = Token_NewToken(pCurrent, MINUS, str + i, 1);
            }
        } else if (str[i] == '*') {
            pCurrent = Token_NewToken(pCurrent, MUL, str + i, 1);
        } else if (str[i] == '/') {
            pCurrent = Token_NewToken(pCurrent, DIV, str + i, 1);
        } else if (str[i] == '^') {
            pCurrent = Token_NewToken(pCurrent, POW, str + i, 1);
        } else if (isdigit(str[i])) {
            int start = i;
            while (isdigit(str[i]) || str[i] == '.') {
                i++;
            }
            pCurrent = Token_NewToken(pCurrent, NUM, str + start, i - start);
            continue;
        } else if (isalpha(str[i])) {
            int start = i;
            while (isalpha(str[i])) {
                i++;
            }
            char temp[MAX_TOKEN_LENGTH];
            memset(temp, '\0', MAX_TOKEN_LENGTH);
            memcpy(temp, str + start, i - start);
            if (strcmp(temp, "sin") == 0) {
                pCurrent = Token_NewToken(pCurrent, SIN, str + start, i - start);
            } else if (strcmp(temp, "cos") == 0) {
                pCurrent = Token_NewToken(pCurrent, COS, str + start, i - start);
            } else if (strcmp(temp, "ln") == 0) {
                pCurrent = Token_NewToken(pCurrent, LOG, str + start, i - start);
            } else if (strcmp(temp, "sqrt") == 0) {
                pCurrent = Token_NewToken(pCurrent, SQRT, str + start, i - start);
            } else if (strcmp(temp, "asin") == 0) {
                pCurrent = Token_NewToken(pCurrent, ASIN, str + start, i - start);
            } else if (strcmp(temp, "acos") == 0) {
                pCurrent = Token_NewToken(pCurrent, ACOS, str + start, i - start);
            } else {
                return NULL;
            }
            continue;
        } else if (str[i] == '(') {
            pCurrent = Token_NewToken(pCurrent, LPAREN, str + i, 1);
        } else if (str[i] == ')') {
            pCurrent = Token_NewToken(pCurrent, RPAREN, str + i, 1);
        } else {
            return NULL;
        }

        i++;
    }

    return head.next;
}

void Token_Print(Token *pHead) {
    for (Token *pCurrent = pHead; pCurrent != NULL ; pCurrent = pCurrent->next) {
        printf("%s ", pCurrent->value);
    }
}

void Token_Free(Token *pHead) {
    Token *pCurrent = NULL;
    while (pHead != NULL) {
        pCurrent = pHead;
        pHead = pHead->next;
        free(pCurrent);
    }
}
