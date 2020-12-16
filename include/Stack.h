#ifndef CALC_STACK_H
#define CALC_STACK_H
#define DEFAULT_STACK_INIT_SIZE 100
#define DEFAULT_STACK_INCREMENT_SIZE 50
#include <stdbool.h>

typedef struct Stack{
    void *pBase;
    void *pTop;
    int elementSize;
    int stackSize;
} Stack;

Stack *Stack_NewStack(int stackSize, int elementSize);

bool Stack_IsEmpty(Stack *pStack);

bool Stack_IsFull(Stack *pStack);

int Stack_GetSize(Stack *pStack);

int Stack_GetLength(Stack *pStack);

int Stack_IncreaseSize(Stack *pStack, int incrementSize);

int Stack_Push(Stack *pStack, void *pElement);

int Stack_Pop(Stack *pStack);

int Stack_PopTo(Stack *pStack, void *pDestination);

int Stack_GetTop(Stack *pStack, void *pDestination);

int Stack_Traverse(Stack *pStack, int (*func)());

void Stack_Free(Stack *pStack);

#endif
