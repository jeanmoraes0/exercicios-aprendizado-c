#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE 10

int escolher_assento(int a[]);
void listar_assentos(const int a[], int opt);
void imprimir_bilhete(int opt, int assento);

int main(){
	system("clear");

	static int assentos[QUANTIDADE] = {0};

	int opt;
	
	printf("Bem vindo a companhia aŕea\n\n");

	do{
		printf("Digite 1 para escolher assentos\n");
		printf("Digite 2 para sair\n\n");
		printf("Digite a opção escolhida: ");
		scanf("%d", &opt);

		switch(opt){
			case 1:
				escolher_assento(assentos);
				system("clear");
				break;
			case 2:
				system("exit");
				break;
			default:
				printf("Valor inválido\n");
				break;
		}
	}while(opt != 2);

	return 0;
}

int escolher_assento(int a[]){
	system("clear");
	int opt;
	int assento;

	printf("1 para Primeira classe\n2 para Classe econômica: ");
	scanf("%d", &opt);

	listar_assentos(a, opt);

	printf("Qual assento deseja escolher?\n");
	printf("Digite o assento escolhido: ");
	scanf("%d", &assento);

	for(int i = 0; i < QUANTIDADE; i++){
		if(a[assento - 1] == a[i]){
			if(a[i] == 0){
				++a[assento - 1];
				imprimir_bilhete(opt, assento);
			}
		}
	}
}

void listar_assentos(const int a[], int opt){
	system("clear");
	int i;

	if(opt == 1){
		printf("Assentos na primeira classe\n");
		for(i = 0; i < 5; i++)
			printf("Assento %d: %s\n", i + 1, 
				a[i] == 0 ? "vago" : "ocupado");
		printf("\n");
	}
	if(opt == 2){
		printf("Assentos na classe econômica\n");
		for(i = 5; i < 10; i++)
			printf("Assento %d: %s\n", i + 1, 
				a[i] == 0 ? "vago" : "ocupado");
		printf("\n");
	}
}

void imprimir_bilhete(int opt, int assento){
	system("clear");
	if(opt == 1){
		printf("Assento %d escolhido\n", assento);
		printf("Sessão: primeira classe\n");
	}
	if(opt == 2){
		printf("Assento %d escolhido\n", assento);
		printf("Sessão: classe econômica\n");
	}

	getchar();
}