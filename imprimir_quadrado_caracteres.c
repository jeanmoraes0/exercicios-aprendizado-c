// imprimir caracteres

#include <stdio.h>

int fillCharacter(int side, int simbolo);

int main(void){
    
    int side;
    int simbolo;

	printf("Digite o simbolo para imprimir o quadrado: ");
	simbolo = getchar();
    
	printf("Digite o lado do quadrado: ");
	scanf("%d", &side);
    
	fillCharacter(side, simbolo);
    
    return 0;

}

int fillCharacter(int side, int simbolo){

    for(int i = 1; i <= side; i++){ 
        for(int j = 1; j <= side; j++)
            putchar(simbolo);
            
        printf("\n");
    }

}
