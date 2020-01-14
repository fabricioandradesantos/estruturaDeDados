/*
Autor: Fabricio Andrade
Data: 11/01/20
Algoritmo: Arvore binaria 
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: Esta implementacao nao permite a insercao de elementos repetidos
Obs3: A struct tipoItem guarda apenas um valor inteiro, mas pode ser modificada 
para que cada noh da arvore possa armazenar um conjunto de informaçoes Ex: Nome, matricula e etc. 
Obs4: Após o uso da funçao free o ponteiro é setado com NULL para evitar "Ponteiros selvagens"
Obs5: A funcao imprimir(); é uma adaptacao do código do site GeeksforGeeks
*/

#include <stdlib.h>
#include <stdio.h>
#define tamanhoDoEspaco 10 
//usada para definir os espacos entre os item da arvore na impressão da arvore 

typedef struct ITEM
{
	int valor;
}tipoItem;


typedef struct NOH
{
	tipoItem item;
	struct NOH *esquerda;
	struct NOH *direita;
}tipoNoh;

int alturaArvore(tipoNoh *raiz){

	int alturaDireita=0;
	int alturaEsquerda=0;

	if (raiz == NULL)
	{	
		return -1;
	}

	alturaEsquerda = alturaArvore(raiz->esquerda);
	alturaDireita = alturaArvore(raiz->direita);

	if (alturaEsquerda > alturaDireita)
	{
		return alturaEsquerda+1;
	}
	else
	{
		return alturaDireita+1;
	}

}

int contarNos(tipoNoh *raiz){
	//contar quantos nós tem na árvore
	if (raiz == NULL)
	{
		return 0;
		
	}else{

		return contarNos(raiz->esquerda) + contarNos(raiz->direita) + 1; 
	}

}


tipoNoh *inicializar(){
	return NULL;
}

tipoItem criarItem(int valor){

	tipoItem item;
	item.valor = valor;
	return item;
}

tipoNoh *alocar(){

		tipoNoh *novoNoh = (tipoNoh*) malloc(sizeof(tipoNoh));
		if (novoNoh != NULL)
		{
			return novoNoh;
		}else{
			printf("Erro ao criar novo nó\n");
			exit(1); //interrompe o programa
		}
}

tipoNoh *inserir(tipoNoh *raiz, tipoItem item){

	
	if (raiz == NULL)
	{
		//inserir na árvore vazia
		tipoNoh *novoNoh = alocar();
		novoNoh->item = item;
		novoNoh->esquerda = NULL;
		novoNoh->direita = NULL;
		return novoNoh;
	}else{

		if (item.valor > raiz->item.valor)
		{
			//inserir na direita se for maior que a raiz
			raiz->direita = inserir(raiz->direita, item);

		}else if(item.valor < raiz->item.valor){
			//inserir na esquerda se for menor 
			raiz->esquerda = inserir(raiz->esquerda, item);
		}

	}
		return raiz;
}

void imprimir(tipoNoh *raiz, int espaco) 
{ 
    //Caso base 
    if (raiz == NULL){ 
        return; 
    }else{
    //Aumentar a distância entre os níveis 
    espaco += tamanhoDoEspaco; 

    //Trabalhando com a sub Arvore direita 
    imprimir(raiz->direita, espaco); 
  
    // Imprimir nó após o espaço 
    printf("\n"); 
    for (int i = tamanhoDoEspaco; i < espaco; i++) {
        printf(" "); 
    }

    printf("%d\n", raiz->item.valor); 
  
    //Trabalhando com a sub Arvore direita
    imprimir(raiz->esquerda, espaco); 
	}
}

void apagarArvore(tipoNoh *raiz)
{
	//Funcao para liberar a memoria utilizada pela arvore
	if (raiz != NULL)
	{
		apagarArvore(raiz->esquerda);
		apagarArvore(raiz->direita);
		free(raiz);
		raiz = NULL;
	}

}

tipoNoh *pesquisar(tipoNoh *raiz, int valor){

	if (raiz != NULL)
	{
		if (raiz->item.valor == valor)
		{
			return raiz;
		}
		else
		{
			if (valor > raiz->item.valor)
			{
			//pesquisar na direita
			return pesquisar(raiz->direita, valor);

			}else{
			//pesquisar na esquerda
			 return pesquisar(raiz->esquerda, valor);
			}
		}

	}

	return NULL;

}

tipoNoh *minimo(tipoNoh *raiz){

	if (raiz != NULL)
	{
		tipoNoh *nohAuxiliar = raiz;
		while(nohAuxiliar->esquerda != NULL){
			nohAuxiliar = nohAuxiliar->esquerda;
		}
		return nohAuxiliar;
	}
	return NULL;
}


tipoNoh *remover(tipoNoh *raiz, int valor){

	if (raiz != NULL)
	{
		if (valor > raiz->item.valor)
		{
			//busca na direita 
			raiz->direita = remover(raiz->direita, valor);
		
		}else if (valor < raiz->item.valor)
		{
			//busca na esquerda 
			raiz->esquerda = remover(raiz->esquerda, valor);
		}
		else //encontrou o elemento a ser removido
		{
			//removendo nó folha
			if (raiz->esquerda == NULL && raiz->direita == NULL)
			{
				free(raiz);
				raiz = NULL;

				return NULL;
			}
			else if (raiz->esquerda == NULL && raiz->direita != NULL)
			{
				//faz a ponte de ligação com a sub Arvore direita
				tipoNoh *nohAuxiliar = raiz->direita; //salva  a sub Arvore direita
				free(raiz); //apaga o nó onde a fun está no momento
				raiz = NULL;
				return nohAuxiliar; //retorna pro ant do nó excluido a subArv dir
			}
			else if (raiz->esquerda != NULL && raiz->direita == NULL)
			{
				//faz a ponte de ligação com a sub Arvore esquerda
				tipoNoh *nohAuxiliar = raiz->esquerda;
				free(raiz);
				raiz = NULL;
				return nohAuxiliar;
			}
			else{
				//remover quando tiver 2 filhos
				tipoNoh *nohAuxiliar = minimo(raiz->direita); //descobre o minimo da sub Arvore direita
				tipoItem itemAuxiliar = nohAuxiliar->item; //faz uma cópia do item minimo (que será a nova raiz)
				raiz = remover(raiz, itemAuxiliar.valor); //remove a nó minimo
				raiz->item = itemAuxiliar; //faz a raiz receber a cópia do novo nó raiz
			}
		}

		return raiz;

	}
	else{

		return NULL;

	}

}


int main(){

	tipoNoh *raiz = inicializar();
	int opcao=-1;
	int valor=0;

	while(opcao!=0){

		//imprimindo árvore a cada opcaoeração
		printf("\n---Arvore atual---\n");
		imprimir(raiz, tamanhoDoEspaco);

		valor=0;
		printf("\n---------------MENU---------------\n");
		printf("1: Inserir \n");
		printf("2: Remover \n");
		printf("3: Pesquisar \n");
		printf("0: SAIR \n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
			printf("\n------INSERINDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);
			raiz = inserir(raiz, criarItem(valor));
			break;

			case 2:
			printf("\n------REMOVENDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);
			raiz = remover(raiz, valor);
			break;

			case 3:
			printf("\n------PESQUISANDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);

			tipoNoh *nohAuxiliar = pesquisar(raiz, valor);
			if (nohAuxiliar == NULL)
			{
				printf("\nElemento nao encontrado!\n");
			}else {
				printf("\nElemento encontrado com sucesso! \n");
			}
			break;

			case 0:
			printf("\nTchau! Ate a proxima\n");
			break;

			default:
			printf("\nOpcao inválida! \n");
			break;
		}


	}
		apagarArvore(raiz);

	return 0;
}

