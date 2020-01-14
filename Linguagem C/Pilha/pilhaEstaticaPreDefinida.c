/*
Autor: Fabricio Andrade
Data: 10/01/20
Algoritmo: Pilha Estática com tamanho definido pelo programador
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: inserir = push, remover = pop, pesquisar = search, exibir = display.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 3 //define a quantidade de elementos

typedef struct{
int topo;
int dados[TAM];
}tipoPilha;

void inicializar(tipoPilha *pilha){
    pilha->topo = -1;
}

int cheia(tipoPilha *pilha){
    if(pilha->topo == TAM-1){
        return 1;
    }else{
        return 0;
    }
}

int vazia(tipoPilha *pilha){
    if(pilha->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

void inserir(tipoPilha *pilha, int valor){

    if(cheia(pilha)==1){
        printf("\nPilha cheia!\n");
    }else{
        pilha->topo++;
        pilha->dados[pilha->topo] = valor;
        printf("\n%d Inserido com sucesso!\n",valor);
    }
}

void remover(tipoPilha *pilha){

    if(vazia(pilha)==1){
        printf("\nPilha vazia!\n");
    }else{
        printf("\n%d Removido com sucesso!\n",pilha->dados[pilha->topo]);
        pilha->topo--;
    }
}

void exibir(tipoPilha *pilha){

    int posicao=pilha->topo;
    printf("\n---Pilha atual---\n");
    if(vazia(pilha)==1){
        printf("Pilha vazia!\n");
    }else{
        while(posicao!=-1){
            printf("\t%d\n",pilha->dados[posicao]);
            posicao--;
        }
    }
}

void pesquisar(tipoPilha *pilha, int valor){

    int posicao=pilha->topo;
    int contador=0;

    if(vazia(pilha)==1){
        printf("Pilha vazia!\n");
    }else{
        while(posicao!=-1){

            if(valor == pilha->dados[posicao]){
                contador++;
            }
            posicao--;
        }

            printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);

    }
}

void exibirTopo(tipoPilha *pilha){

    if(vazia(pilha)==1){
        printf("\nPilha vazia!\n");
    }else{
        printf("\nO valor do topo eh %d\n",pilha->dados[pilha->topo]);
    }
}

int main()
{
    tipoPilha pilha;
    int opcao=-1;
    int valor=0;

    inicializar(&pilha);

    while (opcao!=0){
    valor=0;
    exibir(&pilha);

    printf("DIGITE 0 PARA SAIR\n");
    printf("1: Inserir\n");
    printf("2: Remover\n");
    printf("3: Visualizar topo\n");
    printf("4: Pesquisar\n");
    scanf("%d",&opcao);

    switch(opcao){
    case 1:
    printf("Digite um valor\n");
    scanf("%d",&valor);
    inserir(&pilha, valor);
    break;

    case 2:
    remover(&pilha);
    break;

    case 3:
    exibirTopo(&pilha);
    break;

    case 4:
        printf("Digite um valor\n");
        scanf("%d",&valor);
        pesquisar(&pilha,valor);
        break;

    case 0:
    printf("\nTchau! Ate a proxima\n");
    break;

    default:
    printf("Opcao invalida!\n");
    break;
    }
    }


    return 0;
}
