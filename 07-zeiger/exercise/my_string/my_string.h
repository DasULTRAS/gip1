#include <stdbool.h>

#ifndef __MY_STRING_H
#define __MY_STRING_H

bool my_islower(char c);
bool my_isupper(char c);
char my_tolower(char c);
char my_toupper(char c);


void my_strcpy_std(char* source, char* destination);
void my_strtolower_std(char* source, char* destination);
void my_strtoupper_std(char* source, char* destination);


unsigned int my_strlen(char* c);


void my_strcpy_map(char* s_first, char* s_last, char* d_first);

#endif //my_string
