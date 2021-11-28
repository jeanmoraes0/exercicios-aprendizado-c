#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void bubble(int work[], const int size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);

int main(void){
	system("clear");

	int order;
	int counter;

	int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

	printf("Digite 1 para classificar em ordem crescente,\n"
		"Digite 2 para classificar em ordem decrescente: ");
	scanf("%d", &order);

	printf("\nItens de dados na ordem original\n");

	for(counter = 0; counter < SIZE; counter++)
		printf("%5d", a[counter]);

	if(order == 1){
		bubble(a, SIZE, ascending);
		printf("\nItens de dados em ordem crescente\n");
	}
	else{
		bubble(a, SIZE, descending);
		printf("\nItens de dados em ordem decrescente\n");
	}

	for(counter = 0; counter < SIZE; counter++){
		printf("%5d", a[counter]);
	}

	printf("\n");

	return 0;
}

void bubble(int work[], const int size, int (*compare)(int a, int b)){
	int passada;
	int contador;

	void swap(int *p_element1, int *p_element2);

	for(passada = 1; passada < size; passada++){
		for(contador = 0; contador < size - 1; contador++){
			if((*compare)(work[contador], work[contador + 1])){
				swap(&work[contador], &work[contador + 1]);
			}
		}
	}
}

void swap(int *p_element1, int *p_element2){
	int manutencao;

	manutencao = *p_element1;
	*p_element1 = *p_element2;
	*p_element2 = manutencao;
}

int ascending(int a, int b){
	return b < a;
}

int descending(int a, int b){
	return b > a;
}