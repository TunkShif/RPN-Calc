#include "LinkedStack.h"

LinkedStack *LinkedStack_NewStack(void) {
    LinkedStack *pStack = (LinkedStack *) malloc(sizeof(LinkedStack));
    pStack->pList = LinkedList_NewList();
    return pStack;
}

bool LinkedStack_IsEmpty(LinkedStack *pStack) {
    return pStack->pList->length == 0;
}

int LinkedStack_Length(LinkedStack *pStack) {
    return pStack->pList->length;
}

Status *LinkedStack_Push(LinkedStack *pStack, void *pElement) {
    return LinkedList_Append(pStack->pList, pElement);
}

void *LinkedStack_Pop(LinkedStack *pStack, void (*freeData)()) {
    int length = LinkedList_Length(pStack->pList);
    LinkedListNode *pLastNode = LinkedList_GetNodeAt(pStack->pList, length - 1);
    if (pLastNode == NULL) {
        return NULL;
    }
    void *pData = LinkedList_GetDataFromNode(pLastNode);
    LinkedList_DeleteLastNode(pStack->pList, freeData);
    return pData;
}

Status *LinkedStack_PopTo(LinkedStack *pStack, void **pDestination, void (*freeDara)()) {
    int length = LinkedList_Length(pStack->pList);
    LinkedListNode *pLastNode = LinkedList_GetNodeAt(pStack->pList, length - 1);
    if (pLastNode == NULL) {
        return Status_NullPointerError();
    }
    *pDestination = LinkedList_GetDataFromNode(pLastNode);
    return LinkedList_DeleteLastNode(pStack->pList, freeDara);
}

void *LinkedStack_GetTop(LinkedStack *pStack) {
    int length = LinkedList_Length(pStack->pList);
    LinkedListNode *pLastNode = LinkedList_GetNodeAt(pStack->pList, length - 1);
    if (pLastNode == NULL) {
        return NULL;
    }
    return LinkedList_GetDataFromNode(pLastNode);
}

char LinkedStack_GetTopChar(LinkedStack *pStack) {
    return *((char *) LinkedStack_GetTop(pStack));
}

Status *LinkedStack_Traverse(LinkedStack *pStack, Status *(*func)()) {
    return LinkedList_Traverse(pStack->pList, func);
}

void LinkedStack_Free(LinkedStack *pStack, void (*freeData)()) {
    LinkedList_FreeList(pStack->pList, freeData);
    pStack->pList = NULL;
    free(pStack);
    pStack = NULL;
}