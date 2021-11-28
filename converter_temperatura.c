//converter temperatura

#include <stdio.h>

float fahrenheitToCelsius(float fahrenheit);
float celsiusToFahrenheit(float celsius);

int main(void){

    float fahrenheit;
    float celsius;
    
    printf("Conversão de temperatura\n");
    printf("Digite 1 para converter Fahrenheit para Celsius\nDigite 2 para converter Celsius para Fahrenheit\n");
    printf("Digite: ");
    
    switch(getchar()){
    
        case 49:
            printf("Digite a temperatura em Fahrenheit: ");
            scanf("%f", &fahrenheit);
            printf("%.1f\n", fahrenheitToCelsius(fahrenheit));
            break;
            
        case 50:
            printf("Digite a temperatura em Celsius: ");
            scanf("%f", &celsius);
            printf("%.1f\n", celsiusToFahrenheit(celsius));
            break;
        
        default:
            printf("Valor inválido!");
            break;
    }
    
	
	return 0;

}

float fahrenheitToCelsius(float fahrenheit){

    return (fahrenheit - 32) / 1.8;

}

float celsiusToFahrenheit(float celsius){

    return (celsius * 1.8) + 32;

}
