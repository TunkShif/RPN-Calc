#ifndef RPN_CALC_PARSER_H
#define RPN_CALC_PARSER_H
#include <ctype.h>
#include <string.h>
#include "Utils.h"
#include "structures/String.h"
#include "structures/LinkedStack.h"

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

String *ExtractFirstNumberFromString(char *str);

/*
 * InfixToSuffix
 * Convert an infix expression to suffix expression
 * @param:
 *     char *srcString: the source string of the infix expression
 *     char *destString: the destination string of the suffix expression
 * @return:
 *     Status*
 */
char *InfixToSuffix(char *srcString);

#endif
