#include <stdio.h>

int main(){
    printf("Taschenrechner: x o x \nEingabe: zahl operator zahl \nBsp.: 5 + 8 \n");
    
    while(1){
        int zahl1, zahl2, ergebnis;
        char operator;
        int input = scanf("%d %c %d", &zahl1, &operator, &zahl2);
        
        if(input == EOF)
            break;
        
        printf("%d %c %d = ", zahl1, operator, zahl2);
        
        switch (operator) {
            case '+':
                ergebnis = zahl1 + zahl2;
                break;
            
            case '-':
                ergebnis = zahl1 - zahl2;
                break;
                
            case '/':
                ergebnis = zahl1 / zahl2;
                break;
                
            case '%':
                ergebnis = zahl1 % zahl2;
                break;
                
            case '*':
                ergebnis = zahl1 * zahl2;
                break;
        
            default:
                printf("Der Operator wurde nicht implementiert.");
        }
        
        printf("%d \n", ergebnis);
    }
    
    return 0;
}
