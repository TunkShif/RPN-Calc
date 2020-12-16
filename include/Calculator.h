#ifndef CALC_CALCULATOR_H
#define CALC_CALCULATOR_H
#include "Lexer.h"
#include <stdbool.h>
#define INVALID_EXPRESSION_MESSAGE "ERROR: Invalid expression! Exiting..."
#define DIVISION_BY_ZERO_MESSAGE "ERROR: Division by zero! Exiting..."
#define SQUARE_ROOT_ERROR_MESSAGE "ERROR: Can't find the square root of negative number! Exiting..."

int GetPriority(TokenType operator);

bool IsUnaryOperator(TokenType operator);

double ConvertStringToFloat(const char *str);

Token *InfixToSuffix(Token *head);

double CalculateFromSuffix(Token *head);

void FreeData();

#endif
