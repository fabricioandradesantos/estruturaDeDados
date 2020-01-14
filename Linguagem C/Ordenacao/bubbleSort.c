/*
Autor: Fabricio Andrade
Data: 11/01/20
Algoritmo: Bubble Sort
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>

void bubbleSort(int *vetor, int tamanho) {
 int atual=0;
 int proximo=0;;
 int auxiliar=0;

 for (atual=1; atual < tamanho; atual++) {

 for (proximo=0; proximo < tamanho-1; proximo++) {

 if (vetor[proximo] > vetor[proximo+1]) {
 auxiliar = vetor[proximo];
 vetor[proximo] = vetor[proximo+1];
 vetor[proximo+1] = auxiliar;
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

bubbleSort(vetor, 10);

printf("\n\nVetor ordenado\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

 return 0;

}
