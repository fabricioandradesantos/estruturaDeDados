/*
Autor: Fabricio Andrade
Data: 11/01/19
Algoritmo: Busca Sequencial 
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>

int buscaSequencial(int *vetor,int valor, int tamanho)
{

 int indice = 0;
 int contador = 0;
 for(indice=0; indice < tamanho;indice++)
 {
  if(vetor[indice]==valor){
   contador++;
   }
 }
 return contador;

}


int main ()
{

 int vetor[10]={1,3,2,8,3,4,6,5,9,10};
 int resultado=0;
 int valor = 0;

 printf("Informe o valor a ser encontrado:\n");
 scanf("%d",&valor);
 resultado = buscaSequencial(vetor, valor, 10);
 if(resultado == 0){
 	printf("\nValor nao encontrado!\n");
 }else{
 	printf("\nValor encontrado!\n");
 }

 return 0;

}
