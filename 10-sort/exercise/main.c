#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "my_array/my_array.h"
#include "my_sorting/my_sorting.h"

#define length 10

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
    }
    return true;
}

int main() {
    // use current time as seed for random generator
    srand(time(NULL));

    int *int_array = get_random_int_array(length);
    print_int_array(int_array, length);

    assert(is_sorting(1000, 1000, &bubble_sort));

    // Reservierten Speicher zurückgeben
    free(int_array);
    int_array = NULL;

    return 0;
}
