#include "vigenere.h"

/**
 *
 * @param clear klein/großbuchstabe
 * @param key klein/großbuchstabe
 * @return chipher
 */
char encrypt_char(char clear, char key) {
    return ((clear + key) % 128);
}

/**
 * entschlüsselt buchstaben
 * @param cipher ein klein/großbuchstabe
 * @param key ein klein/großbuchstabe
 * @return klartext
 */
char decrypt_char(char cipher, char key) {
    return ((cipher - key + 128) % 128);
}
