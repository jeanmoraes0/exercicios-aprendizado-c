#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card{
  const char *face;
  const char *suit;
};

typedef struct card Card;

void fillDeck(Card * const wDeck, const char * wFace[],
  const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(){
  system("clear");

  Card deck[52];

  const char *face[] = 
  {
    "Ás", "Dois", "Três", "Quatro", "Cinco", "Seis",
    "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"
  };

  const char *suit[] = 
  {
    "Copas", "Ouros", "Paus", "Espadas"
  };

  srand(time(NULL));

  fillDeck(deck, face, suit);
  shuffle(deck);
  deal(deck);

  return 0;

}

void fillDeck(Card * const wDeck, const char * wFace[],
  const char * wSuit[]){

  int i;

  for(i = 0; i <= 51; i++){
    wDeck[i].face = wFace[i % 13];
    wDeck[i].suit = wSuit[i / 13];
  }
}

void shuffle(Card * const wDeck){
  int i;
  int j;
  Card temp;

  for(i = 0; i <= 51; i++){
    j = rand() % 52;
    temp = wDeck[i];
    wDeck[i] = wDeck[j];
    wDeck[j] = temp;
  }
}

void deal(const Card * const wDeck){
  int i;

  for(i = 0; i <= 51; i++){
    printf("%5s de %-8s%s", wDeck[i].face,
      wDeck[i].suit, (i + 1) % 4 ? " " : "\n");
  }
}