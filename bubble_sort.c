/*Esse programa coloca valores em um array, ordena os valores em
ordem crescente e imprime o array resultante.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void bubbleSort(int * const array, const int size);

int main(){
    system("clear");

    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    int i;

    printf("Itens de dados na ordem original\n");

    for(i = 0; i < SIZE; i++)
        printf("%4d", a[i]);

    bubbleSort(a, SIZE);

    printf("\nItens de dados em ordem crescente\n");

    for(i = 0; i < SIZE; i++)
        printf("%4d", a[i]);

    printf("\n");

    return 0;
}

void bubbleSort(int * const array, const int size){

    void swap(int *p_element1, int *p_element2);
    int pass;
    int j;

    for(pass = 0; pass < size - 1; pass++){
        for(j = 0; j < size - 1; j++){
            if(array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void swap(int *p_element1, int *p_element2){

    int hold = *p_element1;
    *p_element1 = *p_element2;
    *p_element2 = hold;
}