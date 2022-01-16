#include <stdio.h>
#include <stdlib.h>

#include "src/bst.h"

void print_string(char* string){
    printf("%s, ", string);
}

int main(){
    struct bst* tree = bst_construct();

    char* abbreviation = calloc(6, sizeof(char));
    while(1){
        int input = scanf(" %5s", abbreviation);

        if(input == EOF)
            break;

        bst_insert(&tree, abbreviation);
    }
    free(abbreviation);

    bst_in_order_traverse(tree, &print_string);
    printf("\n");

    bst_print(tree);

    bst_destruct(tree);

    printf("Number of Nodes: %d\n", bst_count_nodes(tree));

    return 0;
}
