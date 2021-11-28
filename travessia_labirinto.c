#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 12
#define RED "\x1b[31m"
#define WHITE "\x1b[37m"

void imprimir_labirinto(const char labirinto[][TAMANHO]);
int verificar_labirinto(const char labirinto[][TAMANHO], const int pos_y, const int pos_x);
int mazeTraverse(char labirinto[][TAMANHO], int pos_y, int pos_x);

int main(){
	system("clear");

	char labirinto[TAMANHO][TAMANHO] = 
	{ 
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
		'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
		'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
		'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',
		'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
		'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
		'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
		'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
		'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
		'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' 
	};

	mazeTraverse(labirinto, 2, 0);

	imprimir_labirinto(labirinto);

	return 0;
}

void imprimir_labirinto(const char labirinto[][TAMANHO]){
	for(int i = 0; i < TAMANHO; i++){
		for(int j = 0; j < TAMANHO; j++){
			if(labirinto[i][j] == 'X')
				printf(RED "%c ", labirinto[i][j]);
			else if(labirinto[i][j] == '#' || labirinto[i][j] == '.')
				printf(WHITE "%c ", labirinto[i][j]);
		}

		printf("\n");
	}
}

int verificar_labirinto(const char labirinto[][TAMANHO], const int pos_y, const int pos_x){

	if((pos_y >= 0 && pos_y < TAMANHO) && (pos_x >= 0 && pos_x < TAMANHO))
		if(labirinto[pos_y][pos_x] != '#' && labirinto[pos_y][pos_x] != 'X')
			return 1;
	
	return 0;
}

int mazeTraverse(char labirinto[][TAMANHO], int pos_y, int pos_x){

	if(verificar_labirinto(labirinto, pos_y, pos_x) && pos_y == TAMANHO - 1 || pos_x == TAMANHO){
		labirinto[pos_y][pos_x] = 'X';
		return 1;
	}

	else if(verificar_labirinto(labirinto, pos_y, pos_x)){

		labirinto[pos_y][pos_x] = 'X';

		if(mazeTraverse(labirinto, pos_y + 1, pos_x) == 1)
			return 1;

		if(mazeTraverse(labirinto, pos_y - 1, pos_x) == 1)
			return 1;

		if(mazeTraverse(labirinto, pos_y, pos_x + 1) == 1)
			return 1;

		if(mazeTraverse(labirinto, pos_y, pos_x - 1) == 1)
			return 1;

		labirinto[pos_y][pos_x] = '.';
	}

	return 0;

}