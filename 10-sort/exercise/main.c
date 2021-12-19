#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "my_array/my_array.h"
#include "my_sorting/my_sorting.h"

#define length 10

bool is_sorting(unsigned int trys, unsigned int array_length, bool(*sort_fn)(int *, unsigned int)) {
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

    int sorted[length] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(is_sorted_int(&sorted, length));

    assert(is_sorting(100, 1000, &bubble_sort));

    // Reservierten Speicher zurückgeben
    free(int_array);
    int_array = NULL;

    return 0;
}
