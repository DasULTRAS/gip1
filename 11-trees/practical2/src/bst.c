#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

// binary search tree --> bst

// PRIVATE HEADER
struct bst *bst_destruct_node(struct bst *node);
// end PRIVATE HEADER

struct bst *bst_construct() {
    return NULL;
}

struct bst *bst_destruct(struct bst *tree) {
    bst_post_order_traverse(tree, &bst_destruct_node);
}

struct bst *bst_destruct_node(struct bst *node) {
    free(node);
}

struct bst *bst_remove_node(struct bst **node) {
    if (((*node)->left || (*node)->right) != NULL)
        assert(0);
    free(*node);
    *node = NULL;
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

void bst_pre_order_traverse(struct bst *tree, void(*fn)(char *data)) {
    if (tree == NULL)
        return;

    fn(tree->data);
    bst_in_order_traverse(tree->left, fn);
    bst_in_order_traverse(tree->right, fn);
}

void bst_in_order_traverse(struct bst *tree, void(*fn)(char *data)) {
    if (tree == NULL)
        return;

    bst_in_order_traverse(tree->left, fn);
    fn(tree->data);
    bst_in_order_traverse(tree->right, fn);
}

void bst_post_order_traverse(struct bst *tree, void(*fn)(char *data)) {
    if (tree == NULL)
        return;

    bst_in_order_traverse(tree->left, fn);
    bst_in_order_traverse(tree->right, fn);
    fn(tree->data);
}
