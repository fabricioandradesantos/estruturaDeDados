/*
Autor: Fabricio Andrade
Data: 10/01/19
Algoritmo: Pilha Estática com tamanho definido pelo usuario
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: inserir = push, remover = pop, pesquisar = search, exibir = display.
Obs3: Após o uso da funçao free o ponteiro é setado com NULL para evitar o
"Ponteiros selvagens"
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacidade;
    int topo;
    int *pElem; //ponteiro dos elementos da pilha
}tipoPilha;

void criarPilha(tipoPilha *pilha, int capacidade)
{
    pilha->pElem = NULL;
    pilha->pElem = (int *) malloc(capacidade*sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;

    if(pilha->pElem != NULL)
    {
        printf("Pilha criada com sucesso!\n");
    }
    else
    {
        printf("Erro ao criar Pilha!\n");
    }
}


void apagarPilha(tipoPilha *pilha)
{

    if(pilha->pElem != NULL)
    {
        free(pilha->pElem);
        pilha->pElem = NULL;
        printf("Pilha Apagada!\n");

    }
    else
    {
        printf("Nao existe pilha para apagar!\n");
    }

}

int vazia(tipoPilha *pilha)
{

    if(pilha->topo <= -1 || pilha->pElem == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cheia(tipoPilha *pilha)
{
    if(pilha->pElem != NULL)
    {
        if(pilha->topo >= pilha->capacidade-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

void inserir(tipoPilha *pilha, int valor)
{

    if(cheia(pilha)==0)
    {
        pilha->topo++;
        pilha->pElem[pilha->topo] = valor;
        printf("Empilhou! o %d\n",valor);
    }
    else
    {
        printf("Pilha cheia\n");
    }

}

void remover(tipoPilha *pilha)
{

    if(vazia(pilha)==0)
    {
        printf("Desempilhou o %d\n",pilha->pElem[pilha->topo]);
        pilha->topo--;
    }
    else
    {
        printf("Pilha vazia!\n");
    }
}

void exibirTopo(tipoPilha *pilha)
{

    if(vazia(pilha)==1)
    {
        printf("\nPilha vazia!\n");
    }
    else
    {
        printf("\nO valor do topo eh %d\n",pilha->pElem[pilha->topo]);
    }
}

void pesquisar(tipoPilha *pilha, int valor)
{

    int posicao=pilha->topo;
    int contador=0;

    if(vazia(pilha)==1)
    {
        printf("Pilha vazia!\n");
    }
    else
    {
        while(posicao!=-1)
        {

            if(valor == pilha->pElem[posicao])
            {
                contador++;
            }
            posicao--;
        }

        printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);

    }
}

void exibir(tipoPilha *pilha)
{

    int posicao=pilha->topo;
    printf("\n---Pilha atual---\n");
    if(vazia(pilha)==1)
    {
        printf("Pilha vazia!\n");
    }
    else
    {
        while(posicao!=-1)
        {
            printf("\t%d\n",pilha->pElem[posicao]);
            posicao--;
        }
    }
}

int main()
{
    int opcao=-1;
    int valor=0;
    tipoPilha pilha;
    pilha.pElem = NULL;
    pilha.capacidade =-1;

    while (opcao!=0)
    {
        exibir(&pilha);
        valor=0;
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Criar pilha\n");
        printf("2: Apagar pilha\n");
        printf("3: Inserir\n");
        printf("4: Remover\n");
        printf("5: Exibir topo\n");
        printf("6: Pesquisar\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite o tamanho da pilha que deseja\n");
            scanf("%d",&valor);
            criarPilha(&pilha,valor);
            break;

        case 2:
            apagarPilha(&pilha);
            pilha.pElem = NULL;
            pilha.capacidade =-1;
            break;

        case 3:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            inserir(&pilha,valor);
            break;

        case 4:
            remover(&pilha);
            break;

        case 5:
            exibirTopo(&pilha);
            break;

        case 6:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pesquisar(&pilha,valor);
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
