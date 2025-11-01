#include "linkedlist.h"
#include <stdlib.h>

LinkedList* listCreate(void) {
    LinkedList* list = malloc(sizeof(LinkedList));
    if (!list) {
        return NULL;
    }
    list -> head = list -> tail = NULL;
    list -> size = 0;
    return list;
}

void listPushFront(LinkedList* list, void* data) {
    Node* node = malloc(sizeof(node));
    node -> data = data;
    node -> prev = NULL;
    node -> next = list -> head;

    if (list -> head) {
        list -> head -> prev = node;
    } else {
        list -> tail = node;
    }

    list -> head = node;
    list -> size++;
}

void listPushBack(LinkedList* list, void* data) {
    Node* node = malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    node -> prev = list -> tail;

    if (list -> tail) {
        list -> tail -> next = node;
    } else {
        list -> head = node;
    }

    list -> tail = node;
    list -> size++;
}

void* listPopFront(LinkedList* list) {
    if (!list -> head) {
        return NULL;
    }

    Node* node = list -> head;
    void* data = node -> data;

    list -> head = node -> next;
    if (list -> head) {
        list -> head -> prev = NULL;
    } else {
        list -> tail = NULL;
    }

    free(node);
    list -> size--;
    return data;
}

void* listPopBack(LinkedList* list) {
    if (!list -> tail) {
        return NULL;
    }

    Node* node = list -> tail;
    void* data = node -> data;

    list -> tail = node -> prev;
    if (list -> tail) {
        list -> tail -> next = NULL;
    } else {
        list -> head = NULL;
    }

    free(node);
    list -> size--;
    return data;
}

void listClear(LinkedList* list) {
    Node* current = list -> head;
    while (current) {
        Node* next = current -> next;
        free(current);
        current = next;
    }

    list -> head = list -> tail = NULL;
    list -> size = 0;
}

void listDestroy(LinkedList* list) {
    if (!list) {
        return;
    }

    listClear(list);
    free(list);
}