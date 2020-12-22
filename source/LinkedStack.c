#include "../include/LinkedStack.h"
#include <stdlib.h>

LinkedStack *LinkedStack_NewStack(void) {
    return LinkedList_NewList();
}

bool LinkedStack_IsEmpty(LinkedStack *pStack) {
    return pStack->length == 0;
}

int LinkedStack_Length(LinkedStack *pStack) {
    return pStack->length;
}

int LinkedStack_Push(LinkedStack *pStack, void *pElement) {
    return LinkedList_InsertAtHead(pStack, pElement);
}

void *LinkedStack_Pop(LinkedStack *pStack, void (*freeData)()) {
    LinkedListNode *pHeadNode = LinkedList_GetNodeAt(pStack, 0);
    if (pHeadNode == NULL) {
        return NULL;
    }
    void *pData = LinkedList_GetDataFromNode(pHeadNode);
    LinkedList_DeleteHeadNode(pStack, freeData);
    return pData;
}

int LinkedStack_PopTo(LinkedStack *pStack, void **pDestination, void (*freeDara)()) {
    LinkedListNode *pHeadNode = LinkedList_GetNodeAt(pStack, 0);
    if (pHeadNode == NULL) {
        return 1;
    }
    *pDestination = LinkedList_GetDataFromNode(pHeadNode);
    return LinkedList_DeleteHeadNode(pStack, freeDara);
}

void *LinkedStack_GetTop(LinkedStack *pStack) {
    LinkedListNode *pHeadNode = LinkedList_GetNodeAt(pStack, 0);
    if (pHeadNode == NULL) {
        return NULL;
    }
    return LinkedList_GetDataFromNode(pHeadNode);
}

int LinkedStack_Traverse(LinkedStack *pStack, int (*func)()) {
    return LinkedList_Traverse(pStack, func);
}

void LinkedStack_Free(LinkedStack *pStack, void (*freeData)()) {
    LinkedList_FreeList(pStack, freeData);
    pStack = NULL;
    free(pStack);
}