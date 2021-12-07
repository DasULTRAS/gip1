#include "vigenere.h"
#include "../my_string/my_string.h"

/**
 *
 * @param clear großbuchstabe
 * @param key großbuchstabe
 * @return chipher
 */
char encrypt_char(char clear, char key) {
    return (((clear - ' ') + (key - ' ')) % ('~' - ' ' +1)) + ' ';
}

/**
 * entschlüsselt buchstaben
 * @param cipher großbuchstabe
 * @param key großbuchstabe
 * @return klartext
 */
char decrypt_char(char cipher, char key) {
    return (((cipher - ' ') - (key - ' ')  + ('~' - ' ' +1)) % ('~' - ' ' +1)) + ' ';
}

void *for_each_vig(char *destination, char *text, char *key, char (*fn)(char, char)){
    char *pkey = key;
    for(; *text != '\0'; ++destination, ++text, ++pkey){
        if(*pkey == '\0')
            pkey = key;
        *destination = fn(*text, *key);
    }
}

char *encrypt_string(char *cleartext, char *keyword) {
    char *encrypted = my_string_duplicate(cleartext);
    for_each_vig(encrypted, cleartext, keyword, &encrypt_char);
    return encrypted;
}

char* decrypt_string(char* ciphertext, char* keyword){
    char *decrypted = my_string_duplicate(ciphertext);
    for_each_vig(decrypted, ciphertext, keyword, &decrypt_char);
    return decrypted;
}