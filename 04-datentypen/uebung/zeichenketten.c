#include <stdio.h>

int main(){
	char input[101];
	char a;
	
    // max 100 Zeichen lagen String einlesen
	int scanf_input = scanf("%100s %c", input, &a);
	if(scanf_input == EOF)
		return 1;
    
    // Zählen wie of a in input vorkommt
	int count = 0;
    int array_length = 0;
    for(; input[array_length] != '\0'; ++array_length){
		if(input[array_length] == a)
			count++;
        printf("%d: %c\n", array_length, input[array_length]);
    }
    
    printf("Array Groeße: %d\n", array_length);
    
    // Zeichenkette input invertieren
    char invertiert[array_length +1];
    for(int i = 0; i <= array_length; ++i)
        invertiert[i] = input[i];
    
    for(int i = 0; i < array_length-i; ++i){
        char temp = invertiert[i];
        invertiert[i] = invertiert[array_length-i-1];
        invertiert[array_length-i-1] = temp;
    }
    printf("Invertierte Zeichenkette: \n%s \n", invertiert);
    
    // alle e aus den Zeichenketten entfernen
    count = 0;
    char ohne_e[array_length +1];
    for(int i = 0; i <= array_length; ++i)
        ohne_e[i] = input[i];
    
    for(int i = 0; i+count <= array_length; ++i){
        while((ohne_e[i +count] == 'E') || (ohne_e[i +count] == 'e'))
            count++;
        ohne_e[i] = ohne_e[i +count];
    }
    printf("Zeichenkette ohne e: \n%s \n", ohne_e);
    
	return 0;
}
