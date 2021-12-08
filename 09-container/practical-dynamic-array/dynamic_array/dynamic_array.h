#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <stdbool.h>

struct Modul{
    char titel[64];
    char abkuerzung[5];
    unsigned int workload, credits, semester, dauer;
};

struct Dynamic_modul_array{
    struct Modul *data;
    unsigned int size, capacity;
};

struct Dynamic_modul_array construct_dynamic_modules_array(unsigned int size);
void destruct_dynamic_modules_array(struct Dynamic_modul_array *array);
void extend_dynamic_modules_array(struct Dynamic_modul_array *array, unsigned int new_capacity);
void push_back_module(struct Dynamic_modul_array *array, struct Modul *modul);
bool is_equal(char *str1, char *str2);
unsigned int find_module_index(struct Dynamic_modul_array *array, char *abbreviation);
void erase_module(struct Dynamic_modul_array *array, unsigned int index);
void insert_module(struct Dynamic_modul_array *array, unsigned int index, struct Modul *module);
void print_modul(struct Modul modul);
void print_modul_array(struct Dynamic_modul_array *array);

#endif // dynamic_array_h_