/*
Autor: Fabricio Andrade
Data: 12/01/20
Algoritmo: Selection Sort
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>

void insertionSort(int vetor[], int tamanho) {
 
 int atual=0;
 int proximo = 0; 
 int auxiliar;
 
 for (atual = 1; atual < tamanho; atual++) {
 proximo = atual;
 while (proximo > 0 && vetor[proximo-1] > vetor[proximo]) {

 if (vetor[proximo-1] > vetor[proximo])
 {
 auxiliar = vetor[proximo];
 vetor[proximo] = vetor[proximo-1];
 vetor[proximo-1] = auxiliar;
 proximo--;
}

}

}

}


int main ()
{

 int vetor[10]={1,3,2,8,3,4,6,5,9,10};
 
 int i=0;

printf("\nVetor antes da ordenacao\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

insertionSort(vetor, 10);

printf("\n\nVetor ordenado\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

 return 0;

}
