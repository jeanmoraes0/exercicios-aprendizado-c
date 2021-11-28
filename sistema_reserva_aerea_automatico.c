#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANTIDADE 10

int gerar_assento(int opt);
int gerar_bilete(int assento, int opt);
int adicionar_assento(int opt, int a[]);
int verificar_cheio(const int a[], int opt);

int main(){
    system("clear");
    srand(time(NULL));
    
    int assentos[QUANTIDADE] = {0};
    
    int opt;
    int i;
    int assento;
    int soma;

    do{
        system("clear");
        printf("Favor digitar 1 para ""primeira classe""\n");
        printf("Favor digitar 2 para ""econômica""\n");
        printf("Digite a opção: ");
        scanf("%d", &opt);

        adicionar_assento(opt, assentos);


    }while(opt <= 2);
    
    
   
    return 0;
}

int gerar_assento(int opt){
    int inicio;
    int limite = QUANTIDADE - 5;
    
    switch(opt){
        case 1:
            inicio = 0;
            break;
        case 2:
            inicio = 5;
            break;
    }
    
    return inicio + rand() % limite;
}

int gerar_bilete(int assento, int opt){
    system("clear");
    switch(opt){
        case 1:
            printf("Seção: primeira classe\nAssento %d\n", assento + 1);
            break;
        case 2:
            printf("Seção: classe econômica\nAssento %d\n", assento + 1);
            break;
    }

    getchar();
    getchar();
}

int adicionar_assento(int opt, int a[]){
    int assento;
    int i;
    int verificar;
    int escolha;

    assento = gerar_assento(opt);

    for(i = 0; i < QUANTIDADE; i++){
            if(assento == i){
                if(a[i] == 0){
                    ++a[i];
                    gerar_bilete(assento, opt);
                }
                else{
                    verificar = verificar_cheio(a, opt);
                    if(verificar == 1){
                        printf("Todos os assentos estão cheios\n");
                        printf("Deseja ir para %s\n", opt == 1 ? "classe econômica" : "primeira classe");
                        printf("1 para SIM, 2 para NÂO\n");
                        printf("Digite a opção: ");
                        scanf("%d", &escolha);
                        if(escolha == 1){
                            if(opt == 1){
                                adicionar_assento(2, a);
                            }
                            if(opt == 2){
                                adicionar_assento(1, a);
                            }
                        }
                        else{
                            printf("O proximo voo sairá em 3 horas\n");
                            getchar();
                            break;
                        }
                        getchar();
                        getchar();
                    }
                    else
                        adicionar_assento(opt, a);

                }
            }
        }
}

int verificar_cheio(const int a[], int opt){
    int soma;
    int i;
    int cheio = 0;

    if(opt == 1){
        for(i = 0; i < 5; i++){
            soma += a[i];
            if(soma == 5)
                cheio = 1;
        }
    }
    if(opt == 2){
        for(i = 5; i < 10; i++){
            soma += a[i];
            if(soma == 5)
                cheio = 1;
        }
    }

    return cheio;
}
