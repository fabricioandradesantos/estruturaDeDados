/*
Autor: Fabricio Andrade
Data: 10/01/20
Algoritmo: Pilha dinamica/ligada/encadeada
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: inserir = push, remover = pop, pesquisar = search, exibir = display.
Obs3: Note que o tipoPilha é definido como um ponteiro na definição da struct
Obs4: Após o uso da funçao free o ponteiro é setado com NULL para evitar
"Ponteiros selvagens"
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
	int item;
	struct ITEM *proximo;
}*tipoPilha;


tipoPilha criarItem(int valor){

	tipoPilha novoItem = (tipoPilha) malloc(sizeof(tipoPilha));

	if(novoItem == NULL){
        printf("\nErro ao criar item!\n");
        return NULL;
	}else{
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
	}

}

tipoPilha inserir(int valor, tipoPilha pilha){
	tipoPilha novoItem = criarItem(valor);
    novoItem->proximo = pilha;
	return novoItem;
}

tipoPilha remover(tipoPilha pilha){
    if(pilha==NULL){
        printf("\nVazia!\n");
        return pilha;
	}else{
	tipoPilha pilhaAuxiliar = pilha->proximo;
	free(pilha);
	pilha = NULL;
	return pilhaAuxiliar;
	}

}

void exibir(tipoPilha pilha){

	printf("\n---Pilha atual---\n");

	if(pilha==NULL){
        printf("Vazia!\n");
	}else{

	while(pilha!=NULL){
		printf("\t %d\n",pilha->item);
		pilha = pilha->proximo;
	}

}


}

void exibirTopo(tipoPilha pilha){

	if(pilha==NULL){
        printf("\nVazia!\n");
	}else{
        printf("\nO valor do topo eh %d\n",pilha->item);
}

}

void pesquisar(int valor, tipoPilha pilha){

	int contador=0;

	while(pilha != NULL){

		if( pilha->item == valor ){
            contador++;
		}
    pilha = pilha->proximo;
	}
        printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);
}

int main(){

	int opcao=-1;
    int valor=0;
    tipoPilha pilha = NULL;

    while (opcao!=0)
    {
        exibir(pilha);
        valor=0;
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir\n");
        printf("2: Remover\n");
        printf("3: Pesquisar\n");
        printf("4: Exibir topo\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pilha = inserir(valor,pilha);
            break;

        case 2:
           pilha = remover(pilha);
            break;

        case 3:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pesquisar(valor,pilha);
            break;

        case 4:
            exibirTopo(pilha);
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
