#ifndef QUEUE_H
#define QUEUE_H

#include "vector.h"
#include <stddef.h>

typedef struct {
    Vector* vec;
} Queue;

Queue* queueCreate(void);
void queueEnqueue(Queue* queue, void* item);
void* queueDequeue(Queue* queue);
void* queueFront(Queue* queue);
size_t queueSize(Queue* queue);
int isEmptyQueue(Queue* queue);
void queueDestroy(Queue* queue);

#endif