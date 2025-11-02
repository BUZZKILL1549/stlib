#include "bst.h"
#include <stdlib.h>

// --------- ALL THIS IS PRIVATE. THEY ARE HELPER FUNCTIONS ONLY
// --------- DONT BE RETARDED AND CALL THEM IN UR PROGRAM

// creates node
static BSTNode* bstNodeCreate(int key, void* value) {
    BSTNode* node = malloc(sizeof(BSTNode));
    node -> key = key;
    node -> value = value;
    node -> left = node -> right = NULL;
    return node;
}

// isnters node recursively
static BSTNode* bstInsertRec(BSTNode* node, int key, void* value) {
    if (node == NULL) {
        return bstNodeCreate(key, value);
    }

    if (key < node -> key) {
        node -> left = bstInsertRec(node -> left, key, value);
    } else if (key > node -> key) {
        node -> right = bstInsertRec(node -> right, key, value);
    } else {
        node -> value = value;
    }

    return node;
}

// search recursively
static void* bstSearchRec(BSTNode* node, int key) {
    if (node == NULL) {
        return NULL;
    }

    if (key == node -> key) {
        return node -> value;
    }

    if (key < node -> key) {
        return bstSearchRec(node -> left, key);
    }

    return bstSearchRec(node -> right, key);
}

static BSTNode* bstFindMin(BSTNode* node) {
    while (node && node -> left) {
        node = node -> left;
    }

    return node;
}

static BSTNode* bstRemoveRec(BSTNode* node, int key) {
    if (!node) {
        return NULL;
    }

    if (key < node -> key) {
        node -> left = bstRemoveRec(node -> left, key);
    } else if (key > node -> key) {
        node -> right = bstRemoveRec(node -> right, key);
    } else {
        if (!node -> left) {
            BSTNode* right = node -> right;
            free(node);
            return right;
        } else if (!node -> right) {
            BSTNode* left = node -> left;
            free(node);
            return left;
        } else {
            BSTNode* min = bstFindMin(node -> right);
            node -> key = min -> key;
            node -> value = min -> value;
            node -> right = bstRemoveRec(node -> right, min -> key);
        }
    }

    return node;
}

static void bstTraverseRec(BSTNode* node, void (*visit)(int, void* )) {
    if (!node) {
        return;
    }

    bstTraverseRec(node -> left, visit);
    visit(node -> key, node -> value);
    bstTraverseRec(node -> right, visit);
}

static void bstDestroyRec(BSTNode* node) {
    if (!node) {
        return;
    }

    bstDestroyRec(node -> left);
    bstDestroyRec(node -> right);
    free(node);
}

// -------- PUBLIC CODE BEGINS. USE THE SHIT FROM HERE FOR UR PROGRAM
BSTree* bstCreate(void) {
    BSTree* tree = malloc(sizeof(BSTree));
    tree -> root = NULL;
    tree -> size = 0;
    return tree;
}

void bstInsert(BSTree* tree, int key, void* value) {
    tree -> root = bstInsertRec(tree -> root, key, value);
    tree -> size++;
}

void* bstSearch(BSTree* tree, int key) {
    return bstSearchRec(tree -> root, key);
}

void bstRemove(BSTree* tree, int key) {
    tree -> root = bstRemoveRec(tree -> root, key);
    if (tree -> size > 0) {
        tree -> size--;
    }
}

void bstTraverseInOrder(BSTree* tree, void (*visit)(int, void* )) {
    bstTraverseRec(tree -> root, visit);
}

void bstDestroy(BSTree* tree) {
    bstDestroyRec(tree -> root);
    free(tree);
}