// binary search tree
#ifndef BST_H
#define BST_H

#include <stddef.h>

typedef struct BSTNode {
    int key;
    void* value;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct {
    BSTNode* root;
    size_t size;
} BSTree;

BSTree* bstCreate(void);
void bstInsert(BSTree* tree, int key, void* value);
void* bstSearch(BSTree* tree, int key);
void bstRemove(BSTree* tree, int key);
void bstTraverseInOrder(BSTree* tree, void (*visit)(int key, void* value));
void bstDestroy(BSTree* tree);

#endif