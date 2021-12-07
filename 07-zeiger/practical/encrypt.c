#include <stdio.h>
#include <stdlib.h>
#include "common/common.h"
#include "vigenere/vigenere.h"
#include "my_string/my_string.h"

int main() {
    char str[] = "StayHigh";
    printf("Length: %d\n", my_string_length(str));
    printf("default: %s \n", str);
    my_string_to_upper_case(str);
    printf("upper case: %s \n", str);
    my_string_to_lower_case(str);
    printf("lower case: %s \n", str);

    char *key = read_size_and_input();
    if (key == NULL) {
        return 2;
    }
    printf("%s\n", key);

    char *text = read_size_and_input();
    if (text == NULL) {
        return 1;
    }
    printf("%s\n", text);


    printf("encrypt: %c\n", encrypt_char('R', 'D'));
    printf("decrypt: %c\n", decrypt_char('y', '2'));

    // Gibt Speicher von calloc wieder frei
    free(text);
    free(key);

    return 0;
}
