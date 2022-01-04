#ifndef MODUL_TREE_H_
#define MODUL_TREE_H_

#include "modul.h"

struct modul_tree_node {
    struct modul data;
    struct modul_tree_node *left;
    struct modul_tree_node *right;
};

struct modul_tree {
    struct modul_tree_node *first;
    int (*sort_criteria)(struct modul, struct modul); // if first
};

struct modul_tree* construct_modul_tree (int (*sort_criteria)(struct modul, struct modul));
void insert_sorted_tree(struct modul_tree* tree, struct modul data);

void pre_order_traversierung(struct modul_tree_node* node, void(*fn)(struct modul data));
void in_order_traversierung(struct modul_tree_node *node, void(*fn)(struct modul data));
void post_order_traversierung(struct modul_tree_node *node, void(*fn)(struct modul data));

#endif // modul_tree.h
