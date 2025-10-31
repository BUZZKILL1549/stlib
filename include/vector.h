#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    void** data;
    size_t size;
    size_t capacity;
} Vector;

Vector* vectorCreate();
void vectorPush(Vector* vec, void* item);
void* vectorGet(Vector* vec, size_t index);
void vectorFree(Vector* vec);

#endif