#ifndef RPN_CALC_FILE_H
#define RPN_CALC_FILE_H
#include <stdio.h>
#include "Status.h"
#define MAX_LINE_LENGTH 100

Status *FileTraverseLines(char *filePath, Status *(*func)());

Status *FileReadLines(char *filePath);

Status *FileAppendLine(char *filePath, char *content);

#endif
