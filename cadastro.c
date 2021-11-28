#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 200

char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int op;

void cadastro();
void pesquisa();
void lista();

int main() {
    do{
        system("clear");
        printf("\n----Menu---\n1 - Cadastrar\n2 - Listar todos\n3 - Pesquisar\n4 - Sair ");
        scanf("%d", &op);
        switch(op){
            case 1:
                cadastro();
                break;
            case 2:
                lista();
                break;
            case 3:
                pesquisa();
                break;
            case 4:
                system("exit");
                break;
            default:
                printf("Opção inválida");
                getchar();
                getchar();
                break;
        }
    }while(op != 4);
}

void lista(){
    int i;
    for(i = 0; i < SIZE; i++){
        if(cpf[i] > 0)
            printf("\nNome: %s\nEmail: %s\nCPF: %d\n", nome[i], email[i], cpf[i]);
        else
            break;
    }
    getchar();
    getchar();
}

void cadastro(){

	static int linha;

	do{
		printf("\nDigite o nome: ");
		scanf("%s", nome[linha]);
		printf("\nDigite o email: ");
		scanf("%s", email[linha]);
		printf("\nDigite o CPF: ");
		scanf("%d", &cpf[linha]);
		printf("\nDigite 1 continuar ou outro valor para sair ");
		scanf("%d", &op);
		linha++;
	}while(op == 1);
	
}

void pesquisa(){
    int cpf_pesquisa;
    char email_pesquisa[50];
    int i;

    do{
        printf("\nDigite 1 para pesquisar por CPF ou 2 para pesquisar por email ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nDigite o CPF: ");
                scanf("%d", &cpf_pesquisa);
                for(i = 0; i < SIZE; i++){
                    if(cpf[i] == cpf_pesquisa){
                        printf("\nNome: %s\nEmail: %s\nCPF: %d\n", nome[i], email[i], cpf[i]);
                    }
                }
                break;
                
            case 2:
                printf("\nDigite o Email: ");
                scanf("%s", email_pesquisa);
                for(i = 0; i < SIZE; i++){
                    if(strcmp(email[i], email_pesquisa) == 0){ //função usado para comparar strings
                        printf("\nNome: %s\nEmail: %s\nCPF: %d\n", nome[i], email[i], cpf[i]);
                    }
                }
            
                break;
                
            default:
                printf("\nOpção inválida!");
                break;
                
        }
        printf("\nDigite 1 para continuar pesquisando ");
        scanf("%d", &op);
    }while(op == 1);

}
  
