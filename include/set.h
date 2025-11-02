#ifndef SET_H
#define SET_H

#include "hashtable.h"
#include <stddef.h>

typedef struct {
    HashTable* table;
} Set;

Set* setCreate(size_t capacity);
void setInsert(Set* set, const char* key);
void setRemove(Set* set, const char* key);
int setContains(Set* set, const char* key);
size_t setSize(Set* set);
void setDestroy(Set* set);

#endif