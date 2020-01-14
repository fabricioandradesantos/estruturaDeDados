/*
Autor: Fabricio Andrade
Data: 12/01/20
Algoritmo: Shell Sort
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>

void shellSort(int *vetor, int tamanho) {

int atual=0;
int proximo=0; 
int valor=0;
int salto = 1;

 while(salto < tamanho) {
 salto = 3*salto+1;
 }
 while (salto > 0) {
 for(atual = salto; atual < tamanho; atual++) {
 valor = vetor[atual];
 proximo = atual;
 while (proximo > salto-1 && valor <= vetor[proximo-salto]) {
 vetor[proximo] = vetor[proximo-salto];
 proximo = proximo - salto;
 }
 vetor[proximo] = valor;
 }
 salto = salto/3;
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

shellSort(vetor, 10);

printf("\n\nvetor ordenado\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

 return 0;

}
