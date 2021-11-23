#include <stdio.h>

void print_binary(char b, int zahlen_system){
    if(b > 0){
        print_binary(b /zahlen_system, zahlen_system);
        char a = b %zahlen_system;
        switch(a){
            case 10:
                a = 'a';
                break;
                
            case 11:
                a = 'b';
                break;
                
            case 12:
                a = 'c';
                break;
                
            case 13:
                a = 'd';
                break;
                
            case 14:
                a = 'e';
                break;
                
            default:
                break;
        }
        printf("%d", a);
    }
}

void print_is_equal(char decimal, char binary, int zahlen_system){
    printf("%hhi ", decimal);
    if(decimal == binary)
        printf("==");
    else
        printf("!=");
    printf(" 0b");
    print_binary(binary, zahlen_system);
    printf("\n");
}

void aufgabe_1_a(){
    printf("Aufgabe 1: a)\n");
    // 7 == 0b111
    print_is_equal(7, 0b0111, 2);
    // 9 == 0b1001& -9 == 0b11110111
    print_is_equal(-9, 0b11110111, 2);
    // 11 == 0b1011
    print_is_equal(11, 0b1011, 2);
    // 13 == 1101 & -13 == 0b11110011
    print_is_equal(-13, 0b11110011, 2);
    // 15 = 1111 & -15 == 0b11110001
    print_is_equal(-15, 0b11110001, 2);
}

void aufgabe_1_b(){
    printf("Aufgabe 2: b)\n");
    // CHAR MAX: 256 -> 0xFF -> 0377 -> 0b11111111     --> 0 1 2 3 4 5 6 7 8 9 A B C D E F
    
    // 43 = 0x2b = 053 = 0b101011 & -43 = 0xD5 = 0325 = 0b11010101
    print_is_equal(-43, 0xD5, 16);
    print_is_equal(-43, 0325, 8);
    print_is_equal(-43, 0b11010101, 2);
    
    /*
     217 =  0xD0 =  0           8
            15
     */
    
    print_is_equal(16, 11, 16);
}

int main(){
    aufgabe_1_a();
    aufgabe_1_b();
    return 0;
}
