#ifndef RPN_CALC_GENERICSTACK_H
#define RPN_CALC_GENERICSTACK_H
#include <stdlib.h>
#include <stdbool.h>
#include "../include/Status.h"
#define DEFAULT_STACK_INIT_SIZE 100
#define DEFAULT_STACK_INCREMENT_SIZE 50

/*
 * Generic Stack
 * @members:
 *     int size: the max capacity of the stack
 *     void *pBase: a pointer to the base element
 *     void *pTop: a pointer to the top element
 */
typedef struct GenericStack{
    void **pBase;
    void **pTop;
    int size;
} GenericStack;

/*
 * Stack_Init
 * Initiate a stack
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 *     int size: the initial size of the stack
 * @return:
 *     Status*
 */
Status *Stack_Init(GenericStack*, int);

/*
 * Stack_IsEmpty
 * Check whether a stack is empty
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 * @return:
 *     bool
 */
bool Stack_IsEmpty(GenericStack*);

/*
 * Stack_IsFull
 * Check whether a stack is full
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 * @return:
 *     bool
 */
bool Stack_IsFull(GenericStack*);

/*
 * Stack_Size
 * Get the max capacity of the stack
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 * @return:
 *     int: the size of the stack
 */
int Stack_Size(GenericStack*);

/*
 * Stack_Length
 * Get the number of the elements in the stack
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 * @return:
 *     int: the number of the elements in the stack
 */
int Stack_Length(GenericStack*);

/*
 * Stack_IncreaseSize
 * Increase the max capacity of the stack
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 *     int incrementSize: the increment size
 * @return:
 *     Status*
 */
Status *Stack_IncreaseSize(GenericStack*, int);

/*
 * Stack_Push
 * Add a new element to the top of the stack, automatically
 * increase the size of the stack when it's full, the default
 * increment size is defined in marco DEFAULT_STACK_INCREMENT_SIZE,
 * the value of which is 50
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 *     void *pElement: a pointer to the element to be added to the stack
 * @return:
 *     Status*
 */
Status *Stack_Push(GenericStack*, void*);

/*
 * Stack_Pop
 * Pop the top element
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 * @return:
 *     Status*
 */
Status *Stack_Pop(GenericStack*);

/*
 * Stack_PopTo
 * Get the top element and assign it to another variable,
 * then pop the top element
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 * @return:
 *     Status*
 */
Status *Stack_PopTo(GenericStack*, void**);

/*
 * Stack_GetTop
 * Get the top element and assign it to another variable
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 *     ElementType pDestination:
 * @return:
 *     Status*
 */
Status *Stack_GetTop(GenericStack*, void**);

/*
 * Stack_Traverse
 * Traverse the stack, and perform the function on each element
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 *     void (*)func(ElementType*): a function operating on the stack element
 * @return:
 *     Status*
 */
Status *Stack_Traverse(GenericStack*, Status *(*)());

/*
 * Stack_Free
 * Deconstruct and free the stack
 * @param:
 *     GenericStack *pStack: a pointer to the stack-type struct
 */
void Stack_Free(GenericStack*);
#endif
