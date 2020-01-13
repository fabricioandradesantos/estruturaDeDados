/*
Autor: Fabricio Andrade
Data: 11/01/19
Algoritmo: Arvore Splay 
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: Esta implementacao nao permite a insercao de elementos repetidos
Obs3: A struct tipoItem guarda apenas um valor inteiro, mas pode ser modificada 
para que cada noh da arvore possa armazenar um conjunto de informaçoes Ex: Nome, matricula e etc. 
Obs4: Após o uso da funçao free o ponteiro é setado com NULL para evitar "Ponteiros selvagens"
Obs5: A funcao imprimir(); é uma adaptacao do código do site GeeksforGeeks
Obs6: Na exclusao foi utilizada a abordagem (o noh mais a esquerda da sub Arvore direita)
logo, a impressao da arvore será diferente da abordagem (noh mais a direita da sub Arvore esquerda)
*/

#include<stdio.h> 
#include<stdlib.h> 
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

tipoNoh *inicializar(){
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

tipoNoh *rotacaoDireita(tipoNoh *raiz) 
{ 
	tipoNoh *nohAuxiliar = raiz->esquerda; 
	raiz->esquerda = nohAuxiliar->direita; 
	nohAuxiliar->direita = raiz; 
	return nohAuxiliar; 
} 

tipoNoh *rotacaoEsquerda(tipoNoh *raiz) 
{ 
	tipoNoh *nohAuxiliar = raiz->direita;
	raiz->direita = nohAuxiliar->esquerda; 
	nohAuxiliar->esquerda = raiz; 
	return nohAuxiliar;
} 

tipoNoh *splay(tipoNoh *raiz, int valor) 
{ 
	// Caso base 
	if (raiz == NULL || raiz->item.valor == valor) 
		return raiz; 

	// O valor está na sub arvore esquerda 
	if (raiz->item.valor > valor) 
	{ 
		//O valor nao esta nessa sub arvore 
		if (raiz->esquerda == NULL) 
			return raiz; 

		if (raiz->esquerda->item.valor > valor) // Zig-Zig (esquerda esquerda)
		{  
			raiz->esquerda->esquerda = splay(raiz->esquerda->esquerda, valor);  
			raiz = rotacaoDireita(raiz); 
		} 
		else if (raiz->esquerda->item.valor < valor) // Zig-Zag (esquerda direita) 
		{ 
			
			raiz->esquerda->direita = splay(raiz->esquerda->direita, valor); 

			if (raiz->esquerda->direita != NULL) 
				raiz->esquerda = rotacaoEsquerda(raiz->esquerda); 
		} 

		//Condicional utilizando o operador ternario (é tipo um If e Else) 
		return (raiz->esquerda == NULL)? raiz: rotacaoDireita(raiz);	
		 
	} 
	else if (raiz->item.valor < valor) // Valor está na subárvore direita 
	{ 
		//Nao esta nessa sub arvore 
		if (raiz->direita == NULL) 
			return raiz; 

		// Zag-Zig (Direita esquerda) 
		if (raiz->direita->item.valor > valor) 
		{ 
			raiz->direita->esquerda = splay(raiz->direita->esquerda, valor); 

			if (raiz->direita->esquerda != NULL) 
				raiz->direita = rotacaoDireita(raiz->direita); 
		} 
		else if (raiz->direita->item.valor < valor)// Zag-Zag (direita direita) 
		{ 
			raiz->direita->direita = splay(raiz->direita->direita, valor); 
			raiz = rotacaoEsquerda(raiz); 
		} 

		//Condicional utilizando o operador ternario (é tipo um If e Else)
		return (raiz->direita == NULL)? raiz: rotacaoEsquerda(raiz);
		 
	} 
} 


tipoNoh *pesquisar(tipoNoh *raiz, int valor) 
{ 
	return splay(raiz, valor); 
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

int main() 
{ 
	 
	tipoNoh *raiz = inicializar();
	int opcao=-1;
	int valor=0;

	while(opcao!=0){

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
			raiz = inserir(raiz,criarItem(valor) );
			raiz = splay(raiz, valor);

			break;

			case 2:
			printf("\n------REMOVENDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);
			raiz = splay(raiz, valor);
			raiz = remover(raiz, valor);
			break;

			case 3:
			printf("\n------PESQUISANDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);

			raiz = pesquisar(raiz, valor);
			if (raiz->item.valor == valor)
			{
				printf("\nElemento encontrado com sucesso!\n");
			}else {
				printf("\nElemento nao encontrado! \n");
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