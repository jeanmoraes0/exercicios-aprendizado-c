#include <stdio.h>
#include <stdlib.h>

void mostrar_resultado(const int respostas[][10], const char *perguntas[], float *media);
void fazer_perguntas(const char *perguntas[], int respostas[][10], int *voto);
void intro();

int main(){
	system("clear");

	const char *perguntas[5] = 
	{
		"Você acha escola importante?            ", 
		"Qual a importancia de uma faculdade?    ", 
		"O sistema de avaliação é bom?           ", 
		"Qual o estado da estrutura da faculdade?", 
		"O sistema EAD é eficaz?                 "
	};

	int respostas[5][10] = {0};

	int voto;
	int sent = 1;
	float media = 0;

	intro();

	if(getchar()){

		while(sent == 1){

			fazer_perguntas(perguntas, respostas, &voto);

			printf("Deseja votar novamente?\n");
			printf("1 - SIM 0 - NÂO ");
			scanf("%d", &sent);
		}
	}

	mostrar_resultado(respostas, perguntas, &media);

	return 0;
}

void mostrar_resultado(const int respostas[][10], const char *perguntas[], float *media){

	printf("----------------------------------------------------------------------------\n");
	printf("%-50s", "Perguntas");
	for(int i = 1; i <= 10; i++)
		printf("%d ", i);

	printf("Média");

	printf("\n");
	printf("----------------------------------------------------------------------------\n");

	for(int i = 0; i < 5; i++){
		printf("%s", perguntas[i]);
		printf("%-10s", "");
		for(int j = 0; j < 10; j++){
			printf("%d ",respostas[i][j]);
			(*media) += respostas[i][j] * (j + 1);
		}
		printf("  %.2f", (*media) / 10);
		printf("\n");
		(*media) = 0;
	}
	printf("----------------------------------------------------------------------------\n");
}

void fazer_perguntas(const char *perguntas[], int respostas[][10], int *voto){

	for(int i = 0; i < 5; i++){

		system("clear");
		intro();
		printf("\n");

		printf("\nPergunta %d:\n", i + 1);
		printf("%s\n\n", perguntas[i]);
		printf("Dê um voto de 1(menos importante) a 10(mais importante): ");
		scanf("%d", &(*voto));

		respostas[i][(*voto) - 1] += 1;
	}

}

void intro(){

	printf("==================\n");
	printf("Sistema de votação\n");
	printf("==================\n\n");

	printf("Aperte enter para iniciar as perguntas ");
}