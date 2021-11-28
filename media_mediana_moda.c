#include <stdio.h>
#include <stdlib.h>
#define SIZE 99

// PROTOTIPO DE FUNÇÕES
void mean(const int answer[]);
void median(int answer[]);
void mode(int freq[], const int answer[]);
void bubble_sort(int a[]);
void print_array(const int a[]);

int main(){
	system("clear");
	
	int frequency[10] = {0};

	int response[SIZE] = 
		{6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
		7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
		6, 7 ,8, 9, 3, 9, 8, 7, 8, 7,
		7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
		6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
		7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
		5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
		7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
		7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
		4, 5, 6, 1, 6, 5, 7, 8, 7};

	// PROCESSA RESPOSTAS
	mean(response);
	median(response);
	mode(frequency, response);

	return 0;
}

// CALCULA MEDIA DE TODOS OS VALORES DE RESPOSTA
void mean(const int answer[]){
	int j;	// CONTADOR PARA TOTALIZAR OS ELEMENTOS DO ARRAY
	int total = 0;	// MANTER A SOMA DOS ELEMENTOS DO ARRAY

	printf("%s\n%s\n%s\n", "********", " Média", "********");

	// VALORES TOTAIS DE RESPOSTAS
	for(j = 0; j < SIZE; j++)
		total += answer[j];

	printf("A média é o valor médio dos itens de dados.\n"
			"A média é igual ao total de todos\n"
			"os itens de dados divididos pelo número\n"
			"de itens de dados (%d). O valor médio para esta\n"
			"execução é: %d / %d = %.4f\n\n",
			SIZE, total, SIZE, (double) total / SIZE);

}

// ORDENA ARRAY E DETERMINA VALOR DO ELEMENTO MEDIANO
void median(int answer[]){
	printf("\n%s\n%s\n%s\n%s", "********", " Mediana", "********",
			"O array de respostas, não ordenado, é");

	print_array(answer);	// EXIBE ARRAY NÃO ORDENADO

	bubble_sort(answer);	// ORDENA ARRAY

	printf("\n\nO array ordenado é");

	print_array(answer);	// EXIBE ARRAY ORDENADO

	// EXIBE ELEMENTO MEDIANO
	printf("\n\nA mediana é o elemento %d do\n"
			"array ordenado de %d elementos.\n"
			"Para essa execução, a mediana é %d\n\n",
			SIZE / 2, SIZE, answer[SIZE / 2]);
}

// DETERMINA A RESPOSTA MAIS FREQUENTE
void mode(int freq[], const int answer[]){
	int rating;	// CONTADOR PARA ACESSAR OS ELEMENTOS 1-9 DO ARRAY FREQ
	int j;	// CONTADOR PARA RESUMIR OS ELEMENTOS 0-98 DO ARRAY ANSWER
	int h;	// CONTADOR PARA EXIBIR HISTOGRAMAS DOS ELEMENTOS NO ARRAY FREQ
	int largest = 0;	// REPRESENTA MAIOR FREQUENCIA
	int mode_value = 0;	// REPRESENTA RESPOSTA MAIS FREQUENTE

	printf("\n%s\n%s\n%s\n", "********", " Moda", "********");

	// INICIALIZA FREQUENCIAS EM 0
	for(rating = 1; rating <= 9; rating++)
		freq[rating] = 0;

	// FREQUENCIA DE RESUMO
	for(j = 0; j < SIZE; j++)
		++freq[answer[j]];

	// CABEÇALHOS DE IMPRESSÃO PARA COLUNAS DO RESULTADO
	printf("%s%11s%19s\n\n%54s\n%54s\n\n", "Resposta", "Frequência", "Histograma",
			"1 1 2 2", "5 0 5 0 5");

	// EXIBE RESULTADOS
	for(rating = 1; rating <= 9; rating++){
		printf("%8d%11d", rating, freq[rating]);

		// ACOMPANHA VALOR DA MODA E VALOR DA MAIOR FREQUENCIA
		if(freq[rating] > largest){
			largest = freq[rating];
			mode_value = rating;
		}

		/*BARRA DE HISTOGRAMA DE SAIDA DE IMPRESSÃO QUE REPRESENTA
		VALOR DE FREQUENCIA*/
		for(h = 1; h <= freq[rating]; h++)
			printf("*");

		printf("\n");
	}

	// EXIBE VALOR DA MODA
	printf("A moda é o valor mais frequente.\n"
			"Para essa execução, a moda é %d, que ocorreu"
			" %d vezes.\n", mode_value, largest);
}

// FUNÇÃO QUE ORDENA UM ARRAY COM O ALGORITMO BUBBLE SORT
void bubble_sort(int a[]){
	int pass;	// CONTADOR DE PASSADA
	int j;	// CONTADOR DE COMPARAÇÃO
	int hold;	// LOCAL TEMPORARIO USADO PARA TROCA DE ELEMENTOS

	// LOOP PARA CONTROLAR NUMERO DE PASSADAS
	for(pass = 1; pass < SIZE; pass++){
		// LOOP PARA CONTROLAR NUMERO DE COMPARAÇÕES POR PASSADA
		for(j = 0; j < SIZE - 1; j++){
			// TROCA ELEMENTOS SE ESTIVEREM FORA DE ORDEM
			if(a[j] > a[j + 1]){
				hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}
		}
	}
}

// IMPRIME CONTEUDO DO ARRAY DE RESULTADOS (20 VALORES POR LINHA)
void print_array(const int a[]){
	int j; // CONTADOR

	// IMPRIME CONTEUDO DO ARRAY
	for(j = 0; j < SIZE; j++){
		// INICIA NOVA LINHA A CADA 20 VALORES
		if(j % 20 == 0){
			printf("\n");
		}

		printf("%2d", a[j]);
	}
}