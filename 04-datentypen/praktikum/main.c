#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define korb_size 4

char farben[7][5] = {"Grün", "Rot", "Blau", "Gelb", "Korb", "Rabe"};

int get_dice_result(){
    return rand()%6 +1;
}

int get_sum_korb(int korb[]){
    int sum = 0;
    for(int i = 0; i < korb_size; i++)
        sum += korb[i];
    
    return sum;
}

void fill_korb(int korb[], int i){
    if(korb[i] < 10)
        korb[i]++;
}

void print_obstgarten_status(int korb[], int raben_teile){
    printf("Spielstand - ");
    for(int i = 0; i < korb_size; ++i){
        printf("%s: %d, ", farben[i], korb[i]);
    }
    printf("%s: %d\n", farben[5], raben_teile);
}

int obstgarten(){
    int korb[5] = {0,0,0,0}; // 0-Grün, 1-Rot, 2-Blau, 3-Gelb
    int raben_teile = 0;
    
    while(get_sum_korb(korb) < 40 && raben_teile < 9){
        int dice_result = get_dice_result();
        
        // printf("Es wurde %d:%s gewürfelt.\n", dice_result, farben[dice_result]);
        
        if (dice_result < 5) {
            // Eine bestimmte flaume ziehen
            fill_korb(korb, dice_result-1);
        } else if (dice_result == 5) {
            int i = 0;
            // Zwei Pflaumen ziehen
            for(int j = 0; j < 2; ++j){
                // Suchen der geringsten Pfrucht
                for(int k = 0; k < korb_size; ++k){
                    if(korb[i] > korb[k])
                        i = k;
                }
                
                fill_korb(korb, i);
            }
        } else {
            raben_teile++;
        }
        
        // print_obstgarten_status(korb, raben_teile);
    }
    if(get_sum_korb(korb) < 40)
        return 0; // Spieler haben verloren
    else
        return 1; // Spieler haben gewonnen
}

int main(){
    srand(time(NULL)); // use current time as seed for random generator

    int gewinne [] = {0,0};
    for(int i = 0; i < 1000000; i++){
        if(obstgarten()){
            printf("Spieler gewonnen.\n");
            ++gewinne[0];
        } else {
            printf("Rabe gewonnen.\n");
            ++gewinne[1];
        }
    }
    
    int summe = gewinne[0] + gewinne[1];
    printf("Die Spieler haben %d von %d gewonnen.\n", gewinne[0], summe);
    double gewinn_quote = (double)gewinne[0] /(double)summe;
    printf("Die Gewinnquote liegt bei: %f \n", gewinn_quote);
    
    return 0;
}
