#include <stdio.h>

#define MAZE_SIZE 22

char labyrinth[MAZE_SIZE +1][MAZE_SIZE +1];

void print_labyrinth(){
	for(int i = 0; i < MAZE_SIZE; ++i){
			printf("%s\n", labyrinth[i]);
	}
}

void scan_labyrinth(){
	int input;
	int zeile = 0;
	while (1) {
		input = scanf("%[#!@ ]%*[\n] ", labyrinth[zeile]);

		if(input == EOF)
			break;

		++zeile;
	}
}

/**
bool solve_maze(unsigned int x, unsigned int y), die versucht,
einen Weg von einem durch x und y angegeben Startpunk
(markiert durch @) zum Ziel (markiert durch !) zu finden
*/
bool solve_maze(unsigned int x, unsigned int y){
	
}

int main(){
	scan_labyrinth();
	print_labyrinth();

	return 0;
}
