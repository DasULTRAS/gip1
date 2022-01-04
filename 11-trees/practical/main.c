#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "src/modul.h"
#include "src/modul_tree.h"

/**
 * Compares two modules
 * @param first
 * @param second
 * @return If first is less than second < 0
 * If first is equal 0
 * If first is more than second > 0
 */
int modul_cmp(struct modul first, struct modul second){
    return strcmp(first.abkuerzung, second.abkuerzung);
}

int main(){
    struct modul gip1 = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};
    struct modul gip2 = {"Grundlagen der Informatik und Programmierung 2", "GIP2", 210, 7, 2, 1};

    struct modul_tree* tree = construct_modul_tree(&modul_cmp);
    insert_sorted_tree(tree, gip1);
    insert_sorted_tree(tree, gip2);

    print_modul(tree->first->data);
    print_modul(tree->first->right->data);
}
