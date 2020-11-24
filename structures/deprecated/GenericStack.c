#include "GenericStack.h"
#define DEBUG 0

Status *Stack_Init(GenericStack *pStack, int size) {
    pStack->pBase = (void **) calloc(size, sizeof(void *));
    if (pStack->pBase == NULL) {
        return Status_MallocFailed();
    }
    pStack->pTop = pStack->pBase;
    pStack->size = size;
    return Status_ActionSucceeded();
}

bool Stack_IsEmpty(GenericStack *pStack) {
    return pStack->pBase == pStack->pTop;
}

bool Stack_IsFull(GenericStack *pStack) {
    return Stack_Length(pStack) == Stack_Size(pStack);
}

int Stack_Size(GenericStack *pStack) {
    return pStack->size;
}

int Stack_Length(GenericStack *pStack) {
    return pStack->pTop - pStack->pBase;
}

Status *Stack_IncreaseSize(GenericStack *pStack, int incrementSize) {
    int newSize = pStack->size + incrementSize;
    int currentLength = Stack_Length(pStack);
    void **pTemp = (void **) realloc(pStack->pBase, newSize);

    if (pTemp == NULL) {
        return Status_MallocFailed();
    }

    pStack->pBase = pTemp;
    pStack->pTop = pStack->pBase + currentLength;
    pStack->size = newSize;

    return Status_ActionSucceeded();
}

Status *Stack_Push(GenericStack *pStack, void *pElement) {
    if (Stack_IsFull(pStack)) {
        Stack_IncreaseSize(pStack, DEFAULT_STACK_INCREMENT_SIZE);
    }

    *(pStack->pTop) = pElement;
    pStack->pTop++;
    return Status_ActionSucceeded();
}

Status *Stack_Pop(GenericStack *pStack) {
    if (Stack_IsEmpty(pStack)) {
        return Status_StackEmptyError();
    }
    pStack->pTop--;
    return Status_ActionSucceeded();
}

Status *Stack_PopTo(GenericStack *pStack, void **pDestination) {
    if (Stack_IsEmpty(pStack)) {
        return Status_StackEmptyError();
    }
    pStack->pTop--;
    *pDestination = *(pStack->pTop);
    return Status_ActionSucceeded();
}

Status *Stack_GetTop(GenericStack *pStack, void **pDestination) {
    if (Stack_IsEmpty(pStack)) {
        return Status_StackEmptyError();
    }
    *pDestination = *(pStack->pTop - 1);
    return Status_ActionSucceeded();
}

Status *Stack_Traverse(GenericStack *pStack, Status *(*func)()) {
    int i;
    int length = Stack_Length(pStack);
    Status *pStatus;
    for (i = 0; i < length; i++) {
        pStatus = func(pStack->pBase[i]);
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
    pStack->size = 0;
}

#if DEBUG
#include <stdio.h>
Status *PrintChar(char *ch) {
    putchar(*ch);
    return Status_ActionSucceeded();
}

int main() {
    char chs[] = {'a', 'c', 'd', 't', 's'};
    GenericStack *pStack = (GenericStack *) malloc(sizeof(GenericStack));
    Stack_Init(pStack, 10);
    for (int i = 0; i < 5; i++) {
        Stack_Push(pStack, &chs[i]);
    }
    Stack_Traverse(pStack, PrintChar);
    Stack_Free(pStack);
    return 0;
}
#endif