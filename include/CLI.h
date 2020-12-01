#ifndef RPN_CALC_CLI_H
#define RPN_CALC_CLI_H
#include <stdio.h>
#include <stdbool.h>
#include "Parser.h"
#include "Calculator.h"
#include "File.h"
#include "String.h"
#define MAX_INPUT_NUMBER 100
#define WELCOME_MESSAGE "Help: Input an arithmetic expression and get the value, q for exit"
#define PROMPT_MESSAGE "Input an expression: "
#define INVALID_EXPRESSION_MESSAGE "Invalid expression, try again!"
#define DIVIDE_ZERO_MESSAGE "Can't divide by zero, input again!"

void PrintBar(int n);

void PrintLogo(void);

void PromptLoop(void);

void CalcFromFile(char *filePath);

Status *CalcCallBack(char *str);
#endif
