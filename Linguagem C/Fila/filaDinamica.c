/*
Autor: Fabricio Andrade
Data: 10/01/19
Algoritmo: Fila Dinamica/Ligada/encadeada
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: Note que o tipoFila é definido como um ponteiro na definição da struct
Obs3: Após o uso da funçao free o ponteiro é setado com NULL para evitar 
"Ponteiros selvagens"
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
	int item;
	struct ITEM *proximo;
}*tipoFila;


tipoFila criarItem(int valor){

	tipoFila novoItem = (tipoFila) malloc(sizeof(tipoFila));

	if(novoItem == NULL){
        printf("\nErro ao criar item!\n");
        return NULL;
	}else{
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
	}

}

tipoFila inserir(int valor, tipoFila fila){
	   
    tipoFila novoItem = criarItem(valor);
    if (fila == NULL)
    {
        //novoItem->proximo = fila;
        return novoItem;
    }else{
    
    tipoFila filaAuxiliar = fila;

    while(filaAuxiliar->proximo != NULL){
        filaAuxiliar = filaAuxiliar->proximo;
    }

    filaAuxiliar->proximo = novoItem;
    
        return fila;
    }

    
}

tipoFila remover(tipoFila fila){
    
    if(fila==NULL){
        printf("\nVazia!\n");
	}else{

	tipoFila filaAuxiliar;
    filaAuxiliar = fila;
    fila = fila->proximo;

	free(filaAuxiliar);
	filaAuxiliar = NULL;
	}
    return fila;
}

void exibir(tipoFila fila){

	printf("\n---Fila atual---\n");

	if(fila==NULL){
        printf("\nVazia!\n");
    }else{

    tipoFila filaAuxiliar = fila;

    while(filaAuxiliar != NULL){
        printf("[%d] ",filaAuxiliar->item);
        filaAuxiliar = filaAuxiliar->proximo;
    }

    }

}

void exibirPrimeiro(tipoFila fila){

	if(fila==NULL){
        printf("\nVazia!\n");
    }else{

    printf("\nO valor do primeiro eh %d\n",fila->item);

    }

}

void pesquisar(int valor, tipoFila fila){

	int contador=0;
    tipoFila filaAuxiliar = fila;
	while(filaAuxiliar != NULL){

		if( filaAuxiliar->item == valor ){
            contador++;
		}
    filaAuxiliar = filaAuxiliar->proximo;
	}
        printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);
}

int main(){

	int opcao=-1;
    int valor=0;
    tipoFila fila = NULL;

    while (opcao!=0)
    {
        exibir(fila);
        valor=0;
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir\n");
        printf("2: Remover\n");
        printf("3: Pesquisar\n");
        printf("4: Exibir primeiro\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            fila = inserir(valor,fila);
            break;

        case 2:
           fila = remover(fila);
            break;

        case 3:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pesquisar(valor,fila);
            break;

        case 4:
            exibirPrimeiro(fila);
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
