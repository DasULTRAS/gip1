/**
  INCLUDE GUARD
*/
#ifndef VIGENERE_H_
#define VIGENERE_H_

char encrypt_char(char clear, char key);
char decrypt_char(char cipher, char key);

char *encrypt_string(char *cleartext, char *keyword);
char* decrypt_string(char* ciphertext, char* keyword);

#endif // vigenere.h
