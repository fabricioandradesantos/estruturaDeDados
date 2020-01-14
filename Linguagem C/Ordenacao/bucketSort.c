/*
Autor: Fabricio Andrade
Data: 12/01/20
Algoritmo: Bucket Sort
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>

int pegarmaximoimo(int *vetor, int tamanho)
{
  int maximo = vetor[0];
  for (int i = 1; i < tamanho; i++)
    if (vetor[i] > maximo)
      maximo = vetor[i];
  return maximo;
}

void bucketSort(int *vetor, int tamanho)
{

  /*
  Como não estamos trabalhando com alocacao dinamica
  de memoria, utilizamos o tamanho+1 para definir o
  número maximo de baldes  
  */
  int balde[tamanho+1];

  const int maximo = pegarmaximoimo(vetor, tamanho);
  for (int i = 0; i <= maximo; i++)
  {
    balde[i] = 0;
  }
  for (int i = 0; i < tamanho; i++)
  {
    balde[vetor[i]]++;
  }
  for (int i = 0, j = 0; i <= maximo; i++)
  {
    while (balde[i] > 0)
    {
      vetor[j++] = i;
      balde[i]--;
    }
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

bucketSort(vetor, 10);

printf("\n\nvetor ordenado\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

getchar();

 return 0;

}
