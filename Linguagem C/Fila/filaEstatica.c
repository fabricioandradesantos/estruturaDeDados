/*
Autor: Fabricio Andrade
Data: 10/01/19
Algoritmo: Fila Estática 
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: Uma vez que a fila estiver cheia, não será possivel inserir novos itens 
mesmo que os anteriores tenham sido apagados e não compensa "puxar" os itens 
para o começo do vetor por conta do custo computacional. Soluções para este problema:
fila estática circular ou fila dinamica 
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 3 //define o tamanho da fila

typedef struct {

int primeiro;
int ultimo;
int itens[TAM];

}Fila;

void iniciar(Fila *fila){

fila->primeiro = 0;
fila->ultimo = -1;

}

int cheia(Fila *fila){

    if( fila->ultimo == TAM-1){
        return 1;
    }else {
        return 0;
    }
}

int vazia(Fila *fila){

    if(fila->primeiro > fila->ultimo){
        return 1;
    }else {
        return 0;
    }
}

void enfileirar(Fila *fila, int valor){

    if(cheia(fila)==1){
        printf("\nFila cheia!\n");
    }else{
        fila->ultimo++;
        fila->itens[fila->ultimo] = valor;
    }
}

void desenfileirar(Fila *fila){

    int auxiliar=0;

    if(vazia(fila)==1){
        printf("\nFila vazia!\n");
    }else {
        auxiliar = fila->itens[fila->primeiro];
        fila->primeiro++;
    }
}

void mostrarPrimeiro(Fila *fila){

if(vazia(fila)==1){
    printf("\nFila vazia!\n");
}else{
    printf("\nO primeiro da fila eh o [%d]\n",fila->itens[fila->primeiro]);
}

}

void tamanho(Fila *fila){

    if(vazia(fila)==1){
         printf("\nFila vazia\n");
    }else {
        printf("\nO tamanho da fila eh %d\n",(fila->ultimo - fila->primeiro) + 1);
    }

}


void exibir(Fila *fila){

int i = fila->primeiro;
printf("\n---Fila atual---\n");
while (i <= fila->ultimo){
   
    printf("[%d] ",fila->itens[i]);
    i++;
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
            printf("3: Mostrar primeiro\n");
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
                desenfileirar(&fila);
                break;

            case 3:
                mostrarPrimeiro(&fila);
                break;

            case 4:
                tamanho(&fila);
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
