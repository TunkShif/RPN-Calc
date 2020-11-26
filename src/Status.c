#include "../include/Status.h"

Status *Status_NewStatus(Code code, char *msg) {
    Status *pStatus = (Status *) malloc(sizeof(Status));
    pStatus->code = code;
    pStatus->msg = msg;
    return pStatus;
}

Status *Status_MallocFailed(void) {
    Status *pStatus = Status_NewStatus(ERROR, "ERROR: Failed to allocate memory.");
    return pStatus;
}

Status *Status_StackEmptyError(void) {
    Status *pStatus = Status_NewStatus(ERROR, "ERROR: The stack is empty.");
    return pStatus;
}

Status *Status_ListEmptyError(void) {
    Status *pStatus = Status_NewStatus(ERROR, "ERROR: The list is empty.");
    return pStatus;
}

Status *Status_OutOfIndex(void) {
    Status *pStatus = Status_NewStatus(ERROR, "ERROR: Out of index.");
    return pStatus;
}

Status *Status_NullPointerError(void) {
    Status *pStatus = Status_NewStatus(ERROR, "ERROR: Null pointer.");
    return pStatus;
}

Status *Status_FileNotFound(void) {
    Status *pStatus = Status_NewStatus(ERROR, "ERROR: File not found");
}

Status *Status_ActionSucceeded(void) {
    Status *pStatus = Status_NewStatus(SUCCESS, "INFO: Action succeeded.");
    return pStatus;
}

Status *Status_CustomFailedMsg(char *msg) {
    Status *pStatus = Status_NewStatus(ERROR, msg);
    return pStatus;
}

Status *Status_CustomSucceededMsg(char *msg) {
    Status *pStatus = Status_NewStatus(SUCCESS, msg);
    return pStatus;
}