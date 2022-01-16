#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

// binary search tree --> bst

// PRIVATE HEADER
struct bst *bst_destruct_node(struct bst *node);
void bst_print_tree(struct bst* node, int level);
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

void bst_print(struct bst* tree){
    bst_print_tree(tree, 0);
}

void bst_print_tree(struct bst* node, int level){
    if(node == NULL)
        return;

    for(int i = 0; i < level; ++i)
        printf("    ");

    printf("%s\n", node->data);

    bst_print_tree(node->right, level+1);
    bst_print_tree(node->left, level+1);
}

int bst_count_nodes(struct bst* tree){
    if(tree == NULL)
        return 0;

    int counter = 1;

    counter += bst_count_nodes(tree->left);
    counter += bst_count_nodes(tree->right);

    return counter;
}
