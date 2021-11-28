#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//protótipos
void embaralha(int wbaralho[][13]);
void distribui(const int wbaralho[][13], const char *wCartas[],
	const char *wNaipe[]);

int main(void){
	system("clear");

	//inicializa array naipe
	const char *naipe[4] = {"Copas", "Ouros", "Paus", "Espadas"};

	//inicializa array naipe
	const char *cartas[13] = {
		"Ás", "Dois", "Três", "Quatro",
		"Cinco", "Seis", "Sete", "Oito",
		"Nove", "Dez", "Valete", "Dama", "Rei"
	};

	//inicializa array baralho
	int baralho[4][13] = {0};

	srand(time(NULL)); //semente do gerador de número aleatório

	embaralha(baralho); //embaralha
	distribui(baralho, cartas, naipe); //distribui as cartas do baralho

	return 0;
}

//embaralha cartas
void embaralha(int wbaralho[][13]){
	int linha; //número de linha
	int coluna; //número de coluna
	int carta; //contador

	//para cada uma das 52 cartas, escolhe slot de baralho aleatoriamente
	for(carta = 1; carta <= 52; carta++){
		//escolhe novo local aleatório até que slot não ocupado seja encontrado
		do{
			linha = rand() % 4;
			coluna = rand() % 13;
		} while(wbaralho[linha][coluna] != 0);

		//coloca número da carta no slot escolhido do baralho
		wbaralho[linha][coluna] = carta;
	}
}

//distribui cartas no baralho
void distribui(const int wbaralho[][13], const char *wCartas[],
	const char *wNaipe[]){

	int carta; //contador de cartas
	int linha; //contador de linhas
	int coluna; //contador de coluna

	//distribui cada uma das 52 cartas
	for(carta = 1; carta <= 52; carta++){
		//loop pelas linhas de wbaralho
		for(linha = 0; linha <= 3; linha++){
			//loop pelas colunas de wbaralho para linha atual
			for(coluna = 0; coluna <= 12; coluna++){
				//se slot contém cartão atual, mostra carta
				if(wbaralho[linha][coluna] == carta){
					printf("%5s de %-8s%c", wCartas[coluna], wNaipe[linha],
						carta % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}
