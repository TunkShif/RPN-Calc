#ifndef RPN_CALC_UTILS_H
#define RPN_CALC_UTILS_H
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "Status.h"

/*
 * IsOperator
 * Check if a character is a valid operator
 * @param:
 *     const char ch: character
 * @return:
 *     bool
 */
bool IsOperator(const char ch);

/*
 * IsValidNumber
 * Check if a string is a valid float or int number
 * No positive or negative allowed for check
 * @param:
 *     const char *str: the string to be checked
 * @return:
 *     bool
 */
bool IsValidNumber(const char *str);

/*
 * ConvertStringToFloat
 * Convert a string of a number to float type number
 * @param:
 *     const char *str: the string to be converted
 * @return:
 *     float
 */
float ConvertStringToFloat(const char *str);

/*
 * PrintChar
 * Used for traversing a stack or a list
 * @param:
 *     char *ch: a pointer to the element
 * @return:
 *     Status*
 */
Status *PrintChar(const char *ch);

/*
 * PrintInt
 * Used for traversing a stack or a list
 * @param:
 *     int *n: a pointer to the element
 * @return:
 *     Status*
 */
Status *PrintInt(const int *n);

/*
 * PrintString
 * Used for traversing a stack or a list
 * @param:
 *     char *str: string
 * @return:
 *     Status*
 */
Status *PrintString(const char *str);

/*
 * NoNeedToFreeData
 * An empty function used as a placeholder
 * when free a linked list node but there is
 * no need to free data
 */
void NoNeedToFreeData();
#endif
