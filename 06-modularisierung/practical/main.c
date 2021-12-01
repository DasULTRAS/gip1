#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

#define MAZE_SIZE 50

char maze[MAZE_SIZE][MAZE_SIZE +1];

void print_maze(){
	// x-Koordniaten
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

/**
	scan_maze scannt ein labyrinth ein.
*/
void scan_maze(){
		for(int i = 0; i < MAZE_SIZE && scanf("%[#!@ ]%*[\n] ", maze[i]) != EOF; ++i);
}

/**
	clear löscht die Bildschirmausgaben
*/
void clear() {
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	  system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
	 system("cls");
	#endif
}

/**
	pause() wartet die angegebene Zeit
*/
void pause(unsigned int milliseconds) {
  clock_t start = clock();
  while (1000.0f * (clock() - start) / CLOCKS_PER_SEC < milliseconds);
}

/**
bool solve_maze(unsigned int x, unsigned int y), die versucht,
einen Weg von einem durch x und y angegeben Startpunk
(markiert durch @) zum Ziel (markiert durch !) zu finden
*/
bool solve_maze(unsigned int x, unsigned int y){
		if(maze[y][x] == '!') {
			return true;
		} else if(maze[y][x] == '#' || maze[y][x] == '.' || maze[y][x] == '*'){
			return false;
		}

		clear();
		print_maze();
		//pause(1);

		// Absichern das ein Weg nicht doppelt genommen wird
		maze[y][x] = '.';

		// Nach rechts
		if(solve_maze(x+1, y)){
			maze[y][x] = '>';
		} else
		// Nach unten
		if(solve_maze(x, y+1)){
			maze[y][x] = 'v';
		} else
		// Nach links
		if(solve_maze(x-1, y)){
			maze[y][x] = '<';
		} else
		// Nach oben
		if(solve_maze(x, y-1)){
			maze[y][x] = '^';
		} else {
			maze[y][x] = '*';
			return false;
		}
		return true;
}

int main(){
	scan_maze();
	print_maze();

	if(solve_maze(1, 1)){
		printf("\nMaze solved.\n");
	} else {
		printf("\nMaze not solved.\n");
	}

	clear();
	print_maze();

	return 0;
}
