#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 11
#define JOGADAS 36000

int lancar_dado();
void imprimir_resultado(const int a[], const int b[]);

int main(){
	system("clear");
	srand(time(NULL));

	int quant_resultados[TAMANHO] = {0};
	int resultados_possiveis[TAMANHO] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	int dado1;
	int dado2;
	int soma_dados;
	int contador = 0;

	while(contador < JOGADAS){
		int i;

		dado1 = lancar_dado();
		dado2 = lancar_dado();
		soma_dados = dado1 + dado2;

		for(i = 0; i < TAMANHO; i++)
			if(soma_dados == resultados_possiveis[i])
				++quant_resultados[i];

		contador++;
	}

	printf("Soma\tQuantidade de vezes\tPorcentagem\n\n");

	imprimir_resultado(resultados_possiveis, quant_resultados);

	return 0;

}

int lancar_dado(){

	return 1 + rand() % 6;
}

void imprimir_resultado(const int a[], const int b[]){
	for (int i = 0; i < TAMANHO; i++)
		printf("% 4d\t% 19d\t% 11d%%\n", 
			a[i], 
			b[i], 
			(b[i] * 100) / JOGADAS);
}