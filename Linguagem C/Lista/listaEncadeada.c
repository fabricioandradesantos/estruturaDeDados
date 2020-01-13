/*
Autor: Fabricio Andrade
Data: 11/01/19
Algoritmo: Lista simplesmente encadeada/ligada
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: Note que o tipoLista é definido como um ponteiro na definição da struct
Obs3: Após o uso da funçao free o ponteiro é setado com NULL para evitar "Ponteiros selvagens"
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
    int item;
    struct ITEM *proximo;
}*tipoLista;


tipoLista criarItem(int valor){

    tipoLista novoItem = (tipoLista) malloc(sizeof(tipoLista));

    if(novoItem == NULL){
        printf("\nErro ao criar item!\n");
        return NULL;
    }else{
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

tipoLista inserirEsquerda(int valor, tipoLista lista){
       
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }else{
    
        novoItem->proximo = lista;
    
        return novoItem;
    }
    
}

tipoLista inserirDireita(int valor, tipoLista lista){
       
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }else{
    
    tipoLista listaAuxiliar = lista;

    while(listaAuxiliar->proximo != NULL){
        listaAuxiliar = listaAuxiliar->proximo;
    }

    listaAuxiliar->proximo = novoItem;
    
        return lista;
    }

    
}

tipoLista removerEsquerda(tipoLista lista){
    
    if(lista==NULL){
        printf("\nVazia!\n");
    }else{

    tipoLista listaAuxiliar;
    listaAuxiliar = lista;
    lista = lista->proximo;

    free(listaAuxiliar);
	listaAuxiliar = NULL;
    }
    return lista;
}

tipoLista removerDireita(tipoLista lista){
    
    if(lista==NULL){
        printf("\nVazia!\n");
    }else{

    if(lista->proximo == NULL){ //apenas um elemento
        free(lista);
        lista = NULL;
    }else{
        tipoLista listaAuxiliar;
        listaAuxiliar = lista;

    while(listaAuxiliar->proximo->proximo != NULL){ //encontra o penultimo elemento
        listaAuxiliar = listaAuxiliar->proximo;
    }

    tipoLista itemDescartar;
    itemDescartar = listaAuxiliar->proximo;

    free(itemDescartar);
	itemDescartar = NULL;

    listaAuxiliar->proximo = NULL;

    }
    
    }

    return lista;
}

void exibir(tipoLista lista){

    printf("\n---Lista atual---\n");

    if(lista==NULL){
        printf("\nVazia!\n");
    }else{

    tipoLista listaAuxiliar = lista;

    while(listaAuxiliar != NULL){
        printf("[%d] ",listaAuxiliar->item);
        listaAuxiliar = listaAuxiliar->proximo;
    }

    }

}


void pesquisar(int valor, tipoLista lista){

    int contador=0;
    tipoLista listaAuxiliar = lista;
    while(listaAuxiliar != NULL){

        if( listaAuxiliar->item == valor ){
            contador++;
        }
    listaAuxiliar = listaAuxiliar->proximo;
    }
        printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);
}

int main(){

    int opcao=-1;
    int valor=0;
    tipoLista lista = NULL;

    while (opcao!=0)
    {
        exibir(lista);
        valor=0;
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Remover no inicio\n");
        printf("4: Remover no final\n");
        printf("5: Pesquisar\n");

        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista = inserirEsquerda(valor,lista);
            break;

        case 2:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista = inserirDireita(valor,lista);
            break;

        case 3:
            lista = removerEsquerda(lista);
            break;

        case 4:
            lista = removerDireita(lista);
            break;

        case 5:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pesquisar(valor, lista);
            
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}
