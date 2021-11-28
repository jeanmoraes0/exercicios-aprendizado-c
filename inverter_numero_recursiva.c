// inverter numeros usando funcao recursiva

#include <stdio.h>

int inverter_numero(int num);

int main(void){

    int num;
    
    printf("Digite um número para inverter: ");
    scanf("%d", &num);
    
    inverter_numero(num);
    
    return 0;

}

int inverter_numero(int num){

    if(num != 0){
        printf("%d", num % 10);
        inverter_numero(num / 10);
    }
    else
        printf("\n");
}
