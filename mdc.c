// encontrar MDC de dois numeros

#include <stdio.h>

int mdc(int num1, int num2);

int main(void){

	int num1;
	int num2;

	printf("Digite o primeiro número: ");
	scanf("%d", &num1);

	printf("Digite o segundo número: ");
	scanf("%d", &num2);

    printf("O MDC de %d e %d é: %d\n", num1, num2, mdc(num1, num2));
	return 0;
}

int mdc(int num1, int num2){

	int mdc = 1;

	for(int i = 2; i <= 9; i++){
		if(num1 % i == 0 && num2 % i == 0){
			mdc *= i;;
			num1 /= i;
			num2 /= i;
			i--;
		}
	}

	return mdc;

}
