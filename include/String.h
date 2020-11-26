#ifndef RPN_CALC_STRING_H
#define RPN_CALC_STRING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Status.h"
#define DEFAULT_STRING_SIZE 50
#define DEFAULT_STRING_INCREMENT 50

/*
 * String
 * @member:
 *     char *str: internal dynamic array to store data
 *     int size: the max capacity of the string
 */
typedef struct String {
    char *str;
    int size;
} String;

/*
 * String_NewString
 * Create an empty string with an initial size
 * The default value is defined in the marco
 * DEFAULT_STRING_SIZE, whose value is 50
 * @param:
 *     int size: the max capacity of the string
 * @return:
 *     String*
 */
String *String_NewString(int size);

/*
 * String_NewStringFrom
 * Create a string from an existed C string
 * The default size is defined in the marco
 * DEFAULT_STRING_SIZE, whose value is 50
 * @param:
 *     char *str: a C string
 * @return:
 *     String*
 */
String *String_NewStringFrom(char *str);

/*
 * String_IncreaseSize
 * Increase the size of a string, the default
 * size increment is defined in the marco
 * DEFAULT_STRING_INCREMENT, whose value is 50
 * @param:
 *     String *pStr: a pointer to string struct
 *     int newSize: a size greater than its original size
 * @return:
 *     String*
 */
Status *String_IncreaseSize(String *pStr, int newSize);

/*
 * String_SetValue
 * Change the content of the string struct
 * @param:
 *     String *pStr: a pointer to string struct
 *     char *str: a C string
 * @return:
 *     Status*
 */
Status *String_SetValue(String *pStr, char *str);

/*
 * String_GetCharAt
 * Get a character from string by the given index
 * @param:
 *     String *pStr: a pointer to string struct
 *     int index: the index of the character
 * @return:
 *     char
 */
char String_GetCharAt(String *pStr, int index);

/*
 * String_InsertCharAt TODO
 * Insert a character after the character of given index
 * @param:
 *     String *pStr: a pointer to string struct
 *     int index: the index of the character
 * @return:
 *     Status*
 */
Status *String_InsertCharAt(String *pStr, int index, char ch);

Status *String_InsertCharAtHead(String *pStr, char ch);

/*
 * String_SetCharAt
 * Change a character of a string by the given index
 * @param:
 *     String *pStr: a pointer to string struct
 *     int index: the index of the character
 *     char ch: the new character
 * @return:
 *     Status*
 */
Status *String_SetCharAt(String *pStr, int index, char ch);

/*
 * String_RemoveLastChar
 * Remove the last non-null character, i.e. set the
 * last non-null character to '\0'
 * @param:
 *     String *pStr: a pointer to string struct
 * @return:
 *     Status*
 */
Status *String_RemoveLastChar(String *pStr);

/*
 * String_Slice
 * Get a slice of the string by the give closed range
 * If the op equals ed, return a single character string
 * Similar the string slice in Python
 * @param:
 *     String *pStr: a pointer to string struct
 *     int op: the opening index of the range
 *     int ed: the ending index of the range
 * @return:
 *     String*
 */
String *String_Slice(String *pStr, int op, int ed);

/*
 * String_ConcatString
 * Append the C string to the end of the string struct
 * @param:
 *     String *pStr: a pointer to string struct
 *     char *str: a C string
 * @return:
 *     Status*
 */
Status *String_ConcatString(String *pStr, char *str);

/*
 * String_AppendChar
 * Append a single character to the end of the string
 * @param:
 *     String *pStr: a pointer to string struct
 *     char ch: a single character
 * @return:
 *     Status*
 */
Status *String_AppendChar(String *pStr, char ch);

bool String_IsSingleChar(String *pStr);

bool String_HasChar(String *pStr, char key);

bool String_HasWord(String *pStr, char *key);

int String_FindFirstCharIndex(String *pStr, char key);

Status *String_ReplaceWithChar(String *pStr, char key, char replace);

/*
 * String_ToCString
 * Convert the string struct to a character array
 * @param:
 *     String *pStr: a pointer to string struct
 * @return:
 *     char*
 */
char *String_ToCString(String *pStr);

/*
 * String_GetSize
 * Get the size of a string
 * @param:
 *     String *pStr: a pointer to string struct
 * @return:
 *     int
 */
int String_GetSize(String *pStr);

/*
 * String_GetLength
 * Get the length of a string
 * @param:
 *     String *pStr: a pointer to string struct
 * @return:
 *     int
 */
int String_GetLength(String *pStr);

/*
 * String_Print
 * Print the content of the string
 * @param:
 *     String *pStr: a pointer to string struct
 */
void String_Print(String *pStr);

/*
 * String_Println
 * Print the content of the string with a new line character
 * @param:
 *     String *pStr: a pointer to string struct
 */
void String_Println(String *pStr);

/*
 * String_Free
 * Free a string struct
 * @param:
 *     String *pStr: a pointer to string struct
 */
void String_Free(String *pStr);
#endif
