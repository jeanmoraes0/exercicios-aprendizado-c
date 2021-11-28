// encontrar numero primo

#include <stdio.h>

int primo(int num);

int main(void){

    for(int i = 1; i <= 1000; i++)
        primo(i);

    return 0;

}

int primo(int num){

    int cont = 0;
    
    for(int i = 1; i <= num; i++){
        if((num % i) == 0){
            cont++;
        }
    }
    
    if(cont == 2)
        printf("%d é um número primo\n", num);
    //else
        //printf("%d não é um número primo\n", num);

}

