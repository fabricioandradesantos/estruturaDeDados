/*
Autor: Fabricio Andrade
Data: 13/01/19
Algoritmo: Knuth Morris Pratt
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void knuthMorrisPratt(char *texto, char *palavra, int tamanhoTexto, int tamanhoPalavra)
{

	int contador=0;

	//armazena o índice da próxima melhor correspondência 
	int proximos[tamanhoPalavra+1];

	for (int i = 0; i < tamanhoPalavra + 1; i++){
		proximos[i] = 0;
	}

	for (int i = 1; i < tamanhoPalavra; i++)
	{
		int j = proximos[i+1];

		while (j > 0 && palavra[j] != palavra[i]){
			j = proximos[j];
		}

		if (j > 0 || palavra[j] == palavra[i]){
			proximos[i+1] = j + 1;
		}
	}

	for (int i = 0, j = 0; i < tamanhoTexto; i++)
	{
		if (*(texto + i) == *(palavra + j))
		{
			if (++j == tamanhoPalavra){
				contador++;
			}
		}
		else if (j > 0) {
			j = proximos[j];
			i--;	
		}
	}
	printf("\nHouve %d ocorrencia(s) do padrao %s\n",contador, palavra);
}

// Program to implement knuthMorrisPratt Algorithm in C
int main()
{
	char texto[] = "ABCABAABCABAC";
	char palavra[] = "ABA";

	int tamanhoTexto = strlen(texto);
	int tamanhoPalavra = strlen(palavra);

	knuthMorrisPratt(texto, palavra, tamanhoTexto, tamanhoPalavra);
	return 0;
}