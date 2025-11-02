#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h>

typedef struct HashNode {
    char* key;
    void* value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode** buckets;
    size_t capacity;
    size_t size;
} HashTable;

HashTable* hashTableCreate(size_t capacity);
void hashTableDestroy(HashTable* table);
void hashTableInsert(HashTable* table, const char* key, void* value);
void* hashTableGet(HashTable* table, const char* key);
int hashTableContains(HashTable* table, const char* key);
size_t hashTableSize(HashTable* table);
void hashTableRemove(HashTable* table, const char* key);

#endif