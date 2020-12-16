#ifndef CALC_LEXER_H
#define CALC_LEXER_H
#define MAX_TOKEN_LENGTH 10

typedef enum TokenType {
    BASE = 128, NUM, ADD, MINUS, MUL, DIV, POS, NEG,
    SIN, COS, LOG, SQRT, LPAREN, RPAREN
} TokenType;

typedef struct Token {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
    struct Token *next;
} Token;

Token *Token_NewToken(Token *current, TokenType type, char *start, int length);

Token *Token_Tokenize(char *src);

void Token_Print(Token *head);

void Token_Free(Token *head);

#endif