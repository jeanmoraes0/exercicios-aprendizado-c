#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void imprimir_pista(int *posicao_tartaruga, int *posicao_coelho);
void gerar_movimento(int *posicao_animal, int id);
int verificar_vencedor(const int *posicao_tartaruga, const int *posicao_coelho, int *fim);
void intro();

int main(){
	system("clear");

	srand(time(NULL));

	int posicao_tartaruga = 1;
	int posicao_coelho = 1;
	int animal;
	int fim = 0;
	int op;

	printf("Deseja usar timer? 1 - NÂO, 2 - SIM ");
	scanf("%d", &op);

	if(op == 1)
		intro();

	while(fim == 0){
		if(op == 2){
			system("clear");
			intro();
		}

		

		for(animal = 1; animal <= 2; animal++){
			gerar_movimento(animal == 1 ? &posicao_tartaruga : &posicao_coelho, animal);
		}

		printf("\n");

		imprimir_pista(&posicao_tartaruga, &posicao_coelho);

		verificar_vencedor(&posicao_tartaruga, &posicao_coelho, &fim);

		printf("\n");

		if(op == 2)
			sleep(1);

	}

	return 0;
}

int gerar_aleatorio(){

	return (1 + rand() % 10);
}

void imprimir_pista(int *posicao_tartaruga, int *posicao_coelho){
	for(int i = 1; i <= 70; i++){
		if((*posicao_tartaruga) == i && (*posicao_coelho) == i){
			printf("AI");
		}
		else if(i == 1){
			printf("S");
		}
		else if(i == 70){
			printf("F");
		}
		else if((*posicao_tartaruga) == i){
			printf("T");
		}
		else if((*posicao_coelho) == i){
			printf("C");
		}
		else{
			printf(".");
		}
	}

	printf("\n");
	printf("Posĩção Tartaruga: %d\n", (*posicao_tartaruga));
	printf("Posĩção Coelho: %d\n", (*posicao_coelho));
}

void gerar_movimento(int *posicao_animal, int id){

	int gerar_aleatorio();
	int verificar_tamanho_pista(int *posicao_animal);

	int aleatorio = gerar_aleatorio();

	if(id == 1){
		if(aleatorio >= 0 && aleatorio <= 5){
			(*posicao_animal) += 3;
		}
		else if(aleatorio <= 7){
			if((*posicao_animal) == 1)
				(*posicao_animal) = 1;
			else{
				(*posicao_animal) -= 6;
			}
		}
		else if(aleatorio <= 10){
			(*posicao_animal) += 1;
		}
	}
	else if(id == 2){
		if(aleatorio >= 1 && aleatorio <= 2){
			;
		}
		else if(aleatorio <= 4){
			(*posicao_animal) += 9;
		}
		else if(aleatorio <= 5){
			if((*posicao_animal) == 1)
				(*posicao_animal) = 1;
			else{
				(*posicao_animal) -= 12;
			}
		}
		else if(aleatorio <= 8){
			(*posicao_animal) += 1;
		}
		else if(aleatorio <= 10){
			if((*posicao_animal) == 1)
				(*posicao_animal) = 1;{
					(*posicao_animal) -= 2;
				}
		}
	}

	verificar_tamanho_pista(posicao_animal);
}

int verificar_tamanho_pista(int *posicao_animal){
	if((*posicao_animal) < 1)
		(*posicao_animal) = 1;
	else if((*posicao_animal) > 70)
		(*posicao_animal = 70);
}

int verificar_vencedor(const int *posicao_tartaruga, const int *posicao_coelho, int *fim){
	if((*posicao_tartaruga) >= 70 && (*posicao_coelho) >= 70){
		printf("\n\nEMPATE\n");
		(*fim) = 1;
	}
	else if((*posicao_tartaruga) == 70){
		printf("\n\nTartaruga venceu!\n");
		(*fim) = 1;
	}
	else if((*posicao_coelho) == 70){
		printf("\n\nCoelho venceu\n");
		(*fim) = 1;
	}
}

void intro(){
	printf("\t\t\t##########################\n");
	printf("\t\t\t#        BANG !!!!       #\n");
	printf("\t\t\t#   E LA VÂO ELES !!!!   #\n");
	printf("\t\t\t##########################\n");
	printf("S - Saída   F - Final   T - Tartaruga   C - Coelho   AI - Encontro\n\n");
}