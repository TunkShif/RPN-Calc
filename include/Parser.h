#ifndef RPN_CALC_PARSER_H
#define RPN_CALC_PARSER_H
#include <ctype.h>
#include <string.h>
#include "Utils.h"
#include "String.h"
#include "LinkedStack.h"

/*
 * GetPriority
 * Get the priority of a operator
 * 0: '#', 1: '(', 2: '+' '-', 3: '*' '/'
 * if the input is not a valid operator,
 * return -1 instead
 * @param:
 *     char operator: arithmetic operator
 * @return:
 *     int
 */
int GetPriority(char operator);

/*
 * ExtractFirstNumberFromString
 * Find the first number from a string.
 * e.g. given "test3.14test", return "3.14"
 * Return NULL if there's no number in it
 * @param:
 *     char *str: a string containing number
 * @return:
 *     String*
 */
String *ExtractFirstNumberFromString(char *str);

/*
 * PreprocessSign
 * Preprocess an expression with positive or
 * negative sign.
 * e.g. given "(+5)-(-7)", return "(0+5)-(0-7)"
 * @param:
 *     char *str: a string containing number
 * @return:
 *     char*
 */
char *PreprocessSign(char *srcString);

/*
 * InfixToSuffix
 * Convert an infix expression to suffix expression,
 * return null if the expression is invalid
 * @param:
 *     char *srcString: the source string of the infix expression
 * @return:
 *     char*
 */
char *InfixToSuffix(char *srcString);

#endif
