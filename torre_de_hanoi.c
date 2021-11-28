#include <stdio.h>

void resolver_torre(int pecas, int origem, int destino, int temp);

int main(){

    int pecas;

    printf("Digite quantas peças: ");
    scanf("%d", &pecas);
    
    resolver_torre(pecas, 1, 3, 2);
    
    return 0;

}

void resolver_torre(int pecas, int origem, int destino, int temp){

    if(pecas == 1){
		printf("%d ---> %d\n", origem, destino);
		return;
	}

	resolver_torre(pecas - 1, origem, temp, destino);

	printf("%d ---> %d\n", origem, destino);
	
	resolver_torre(pecas - 1, temp, destino, origem);

}
