#ifndef CALC_STACK_H
#define CALC_STACK_H
#define DEFAULT_STACK_INIT_SIZE 100
#define DEFAULT_STACK_INCREMENT_SIZE 50
#include <stdbool.h>

/*
 * Stack
 * @members:
 *     void *pBase: a pointer to the base element
 *     void *pTop: a pointer to the top element
 *     int elementSize: the size of a single element
 *     int stackSize: the max capacity of the stack
 */
typedef struct Stack{
    void *pBase;
    void *pTop;
    int elementSize;
    int stackSize;
} Stack;

/*
 * Stack_NewStack
 * Create a new stack
 * @param:
 *     int stackSize: the initial size of the stack
 *     int elementSize: the size of a single element
 * @return:
 *     Stack*: pointer to the newly created stack struct
 */
Stack *Stack_NewStack(int stackSize, int elementSize);

/*
 * Stack_IsEmpty
 * Check whether a stack is empty
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 * @return:
 *     bool
 */
bool Stack_IsEmpty(Stack *pStack);

/*
 * Stack_IsFull
 * Check whether a stack is full
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 * @return:
 *     bool
 */
bool Stack_IsFull(Stack *pStack);

/*
 * Stack_GetSize
 * Get the max capacity of the stack
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 * @return:
 *     int: the size of the stack
 */
int Stack_GetSize(Stack *pStack);

/*
 * Stack_GetLength
 * Get the number of the elements in the stack
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 * @return:
 *     int: the number of the elements in the stack
 */
int Stack_GetLength(Stack *pStack);

/*
 * Stack_IncreaseSize
 * Increase the max capacity of the stack
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 *     int incrementSize: the increment size
 * @return:
 *     int: 0 for SUCCESS, 1 for ERROR
 */
int Stack_IncreaseSize(Stack *pStack, int incrementSize);

/*
 * Stack_Push
 * Add a new element to the top of the stack, automatically
 * increase the size of the stack when it's full, the default
 * increment size is defined in marco DEFAULT_STACK_INCREMENT_SIZE,
 * the value of which is 50
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 *     void * pElement: a pointer to the element to be added to the stack
 * @return:
 *     int: 0 for SUCCESS, 1 for ERROR
 */
int Stack_Push(Stack *pStack, void *pElement);

/*
 * Stack_Pop
 * Pop the top element
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 * @return:
 *     int: 0 for SUCCESS, 1 for ERROR
 */
int Stack_Pop(Stack *pStack);

/*
 * Stack_PopTo
 * Get the top element and assign it to another variable,
 * then pop the top element
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 *     void **pDestination: specify the destination variable
 * @return:
 *     int: 0 for SUCCESS, 1 for ERROR
 */
int Stack_PopTo(Stack *pStack, void *pDestination);

/*
 * Stack_GetTop
 * Get the top element and assign it to another variable
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 *     void **pDestination: specify the destination variable
 * @return:
 *     int: 0 for SUCCESS, 1 for ERROR
 */
int Stack_GetTop(Stack *pStack, void *pDestination);

/*
 * Stack_Traverse
 * Traverse the stack, and perform the function on each element
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 *     int *(*func)(): a function operating on the stack element
 * @return:
 *     int: 0 for SUCCESS, 1 for ERROR
 */
int Stack_Traverse(Stack *pStack, int (*func)());

/*
 * Stack_Free
 * Deconstruct and free the stack
 * @param:
 *     Stack *pStack: a pointer to the stack-type struct
 */
void Stack_Free(Stack *pStack);

#endif
