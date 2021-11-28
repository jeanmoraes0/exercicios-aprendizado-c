#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50
#define X_INICIAL 25
#define Y_INICIAL 25

void mostrar_array(const int floor[][TAMANHO]);
void caminhar(int floor[][TAMANHO], const int direcao, const int caneta);


int main(){
	system("clear");

	int floor[TAMANHO][TAMANHO] = {0};

	while(1){
		system("clear");
		int comando;
		int caneta;
		int passos;
		int direcao;

		printf("1 - Caneta pra cima\n");
		printf("2 - Caneta pra baixo\n");
		printf("3 - Virar'para cima\n");
		printf("4 - Virar para baixo\n");
		printf("5 - Virar à direita\n");
		printf("6 - Virar à esquerda\n");
		printf("7 - Mover x passos\n");
		printf("8 - Mostrar passos\n");
		printf("9 - Encerrar\n");
		printf("Digite o comando: ");
		scanf("%d", &comando);

		switch(comando){
			case 1:
				caneta = 1;
				break;
			case 2:
				caneta = 2;
				break;
			case 3:
			case 4:
			case 5:
			case 6:
				direcao = comando;
				break;
			case 7:
				caminhar(floor, direcao, caneta);
				break;
			case 8:
				mostrar_array(floor);
				getchar();
				getchar();
				break;
			case 9:
				return 0;
		}
	}

	
}

void mostrar_array(const int floor[][TAMANHO]){
	system("clear");
	for(int i = 0; i < TAMANHO; i++){
		for(int j = 0; j < TAMANHO; j++){
			if(floor[i][j] == 0)
				printf(".");
			else
				printf("@");
		}

		printf("\n");
	}

	printf("\n");
}

void caminhar(int floor[][TAMANHO], const int direcao, const int caneta){
	static int x_atual = X_INICIAL;
	static int y_atual = Y_INICIAL;
	int passos;

	printf("Digite quantos passos: ");
	scanf("%d", &passos);

	if(direcao == 3){
		for(int i = 0; i < passos; i++){
			x_atual--;
			if(x_atual < 0)
				x_atual = 0;
			if(caneta == 1)
				floor[x_atual][y_atual] = 1;
			else
				floor[x_atual][y_atual] = 0;
		}
	}

	if(direcao == 4){
		for(int i = 0; i < passos; i++){
			x_atual++;
			if(x_atual > TAMANHO)
				x_atual = 49;
			if(caneta == 1)
				floor[x_atual][y_atual] = 1;
			else
				floor[x_atual][y_atual] = 0;
		}
	}

	if(direcao == 5){
		for(int i = 0; i < passos; i++){
			y_atual++;
			if(y_atual >= TAMANHO)
				y_atual = 49;
			if(caneta == 1)
				floor[x_atual][y_atual] = 1;
			else
				floor[x_atual][y_atual] = 0;
		}
	}

	if(direcao == 6){
		for(int i = 0; i < passos; i++){
			y_atual--;
			if(y_atual < 0)
				y_atual = 0;
			if(caneta == 1)
				floor[x_atual][y_atual] = 1;
			else
				floor[x_atual][y_atual] = 0;
		}
	}


}
