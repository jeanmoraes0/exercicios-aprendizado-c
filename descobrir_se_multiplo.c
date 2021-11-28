// descubrir se é multiplo

#include <stdio.h>

int multiple(int numero1, int numero2);

int main(void){

    int numero1;
    int numero2;
    
    printf("Digite o primeiro número: ");
    scanf("%d", &numero1);
    
    printf("Digite o segundo número: ");
    scanf("%d", &numero2);
    
    int true_false = multiple(numero1, numero2);
    
    if(true_false)
        printf("%d é um multiplo de %d\n", numero2, numero1);
    else
        printf("%d não é um multiplo de %d\n", numero2, numero1);
        
    return 0;    

}

int multiple(int numero1, int numero2){

    if(numero2 % numero1 == 0)
        return 1;
    else
        return 0;

}
