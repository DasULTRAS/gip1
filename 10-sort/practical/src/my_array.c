#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_array.h"

/**
 * Generating an int array with random indices
 * @param length of the generated array
 * @return pointer to an random array
 */
int *get_random_int_array(unsigned int length) {
    // init a array with size length
    int *first = calloc(length, sizeof(int));

    // replace every index with random number
    for (int i = 0; i < length; ++i)
        first[i] = rand() %1000000;

    return first;
}

/**
 * print the array
 * @param int_array pointer to the array
 * @param length of the array
 */
void print_int_array(int *int_array, unsigned int length) {
    for (int i = 0; i < length; ++i) {
        printf("%4d", i);
        printf("    ");
    }

    printf("\n");

    for (int i = 0; i < length; ++i)
        printf("%6d, ", int_array[i]);

    printf("\n");
}

/**
 * Testing if array int_array is sorted
 * @param int_array array who will be tested
 * @param length of the array
 * @return true if array is sorted
 */
bool is_sorted_int(int *int_array, unsigned int length) {
    for (int i = 1; i < length; ++i)
        if (int_array[i - 1] > int_array[i])
            return false;
    return true;
}
