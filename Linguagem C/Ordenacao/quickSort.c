/*
Autor: Fabricio Andrade
Data: 12/01/20
Algoritmo: Quick Sort
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>

// função que realiza a troca entre dois elementos
void troca(int *vetor, int valor1, int valor2)
{

int auxiliar = vetor[valor1];
vetor[valor1] = vetor[valor2];
vetor[valor2] = auxiliar;

}

// particionar e retorna o índice do pivô
int particionar(int *vetor, int inicio, int fim)
{
int pivo=0;
int pivoIndice=0;
int i=0;

pivo = vetor[fim]; 
pivoIndice = inicio;
for(i = inicio; i < fim; i++)
{

if(vetor[i] <= pivo)
{

troca(vetor, i, pivoIndice);
pivoIndice++;

}
}

// troca o pivô
troca(vetor, pivoIndice, fim);
// retorna o índice do pivô
return pivoIndice;
}
// escolhe um pivô aleatório para evitar o pior caso do Quick Sort
int particionamentoAleatorio(int *vetor, int inicio, int fim)
{
// seleciona um número entre fim (inclusive) e inicio (inclusive)
int pivoIndice = (rand() % (fim - inicio + 1)) + inicio;
// faz a troca para colocar o pivô no fim
troca(vetor, pivoIndice, fim);

return particionar(vetor, inicio, fim);
}

void quickSort(int *vetor, int inicio, int fim)
{
if(inicio < fim)
{
// função particionarr retorna o índice do pivô
int pivoIndice = particionamentoAleatorio(vetor, inicio, fim);
// chamadas recursivas quickSort
quickSort(vetor, inicio, pivoIndice - 1);
quickSort(vetor, pivoIndice + 1, fim);
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

quickSort(vetor, 0, 9);

printf("\n\nvetor ordenado\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }
getchar();
 return 0;

}
