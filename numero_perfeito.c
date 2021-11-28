// encontrar numero perfeito

#include <stdio.h>

int perfect(int number);

int main(void){

    for(int i = 1; i <= 10000; i++){
       if(perfect(i))
            printf("%d é um número perfeito\n", i);
        else
            printf("%d não é um número perfeito\n", i);
    }
    
    return 0;

}

int perfect(int number){

    int soma = 0;
    
    for(int i = 1; i < number; i++){
    
        if(number % i == 0)
            soma += i;
    
    }
    
    if(soma == number)
        return 1;
    else
        return 0;

}
