/*
Autor: Fabricio Andrade
Data: 12/01/20
Algoritmo: Selection Sort
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>

void selectionSort(int *vetor, int tamanho){
 
int atual = 0;
int proximo = 0;
int auxiliar = 0;
 
          for( atual=0; atual<tamanho; atual++ ){
                  for( proximo=atual+1; proximo<tamanho; proximo++ ){
                       if( vetor[atual] > vetor[proximo] ){
                           auxiliar = vetor[atual];
                           vetor[atual] = vetor[proximo];
                           vetor[proximo] = auxiliar;
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

 selectionSort(vetor, 10);

printf("\n\nVetor ordenado\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

 return 0;

}
