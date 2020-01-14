/*
Autor: Fabricio Andrade
Data: 11/01/20
Algoritmo: Busca Binaria 
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include<stdio.h>
#include <stdlib.h>

int buscaBinaria(int *vetor, int valor, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] < valor) {
            return buscaBinaria(vetor, valor, meio + 1, fim);
        } else {
            return buscaBinaria(vetor, valor, inicio, meio - 1);
        }
    }else {
    	return -1;
    }
}


int main ()
{

 int vetor[10]={1,3,2,8,3,4,6,5,9,10};
 int resultado = 0;
 int valor = 0;

 printf("Informe o valor a ser encontrado:\n");
 scanf("%d",&valor);
 resultado = buscaBinaria(vetor, valor, 0, 10);
 if(resultado == -1){
 	printf("\nValor nao encontrado!\n");
 }else{
 	printf("\nValor encontrado!\n");
 }
 return 0;

}
