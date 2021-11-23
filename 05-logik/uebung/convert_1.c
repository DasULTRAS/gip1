#include <stdio.h>

/*
  5 => "00000101"
        00000100
 */

void print_binary(char n) {
    char binary[9] = "00000000";
    int i;

    for (i = 0; i < 8; i++) {
        if (n & (1<<i)) {
            binary[7 - i] = '1';
        }
    }

    printf("%s\n", binary);
}

int get_str_length(char str[]){
    int n;
    for(n = 0; str[n] != '\0'; n++)
        ;
    return n;
}

void print_decimal(char bin_str[]){
    int length = get_str_length(bin_str);
    char decimal = 0;
    for(int i = 0; i < length; i++){
        if(bin_str[i] == '1')
            decimal = decimal | (1 << i);
    }
    
    printf("%hhi\n", decimal);
}

int main() {
    char input;
    char prefix;
    int result = 0;
    char bin_str[9];

    while (1) {
        printf("Bitte eine Zahl mit dem Prefix 'b' für binaere und 'd' für Dezimalzahlen an:\n");
        
        result = scanf(" %c", &prefix);
    
        if (result == EOF)
            break;
        
        if (prefix == 'd') {
            result = scanf("%hhi", &input);

            if (result == EOF)
                break;

            print_binary(input);
        } else if (prefix == 'b') {
            result = scanf("%s", bin_str);

            if (result == EOF)
                break;

            print_decimal(bin_str);
        }
    }
}
