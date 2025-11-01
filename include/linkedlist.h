#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

typedef struct Node {
    void* data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

LinkedList* listCreate(void);
void listPushFront(LinkedList* list, void* data);
void iistPushBack(LinkedList* list, void* data);
void* listPopFront(LinkedList* list);
void* listPopBack(LinkedList* list);
void listClear(LinkedList* list);
void listDestroy(LinkedList* list);

#endif