#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

static unsigned long hash(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

HashTable* hashTableCreate(size_t capacity) {
    HashTable* table = malloc(sizeof(HashTable));
    table -> capacity = capacity;
    table -> size = 0;
    table -> buckets = calloc(capacity, sizeof(HashNode* ));
    return table;
}

void hashTableInsert(HashTable* table, const char* key, void* value) {
    unsigned long index = hash(key) % table -> capacity;

    HashNode* node = table -> buckets[index];

    while (node) {
        if (strcmp(node -> key, key) == 0) {
            node -> value = value;
            return;
        }

        node = node -> next;
    }

    HashNode* newNode = malloc(sizeof(HashNode));
    newNode -> key = _strdup(key);
    newNode -> value = value;
    newNode -> next = table -> buckets[index];
    table -> buckets[index] = newNode;
    table -> size++;
}

void* hashTableGet(HashTable* table, const char* key) {
    unsigned long index = hash(key) % table -> capacity;
    HashNode* node = table -> buckets[index];

    while (node) {
        if (strcmp(node -> key, key) == 0) {
            return node -> value;
        }

        node = node -> next;
    }

    return NULL;
}

int hashTableContains(HashTable* table, const char* key) {
    return hashTableGet(table, key) != NULL;
}

size_t hashTableSize(HashTable* table) {
    return table -> size;
}


void hashTableRemove(HashTable* table, const char* key) {
    unsigned long index = hash(key) % table -> capacity;
    HashNode* node = table -> buckets[index];
    HashNode* prev = NULL;

    while (node) {
        if (strcmp(node -> key, key) == 0) {
            if (prev) prev -> next = node -> next;
            else table -> buckets[index] = node -> next;

            free(node -> key);
            free(node);
            table -> size--;
            return;
        } 
        prev = node;
        node = node -> next;
    }
}

void hashTableDestroy(HashTable* table) {
    for (size_t i = 0; i < table -> capacity; i++) {
        HashNode* node = table -> buckets[i];
        while (node) {
            HashNode* next = node -> next;
            free(node -> key);
            free(node);
            node = next;
        }
    }

    free(table -> buckets);
    free(table);
}