#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void displayBits(unsigned value);

int main(){
  system("clear");

  unsigned x;

  printf("Digite um inteiro sem sinal: ");
  scanf("%u", &x);

  displayBits(x);

  return 0;
}

void displayBits(unsigned value){

  unsigned c;

  unsigned displayMask = 1 << CHAR_BIT * sizeof(unsigned) - 1;

  printf("%10u = ", value);

  for(c = 1; c <= CHAR_BIT * sizeof(unsigned); c++){
    putchar(value & displayMask ? '1' : '0');
    value <<= 1;

    if(c % 8 == 0)
      putchar(' ');
  }

  putchar('\n');
}