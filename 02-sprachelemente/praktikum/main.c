#include <stdio.h>

int main(){
    int eingabe;
    int input;
    int summe = 0;
    int min = 0;
    int max = 0;

    while (1) {
        printf("Bitte eine Nummer eingeben:\n");
        input = scanf("%d", &eingabe);
        if(input == EOF)
            break;
        
        // Summe hochzählen
        summe += eingabe;
        
        // Min/Max speichern
        if(max == 0 && min == 0) {
            max = eingabe;
            min = eingabe;
        } else if (max < eingabe)
            max = eingabe;
        else if (min > eingabe)
            min = eingabe;
        
        printf("Eingabe: %d\n", eingabe);
    }
    
    printf("Summe: %d \nMin: %d \nMax: %d", summe, min, max);
    
    return 0;
}
