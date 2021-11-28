// jogo adivinhar numero secreto

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
     printf(" _____                                _                                            __                                      _ \n");
     printf("|  __ \\                              | |                                          /_/                                     | |\n");
     printf("| |  | |   ___   ___    ___   _   _  | |__    _ __    __ _      ___      _ __    _   _   _ __ ___     ___   _ __    ___   | |\n");
     printf("| |  | |  / _ \\ / __|  / __| | | | | | '_ \\  | '__|  / _` |    / _ \\    | '_ \\  | | | | | '_ ` _ \\   / _ \\ | '__|  / _ \\  | |\n");
     printf("| |__| | |  __/ \\__ \\ | (__  | |_| | | |_) | | |    | (_| |   | (_) |   | | | | | |_| | | | | | | | |  __/ | |    | (_) | |_|\n");
     printf("|_____/   \\___| |___/  \\___|  \\__,_| |_.__/  |_|     \\__,_|    \\___/    |_| |_|  \\__,_| |_| |_| |_|  \\___| |_|     \\___/  (_)\n");
     printf("\n\n\n");
     
     
     
     srand(time(NULL));
     
     int true_false = 1;
     int numero_secreto = (1 + rand() % 1001);
     int numero_escolhido;
     int contador = 0;
	 int recomecar;

     
     printf("Eu tenho um número entre 1 e 1000.\n");
     printf("Você consegue descobrir qual é?\n\n");
     
     while(true_false){
     
        printf("Digite sua %dº tentativa: ", contador + 1);
        scanf("%d", &numero_escolhido);
        
        if(numero_escolhido == numero_secreto){
            printf("Excelente! Você descobriu o número!\n\n");
			true_false = 0;
        }
        else if(numero_escolhido < numero_secreto){
            printf("Muito baixo. Tente novamente.\n\n");
        }
        else{
            printf("Muito alto. Tente novamente.\n\n");
        }
        
        contador++;     
     } 
     
    if(contador < 10)
        printf("Ou você conhece o segredo ou teve sorte!\n\n");
    else if(contador == 10)
        printf("Ahah! Você conhece o segredo!\n\n");
    else
        printf("Você deveria se sair melhor!\n\n");

	printf("Quer jogar novamente? Digite 1 - SIM, digite 0 - Não: ");
	scanf("%d", &recomecar);

	if(recomecar)
		main();
                                                                                                                            
    return 0;
    
}
