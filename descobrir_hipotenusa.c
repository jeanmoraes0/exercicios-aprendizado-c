// descobrir hipotenusa

#include <stdio.h>
#include <math.h>

double hipotenusa(void);

float lado1;
float lado2;

int main(void){

    double hipo = hipotenusa();
    
    printf("A hipotenusa de um triângulo retângulo de lado %.1f e lado %.1f é: %.1f\n", lado1, lado2, hipo);
    
    return 0;    
    
}

double hipotenusa(void){
        
    printf("Digite o lado 1: ");
    scanf("%f", &lado1);
    
    printf("Digite o lado 2: ");
    scanf("%f", &lado2);

    return sqrt(pow(lado1, 2) + pow(lado2, 2));

}

