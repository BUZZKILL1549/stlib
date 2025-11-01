#ifndef STACK_H
#define STACK_H

#include "vector.h"
#include <stddef.h>

typedef struct Stack {
    Vector* vec;
} Stack;

Stack* stackCreate(void);
void stackPush(Stack* stack, void* item);
void* stackPeek(Stack* stack);
void* stackPop(Stack* stack);
size_t stackSize(Stack* stack);
int isEmptyStack(Stack* stack);
void stackDestroy(Stack* stack);

#endif