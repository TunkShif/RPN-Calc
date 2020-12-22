#ifndef CALC_LEXER_H
#define CALC_LEXER_H
#define MAX_TOKEN_LENGTH 10

/**
 * enum for Token Type
 * BASE: # NUM: Number
 * ADD: + MINUS: - MUL * DIV / POS: Positive NEG: Negative
 * POW: ^ LPAREN: ( RPAREN: )
 */
typedef enum TokenType {
    BASE, NUM, ADD, MINUS, MUL, DIV, POS, NEG,
    SIN, COS, ASIN, ACOS, LOG, SQRT, POW, LPAREN, RPAREN
} TokenType;

/**
 * Token struct
 * @member:
 *     type: the enum type of the token
 *     value: a string, the value of the token
 *     next: a pointer to the next token struct
 */
typedef struct Token {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
    struct Token *next;
} Token;

/**
 * Create a new token struct and link it with a pCurrent token struct
 * @params:
 *     pCurrent: pointer to the pCurrent token
 *     type: the type of the token
 *     start: pointer to the starting character for the token value
 *     length: length of the token value
 * @return:
 *     pointer to the newly created token
 *     return NULL when failing to allocate memory
 */
Token *Token_NewToken(Token *pCurrent, TokenType type, char *start, int length);

/**
 * Tokenize the given expression to get a token stream
 * @params:
 *     src: string of the expression
 * @return:
 *     head of the token stream
 *     return NULL when the given expression is invalid
 */
Token *Token_Tokenize(char *src);

/**
 * Print the value of each token of a token stream
 * @params:
 *     pHead: pHead of the token stream
 */
void Token_Print(Token *pHead);

/**
 * Destruct the token stream
 * @params:
 *     pHead: pHead of the token stream
 */
void Token_Free(Token *pHead);

#endif