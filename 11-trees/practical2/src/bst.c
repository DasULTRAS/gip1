#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

// binary search tree --> bst

struct bst *bst_construct() {
    return NULL;
}

void bst_insert(struct bst **tree, char *data) {
    if ((*tree) == NULL) {
        *tree = malloc(sizeof(struct bst));
        strcpy((*tree)->data, data);
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    } else if (strcmp((*tree)->data, data) >= 0)
        bst_insert(&(*tree)->left, data);
    else if (strcmp((*tree)->data, data) < 0)
        bst_insert(&(*tree)->right, data);
    else
        assert(0);
}

void bst_in_order_traverse(struct bst *tree, void(*fn)(char* data)){
    if(tree == NULL)
        return;

    bst_in_order_traverse(tree->left, fn);
    fn(tree->data);
    bst_in_order_traverse(tree->right, fn);
}