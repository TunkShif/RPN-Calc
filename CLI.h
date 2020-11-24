#ifndef RPN_CALC_CLI_H
#define RPN_CALC_CLI_H
#include <stdio.h>
#include <stdbool.h>
#include "Parser.h"
#include "Calculator.h"
#include "structures/String.h"
#define MAX_INPUT_NUMBER 100
#define WELCOME_MESSAGE "RPN-Calc\nHelp: Input an arithmetic expression and get the value, q for exit"
#define PROMPT_MESSAGE "Input an expression: "
#define INVALID_EXPRESSION_MESSAGE "Invalid expression, try again!"
#define DIVIDE_ZERO_MESSAGE "Can't divide by zero, input again!"

void PrintBar(int n);

void PromptLoop(void);

#endif
