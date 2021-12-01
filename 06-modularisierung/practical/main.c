#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAZE_SIZE 22

char maze[MAZE_SIZE +1][MAZE_SIZE +1];

void print_maze(){
	// Koordniaten
	printf("\n    ");
	for(int i = 0;  i < MAZE_SIZE/10+1; ++i){
    printf("%d", i);
    for(int j = 0; j < 9; ++j)
      printf(" ");
  }

	printf("\n    ");
	for(int i = 0;  i < MAZE_SIZE/10+1; ++i){
    for(int j = 0; j < 10; ++j)
      printf("%d", j);
  }
	printf("\n");

	// labyrinth
	for(int i = 0; i < MAZE_SIZE; ++i){
			printf("%-3d-%s\n", i, maze[i]);
	}
}

void scan_maze(){
	int input;
	int zeile = 0;
	while (1) {
		input = scanf("%[#!@ ]%*[\n] ", maze[zeile]);

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
		if(maze[y][x] == '!') {
			return true;
		} else if(maze[y][x] == '#'){
			return false;
		}

		maze[y][x] = '#';

		// Nach unten
		if(solve_maze(x, y+1)){
			maze[y][x] = 'v';
			return true;
		}
		// Nach rechts
		if(solve_maze(x+1, y)){
			maze[y][x] = '>';
			return true;
		}
		// Nach links
		if(solve_maze(x-1, y)){
			maze[y][x] = '<';
			return true;
		}
		// Nach oben
		if(solve_maze(x, y-1)){
			maze[y][x] = '^';
			return true;
		}

		maze[y][x] = '*';
		return false;
}

int main(){
	scan_maze();
	print_maze();

	if(solve_maze(1, 1)){
		printf("\nMaze solved.\n");
	} else {
		printf("\nMaze not solved.\n");
	}

	print_maze();

	return 0;
}
