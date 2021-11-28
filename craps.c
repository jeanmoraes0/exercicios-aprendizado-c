#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANCAMENTO 1000

int valor_dado();
int jogar_dados();
void obter_resultado(int valor);

int main(){
	srand(time(NULL));

	int s_n;
	int resultado;

	jogar:
		system("clear");
		resultado = jogar_dados();
		obter_resultado(resultado);

	printf("Deseja jogar novamente?\n1 para SIM - 0 para NÂO: ");
	scanf("%d", &s_n);

	if(s_n)
		goto jogar;
	else
		return 0;
}

int valor_dado(){
	return 1 + rand() % 6;
}

int jogar_dados(){
	int dado1 = valor_dado();
	int dado2 = valor_dado();
	int soma_dados = dado1 + dado2;

	return soma_dados;
}

void obter_resultado(int valor){
	printf("Você tirou %d nos dados\n\n", valor);

	if(valor == 7 || valor == 11)
		printf("Você ganhou!!!\n");
	else if(valor == 2 || valor == 3 || valor == 12)
		printf("Você perdeu!!!\n");
	else{
		printf("Você obteve 1 ponto, jogando novamente os dados\n");
		int resultado = jogar_dados();
		if(resultado != 7)
			printf("Você ganhou!!!\nTirou %d nos dados\n\n", resultado);
		else
			printf("Você perdeu!!!\nTirou %d nos dados\n\n", resultado);
	}
}