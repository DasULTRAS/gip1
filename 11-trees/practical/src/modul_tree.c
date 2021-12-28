#include "modul_tree.h"

#include <stdlib.h>

struct modul_tree_node* modul_tree_node(struct modul){
    struct modul_tree_node* node = malloc(sizeof(modul_tree_node));
    node->data = modul;

};