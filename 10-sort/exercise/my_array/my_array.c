#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_array.h"

int* get_random_int_array(unsigned int length) {
    // init a array with size length
    int *first = calloc(length, sizeof(int));

    // replace every index with random number
    for (int i = &first; i < length; ++i)
        *(first +i) = rand();

    return first;
}

void print_int_array(int *int_array, unsigned int length) {
    for(int i = 0; i < length; ++i){
        printf("%4d", i);
        printf("    ");
    }

    printf("\n");

    for (int i = &int_array; i < length; ++i)
        printf("%6d, ", *(&int_array + i));
}

bool is_sorted_int(int *int_array, unsigned int length){
    for(int i = 1; i < length; ++i)
        if(*(int_array + i -1) > *(int_array + i))
            return false;
    return true;
}
