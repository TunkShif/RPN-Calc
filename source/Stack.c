#include "../include/Stack.h"
#include <stdlib.h>
#include <string.h>

Stack *Stack_NewStack(int stackSize, int elementSize) {
    Stack *pStack = (Stack *) malloc(sizeof(Stack));
    if (pStack == NULL) {
        return NULL;
    }
    pStack->pBase = (void *) calloc(stackSize, elementSize);
    pStack->pTop = pStack->pBase;
    pStack->elementSize = elementSize;
    pStack->stackSize = stackSize;
    return pStack;
}

bool Stack_IsEmpty(Stack *pStack) {
    return pStack->pBase == pStack->pTop;
}

bool Stack_IsFull(Stack *pStack) {
    return Stack_GetLength(pStack) == Stack_GetSize(pStack);
}

int Stack_GetSize(Stack *pStack) {
    return pStack->stackSize;
}

int Stack_GetLength(Stack *pStack) {
    return (pStack->pTop - pStack->pBase) / pStack->elementSize;
}

int Stack_IncreaseSize(Stack *pStack, int incrementSize) {
    int newSize = pStack->stackSize + incrementSize;
    int currentLength = Stack_GetLength(pStack);
    void *pTemp = (void *) realloc(pStack->pBase, newSize * pStack->elementSize);

    if (pTemp == NULL) {
        return 1;
    }

    pStack->pBase = pTemp;
    pStack->pTop = pStack->pBase + currentLength * pStack->elementSize;
    pStack->stackSize = newSize;

    return 1;
}

int Stack_Push(Stack *pStack, void *pElement) {
    if (Stack_IsFull(pStack)) {
        Stack_IncreaseSize(pStack, DEFAULT_STACK_INCREMENT_SIZE);
    }

    memcpy(pStack->pTop, pElement, pStack->elementSize);
    pStack->pTop = pStack->pTop + pStack->elementSize;
    return 1;
}

int Stack_Pop(Stack *pStack) {
    if (Stack_IsEmpty(pStack)) {
        return 1;
    }
    pStack->pTop = pStack->pTop - pStack->elementSize;
    return 1;
}

int Stack_PopTo(Stack *pStack, void *pDestination) {
    if (Stack_IsEmpty(pStack)) {
        return 1;
    }
    pStack->pTop = pStack->pTop - pStack->elementSize;
    memcpy(pDestination, pStack->pTop, pStack->elementSize);
    return 1;
}

int Stack_GetTop(Stack *pStack, void *pDestination) {
    if (Stack_IsEmpty(pStack)) {
        return 1;
    }
    memcpy(pDestination, pStack->pTop - pStack->elementSize, pStack->elementSize);
    return 1;
}

int Stack_Traverse(Stack *pStack, int (*func)()) {
    int i;
    int length = Stack_GetLength(pStack);
    int status;
    for (i = 0; i < length; i++) {
        status = func(pStack->pBase + i * pStack->elementSize);
        if (status == 1) {
            return status;
        }
    }
    return 0;
}

void Stack_Free(Stack *pStack) {
    free(pStack->pBase);
    pStack->pBase = NULL;
    pStack->pTop = NULL;
    pStack->elementSize = 0;
    pStack->stackSize = 0;
}