#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 8
#define X_INICIAL 0
#define Y_INICIAL 0

void mostrar_tabuleiro(const int board[][TAMANHO]);
void mover_cavalo(int board[][TAMANHO], const int vertical[], const int horizontal[]);
int verificar_tabuleiro(int currentRow, int currentCol);
int verificar_visitou(int currentRow, int currentCol, const int board[][TAMANHO]);

int main(){
	system("clear");

	int board[TAMANHO][TAMANHO] = {0};
	int vertical[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int horizontal[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	/*int accessibility[][] = {
		2, 3, 4, 4, 4, 4, 3, 2,
		3, 4, 6, 6, 6, 6, 4, 3,
		4, 6, 8, 8, 8, 8, 6, 4,
		4, 6, 8, 8, 8, 8, 6, 4,
		4, 6, 8, 8, 8, 8, 6, 4,
		4, 6, 8, 8, 8, 8, 6, 4,
		3, 4, 6, 6, 6, 6, 4, 3,
		2, 3, 4, 4, 4, 4, 3, 2};*/

	mover_cavalo(board, vertical, horizontal);
	
	return 0;
}

void mostrar_tabuleiro(const int board[][TAMANHO]){

	printf("%4s%6s%6s%6s%6s%6s%6s%6s\n", "0", "1", "2", "3", "4", "5", "6", "7");
	printf("________________________________________________\n");

	for(int i = 0; i < TAMANHO; i++){
		printf("%d ", i);
		printf("|");
		for(int j = 0; j < TAMANHO; j++){
			if(board[i][j] == 0)
				printf("%-6s", "#");
			else
				printf("%-6d", board[i][j]);
		}
		printf("\n");
	}
	printf("________________________________________________\n");

}

int verificar_tabuleiro(int currentRow, int currentCol){

	if(currentRow < 0 || currentRow > 7)
		return 1;

	if(currentCol < 0 || currentCol > 7)
		return 1;
}

int verificar_visitou(int currentRow, int currentCol, const int board[][TAMANHO]){

	if(board[currentRow][currentCol] != 0)
		return 1;
}

void mover_cavalo(int board[][TAMANHO], const int vertical[], const int horizontal[]){

	int currentRow = Y_INICIAL;
	int currentCol = X_INICIAL;
	int moveNumber = 0;
	int contador = 1;
	int contador_visita = 1;
	int temp1;
	int temp2;

	while(1){

		temp1 = currentRow + vertical[moveNumber];
		temp2 = currentCol + horizontal[moveNumber];

		if(verificar_tabuleiro(temp1, temp2) != 1){
			if(verificar_visitou(temp1, temp2, board) != 1){
				board[currentRow][currentCol] = contador_visita++;
				currentRow += vertical[moveNumber];
				currentCol += horizontal[moveNumber];
			}

		}

		contador++;
		moveNumber++;

		if(moveNumber > 7)
			moveNumber = 0;

		if(contador == 64)
			break;
	}


	mostrar_tabuleiro(board);
	
}