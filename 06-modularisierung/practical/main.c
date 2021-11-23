#include <stdio.h>

#define MAZE_SIZE 22

char labyrinth[MAZE_SIZE +1][MAZE_SIZE +1];

void scan_labyrinth(){
	char temp;
	for(int i = 0; i < MAZE_SIZE; ++i){
		for(int j = 0; j < MAZE_SIZE; ++j){
			scanf("%c", &temp);
			if(temp == '#' || temp == '!' || temp == '@' || temp == ' ')
				labyrinth[i][j] = temp;
			else if(temp == '\n' && j == MAZE_SIZE-1){
				labyrinth[i][j] = '\0';
			}
		}
	}
}

void print_labyrinth(){
	for(int i = 0; i < MAZE_SIZE; ++i){
			printf("%s\n", labyrinth[i]);
	}
}
/*
void print_labyrinth(){
	for(int i = 0; i < MAZE_SIZE; ++i){
		printf("%s\n", labyrinth[i]);
	}
}
*/

int main(){
	scan_labyrinth();
	print_labyrinth();

	return 0;
}
