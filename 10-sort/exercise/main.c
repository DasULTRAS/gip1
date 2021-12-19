#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "my_array/my_array.h"

#define length 10

int main(){
    // use current time as seed for random generator
    srand(time(NULL));

    int* int_array = get_random_int_array(length);
    print_int_array(int_array, length);

    int sorted[length] = {0,1,2,3,4,5,6,7,8,9};
    assert(is_sorted_int(&sorted, length));

    // Reservierten Speicher zurückgeben
    free(int_array);

    return 0;
}
