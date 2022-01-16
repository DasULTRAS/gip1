#include <string.h>
#include <stdio.h>

#include "src/module.h"

/**
 * Compares two modules
 * @param first
 * @param second
 * @return If first is less than second < 0
 * If first is equal 0
 * If first is more than second > 0
 */
int module_cmp(struct module first, struct module second){
    return strcmp(first.abbreviation, second.abbreviation);
}

int main(){
    struct module gip1 = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};
    struct module gip2 = {"Grundlagen der Informatik und Programmierung 2", "GIP2", 210, 7, 2, 1};

    print_module(gip1);

    /*
    struct module_tree* tree = construct_module_tree(&modul_cmp);

    while (1) {
        struct module temp = {"", "", 0, 0, 0, 0};
        int input = scanf("%64[^,],%6[^,],%u,%u,%u,%u ", temp.title, temp.abbreviation, &temp.workload, &temp.credits, &temp.semester, &temp.duration);
        if(input == EOF)
            break;
        insert_sorted_tree(tree, temp);
    }
     */

    printf("FERTIG");
}
