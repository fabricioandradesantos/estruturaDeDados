/*
Autor: Fabricio Andrade
Data: 10/01/20
Algoritmo: Fila Estática Circular
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: Lembre-se que uma posição do vetor deve ser sacrificada
Ex: TAM 5 == capacidade maxima de 4 itens
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 5 //define o tamanho da fila

typedef struct {

int primeiro;
int ultimo;
int itens[TAM];

}Fila;

void iniciar(Fila *fila){

fila->primeiro = TAM-1;
fila->ultimo = TAM-1 ;

}

int cheia(Fila *fila){

    if( fila->ultimo == TAM-1 ){
        if(fila->primeiro == 0){
            return 1;
        }else{
            return 0;
            }

    }else {
        if (fila->primeiro == ((fila->ultimo)+1)){
            return 1;
        }else{
            return 0;
        }

    }
}

int vazia(Fila *fila){

    if(fila->ultimo == fila->primeiro){
        return 1;
    }else {
        return 0;
    }
}

void enfileirar(Fila *fila, int valor){

    if(cheia(fila)==1){
        printf("\nFila cheia!\n");
    }else{
        fila->ultimo = (fila->ultimo+1)%TAM;
        fila->itens[fila->ultimo] = valor;
    }
}

int desenfileirar(Fila *fila){

    if(vazia(fila)==1){
        //printf("\nFila vazia!\n");
        return NULL;
    }else {
        if(fila->primeiro == TAM-1){
        fila->primeiro = 0;
        }else{
            (fila->primeiro)++;
        }
        return (fila->itens[fila->primeiro]);
    }
}

int primeiroItem(Fila *fila){
    return fila->primeiro;
}

void pesquisar(Fila *fila, int valor){
if (vazia(fila)==1){
    printf("\nFila vazia!\n");
}else{

    int guardaPrimeiro = primeiroItem(fila);
    int auxiliar = desenfileirar(fila);
    int contador=0;
    while(auxiliar!=0){

        if(valor == auxiliar){
            contador++;
        }
        auxiliar = desenfileirar(fila);
    }
    fila->primeiro = guardaPrimeiro;

    printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);

}

}


int tamanho(Fila *fila){

    if(fila->primeiro <= fila->ultimo){
         return (fila->ultimo - fila->primeiro);
    }else {
        return (TAM - (fila->primeiro - fila->ultimo));
    }

}


void exibir(Fila *fila){
if (vazia(fila)==1){
    printf("\nFila vazia!\n");
}else{

    int guardaPrimeiro = primeiroItem(fila);
    int auxiliar = desenfileirar(fila);

    while(auxiliar!=0){

        printf("[%d] ",auxiliar);
        auxiliar = desenfileirar(fila);
    }
    fila->primeiro = guardaPrimeiro;
}

}

int main()
{
    int opcao=-1;
    int valor=0;
    Fila fila;

    iniciar(&fila);

        while(opcao!=0)
        {
        	exibir(&fila);

            valor=0;

            printf("\n\nDIGITE 0 PARA SAIR\n");
            printf("Escolha uma opcao\n");
            printf("1: Enfileirar\n");
            printf("2: Desenfileirar\n");
            printf("3: Pesquisar\n");
            printf("4: Tamanho\n");

            scanf("%d",&opcao);

            switch(opcao)
            {

            case 1:
                printf("Digite um valor para enfileirar\n");
                scanf("%d",&valor);

                enfileirar(&fila, valor);

                break;

            case 2:
                valor = desenfileirar(&fila);
                if(valor!=(int)NULL){
                   printf("\nRemoveu o %d\n",valor);
                }

                break;

            case 3:
                printf("Digite um valor\n");
                scanf("%d",&valor);

                pesquisar(&fila, valor);
                break;

            case 4:
                printf("\nTamanho da fila eh %d\n", tamanho(&fila));
                break;

            case 0:
                printf("Tchau! Ate a proxima\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;

            }


        }

    return 0;
}
