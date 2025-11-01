#include "stack.h"
#include <stdlib.h>

Stack* stackCreate(void) {
    Stack* stack = malloc(sizeof(Stack));

    if (!stack) {
        return NULL;
    }

    stack -> vec = vectorCreate();
    return stack;
}

void stackPush(Stack* stack, void* item) {
    vectorPushBack(stack -> vec, item);
}

void* stackPop(Stack* stack) {
    if (isEmptyStack(stack)) {
        return NULL;
    }
    return vectorPopBack(stack -> vec);
}

void* stackPeek(Stack* stack) {
    if (isEmptyStack(stack)) {
        return NULL;
    }
    return vectorGet(stack -> vec, vectorSize(stack -> vec) - 1);
}

size_t stackSize(Stack* stack) {
    return vectorSize(stack -> vec);
}

int isEmptyStack(Stack* stack) {
    return vectorSize(stack -> vec) == 0;
}

void stackDestroy(Stack* stack) {
    vectorDestroy(stack -> vec);
    free(stack);
}