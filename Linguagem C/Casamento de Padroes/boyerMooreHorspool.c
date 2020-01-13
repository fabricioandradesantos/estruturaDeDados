/*
Autor: Fabricio Andrade
Data: 13/01/19
Algoritmo: Boyer Moore Horspool
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define tamanhoAlfabeto 256

void preProcessamento(char *palavra, int tamanhoPalavra, int alfabeto[]) {
   
   int i=0;
   
   /*
   setando todos elementos do alfabeto com 
   o tamanho da palavra
   */
   for (i = 0; i < tamanhoAlfabeto; ++i){ 
  	alfabeto[i] = tamanhoPalavra;
	}


   /*
   setando posicoes das letras da palavra(menos a ultima)
   no alfabeto com seu respectivo valor da
   tabela ASCII
   */
   for (i = 0; i < tamanhoPalavra-1; ++i){
    alfabeto[palavra[i]] = tamanhoPalavra-i-1;
    //printf("ASCII = %d -  pos = %d\n",palavra[i], tamanhoPalavra-i-1 );
	}
 
 }

 void boyerMooreHorspool(char *palavra, int tamanhoPalavra, char *texto, int tamanhoTexto) {
    
    int i=0;
    int alfabeto[tamanhoAlfabeto];
    char caracterAuxiliar;
    int contador=0;
    
    preProcessamento(palavra, tamanhoPalavra, alfabeto);
 
    while (i <= tamanhoTexto - tamanhoPalavra) {
       caracterAuxiliar = texto[i + tamanhoPalavra - 1];
       
       if (palavra[tamanhoPalavra - 1] == caracterAuxiliar)
       {
       	
       	if (memcmp(palavra, texto+i, tamanhoPalavra-1) == 0)//Saber se uma string é igual a outra
       	{
       		contador++;
       	}

       }

      i += alfabeto[caracterAuxiliar];
   }
   printf("\nHouve %d ocorrencia(s) do padrao %s\n",contador, palavra);
}

int main()
{
    char texto[] = "ABCABAAABABCABCJJJABC";
    char palavra[] = "ABC";
    boyerMooreHorspool(palavra, strlen(palavra), texto, strlen(texto) );
    getchar();
    return 0;
}