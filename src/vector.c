#include "vector.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 4

Vector* vectorCreate() {
    Vector* vec = malloc(sizeof(Vector));
    vec -> data = malloc(INITIAL_CAPACITY * sizeof(void* ));
    vec -> size = 0;
    vec -> capacity = INITIAL_CAPACITY;
    return vec;
}

void vectorPush(Vector* vec, void* item) {
    if (vec -> size == vec -> capacity) {
        vec -> capacity *= 2;
        vec -> data = realloc(vec -> data, vec -> capacity * sizeof(void* ));
    }
    vec -> data[vec -> size++] = item;
}

void* vectorGet(Vector* vec, size_t index) {
    return (index < vec -> size) ? vec -> data[index] : NULL;
}

void* vectorPopBack(Vector* vec) {
    if (vec -> size == 0) {
        return NULL;
    }

    void* item = vec -> data[vec -> size - 1];
    vec -> size--;
    return item;
}

size_t vectorSize(Vector* vec) {
    return vec -> size;
}

void vectorRemove(Vector* vec, size_t index) {
    if (index >= vec -> size) {
        return;
    }

    for (size_t i = index; i < vec -> size - 1; i++) {
        vec -> data[i] = vec -> data[i + 1];
    }

    vec -> size--;
}

void vectorDestroy(Vector* vec) {
    if (!vec) {
        return;
    }

    free(vec -> data);
    free(vec);
}