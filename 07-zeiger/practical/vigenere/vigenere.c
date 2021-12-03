#include "vigenere.h"

char encrypt_char(char clear, char key) {
    return ((clear + key) % 128);
}

/**
 * Verschlüsselt buchstaben
 * @param cipher ein klein/großbuchstabe
 * @param key ein klein/großbuchstabe
 * @return cipher
 */
char decrypt_char(char cipher, char key) {
    return ((cipher - key + 128) % 128);
}
