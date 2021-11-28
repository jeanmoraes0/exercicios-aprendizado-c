#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANCAMENTO 1000

int valor_dado();
int jogar_dados();
void obter_resultado(int valor, int a[]);

int main(){
	system("clear");
	srand(time(NULL));

	int ganhou_perdeu[2] = {0};

	int resultado;
	int contador = 0;

	while(contador < LANCAMENTO){
		resultado = jogar_dados();
		obter_resultado(resultado, ganhou_perdeu);

		contador++;
	}

	printf("Você ganhou %d vezes\nVocê perdeu %d vezes\n", 
		ganhou_perdeu[0], ganhou_perdeu[1]);
		
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

void obter_resultado(int valor, int a[]){
	if(valor == 7 || valor == 11)
		++a[0];
	else if(valor == 2 || valor == 3 || valor == 12)
		++a[1];
	else{
		int resultado = jogar_dados();
		if(resultado != 7)
			++a[0];
		else
			++a[1];
	}
}