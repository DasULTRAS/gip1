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
    // struct modul gip1 = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};
    // struct modul gip2 = {"Grundlagen der Informatik und Programmierung 2", "GIP2", 210, 7, 2, 1};

    struct modul_tree* tree = construct_modul_tree(&modul_cmp);

    int input;
    while (1) {
        struct modul temp = {"", "", 0, 0, 0, 0};
        input = scanf("%64[^,],%6[^,],%u,%u,%u,%u ", temp.titel, temp.abkuerzung, &temp.workload, &temp.credits, &temp.semester, &temp.dauer);
        if(input == EOF)
            break;
        insert_sorted_tree(tree, temp);
    }

    printf("FERTIG");
}
