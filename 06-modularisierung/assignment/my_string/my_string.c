#include "my_string.h"
#include <stdio.h>

/**
 Eine Funktion my_strlen, die die Länge der übergebenen Zeichenkette zurückgibt.
 */
int my_strlen(char str[]) {
    int n;
    for(n = 0; str[n] != '\0'; ++n)
        ;
    return n;
}

/**
 Eine Funktion my_strcmp, die zwei Zeichenketten lexikogra sch vergleicht. Sind beide Zeichenketten
 identisch, gibt diese Funktion 0 zurück. Unterscheiden sich beide Zeichenketten, bezieht sich die Rückgabe
 auf das erste verschiedene Zeichenpaar. Die Rückgabe ist negativ, wenn das betre ende Zeichen
 der ersten Zeichenkette in der ASCII-Tabelle weiter vorne steht als das Zeichen in der zweiten Zeichenkette.
 Im anderen Fall ist die Rückgabe positiv.
 */
int my_strcmp(char str1[], char str2[]){
    // Festlegen der max. laufzeit der Schleife
    int length = my_strlen(str1);
    if(my_strlen(str2) < length)
        length = my_strlen(str2);
    
    // Suchen unterschiede
    int i;
    for(i = 0; str1[i] == str2[i] && i < length; ++i)
        ;
    
    // Auswerten
    if(i == length && my_strlen(str1) == my_strlen(str2))
        return 0;
    else if (str1[i] < str2[i])
        return 1;
    else
        return -1;
}

/**
 Eine Funktion my_strstr die zwei Zeichenketten übernimmt, und true zurückgibt, falls die zweite
 Zeichenkette in der ersten enthalten ist.
 */
int my_strstr(char str1[], char str2[]){
    int length1 = my_strlen(str1);
    int length2 = my_strlen(str2);
    for(int i = 0; i < length1; ++i)
        for(int j = 0; str1[i] == str2[j] && i < length1 && j < length2; ++j){
            ++i;
            if(j == length2 -1)
                return 1;
        }
    return 0;
}
