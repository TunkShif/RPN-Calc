#include "../include/Lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Token *Token_NewToken(Token *current, TokenType type, char *start, int length) {
    Token *token = calloc(1, sizeof(Token));
    token->type = type;
    memset(token->value, '\0', MAX_TOKEN_LENGTH);
    memcpy(token->value, start, length);
    current->next = token;
    return token;
}

Token *Token_Tokenize(char *str) {
    Token head;
    head.next = NULL;
    Token *current = &head;

    int i = 0;

    while (str[i] != '\0') {
        if (isspace(str[i])) {
            i++;
            continue;
        } else if (str[i] == '+') {
            if (i == 0 || str[i - 1] == '(') {
                current = Token_NewToken(current, POS, str + i, 1);
            } else {
                current = Token_NewToken(current, ADD, str + i, 1);
            }
        } else if (str[i] == '-') {
            if (i == 0 || str[i - 1] == '(') {
                current = Token_NewToken(current, NEG, str + i, 1);
            } else {
                current = Token_NewToken(current, MINUS, str + i, 1);
            }
        } else if (str[i] == '*') {
            current = Token_NewToken(current, MUL, str + i, 1);
        } else if (str[i] == '/') {
            current = Token_NewToken(current, DIV, str + i, 1);
        } else if (isdigit(str[i])) {
            int start = i;
            while (isdigit(str[i]) || str[i] == '.') {
                i++;
            }
            current = Token_NewToken(current, NUM, str + start, i - start);
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
                current = Token_NewToken(current, SIN, str + start, i - start);
            } else if (strcmp(temp, "cos") == 0) {
                current = Token_NewToken(current, COS, str + start, i - start);
            } else if (strcmp(temp, "ln") == 0) {
                current = Token_NewToken(current, LOG, str + start, i - start);
            } else if (strcmp(temp, "sqrt") == 0) {
                current = Token_NewToken(current, SQRT, str + start, i - start);
            } else {
                return NULL;
            }
            continue;
        } else if (str[i] == '(') {
            current = Token_NewToken(current, LPAREN, str + i, 1);
        } else if (str[i] == ')') {
            current = Token_NewToken(current, RPAREN, str + i, 1);
        } else {
            return NULL;
        }

        i++;
    }

    return head.next;
}

void Token_Print(Token *head) {
    for (Token *current = head; current != NULL ; current = current->next) {
        printf("%s ", current->value);
    }
}

void Token_Free(Token *head) {
    Token *current = head;
    while (head->next != NULL) {
        current = head->next;
        head->next = current->next;
        free(current);
    }
    free(head);
    head = NULL;
}
