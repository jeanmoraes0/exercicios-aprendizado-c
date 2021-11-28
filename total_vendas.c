#include <stdio.h>
#include <stdlib.h>

#define QUANTVENDEDORES 4
#define QUANTPRODUTOS 5

int registrar_venda(int vendedor, int produto, int valor_dia, 
	const int vendedores[], const int produtos[], int sales[][QUANTVENDEDORES]);
int soma_produtos(const int sales[][QUANTVENDEDORES], int num);
int tabela_vendedores(const int vendedores[]);
int soma_vendedor(const int sales[][QUANTVENDEDORES], int num);

int main(){
	system("clear");
	int vendedores[QUANTVENDEDORES] = {1, 2, 3, 4};
	int produtos[QUANTPRODUTOS] = {1, 2, 3, 4, 5};
	int sales[QUANTPRODUTOS][QUANTVENDEDORES] = {0};

	int vendedor;
	int produto;
	int valor_dia;
	int flag = 1;
	int parar;

	while(flag == 1){
		system("clear");

		printf("Número do vendedor: ");
		scanf("%d", &vendedor);

		printf("Número do produto: ");
		scanf("%d", &produto);

		printf("Valor do produto: ");
		scanf("%d", &valor_dia);

		registrar_venda(vendedor, produto, valor_dia, vendedores, produtos, sales);
		
		printf("Deseja parar? 1 - SIM ");
		scanf("%d", &parar);

		if(parar == 1)
			flag = 0;

	}

	system("clear");

	tabela_vendedores(vendedores);

	// linha de produtos e soma total por produto
	for(int i = 0; i < QUANTPRODUTOS; i++){
		printf("Produto %d:\t", i + 1);
		for(int j = 0; j < QUANTVENDEDORES; j++){
			printf("%d\t\t", sales[i][j]);
		}
		printf("Total: %d\n", soma_produtos(sales, produtos[i]));
		printf("\n");
	}
	// fim da linha de produtos

	// linha de soma total de vendas por vendedor
	for(int i = 0; i <= 0; i++){
		printf("$Vendedor:\t");
		for(int j = 0; j < QUANTVENDEDORES; j++){
			printf("%d\t\t", soma_vendedor(sales, vendedores[j]));
		}

		printf("\n");
	}
	// fim da linha de vendedores


	return 0;
}

int registrar_venda(int vendedor, int produto, int valor_dia, 
	const int vendedores[], const int produtos[], int sales[][QUANTVENDEDORES]){
	int i;
	int j;

	for(i = 0; i < QUANTPRODUTOS; i++){
		if(produto != produtos[i])
			continue;
		for(j = 0; j < QUANTVENDEDORES; j++){
			if(vendedor == vendedores[j]){
				sales[i][j] += valor_dia;
			}
		}
	}
}

int soma_produtos(const int sales[][QUANTVENDEDORES], int num){
	int soma = 0;

	for(int i = num - 1; i <= num - 1; i++){
		for(int j = 0; j < QUANTVENDEDORES; j++){
			soma += sales[i][j];
		}

	}

	return soma;
}

int tabela_vendedores(const int vendedores[]){
	for(int i = 0; i < QUANTVENDEDORES; i++){
		printf("\t%s %d", "   Vendedor", i + 1);
	}

	printf("\n");
}

int soma_vendedor(const int sales[][QUANTVENDEDORES], int num){
	int soma = 0;

	for(int i = 0; i < QUANTPRODUTOS; i++){
		for(int j = num - 1; j <= num - 1; j++){
			soma += sales[i][j];
		}
	}

	return soma;
}