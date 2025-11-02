#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {
    // create vector
    Vector* vec = vectorCreate();

    // add values into it
    // store pointers to heap allocated ints
    for (int i = 0; i < 5; i++) {
        int* value = malloc(sizeof(int));
        *value = i * 10;
        vectorPushBack(vec, value);
    }

    // print all elements
    printf("Vector contents:\n");
    for (size_t i = 0; i < vectorSize(vec); i++) {
        int* value = (int*) vectorGet(vec, i);
        printf("  [%zu] = %d\n", i, *value);
    }

    // remove third element
    vectorRemove(vec, 2);
    printf("\nAfter removing index 2:\n");
    for (size_t i = 0; i < vectorSize(vec); i++) {
        int* value = (int*) vectorGet(vec, i);
        printf("  [%zu] = %d\n", i, *value);
    }

    // remove last element
    int* last = (int*) vectorPopBack(vec);
    printf("\nPopped: %d\n", *last);
    free(last); // free removed element

    // print size
    printf("\nVector size: %zu\n", vectorSize(vec));

    // free all elements 
    for (size_t i = 0; i < vectorSize(vec); i++) {
        free(vectorGet(vec, i));
    }
    vectorDestroy(vec); // destroy vector

    return 0;
}
