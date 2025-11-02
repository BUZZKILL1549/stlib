#include "queue.h"
#include <stdlib.h>

Queue* queueCreate(void) {
    Queue* queue = malloc(sizeof(Queue));
    
    if (!queue) {
        return NULL;
    }

    queue -> vec = vectorCreate();
    return queue;
}

void queueEnqueue(Queue* queue, void* item) {
    vectorPushBack(queue -> vec, item);
}

void* queueDequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        return NULL;
    }

    void* item = vectorGet(queue -> vec, 0);
    vectorRemove(queue -> vec, 0);
    return item;
}

void* queueFront(Queue* queue) {
    if (isEmptyQueue(queue)) {
        return NULL;
    }

    return vectorGet(queue -> vec, 0);
}

size_t queueSize(Queue* queue) {
    return vectorSize(queue -> vec);
}

int isEmptyQueue(Queue* queue) {
    return vectorSize(queue -> vec) == 0;
}

void queueDestroy(Queue* queue) {
    vectorDestroy(queue -> vec);
    free(queue);
}