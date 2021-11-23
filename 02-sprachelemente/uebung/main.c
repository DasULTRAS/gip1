#include <stdio.h>

void print_is_ungerade(int zahl){
    // is Ungerade
    if(zahl %2)
        printf("ungerade");
    else
        printf("gerade");
}

void print_teiler(int zahl){
    for(int i = zahl; i > 0; --i){
        if(zahl % i == 0)
            printf("%d ", i);
    }
}

int main(){
    int input, zahl;
    
    while(1){
        printf("\nBitte geben Sie eine Zahl ein: ");
        input = scanf("%d", &zahl);
        
        // Abbruchbedingung
        if(input == EOF)
            break;
        
        printf("%d: ", zahl);
        
        print_is_ungerade(zahl);
        
        printf(", Teiler: ");
        
        print_teiler(zahl);
    }
}
