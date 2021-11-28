#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerar_numero();
int tabuada();
void gerar_resposta(int numero);

int main(){

    printf("TABUADA!!!\n");
	printf("APERTE CTRL + C PARA SAIR\n\n");

	tabuada();
	
	return 0;
}

int gerar_numero(){

    return rand() % 100;

}

void gerar_resposta(int numero){

	srand(time(NULL));

	int random = (1 + rand() % 4);

	if(numero){
		switch(random){

			case 1:
				printf("Muito bom!\n\n");
				break;
			case 2:
				printf("Excelente!\n\n");
				break;
			case 3:
				printf("Bom trabalho!\n\n");
				break;
			case 4:
				printf("Continue assim!\n\n");
				break;
			
		}
	}
	else{
		switch(random){

			case 1:
				printf("Não. Tente novamente.\n\n");
				break;
			case 2:
				printf("Errado. Tente mais uma vez.\n\n");
				break;
			case 3:
				printf("Não desista!\n\n");
				break;
			case 4:
				printf("Não. Continue tentando.\n\n");
				break;
		}
	}
	
}

int tabuada(){

    srand(time(NULL));
    
    int numero1 = gerar_numero();
    int numero2 = gerar_numero();
    int resposta_certa = numero1 * numero2;
    int resposta_usuario;
    int true_false = 1;
	int resposta;
    
    while(true_false){
    
        printf("Quanto é %d x %d? ", numero1, numero2);
        scanf("%d", &resposta_usuario);
    
        if(resposta_usuario == resposta_certa){
        
            resposta = 1;
			gerar_resposta(resposta);
            true_false = 0;
            tabuada();
        
        }
        else{
        
            resposta = 0;
			gerar_resposta(resposta);
        
        }
    
    }  

}
