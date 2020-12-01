#ifndef RPN_CALC_CALCULATOR_H
#define RPN_CALC_CALCULATOR_H
#include <math.h>
#include "Utils.h"
#include "Stack.h"
#include "LinkedStack.h"
#include "String.h"

/*
 * CalculateFroSuffixExpression
 * Calculate the result value from a suffix
 * expression.
 * @param:
 *     char *str: the suffix expression
 * @return:
 *     float
 */
float CalculateFromSuffixExpression(char *str);

float CalculateFromInfixExpression(char *str);

#endif
