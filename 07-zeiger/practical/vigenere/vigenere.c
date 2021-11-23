#include "vigenere.h"

char encrypt_char(char clear, char key){
  return ((clear + key) %128);
}

char decrypt_char(char cipher, char key){
  return ((cipher - key + 128) %128);
}
