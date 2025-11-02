#include "set.h"
#include <stdlib.h>

Set* setCreate(size_t capacity) {
    Set* set = malloc(sizeof(Set));

    if (!set) {
        return NULL;
    }

    set -> table = hashTableCreate(capacity);
    return set;
}

void setInsert(Set* set, const char* key) {
    if (!setContains(set, key)) {
        hashTableInsert(set -> table, key, NULL);
    }
}

void setRemove(Set* set, const char* key) {
    hashTableRemove(set -> table, key);
}

int setContains(Set* set, const char* key) {
    return hashTableContains(set -> table, key);
}

size_t setSize(Set* set) {
    return hashTableSize(set -> table);
}