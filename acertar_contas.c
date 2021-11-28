#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerar_numero();
int tabuada();
void gerar_resposta(int numero);
int gerar_conta(int opcao, int num1, int num2);

int main(){

    printf("TABUADA!!!\n");
	printf("APERTE CTRL + C PARA SAIR\n\n");

	tabuada();
	
	return 0;
}

// gerar numero aleatorio para as contas
int gerar_numero(){

    return rand() % 100;

}

// gerar resposta apos as respostas
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

// gera a tabuada e faz a pergunta
int tabuada(){

    srand(time(NULL));
    
    int opcao;
    int numero1 = gerar_numero();
    int numero2 = gerar_numero();
    int resposta_usuario;
    int true_false = 1;
	int resposta;
	
    printf("Escoha uma opção\n");
    printf("Digite 1 para adição\nDigite 2 para subtração\nDigite 3 para multiplicação\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
	
    int resposta_certa = gerar_conta(opcao, numero1, numero2);
    
    while(true_false){
    
        switch(opcao){
        
            case 1:
                printf("\nQuanto é %d + %d? ", numero1, numero2);
                scanf("%d", &resposta_usuario);
                break;
                
            case 2:
                printf("\nQuanto é %d - %d? ", numero1, numero2);
                scanf("%d", &resposta_usuario);
                break;
            
            case 3:
                printf("\nQuanto é %d x %d? ", numero1, numero2);
                scanf("%d", &resposta_usuario);
                break;
        
        }
    
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

int gerar_conta(int opcao, int num1, int num2){

    switch(opcao){
    
        case 1:
            return num1 + num2;
            break;
            
        case 2:
            return num1 - num2;
            break;
            
        case 3:
            return num1 * num2;
            break;
    
    }

}
