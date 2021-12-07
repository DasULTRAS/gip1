#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common/common.h"
#include "vigenere/vigenere.h"
#include "my_string/my_string.h"

int main() {
    assert(encrypt_char('a', ' ') == 'a'); // null shift
    assert(encrypt_char('c', '#') == 'f'); // arbitrary shift

    assert(encrypt_char('~', '!') == ' '); // alphabet overflow

    assert(encrypt_char('~', ' ' + 1) == ' ' + 0); // data type overflow
    assert(encrypt_char('~', ' ' + 5) == ' ' + 4);

    assert(decrypt_char('a', ' ') == 'a'); // null shift
    assert(decrypt_char('f', '#') == 'c'); // arbitrary shift

    assert(decrypt_char(' ', '!') == '~'); // alphabet overflow

    assert(decrypt_char(' ', ' ' + 1) == '~' - 0); // data type underflow
    assert(decrypt_char(' ', ' ' + 33) == '~' - 32);

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

    char *chiffrat = encrypt_string(text, key);
    printf("Encrypted: %s\n", chiffrat);

    free(text);
    text = decrypt_string(chiffrat, key);
    printf("Decrypted: %s\n", text);


    // Gibt Speicher von calloc wieder frei
    free(text);
    text = NULL;
    free(key);
    key = NULL;
    free(chiffrat);
    chiffrat = NULL;

    return 0;
}
