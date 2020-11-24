#include "Utils.h"
#include <stdio.h>

bool IsOperator(const char ch) {
    bool flag = false;
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
        flag = true;
    }
    return flag;
}

bool IsValidNumber(const char *str) {
    int i;
    int length = strlen(str);
    for (i = 0; i < length; i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'))) {
            return false;
        }
    }
    return true;
}

float ConvertStringToFloat(const char *str) {
    int i = 0;
    float value = 0;
    while (str[i] != '\0' && str[i] != '.') {
        value = value * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '\0') {
        return value;
    } else if (str[i++] == '.') {
        float weight = 0.1f;
        while (str[i] != '\0') {
            value = value + (str[i] - '0') * weight;
            weight = weight / 10;
            i++;
        }
        return value;
    }
}

Status *PrintChar(const char *ch) {
    putchar(*ch);
    return Status_ActionSucceeded();
}

Status *PrintInt(const int *n) {
    printf("%d", *n);
    return Status_ActionSucceeded();
}

Status *PrintString(const char *str) {
    puts(str);
    return Status_ActionSucceeded();
}

void NoNeedToFreeData() {
    return;
}
