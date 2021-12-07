#include "vigenere.h"

<<<<<<< HEAD
=======
/**
 *
 * @param clear klein/großbuchstabe
 * @param key klein/großbuchstabe
 * @return chipher
 */
>>>>>>> 95b2e92989d28319a644e9fecb28fbd630a278a5
char encrypt_char(char clear, char key) {
    return ((clear + key) % 128);
}

<<<<<<< HEAD
=======
/**
 * entschlüsselt buchstaben
 * @param cipher ein klein/großbuchstabe
 * @param key ein klein/großbuchstabe
 * @return klartext
 */
>>>>>>> 95b2e92989d28319a644e9fecb28fbd630a278a5
char decrypt_char(char cipher, char key) {
    return ((cipher - key + 128) % 128);
}
