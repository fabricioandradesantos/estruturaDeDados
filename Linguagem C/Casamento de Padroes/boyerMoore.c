/*
Autor: Fabricio Andrade
Data: 13/01/19
Algoritmo: Boyer Moore
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanhoAlfabeto 256

int maior (int a, int b) { 
    //utilizando o operador ternario
    return (a > b)? a: b; 
}

void preProcessamento( char *palavra, int tamanhoPalavra, int alfabeto[tamanhoAlfabeto])
{
    int i=0;

    // inicia todos do alfabeto com -1
    for (i = 0; i < tamanhoAlfabeto; i++){
         alfabeto[i] = -1;
     }

    //seta os valores das letras da palavra de acordo com a tabela ASCII
    for (i = 0; i < tamanhoPalavra; i++){
         alfabeto[palavra[i]] = i;
         //printf("posicao = %d  ASCII = %d\n", alfabeto[palavra[i]], palavra[i]);
     }
}

void boyerMoore( char *texto,  char *palavra)
{
    int contador=0;
    int tamanhoPalavra = strlen(palavra);
    int tamanhoTexto = strlen(texto);

    int alfabeto[tamanhoAlfabeto];

    preProcessamento(palavra, tamanhoPalavra, alfabeto);

    int i = 0; 
    while(i <= (tamanhoTexto - tamanhoPalavra))
    {
        int j = tamanhoPalavra-1;

        while(j >= 0 && palavra[j] == texto[i+j]){
            j--;
        }

        if (j < 0)
        {

            contador++;

            if(i+tamanhoPalavra < tamanhoTexto){
                i += tamanhoPalavra-alfabeto[texto[i+tamanhoPalavra]];   
            }else{
                i += 1;
            }
        }

        else{

            i += maior(1, j - alfabeto[texto[i+j]]);
        }
    }

    printf("\nHouve %d ocorrencia(s) do padrao %s\n",contador, palavra);
}

int main()
{
    char texto[] = "ABCABAAABABCABCJJJABC";
    char palavra[] = "ABC";
    boyerMoore(texto, palavra);
    return 0;
}
