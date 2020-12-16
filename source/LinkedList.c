#include "../include/LinkedList.h"
#include <stdlib.h>

LinkedListNode *LinkedList_NewNode(void *pData) {
    LinkedListNode *pNode = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    if (pNode == NULL) {
        return NULL;
    }
    pNode->pData = pData;
    pNode->pNextNode = NULL;
    return pNode;
};

void *LinkedList_GetDataFromNode(LinkedListNode *pNode) {
    if (pNode != NULL) {
        return pNode->pData;
    }
    return NULL;
}

LinkedList *LinkedList_NewList(void) {
    LinkedList *pList = (LinkedList *) malloc(sizeof(LinkedList));
    if (pList == NULL) {
        return NULL;
    }
    pList->pHeadNode = NULL;
    pList->length = 0;
    return pList;
}

bool LinkedList_IsEmpty(LinkedList *pList) {
    return (pList->length == 0) ? true : false;
}

int LinkedList_Length(LinkedList *pList) {
    return pList->length;
}

LinkedListNode *LinkedList_GetNodeAt(LinkedList *pList, int index) {
    int length = LinkedList_Length(pList);
    if ((index > length) || (index < 0)) {
        return NULL;
    }
    if (pList->pHeadNode == NULL) {
        return NULL;
    }
    int i;
    LinkedListNode *pCurrentNode = pList->pHeadNode;
    for (i = 0; i < index; i++) {
        pCurrentNode = pCurrentNode->pNextNode;
    }
    return pCurrentNode;
}

int LinkedList_InsertAtHead(LinkedList *pList, void *pData) {
    LinkedListNode *pNewNode = LinkedList_NewNode(pData);
    if (pNewNode == NULL) {
        return 1;
    }
    pNewNode->pNextNode = pList->pHeadNode;
    pList->pHeadNode = pNewNode;
    pList->length++;
    return 0;
}

int LinkedList_Append(LinkedList *pList, void *pData) {
    LinkedListNode *pNewNode = LinkedList_NewNode(pData);
    if (pNewNode == NULL) {
        return 1;
    }

    if (LinkedList_IsEmpty(pList)) {
        pList->pHeadNode = pNewNode;
    } else {
        LinkedListNode *pCurrentNode;
        for (pCurrentNode = pList->pHeadNode; pCurrentNode->pNextNode != NULL; pCurrentNode = pCurrentNode->pNextNode);
        pCurrentNode->pNextNode = pNewNode;
    }
    pList->length++;
    return 0;
}

int LinkedList_DeleteHeadNode(LinkedList *pList, void (*freeData)()) {
    if (LinkedList_IsEmpty(pList)) {
        return 1;
    }
    LinkedListNode *pTempNode = pList->pHeadNode;
    pList->pHeadNode = pTempNode->pNextNode;
    LinkedList_FreeNode(pTempNode, freeData);
    pTempNode = NULL;
    pList->length--;
    return 0;
}

int LinkedList_DeleteLastNode(LinkedList *pList, void (*freeData)()) {
    if (LinkedList_IsEmpty(pList)) {
        return 1;
    }

    LinkedListNode *pTempNode = pList->pHeadNode;
    if (pTempNode->pNextNode == NULL) {
        LinkedList_FreeNode(pTempNode, freeData);
        return 0;
    }

    int length = LinkedList_Length(pList);
    pTempNode = LinkedList_GetNodeAt(pList, length - 1 - 1);
    LinkedListNode *pLastNode = pTempNode->pNextNode;
    LinkedList_FreeNode(pLastNode, freeData);
    pLastNode = NULL;
    pTempNode->pNextNode = NULL;
    pList->length--;
    return 0;
}

int LinkedList_DeleteNodeAt(LinkedList *pList, int index, void (*freeData)()) {
    if (LinkedList_IsEmpty(pList)) {
        return 1;
    }

    int length = LinkedList_Length(pList);
    if (index >= length || index < 0) {
        return 1;
    } else if (index == 0) {
        return LinkedList_DeleteHeadNode(pList, freeData);
    } else if (index == length - 1) {
        return LinkedList_DeleteLastNode(pList, freeData);
    }

    int i;
    LinkedListNode *pCurrentNode = pList->pHeadNode;
    for (i = 0; i < index - 1; i++) {
        pCurrentNode = pCurrentNode->pNextNode;
    }
    LinkedListNode *pTempNode = pCurrentNode->pNextNode;
    if (pTempNode->pNextNode == NULL) {
        LinkedList_FreeNode(pTempNode, freeData);
        pTempNode = NULL;
        pCurrentNode->pNextNode = NULL;
    } else {
        pCurrentNode->pNextNode = pTempNode->pNextNode;
        LinkedList_FreeNode(pTempNode, freeData);
        pTempNode = NULL;
    }
    return 0;
}

LinkedListNode *LinkedList_FindNodeByKey(LinkedList *pList, void *pKey, bool (*isEqual)()) {
    if (LinkedList_IsEmpty(pList)) {
        return NULL;
    }
    LinkedListNode *pCurrentNode;
    for (pCurrentNode = pList->pHeadNode; pCurrentNode->pNextNode != NULL; pCurrentNode = pCurrentNode->pNextNode) {
        void *pData = LinkedList_GetDataFromNode(pCurrentNode);
        if (isEqual(pData, pKey)) {
            return pCurrentNode;
        }
    }
    return NULL;
}

void LinkedList_Clear(LinkedList *pList, void (*freeData)()) {
    LinkedListNode *pCurrentNode;
    for (pCurrentNode = pList->pHeadNode; pCurrentNode->pNextNode != NULL; pCurrentNode = pCurrentNode->pNextNode) {
        LinkedList_FreeNode(pCurrentNode, freeData);
    }
    pList->pHeadNode = NULL;
    pList->length = 0;
}

int LinkedList_Traverse(LinkedList *pList, int (*func)()) {
    if (LinkedList_IsEmpty(pList)) {
        return 1;
    }
    LinkedListNode *pCurrentNode;
    int pStatus;
    for (pCurrentNode = pList->pHeadNode; pCurrentNode != NULL; pCurrentNode = pCurrentNode->pNextNode) {
        int status = func(LinkedList_GetDataFromNode(pCurrentNode));
        if (status == 1) {
            return status;
        }
    }
    return 0;
}

void LinkedList_FreeNode(LinkedListNode *pNode, void (*freeData)()) {
    if (pNode != NULL) {
        freeData(pNode->pData);
    }
    pNode = NULL;
    free(pNode);
};

void LinkedList_FreeList(LinkedList *pList, void (*freeData)()) {
    LinkedList_Clear(pList, freeData);
    pList = NULL;
    free(pList);
}