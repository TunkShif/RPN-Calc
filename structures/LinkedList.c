#include "LinkedList.h"

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

Status *LinkedList_InsertAtHead(LinkedList *pList, void *pData) {
    LinkedListNode *pNewNode = LinkedList_NewNode(pData);
    if (pNewNode == NULL) {
        return Status_MallocFailed();
    }
    pNewNode->pNextNode = pList->pHeadNode;
    pList->pHeadNode = pNewNode;
    pList->length++;
    return Status_ActionSucceeded();
}

Status *LinkedList_InsertAfter(LinkedList *pList, LinkedListNode *pNode, void *pData) {
    if (pNode == NULL) {
        return LinkedList_InsertAtHead(pList, pData);
    }
    LinkedListNode *pNewNode = LinkedList_NewNode(pData);
    if (pNewNode == NULL) {
        return Status_MallocFailed();
    }
    pNewNode->pNextNode = pNode->pNextNode;
    pNode->pNextNode = pNewNode;
    pList->length++;
    return Status_ActionSucceeded();
}

Status *LinkedList_InsertAt(LinkedList *pList, int index, void *pData) {
    int length = LinkedList_Length(pList);
    if ((index >= length) || (index < 0)) {
        return Status_OutOfIndex();
    } else if (index == 0) {
        return LinkedList_InsertAtHead(pList, pData);
    } else if (index == length - 1) {
        return LinkedList_Append(pList, pData);
    } else {
        LinkedListNode *pNewNode = LinkedList_NewNode(pData);
        LinkedListNode *pCurrentNode = pList->pHeadNode;
        int i;
        for (i = 0; i < index; i++) {
            pCurrentNode = pCurrentNode->pNextNode;
        }
        pNewNode->pNextNode = pCurrentNode->pNextNode;
        pCurrentNode->pNextNode = pNewNode;
        pList->length++;
        return Status_ActionSucceeded();
    }
}

Status *LinkedList_Append(LinkedList *pList, void *pData) {
    LinkedListNode *pNewNode = LinkedList_NewNode(pData);
    if (pNewNode == NULL) {
        return Status_NullPointerError();
    }

    if (LinkedList_IsEmpty(pList)) {
        pList->pHeadNode = pNewNode;
    } else {
        LinkedListNode *pCurrentNode;
        for (pCurrentNode = pList->pHeadNode; pCurrentNode->pNextNode != NULL; pCurrentNode = pCurrentNode->pNextNode);
        pCurrentNode->pNextNode = pNewNode;
    }
    pList->length++;
    return Status_ActionSucceeded();
}

Status *LinkedList_DeleteHeadNode(LinkedList *pList, void (*freeData)()) {
    if (LinkedList_IsEmpty(pList)) {
        return Status_ListEmptyError();
    }
    LinkedListNode *pTempNode = pList->pHeadNode;
    pList->pHeadNode = pTempNode->pNextNode;
    LinkedList_FreeNode(pTempNode, freeData);
    pTempNode = NULL;
    pList->length--;
    return Status_ActionSucceeded();
}

Status *LinkedList_DeleteLastNode(LinkedList *pList, void (*freeData)()) {
    if (LinkedList_IsEmpty(pList)) {
        return Status_ListEmptyError();
    }

    LinkedListNode *pTempNode = pList->pHeadNode;
    if (pTempNode->pNextNode == NULL) {
        LinkedList_FreeNode(pTempNode, freeData);
        return Status_ActionSucceeded();
    }

    int length = LinkedList_Length(pList);
    pTempNode = LinkedList_GetNodeAt(pList, length - 1 - 1);
    LinkedListNode *pLastNode = pTempNode->pNextNode;
    LinkedList_FreeNode(pLastNode, freeData);
    pLastNode = NULL;
    pTempNode->pNextNode = NULL;
    pList->length--;
    return Status_ActionSucceeded();
}

Status *LinkedList_DeleteNodeAt(LinkedList *pList, int index, void (*freeData)()) {
    if (LinkedList_IsEmpty(pList)) {
        return Status_ListEmptyError();
    }

    int length = LinkedList_Length(pList);
    if (index >= length || index < 0) {
        return Status_OutOfIndex();
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
    return Status_ActionSucceeded();
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

Status *LinkedList_Traverse(LinkedList *pList, Status *(*func)()) {
    if (LinkedList_IsEmpty(pList)) {
        return Status_ListEmptyError();
    }
    LinkedListNode *pCurrentNode;
    Status *pStatus;
    for (pCurrentNode = pList->pHeadNode; pCurrentNode != NULL; pCurrentNode = pCurrentNode->pNextNode) {
        pStatus = func(LinkedList_GetDataFromNode(pCurrentNode));
        if (pStatus->code == ERROR) {
            return pStatus;
        }
    }
    return Status_ActionSucceeded();
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