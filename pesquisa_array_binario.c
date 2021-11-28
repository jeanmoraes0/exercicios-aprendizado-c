#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

int binary_search(const int b[], int search_key, int low, int high);
void print_header(void);
void print_row(const int b[], int low, int mid, int high);

int main(){
	system("clear");

	int a[SIZE];
	int i;
	int key;
	int result;

	// CRIA DADOS
	for(i = 0; i < SIZE; i++)
		a[i] = 2 * i;

	printf("Digite um número entre 0 e 28: ");
	scanf("%d", &key);

	print_header();

	// PROCURA CHAVE NO ARRAY a
	result = binary_search(a, key, 0, SIZE - 1);

	// MOSTRA RESULTADOS
	if(result != -1)
		printf("\n%d encontrados no elemento de array %d\n", key, result);
	else
		printf("\n%d não encontramos\n", key);

	return 0;
}

// FUNÇÃO PARA REALAIZAR PESQUISA BINARIA DE UM ARRAY
int binary_search(const int b[], int search_key, int low, int high){
	int middle;	// VARIAVEL PARA MANTER ELEMENTO DO MEIO DO ARRAY

	// LOO ATÉ INDICE BAIXO SER MAIOR QUE O INDICE ALTO
	while(low <= high){
		// DETERMINA ELEMENTO DO MEIO DO SUBARRAY SENDO PESQUISADO
		middle = (low + high) / 2;

		// EXIBE SUBARRAY USADO NESSA ITERAÇÃO DE LOOP
		print_row(b, low, middle, high);

		// SE search_key COMBINOU COM ELEMENTO DO MEIO, RETORNA middle
		if(search_key == b[middle])
			return middle;

		// SE search_key MENOR QUE O ELEMENTO DO MEIO, DEFINE NOVO high
		else if(search_key < b[middle])
			high = middle - 1; // PROCURA EXTREMIDADE BAIXA DO ARRAY

		// SE search_key MAIOR QUE O ELEMENTO DO MEIO, DEFINE NOVO low
		else
			low = middle + 1; // PROCURA EXTREMIDADE ALTA DO ARRAY
	}

	return -1; // search_key NÃO ENCONTRADA
}

// IMPRIME CABEÇALHO PARA SAIDA
void print_header(void){
	int i;

	printf("\nIndice: \n");

	// CABEÇALHO DA COLUNA DE SAIDA
	for(i = 0; i < SIZE; i++)
		printf("%3d ", i);

	printf("\n");

	// LINHA DE SAIDA DE CARACTERES
	for(i = 1; i <= 4 * SIZE; i++)
		printf("-");

	printf("\n");
}

// IMPRIME UMA LINHA DE SAIDA MOSTRANDO A PARTE ATUAL DO ARRAY SENDO PROCESSADO
void print_row(const int b[], int low, int mid, int high){
	int i;

	// LOOP ARRAY INTEIRO
	for(i = 0; i < SIZE; i++){
		// MOSTRA ESPAÇOS SE FOR A DA FAIXA ATUAL DO SUBARRAY
		if(i < low || i > high)
			printf(" ");
		else if(i == mid) // MOSTRA ELEMENTO DO MEIO
			printf("%3d*", b[i]); // MARCA VALOR DO MEIO
		else
			printf("%3d ", b[i]);
	}

	printf("\n");
}

