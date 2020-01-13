/*
Autor: Fabricio Andrade
Data: 12/01/19
Algoritmo: Merge Sort
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>


void merge(int *vetor, int tamanho) {
 int meio = tamanho / 2;
 int i = 0, j = meio, k = 0;
 int auxiliar[tamanho];
 while( i < meio && j < tamanho ){
 if( vetor[i] <= vetor[j] )
 auxiliar[k] = vetor[i++];
 else
 auxiliar[k] = vetor[j++];
 k++;
 }
 if( i == meio )
 while( j < tamanho )
 auxiliar[k++] = vetor[j++];
 else
 while( i < meio )
 auxiliar[k++] = vetor[i++];
 for( i = 0; i < tamanho; i++ )
 vetor[i] = auxiliar[i];
}

void mergeSort(int *vetor, int tamanho){
int meio = tamanho / 2;
if( tamanho > 1 ){
mergeSort(vetor, meio);
mergeSort(vetor+meio, tamanho-meio);
merge(vetor, tamanho);
}

}

int main ()
{

 int vetor[10]={1,3,2,8,3,4,6,5,9,10};
 
 int i=0;

printf("\nvetor antes da ordenacao\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

mergeSort(vetor, 10);

printf("\n\nvetor ordenado\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }
getchar();
 return 0;

}