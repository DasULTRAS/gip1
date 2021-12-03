#include "common.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
  Ließt eine Länge ein
*/
unsigned int read_size() {
    unsigned int size;
    unsigned int num_assigned_attribs = scanf("%u ", &size);
    if (num_assigned_attribs != 1) {
        return 0;
    }
    return size;
}

/**
  Ließt eine Zeichenkette mit der länge size ein
*/
char *read_input(unsigned int size) {
    // Reserviert speicher
    char *input = calloc(size + 1, sizeof(char));
    char *curr_input = input;
    for (; curr_input < input + size; ++curr_input) {
        unsigned int num_assigned_attribs = scanf("%c", curr_input);
        if (num_assigned_attribs != 1) {
            free(input);
            return NULL;
        }
    }
    return input;
}

/**
  Ließt die Länge ein, wenn gültig ließt er mit read_input einen String ein
*/
char *read_size_and_input() {
    unsigned int size = read_size();
    if (size == 0) {
        return NULL;
    }
    char *input = read_input(size);
    return input;
}
