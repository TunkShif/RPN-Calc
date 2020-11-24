#include "String.h"

String *String_NewString(int size) {
    char *str = (char *) malloc(sizeof(char) * size);
    if (str == NULL) {
        return NULL;
    }
    memset(str, '\0', size);
    String *pString = (String *) malloc(sizeof(String));
    pString->str = str;
    pString->size = size;
    return pString;
}

String *String_NewStringFrom(char *str) {
    String *pStr = String_NewString(DEFAULT_STRING_SIZE);
    int length = strlen(str);
    if (length >= pStr->size) {
        String_IncreaseSize(pStr, length + 1);
        pStr->size = length + 1;
    }
    strcpy(pStr->str, str);
    return pStr;
}

Status *String_IncreaseSize(String *pStr, int newSize) {
    int size = pStr->size;
    if (newSize <= size) {
        return Status_CustomFailedMsg("ERROR: New size is smaller than the original size.");
    }

    char *strTemp = (char *) malloc(sizeof(char) * newSize);
    if (strTemp == NULL) {
        return Status_MallocFailed();
    }
    memset(strTemp, '\0', newSize);
    strcpy(strTemp, pStr->str);

    free(pStr->str);
    pStr->str = strTemp;
    pStr->size = newSize;

    return Status_ActionSucceeded();
}

Status *String_SetValue(String *pStr, char *str) {
    int size = String_GetSize(pStr);
    int srcLength = strlen(str);

    if (srcLength >= size) {
        String_IncreaseSize(pStr, srcLength + 1);
        pStr->size = srcLength + 1;
    }
    memset(pStr->str, '\0', pStr->size);
    strcpy(pStr->str, str);
    return Status_ActionSucceeded();
}

char String_GetCharAt(String *pStr, int index) {
    int length = String_GetLength(pStr);
    if (index >= length || index < 0) {
        return '\0';
    }
    int i;
    for (i = 0; i < index; i++);
    return pStr->str[i];
}

Status *String_SetCharAt(String *pStr, int index, char ch) {
    int length = String_GetLength(pStr);
    if (index >= length || index < 0) {
        return Status_OutOfIndex();
    }
    pStr->str[index] = ch;
    return Status_ActionSucceeded();
}

Status *String_RemoveLastChar(String *pStr) {
    int length = String_GetLength(pStr);
    return String_SetCharAt(pStr, length - 1, '\0');
}

String *String_Slice(String *pStr, int op, int ed) {
    int length = String_GetLength(pStr);
    if (op >= length || ed >= length || op < 0 || ed < 0 || op > ed) {
        return NULL;
    }

    String *pNewStr;
    if (op == ed) {
        pNewStr = String_NewString(2);
        pNewStr->str[0] = String_GetCharAt(pStr, op);
        pNewStr->str[1] = '\0';
        return pNewStr;
    }

    int newLength = ed - op + 1;
    pNewStr = String_NewString(newLength + 1);
    strncpy(pNewStr->str, pStr->str + op, newLength);
    return pNewStr;
}

Status *String_ConcatString(String *pStr, char *str) {
    int size = String_GetSize(pStr);
    int currentLength = String_GetLength(pStr);
    int length = strlen(str);

    if (currentLength + length >= size) {
        String_IncreaseSize(pStr, currentLength + length + 1);
    }

    strcpy(pStr->str + currentLength, str);
    return Status_ActionSucceeded();
}

Status *String_AppendChar(String *pStr, char ch) {
    int size = String_GetSize(pStr);
    int length = String_GetLength(pStr);
    if (length + 1 == size) {
        String_IncreaseSize(pStr, DEFAULT_STRING_INCREMENT);
    }
    pStr->str[length] = ch;
    return Status_ActionSucceeded();
}

bool String_IsSingleChar(String *pStr) {
    return (String_GetLength(pStr) == 1) ? true : false;
}

bool String_HasChar(String *pStr, char key) {
    return (strchr(pStr->str, key) != NULL) ? true : false;
}

bool String_HasWord(String *pStr, char *key) {
    return (strstr(pStr->str, key) != NULL) ? true : false;
}

int String_FindFirstCharIndex(String *pStr, char key) {
    if (!String_HasChar(pStr, key)) {
        return -1;
    }
    int length = String_GetLength(pStr);
    for (int i = 0; i < length; i++) {
        if (pStr->str[i] == key) {
            return i;
        }
    }
}

Status *String_ReplaceWithChar(String *pStr, char key, char newChar) {
    if (pStr == NULL) {
        return Status_NullPointerError();
    }
    int length = String_GetLength(pStr);
    for (int i = 0; i < length; i++) {
        if (pStr->str[i] == key) {
            pStr->str[i] = newChar;
        }
    }
    return Status_ActionSucceeded();
}

char *String_ToCString(String *pStr) {
    if (pStr == NULL || pStr->str[0] == '\0') {
        return NULL;
    }
    int length = String_GetLength(pStr);
    char *str = (char *) malloc(length + 1);
    if (str == NULL) {
        return NULL;
    }
    strcpy(str, pStr->str);
//    strncpy(str, pStr->str, length); // TODO
    str[length] = '\0';
    return str;
}

int String_GetSize(String *pStr) {
    return pStr->size;
}

int String_GetLength(String *pStr) {
    return strlen(pStr->str);
}

void String_Print(String *pStr) {
    if (pStr == NULL) {
        printf("%s", Status_NullPointerError()->msg);
    }
    printf("%s", pStr->str);
}

void String_Println(String *pStr) {
    if (pStr == NULL) {
        puts(Status_NullPointerError()->msg);
    }
    puts(pStr->str);
}

void String_Free(String *pStr) {
    if (pStr != NULL) {
        free(pStr->str);
        pStr->size = 0;
        free(pStr);
        pStr = NULL;
    }
}