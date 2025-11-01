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
void* vectorPopBack(Vector* vec);
size_t vectorSize(Vector* vec);
void vectorRemove(Vector* vec, size_t index);
void vectorDestroy(Vector* vec);

#endif