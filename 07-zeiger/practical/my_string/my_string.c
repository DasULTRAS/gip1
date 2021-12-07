#include <stdbool.h>
#include "my_string.h"

/**
 * returns the length of an char array
 * @param first is the pointer of the start
 * @return the length of the Char Array
 */
int my_string_length(char *first) {
    char *last = first;
    for (; *last != '\0'; ++last);
    return (int) (last - first);
}

/**
 * returns true if char is upper case
 * @param c will checked
 * @return true if char is upper case
 */
bool my_is_upper_case(char c) {
    if (c > 64 && c < 91)
        return 1;
    return 0;
}

/**
 * returns true if char is lower case
 * @param c will checked
 * @return true if lower case
 */
bool my_is_lower_case(char c) {
    if (c > 96 && c < 123)
        return 1;
    return 0;
}

/**
 * if c is upper case it will be to lower case
 * @param c char
 */
void my_to_lower_case(char *c) {
    if (my_is_upper_case(*c)) {
        *c += 'a' - 'A';
    }
}

/**
 * if c is lower case it will be to upper case
 * @param c char
 */
void my_to_upper_case(char *c) {
    if (my_is_lower_case(*c)) {
        *c -= 'a' - 'A';
    }
}

/**
 * callback function for every char
 * @param first pointer to first char
 * @param fn funktion
 */
void for_each(char *first, void (*fn)(char *)) {
    for (; *first != '\0'; ++first)
        fn(&first);
}

/**
 * Converts every upper case char to lower case
 * @param str char array
 */
void my_string_to_lower_case(char *str) {
    for_each(str, &my_to_lower_case);
}

void my_string_to_upper_case(char *str) {
    for_each(str, &my_to_upper_case);
}
