#include "my_string.h"

/**
 * returns the length of an char array
 * @param first is the pointer of the start
 * @return the length of the Char Array
 */
int my_string_length(char *first) {
    char *last = first;
    for (; *last != '\0'; ++last);

    return last - first;
}