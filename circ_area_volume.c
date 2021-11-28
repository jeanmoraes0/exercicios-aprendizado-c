#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu(int *op);
void circunferencia();
void area();
void volume();

int main(){

	void (*calculo[3])() = {circunferencia, area, volume};

	int op = 0;

	while(op >= 1 && op < 4 || op == 0){
		menu(&op);

		if(op > 3)
			return 0;

		(*calculo[op - 1])();

	}
}

void menu(int *op){

	system("clear");

	printf("==================================================================================\n");
	printf("Calculadora da circunferência do círculo, "
		"da área do círculo e do volume da esfera\n");
	printf("==================================================================================\n\n");
	
	printf(" 1 - Circunferência do círculo\n");
	printf(" 2 - Área do círculo\n");
	printf(" 3 - Volume da esfera\n");
	printf(" 4 - Sair\n\n");

	printf("Qual operação deseja realizar? ");
	scanf("%d", &(*op));
}

void circunferencia(){

	system("clear");

	double raio;
	double circunferencia;

	printf("\nDigite o raio da circunferência: ");
	scanf("%lf", &raio);

	circunferencia = 2 * (3.14) * raio;

	printf("\n\nFoi realizado o calculo da circunferência do circulo\n");
	printf("O valor recebido do raio da circunferência foi de %.2lf\n", raio);
	printf("A circunferência do circulo é de %.2lf\n", circunferencia);

	printf("\n\nEnter para continuar ");
	getchar();
	getchar();
}

void area(){

	system("clear");

	double raio;
	double area;

	printf("\nDigite o raio do circulo: ");
	scanf("%lf", &raio);

	area = (3.14) * (pow(raio, 2));

	printf("\n\nFoi realizado o calculo da area do circulo\n");
	printf("O valor recebido do raio do circulo foi de %.2lf\n", raio);
	printf("A circunferência do circulo é de %.2lf\n", area);

	printf("\n\nEnter para continuar ");
	getchar();
	getchar();

}

void volume(){

	system("clear");

	double raio;
	double volume;

	printf("\nDigite o raio do circulo: ");
	scanf("%lf", &raio);

	volume = (4 * (3.14) * (pow(raio, 3))) / 3;

	printf("\n\nFoi realizado o calculo do volume da esfera\n");
	printf("O valor recebido do raio da esfera foi de %.2lf\n", raio);
	printf("O volume da esfera é de %.2lf\n", volume);

	printf("\n\nEnter para continuar ");
	getchar();
	getchar();

}