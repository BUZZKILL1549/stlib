#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // create hashtable
    // initial size = 8
    HashTable* table = hashTableCreate(8);
    if (!table) {
        fprintf(stderr, "Failed to create hash table.\n");
        return 1;
    }

    // insert values
    hashTableInsert(table, "name", "Aushadh");
    hashTableInsert(table, "language", "C");
    hashTableInsert(table, "library", "stlib");

    // get values
    printf("name: %s\n", (char*)hashTableGet(table, "name"));
    printf("language: %s\n", (char*)hashTableGet(table, "language"));
    printf("library: %s\n", (char*)hashTableGet(table, "library"));

    // find key
    if (hashTableContains(table, "language")) {
        printf("Key 'language' exists!\n");
    }

    if (!hashTableContains(table, "os")) {
        printf("Key 'os' does not exist!\n");
    }

    // removal
    hashTableRemove(table, "library");
    printf("Removed 'library'.\n");

    // check removal
    if (!hashTableGet(table, "library")) {
        printf("'library' key not found.\n");
    }

    // print size of table
    printf("HashTable size: %zu\n", hashTableSize(table));

    // destroy table
    hashTableDestroy(table);

    return 0;
}
