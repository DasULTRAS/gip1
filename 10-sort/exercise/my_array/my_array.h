#ifndef _MY_ARRAY_H_
#define _MY_ARRAY_H_
#include <stdbool.h>

int* get_random_int_array(unsigned int length);
void print_int_array(int *int_array, unsigned int length);
bool is_sorted_int(int *int_array, unsigned int length);

#endif //my_array.h