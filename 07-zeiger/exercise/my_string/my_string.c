#include <stdbool.h>
#include "my_string.h"

/**
eine Funktion bool my_islower(char c), die prüft, ob das übergebene Zeichen ein Kleinbuchstabe
ist
*/
bool my_islower(char c){
  if('a' <= c && c <= 'z')
    return 1;
  return 0;
}


/**
eine Funktion bool my_isupper(char c), die prüft, ob das übergebene Zeichen ein Großbuchstabe
ist.
*/
bool my_isupper(char c){
  if('A' <= c && c <= 'Z')
    return 1;
  return 0;
}

/**
Funktion char my_tolower(char c), die einen übergebenen Großbuchstaben in einen Kleinbuchstaben
umwandelt und ansonsten c zurückgibt
*/
char my_tolower(char c){
  if(my_isupper(c))
    return c - ('A' - 'a');
  return c;
}

/**
Funktion char my_toupper(char c), die einen übergebenen Kleinbuchstaben in einen Großbuchstaben
umwandelt und ansonsten c zurückgibt
*/
char my_toupper(char c){
  if (my_islower(c))
    return c + ('A' - 'a');
  return c;
}

/**
Funktion void my_strcpy_std(char* source, char* destination), die die Zeichenkette
source nach destination kopiert
*/
void my_strcpy_std(char* source, char* destination){
  for( ;*source != '\0'; ++source, ++destination)
      *destination = *source;
}

/**
  Für jedes Element die Methode fn ausführen
*/
void for_each(char* source, char* destination, (*fn)(char)){
  for(;*source != '\0'; ++source, ++destination)
    *destination = fn(*source);
}

/**
Funktion void my_strtolower_std(char* source, char* destination), die die Zeichenkette
source nach destination kopiert und dabei Groß- in Kleinbuchstaben umwandelt
*/
void my_strtolower_std(char* source, char* destination){
  for_each(source, destination, &my_tolower);
}

/**
Funktion void my_strtoupper_std(char* source, char* destination), die die Zeichenkette
source nach destination kopiert und dabei Klein- in Großbuchstaben umwandelt
*/
void my_strtoupper_std(char* source, char* destination){
  for_each(source, destination, &my_toupper);
}

/**
Funktion unsigned int my_strlen(char c), die die Länge der übergebenen Zeichenkette
zurückgibt
*/
unsigned int my_strlen(char* c){
  unsigned int length;
  for(length = 0; *c != '\0'; ++length, ++c)
    ;
  return length;
}
