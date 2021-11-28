#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MEMORIA 100

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
#define MOD 34
#define EXPO 35

void intro();
void add_memoria(int memoria[]);
void registrador(int * const operation_code, int * const operand, const int Register);
void dump(const int memoria[], const int * const acumulador,
  const int  * const instruction_counter, const int * const Register, 
  const int * const operation_code, const int * const operand);

int main(){
  system("clear");

  int memoria[MEMORIA] = {0};

  int acumulador = 0;
  int instruction_counter = 0;
  int operation_code = 0;
  int operand = 0;
  int Register = 0;

  intro();

  add_memoria(memoria);

  while(operation_code != HALT){

    Register = memoria[instruction_counter];

    registrador(&operation_code, &operand, Register);

    switch(operation_code){
      case READ:
        printf("Entrar com número: ");
        scanf("%d", &memoria[operand]);
        instruction_counter++;
        break;
      case WRITE:
        printf("Número %d\n", memoria[operand]);
        instruction_counter++;
        break;
      case LOAD:
        acumulador = memoria[operand];
        instruction_counter++;
        break;
      case STORE:
        memoria[operand] = acumulador;
        instruction_counter++;
        break;
      case ADD:
        acumulador += memoria[operand];
        instruction_counter++;
        break;
      case SUBTRACT:
        acumulador -= memoria[operand];
        instruction_counter++;
        break;
      case DIVIDE:
        if(acumulador == 0)
          return 1;
        else{
          acumulador -= memoria[operand];
          instruction_counter++;
        }
          break;
      case MULTIPLY:
        acumulador *= memoria[operand];
        instruction_counter++;
        break;
      case BRANCH:
      	instruction_counter = operand;
        break;
      case BRANCHNEG:
      	if(acumulador < 0)
      		instruction_counter = operand;
      	else
      		instruction_counter++;
        break;
      case BRANCHZERO:
      	if(acumulador == 0)
      		instruction_counter = operand;
      	else
      		instruction_counter++;
        break;
      case MOD:
      	acumulador %= memoria[operand];
      	instruction_counter++;
      	break;
      case EXPO:
      	acumulador = pow(acumulador, memoria[operand]);
      	instruction_counter++;;
    }

  }
  printf("|\n");
  printf("|\n");
  printf("| **Execução do Simpretron encerrada**\n");
  printf("|\n");
  printf("|\n");

  dump(memoria, &acumulador, &instruction_counter, &Register, &operation_code, &operand);

  return 0;
}

void intro(){

  printf("\t\t   #############################\n");
  printf("\t\t   # *Bem vindo ao Simpretron* #\n");
  printf("\t\t   #############################\n\n");

  printf("-------------------------------------  -------------------------------\n");
  printf("|Primeiros dois dígitos:            |  |Dois últimos dígitos:        |\n");
  printf("|Código de operação a ser realizada.|  |Endereço do local de memória.|\n");
  printf("-------------------------------------  -------------------------------\n\n");

  printf("--------------------------------------------------------------\n");
  printf("|Lista de instruções:                                        |\n");
  printf("| *READ +10\t*WRITE +11\t*LOAD +20\t*STORE +21   |\n");
  printf("| *ADD +30\t*SUBTRACT +31\t*DIVIDE +32\t*MULTIPLY +33|\n");
  printf("| *BRANCH +40\t*BRANCHNEG +41\t*BRANCHZERO +42\t*HALT +43    |\n");
  printf("--------------------------------------------------------------\n");

}

void add_memoria(int memoria[]){

  int codigo;

  for(int i = 0; i < MEMORIA; i++){
    do{
      printf("| %02d > ", i);
      scanf("%d", &codigo);

    }while((codigo < -9999) || (codigo > 9999) & codigo != -1);

    if(codigo != -1)
      memoria[i] = codigo;
    else
      break;
  }
}

void registrador(int * const operation_code, int * const operand, const int Register){

  (*operation_code) = Register / 100;
  (*operand) = Register % 100;

}

void dump(const int memoria[], const int * const acumulador,
  const int  * const instruction_counter, const int * const Register, 
  const int * const operation_code, const int * const operand){

  printf("|Registers:\n");
  printf("|acumulador            %04d\n", (*acumulador));
  printf("|instruction_counter     %02d\n", (*instruction_counter));
  printf("|Register             +%04d\n", (*Register));
  printf("|operation_code          %02d\n", (*operation_code));
  printf("|operand                 %02d\n", (*operand));

  printf("|\n|\n|MEMORY:\n");

  printf("|   ");

  for(int i = 0; i < 10; i++)
    printf("%4d ", i);

  printf("\n");

  for(int i = 0; i < MEMORIA; i++){
    if(i % 10 == 0)
      printf("|%2d %04d ", i, memoria[i]);
    else if((i + 1) % 10 == 0)
      printf("%04d\n", memoria[i]);
    else
      printf("%04d ", memoria[i]);
  }
}