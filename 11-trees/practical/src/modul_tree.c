#include "modul_tree.h"

#include <stdlib.h>

struct modul_tree_node* construct_modul_tree_node(struct modul data){
    struct modul_tree_node* node = malloc(sizeof(struct modul_tree_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

struct modul_tree* construct_modul_tree (int (*sort_criteria)(struct modul, struct modul)){
    struct modul_tree* tree = malloc(sizeof(struct modul_tree));
    tree->first = NULL;
    tree->sort_criteria = sort_criteria;
    return tree;
}

void insert_sorted_tree(struct modul_tree* tree, struct modul data){
    struct modul_tree_node* node = construct_modul_tree_node(data);
    if (tree->first == NULL) {
        tree->first = node;
    } else {
        insert_sorted_tree(tree->first, tree->sort_criteria)
    }
}

void insert_sorted_tree_recursive(struct modul_tree_node* tree_node, struct modul_tree_node* new, int (*sort_criteria)(struct modul, struct modul)){

}