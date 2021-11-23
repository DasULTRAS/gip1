#include <stdio.h>

int ggt_brute_force(int a, int b){
    int max;
    
    if (a > b)
        max = b;
    else
        max = a;
    
    for(; max > 0; --max)
        if (a %max == 0 && b %max == 0)
            return max;
    
    return -1;
}

int ggt_euklidischer_algorithmus(int a, int b){
    if(a > b)
        return ggt_euklidischer_algorithmus(a-b, b);
    else if(a < b)
        return ggt_euklidischer_algorithmus(a, b-a);
    else
        return a;
}

int main(){
    int a, b, ggt, printf_input;
    
    while(1){
        printf("Geben sie zwei ganze Zahlen mit einer Leertaste ein:\n");
        printf_input = scanf("%d %d", &a, &b);
        
        // if(printf_input == E0F || printf_input != 2)
        if(printf_input != 2)
            break;
        
        printf("a: %d, b: %d, ggt brute-force: %d, ggt euklidischer-algorithmus: %d\n", a, b, ggt_brute_force(a, b), ggt_euklidischer_algorithmus(a, b));
        
        //printf("a: %d, b: %d, ggt brute-force: %d\n", a, b, ggt_brute_force(a, b));
        //printf("a: %d, b: %d, ggt euklidischer-algorithmus: %d\n", a, b, ggt_euklidischer_algorithmus(a, b));
        
    }
}
