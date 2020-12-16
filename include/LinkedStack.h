#ifndef CALC_LINKEDSTACK_H
#define CALC_LINKEDSTACK_H
#include "LinkedList.h"

/*
 * LinkedStack
 * @member:
 *     LinkedList *pList
 */
typedef struct LinkedStack {
    LinkedList *pList;
} LinkedStack;

/*
 * LinkedStack_NewStack
 * Initiate a stack
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 *     int size: the initial size of the stack
 * @return:
 *     Status*
 */
LinkedStack *LinkedStack_NewStack(void);

/*
 * LinkedStack_IsEmpty
 * Check whether a stack is empty
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 * @return:
 *     bool
 */
bool LinkedStack_IsEmpty(LinkedStack *pStack);

/*
 * LinkedStack_Length
 * Get the number of the elements in the stack
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 * @return:
 *     int: the number of the elements in the stack
 */
int LinkedStack_Length(LinkedStack *pStack);

/*
 * LinkedStack_Push
 * Add a new element to the top of the stack, automatically
 * increase the size of the stack when it's full, the default
 * increment size is defined in marco DEFAULT_STACK_INCREMENT_SIZE,
 * the value of which is 50
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 *     ElementType pElement: a pointer to the element to be added to the stack
 * @return:
 *     Status*
 */
int LinkedStack_Push(LinkedStack *pStack, void *pElement);

/*
 * LinkedStack_Pop
 * Pop the top element
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 * @return:
 *     Status*
 */
void *LinkedStack_Pop(LinkedStack *pStack, void (*freeData)());

/*
 * LinkedStack_PopTo
 * Get the top element and assign it to another variable,
 * then pop the top element
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 *     ElementType *pDestination: specify the destination variable
 * @return:
 *     Status*
 */
int LinkedStack_PopTo(LinkedStack *pStack, void **pDestination, void (*freeDara)());

/*
 * LinkedStack_GetTop
 * Get the top element and assign it to another variable
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 *     ElementType *pDestination: specify the destination variable
 * @return:
 *     Status*
 */
void *LinkedStack_GetTop(LinkedStack *pStack);

char LinkedStack_GetTopChar(LinkedStack *pStack);

int LinkedStack_GetTopInt(LinkedStack *pStack);

/*
 * LinkedStack_Traverse
 * Traverse the stack, and perform the function on each element
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 *     int (*func)(): a function operating on the stack element
 * @return:
 *     Status*
 */
int LinkedStack_Traverse(LinkedStack *pStack, int (*func)());

/*
 * LinkedStack_Free
 * Deconstruct and free the stack
 * @param:
 *     LinkedStack *pStack: a pointer to the stack-type struct
 */
void LinkedStack_Free(LinkedStack *pStack, void (*freeData)());

#endif
