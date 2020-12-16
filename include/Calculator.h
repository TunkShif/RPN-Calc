#ifndef CALC_CALCULATOR_H
#define CALC_CALCULATOR_H
#include "Lexer.h"
#include <stdbool.h>
#define INVALID_EXPRESSION_MESSAGE "ERROR: Invalid expression! Exiting...\n"
#define DIVISION_BY_ZERO_MESSAGE "ERROR: Division by zero! Exiting...\n"
#define DOMAIN_ERROR_MESSAGE "ERROR: Out of the domain of the function! Exiting...\n"

/**
 * Get the priority of an operator
 * @param
 *     operator: the token type of the operator
 * @return
 *     0: Unknown operator
 *     1: '(' Left parenthesis
 *     2: '+' '-' Plus and Minus
 *     3: '*' '/' Multiply and Divide
 *     4: Positive and Negative signs and functions
 */
int GetPriority(TokenType operator);

/**
 * Check if the given operator is an unary operator
 * @param
 *     operator: the token type of the operator
 * @return
 *     true: Positive and Negative sings and functions
 *     false: binary operators and others
 */
bool IsUnaryOperator(TokenType operator);

/*
 * Convert a string of a number to double type number
 * @param
 *     const char *str: the string to be converted
 * @return
 *     double
 */
double ConvertStringToFloat(const char *str);

/**
 * Convert an infix token stream to a suffix one
 * @param
 *     head: head token of the token stream
 * @return
 *     a new suffix token stream
 */
Token *InfixToSuffix(Token *head);

/**
 * Calculate value from a suffix token stream
 * Program will exit and print a message when
 * error occurs during the calculating process
 * @param
 *     head: head token of the token stream
 * @return
 *     the result
 */
double CalculateFromSuffix(Token *head);

/**
 * An empty function used in LinkedStack_Pop()
 */
void FreeData();

#endif
