#ifndef CALC_LINKEDLIST_H
#define CALC_LINKEDLIST_H
#include <stdbool.h>

/*
 * LinkedListNode
 * @members:
 *     void *pData: a pointer to the data variable
 *     LinkedListNode *pNextNode: a pointer to the next node
 */
typedef struct LinkedListNode {
    void *pData;
    struct LinkedListNode *pNextNode;
} LinkedListNode;

/*
 * LinkedList
 * @members:
 *     LinkedListNode *pHeadNode: a pointer to the first node
 *     int length: the current length of the list
 */
typedef struct LinkedList {
    LinkedListNode *pHeadNode;
    int length;
} LinkedList;

/*
 * LinkedList_NewNode
 * Create a new node
 * @param:
 *     ElementType pData: a pointer to the data variable
 * @return:
 *     LinkedListNode*: a pointer to the newly created node
 */
LinkedListNode *LinkedList_NewNode(void *pData);

/*
 * LinkedList_GetDataFromNode
 * Get the pointer to the data variable of a node
 * @param:
 *     LinkedListNode* pNode: a pointer to a node
 * @return:
 *     ElementType: a pointer to the data variable
 */
void *LinkedList_GetDataFromNode(LinkedListNode *pNode);

/*
 * LinkedList_NewList
 * Create an empty linked list
 * @return:
 *     LinkedList*: a pointer to the newly created list
 */
LinkedList *LinkedList_NewList(void);

/*
 * LinkedList_IsEmpty
 * Check whether the list is empty
 * @param:
 *     LinkedList *pList: a pointer to the list
 */
bool LinkedList_IsEmpty(LinkedList *pList);

/*
 * LinkedList_Length
 * Get the current length of a list
 * @param:
 *     LinkedList *pList: a pointer to the list
 */
int LinkedList_Length(LinkedList *pList);

/*
 * LinkedList_GetNodeAt
 * Get the node of the given index
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     int index: the index of the node
 * @return:
 *     LinkedListNode*: a pointer to the node, return NULL if the node doesn't exist
 */
LinkedListNode *LinkedList_GetNodeAt(LinkedList *pList, int index);

/*
 * LinkedList_InsertAtHead
 * Insert a new node at the head of the list
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     ElementType pData: a pointer to the data variable
 * @return:
 *     Status*
 */
int LinkedList_InsertAtHead(LinkedList *pList, void *pData);

/*
 * LinkedList_Append
 * Append a new node at the end of the list
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     ElementType pData: a pointer to the data variable
 * @return:
 *     Status*
 */
int LinkedList_Append(LinkedList *pList, void *pData);

/*
 * LinkedList_DeleteHeadNode
 * Delete the first node of the list
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     void (*freeData)(): a function used to free the data
 * @return:
 *     Status*
 */
int LinkedList_DeleteHeadNode(LinkedList *pList, void (*freeData)());

/*
 * LinkedList_DeleteLastNode
 * Delete the last node of the list
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     void (*freeData)(): a function used to free the data
 * @return:
 *     Status*
 */
int LinkedList_DeleteLastNode(LinkedList *pList, void (*freeData)());

/*
 * LinkedList_DeleteNodeAt
 * Delete a node by the given index
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     int index: the index of the node to be deleted
 *     void (*freeData)(): a function used to free the data
 * @return:
 *     Status*
 */
int LinkedList_DeleteNodeAt(LinkedList *pList, int index, void (*freeData)());

/*
 * LinkedList_FindNodeByKey
 * Find node by key
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     ElementType pKey: specify which item is used to compare
 *     bool (*isEqual)(): a function used to compare the data with the key
 * @return:
 *     LinkedListNode*
 */
LinkedListNode *LinkedList_FindNodeByKey(LinkedList *pList, void *pKey, bool (*isEqual)());

/*
 * LinkedList_Traverse
 * Traverse the list, and perform the function on each element
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     int (*func)(): a function operating on the stack element
 * @return:
 *     Status*
 */
int LinkedList_Traverse(LinkedList *pList, int (*func)());

/*
 * LinkedList_FreeNode
 * Free a list node
 * @param:
 *     LinkedListNode *pNode: a pointer to the node
 *     void (*freeData)(): a function used to free the data
 */
void LinkedList_FreeNode(LinkedListNode *pNode, void (*freeData)());

/*
 * LinkedList_Clear
 * Make a list empty
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     void (*freeData)(): a function used to free the data
 */
void LinkedList_Clear(LinkedList *pList, void (*freeData)());

/*
 * LinkedList_FreeNode
 * Destruct a list
 * @param:
 *     LinkedList *pList: a pointer to the list
 *     void (*freeData)(): a function used to free the data
 */
void LinkedList_FreeList(LinkedList *pList, void (*freeData)());

#endif
