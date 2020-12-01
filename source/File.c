#include "../include/File.h"

Status *FileTraverseLines(char *filePath, Status *(*func)()) {
    FILE *fp = NULL;
    char line[MAX_LINE_LENGTH] = {'\0'};
    fp = fopen(filePath, "r");
    if (fp == NULL) {
        return Status_FileNotFound();
    }
    Status *pStatus = NULL;
    while (!feof(fp)) {
        fgets(line, MAX_LINE_LENGTH, fp);
        pStatus = func(line);
        if (pStatus->code == ERROR) {
            return pStatus;
        }
    }
    fclose(fp);
    return Status_ActionSucceeded();
}

Status *FileReadLines(char *filePath) {
    FILE *fp = NULL;
    char line[MAX_LINE_LENGTH] = {'\0'};
    fp = fopen(filePath, "r");
    if (fp == NULL) {
        return Status_FileNotFound();
    }
    while (!feof(fp)) {
        fgets(line, MAX_LINE_LENGTH, fp);
        printf("%s", line);
    }
    fclose(fp);
    return Status_ActionSucceeded();
}

Status *FileAppendLine(char *filePath, char *content) {
    FILE *fp = fopen(filePath, "a+");
    if (fp == NULL) {
        return Status_NullPointerError();
    }
    fputs(content, fp);
    fclose(fp);
    return Status_ActionSucceeded();
}
