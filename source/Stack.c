#include "../include/Stack.h"
#define DEBUG 0

GenericStack *Stack_NewStack(int stackSize, int elementSize) {
    GenericStack *pStack = (GenericStack *) malloc(sizeof(GenericStack));
    if (pStack == NULL) {
        return NULL;
    }
    pStack->pBase = (void *) calloc(stackSize, elementSize);
    pStack->pTop = pStack->pBase;
    pStack->elementSize = elementSize;
    pStack->stackSize = stackSize;
    return pStack;
}

bool Stack_IsEmpty(GenericStack *pStack) {
    return pStack->pBase == pStack->pTop;
}

bool Stack_IsFull(GenericStack *pStack) {
    return Stack_Length(pStack) == Stack_Size(pStack);
}

int Stack_Size(GenericStack *pStack) {
    return pStack->stackSize;
}

int Stack_Length(GenericStack *pStack) {
    return (pStack->pTop - pStack->pBase) / pStack->elementSize;
}

Status *Stack_IncreaseSize(GenericStack *pStack, int incrementSize) {
    int newSize = pStack->stackSize + incrementSize;
    int currentLength = Stack_Length(pStack);
    void *pTemp = (void *) realloc(pStack->pBase, newSize * pStack->elementSize);

    if (pTemp == NULL) {
        return Status_MallocFailed();
    }

    pStack->pBase = pTemp;
    pStack->pTop = pStack->pBase + currentLength * pStack->elementSize;
    pStack->stackSize = newSize;

    return Status_ActionSucceeded();
}

Status *Stack_Push(GenericStack *pStack, void *pElement) {
    if (Stack_IsFull(pStack)) {
        Stack_IncreaseSize(pStack, DEFAULT_STACK_INCREMENT_SIZE);
    }

    memcpy(pStack->pTop, pElement, pStack->elementSize);
    pStack->pTop = pStack->pTop + pStack->elementSize;
    return Status_ActionSucceeded();
}

Status *Stack_Pop(GenericStack *pStack) {
    if (Stack_IsEmpty(pStack)) {
        return Status_StackEmptyError();
    }
    pStack->pTop = pStack->pTop - pStack->elementSize;
    return Status_ActionSucceeded();
}

Status *Stack_PopTo(GenericStack *pStack, void *pDestination) {
    if (Stack_IsEmpty(pStack)) {
        return Status_StackEmptyError();
    }
    pStack->pTop = pStack->pTop - pStack->elementSize;
    memcpy(pDestination, pStack->pTop, pStack->elementSize);
    return Status_ActionSucceeded();
}

Status *Stack_GetTop(GenericStack *pStack, void *pDestination) {
    if (Stack_IsEmpty(pStack)) {
        return Status_StackEmptyError();
    }
    memcpy(pDestination, pStack->pTop - pStack->elementSize, pStack->elementSize);
    return Status_ActionSucceeded();
}

Status *Stack_Traverse(GenericStack *pStack, Status *(*func)()) {
    int i;
    int length = Stack_Length(pStack);
    Status *pStatus;
    for (i = 0; i < length; i++) {
        pStatus = func(pStack->pBase + i * pStack->elementSize);
        if (pStatus->code == ERROR) {
            return pStatus;
        }
    }
    return Status_ActionSucceeded();
}

void Stack_Free(GenericStack *pStack) {
    free(pStack->pBase);
    pStack->pBase = NULL;
    pStack->pTop = NULL;
    pStack->elementSize = 0;
    pStack->stackSize = 0;
}