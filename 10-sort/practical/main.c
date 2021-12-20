#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include "src/my_array.h"
#include "src/sorting_function.h"

/**
 * Testing sorting function
 * @param trys times of testing the method
 * @param array_length length of testing array
 * @param sort_fn sorting function
 * @return true if every array is sorted
 */
bool is_sorting(unsigned int trys, unsigned int array_length, void(*sort_fn)(int *, unsigned int)) {
    for (int i = 0; i < trys; ++i) {
        int *arr = get_random_int_array(array_length);
        sort_fn(arr, array_length);
        if (!is_sorted_int(arr, array_length)) {
            free(arr);
            return false;
        }
        free(arr);
        arr = NULL;
    }
    return true;
}

void quick_sort_int(int* array, unsigned int length){
    quick_sort(array, 0, length-1);
}

int main() {
    // use current time as seed for random generator
    srand(time(NULL));

    assert(is_sorting(1000, 10000, &merge_sort));
    assert(is_sorting(1000, 10000, &quick_sort_int));

    printf("FINISHED\n");

    return 0;
}