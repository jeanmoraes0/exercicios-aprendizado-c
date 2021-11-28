#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int linear_search(const int array[], int key, int size);

int main(){
	system("clear");

	int a[SIZE];
	int x;	// CONTADOR PARA INICIALIZAR ELEMENTOS 0-99 DO ARRAY a
	int search_key;	// VALOR PARA LOCALIZAR NO ARRAY a
	int element;	// VARIAVEL PARA MANTER LOCAL DE search_key OR -1

	// CRIAR DADOS
	for(x = 0; x < SIZE; x++)
		a[x] = 2 * x;

	printf("Digite chave de pesquisa de inteiro: ");
	scanf("%d", &search_key);

	// TENTA LOCALIZAR search_key NO ARRAY a
	element = linear_search(a, search_key, SIZE);

	// EXIBE RESULTADOS
	if(element != -1){
		printf("Valor encontrado no elemento %d\n", element);
	}
	else{
		printf("Valor não encontrado\n");
	}

	return 0;
}

/*COMPARA CHAVE COM CADA ELEMENTO DO ARRAY ATÉ LOCAL SER ENCONTRADO
  OU ATÉ O FINAL DO ARRAY SER ALCANÇADO; RETORNA INDICE DO ELEMENTO
  SE CHAVE FOI ENCONTRADA OU -1 SE CHAVE NÃO ENCONTRADA*/
int linear_search(const int array[], int key, int size){
	int n;

	for(n = 0; n < size; ++n){
		if(array[n] == key){
			return n;
		}
	}

	return -1;
}