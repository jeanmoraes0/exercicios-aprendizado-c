// jogar moeda cara ou coroa

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();

int main(){

	srand(time(NULL));

    int cara = 0;
    int coroa = 0;
    
    for(int i = 1; i <= 100; i++){
		
        if(flip()){
            printf("CARA!\n");
            cara++;
        }else{
            printf("COROA!\n");
            coroa++;
        }
    }
    
    printf("CAIU %d VEZES CARA e %d VEZEZ COROA\n", cara, coroa);
    
    return 0;

}

int flip(){
	
    int cara_coroa = (rand() % 2);
    
    if(cara_coroa)
        return 1;
    else
        return 0;

}
