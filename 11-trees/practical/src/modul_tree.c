#include "modul_tree.h"

#include <stdlib.h>

struct modul_tree_node *construct_modul_tree_node(struct modul data) {
    struct modul_tree_node *node = malloc(sizeof(struct modul_tree_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

struct modul_tree *construct_modul_tree(int (*sort_criteria)(struct modul, struct modul)) {
    struct modul_tree *tree = malloc(sizeof(struct modul_tree));
    tree->first = NULL;
    tree->sort_criteria = sort_criteria;
    return tree;
}

void insert_sorted_tree_recursive(struct modul_tree_node *tree_node, struct modul_tree_node *new,
                                  int (*sort_criteria)(struct modul, struct modul)) {
    if (sort_criteria(new->data, tree_node->data) < 0)
        if (tree_node->left == NULL)
            tree_node->left = new;
        else
            insert_sorted_tree_recursive(tree_node->left, new, sort_criteria);
    else if (tree_node->right == NULL)
        tree_node->right = new;
    else
        insert_sorted_tree_recursive(tree_node->right, new, sort_criteria);
}

void insert_sorted_tree(struct modul_tree *tree, struct modul data) {
    struct modul_tree_node *node = construct_modul_tree_node(data);
    if (tree->first == NULL)
        tree->first = node;
        // smaller left, bigger/equal right
    else
        insert_sorted_tree_recursive(tree->first, node, tree->sort_criteria);
}

void pre_order_traversierung(struct modul_tree_node *node, void(*fn)(struct modul data)) {
    if (node != NULL) {
        fn(node->data);
        pre_order_traversierung(node->left, fn);
        pre_order_traversierung(node->right, fn);
    }
}

void in_order_traversierung(struct modul_tree_node *node, void(*fn)(struct modul data)) {
    if (node != NULL) {
        in_order_traversierung(node->left, fn);
        fn(node->data);
        in_order_traversierung(node->right, fn);
    }
}

void post_order_traversierung(struct modul_tree_node *node, void(*fn)(struct modul data)) {
    if (node != NULL) {
        post_order_traversierung(node->left, fn);
        post_order_traversierung(node->right, fn);
        fn(node->data);
    }
}

void print_tree_view(struct modul_tree* tree){

}
