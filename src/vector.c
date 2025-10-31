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

void vectorFree(Vector* vec) {
    free(vec -> data);
    free(vec);
}