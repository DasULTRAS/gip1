#ifndef MODUL_TREE_H_
#define MODUL_TREE_H_

#include "modul.h"

struct modul_tree_node {
    struct modul data;
    struct modul_tree_node *left;
    struct modul_tree_node *right;
};

struct tree {
    struct modul *first;

    int (*sort_criteria)(struct modul first, struct modul second); // if first
};

#endif // modul_tree.h
