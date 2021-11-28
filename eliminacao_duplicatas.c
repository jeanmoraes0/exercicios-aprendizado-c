#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

int main(){
	system("clear");

	int lista_numeros[TAMANHO] = {0};
	int numero;
	int contador = 0;
	int duplicata = 0;
	
	while(contador < TAMANHO){
		printf("Digite o %dº numero: ", contador + 1);
		scanf("%d", &numero);

		for(int i = 0; i <= contador; i++){
			if(numero == lista_numeros[i]){
				duplicata = 1;
				break;
			}
		}

		if(duplicata != 1){
			lista_numeros[contador] = numero;
			printf("%d\n", numero);
		}

		duplicata = 0;
		contador++;
	}

	printf("\n\n");

	for(int i = 0; i < TAMANHO; i++){
		if(lista_numeros[i] > 0)
			printf("%d\n", lista_numeros[i]);
	}

	return 0;

}