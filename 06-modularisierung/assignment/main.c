#include <stdio.h>
#include "my_math/my_math.h"
#include "my_string/my_string.h"

void test_my_string(){
    // Test my_strlen
    char str[] = "Ufo361-StayHigh";
    printf("Länge des String \"%s\" - my_strlen: %d\n", str, my_strlen(str));
    
    // test my_strcmp
    /*
     my_strcmp("abcd", "abcd") gibt 0 zurück,
     my_strcmp("abcd", "abdd") gibt eine negative Zahl zurück,
     my_strcmp("abcd", "abcc")
     */
    char str1[] = "abcd";
    char str2[] = "abcd";
    printf("Test 1: 0 - \"%s\"==\"%s\" - my_strcmp: %d\n", str1, str2, my_strcmp(str1, str2));
    str2[2] = 'd';
    printf("Test 2: 1 - \"%s\"==\"%s\" - my_strcmp: %d\n", str1, str2, my_strcmp(str1, str2));
    str2[2] = 'c';
    str2[3] = 'c';
    printf("Test 3: -1 - \"%s\"==\"%s\" - my_strcmp: %d\n", str1, str2, my_strcmp(str1, str2));
    
    // test my_strstr
    char str3[] = "StayHigh";
    printf("Ist String \"%s\" in \"%s\" - my_strstr: %d\n", str, str3, my_strstr(str, str3));
    char str4[] = "Ufo";
    printf("Ist String \"%s\" in \"%s\" - my_strstr: %d\n", str, str4, my_strstr(str, str4));
    char str5[] = "Ufo360";
    printf("Ist String \"%s\" in \"%s\" - my_strstr: %d\n", str, str5, my_strstr(str, str5));
}

int main(){
    int input;
    int zahl;
    
    // Test
    test_my_string();
    
    while(1){
        input = scanf("%d", &zahl);
        
        if(input == EOF)
            break;
        
        unsigned int fibonacci = get_fibonacci_recursive(zahl);
        unsigned int fakultaet = get_factorial_recursive(zahl);
        printf("%d. fibonacci: %u, fakultät: %u\n", zahl, fibonacci, fakultaet);
    }
    
    return 0;
}
