#ifndef RPN_CALC_CALCULATOR_H
#define RPN_CALC_CALCULATOR_H
#include <math.h>
#include "Utils.h"
#include "structures/Stack.h"
#include "structures/LinkedStack.h"
#include "structures/String.h"

float CalculateFromSuffixExpression(char *str);

float CalculateFromInfixExpression(char *str);

#endif
