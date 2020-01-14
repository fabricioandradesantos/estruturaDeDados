/*
Autor: Fabricio Andrade
Data: 11/01/20
Algoritmo: Arvore AVL 
Obs1: Não são utilizados comandos de limpar tela
para evitar problemas com diferentes SO's
Obs2: Esta implementacao nao permite a insercao de elementos repetidos
Obs3: A struct tipoItem guarda apenas um valor inteiro, mas pode ser modificada 
para que cada noh da arvore possa armazenar um conjunto de informaçoes Ex: Nome, matricula e etc. 
Obs4: Após o uso da funçao free o ponteiro é setado com NULL para evitar "Ponteiros selvagens"
Obs5: A funcao imprimir(); é uma adaptacao do código do site GeeksforGeeks
*/

#include <stdio.h>
#include <stdlib.h>
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
	int fatorBalanceamento;
	int altura;
}tipoNoh;


tipoNoh *inicializar(){
	return NULL;
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


int alturaNoh(tipoNoh *raiz) // calcula a altura de um nó
{
    if (raiz==NULL) // se não existe o nó, retorna a altura -1
        return -1;
    else
        return raiz->altura;
}

int fatorBalanceamento(tipoNoh *raiz) // calcula o fator de balanceamento
{
	//labs retorna o valor absoluto
    return labs(alturaNoh(raiz->esquerda)-alturaNoh(raiz->direita));
}


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

int maior(int x, int y){

	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}

}

void rotacaoDireita(tipoNoh **raiz){
	// árvore pendendo à esquerda, gira pra direita

	tipoNoh *nohAuxiliar;

	nohAuxiliar  = (*raiz)->esquerda;
	(*raiz)->esquerda  = nohAuxiliar->direita;
	nohAuxiliar->direita = *raiz;

	//atualiza altura do nó
	(*raiz)->altura = maior(alturaNoh((*raiz)->esquerda), alturaNoh((*raiz)->direita))+1;
	nohAuxiliar->altura = maior (alturaNoh(nohAuxiliar->esquerda), (*raiz)->altura)+1;

	*raiz = nohAuxiliar;
}

void rotacaoEsquerda(tipoNoh **raiz){
	// árvore pendendo à direita, gira pra esquerda

	tipoNoh *nohAuxiliar;

	nohAuxiliar  = (*raiz)->direita;
	(*raiz)->direita  = nohAuxiliar->esquerda;
	nohAuxiliar->esquerda = *raiz;

	//atualiza altura do nó
	(*raiz)->altura = maior(alturaNoh((*raiz)->esquerda), alturaNoh((*raiz)->direita))+1;
	nohAuxiliar->altura = maior (alturaNoh(nohAuxiliar->esquerda), (*raiz)->altura)+1;

	*raiz = nohAuxiliar;
}

void rotacaoEsquerdaDireita(tipoNoh **raiz){

	rotacaoEsquerda(&(*raiz)->esquerda);
	rotacaoDireita(raiz);
}


void rotacaoDireitaEsquerda(tipoNoh **raiz){

	rotacaoDireita(&(*raiz)->direita);
	rotacaoEsquerda(raiz);
}

tipoNoh* procuraMenor(tipoNoh **raiz) 
{
	//procura pelo nó mais a esquerda

    tipoNoh *nohAuxiliar1;
    tipoNoh *nohAuxiliar2;

    nohAuxiliar1 = (*raiz);
    nohAuxiliar2 = (*raiz)->esquerda;

    while(nohAuxiliar2!=NULL)
    {
        nohAuxiliar1 = nohAuxiliar2;
        nohAuxiliar2 = nohAuxiliar2->esquerda;
    }
    return nohAuxiliar1;
}


int inserir(tipoNoh **raiz, int valor){

    int controle;

	if (*raiz == NULL)
	{
		tipoNoh *nohAuxiliar = alocar();
		nohAuxiliar->item.valor = valor;
		nohAuxiliar->altura = 0;
		nohAuxiliar->esquerda  = NULL;
		nohAuxiliar->direita = NULL;
        *raiz = nohAuxiliar;
		return 1;
	}

	tipoNoh *nohAtual;

	nohAtual = *raiz;

    if(valor < nohAtual->item.valor)
    {
        if((controle=inserir(&(nohAtual->esquerda),valor))==1)
        {
            if(fatorBalanceamento(nohAtual)>=2)
            {
                if(valor < (*raiz)->esquerda->item.valor)
                    rotacaoDireita(raiz);
                else
                    rotacaoEsquerdaDireita(raiz);
            }
        }
    }

    else
    {
        if(valor > nohAtual->item.valor)
        {
            if ((controle=inserir(&(nohAtual->direita),valor))==1)
            {
                if(fatorBalanceamento(nohAtual)>=2)
                {
                    if(valor > (*raiz)->direita->item.valor)
                        rotacaoEsquerda(raiz);
                    else
                        rotacaoDireitaEsquerda(raiz);
                }
            }
        }
        else
        {
            printf("\nValor Duplicado!\n");
            return 0;
        }
    }

    // recalcular a altura do nó
    nohAtual->altura = maior(alturaNoh(nohAtual->esquerda),alturaNoh(nohAtual->direita))+1; 

    return controle;

}

int remover(tipoNoh **raiz,int valor)
{
    int controle;

    if(*raiz==NULL)
    {
        printf("\nEste valor não existe\n");
        return 0;
    }
    if(valor < (*raiz)->item.valor)
    {
        if((controle=remover(&((*raiz)->esquerda),valor))==1)
        {
            if(fatorBalanceamento(*raiz)>=2)
            {
                if(alturaNoh((*raiz)->direita->esquerda)<=alturaNoh((*raiz)->direita->direita))
                    rotacaoEsquerda(raiz);
                else
                    rotacaoEsquerdaDireita(raiz);
            }
        }
    }
    if(valor>(*raiz)->item.valor)
    {
        if ((controle=remover(&((*raiz)->direita),valor))==1)
        {

            if(fatorBalanceamento(*raiz)>=2)
            {
                if(alturaNoh((*raiz)->esquerda->direita)<=alturaNoh((*raiz)->esquerda->esquerda))
                    rotacaoDireita(raiz);
                else
                    rotacaoDireitaEsquerda(raiz);
            }
        }
    }
    if((*raiz)->item.valor==valor)
    {
        if(((*raiz)->esquerda==NULL)||((*raiz)->direita==NULL)) //Pai tem um filho ou nenhum filho
        {
            tipoNoh *nohAuxiliar = *raiz;

            if((*raiz)->esquerda!=NULL)
                *raiz=(*raiz)->esquerda;
            else
                *raiz=(*raiz)->direita;
            free(nohAuxiliar);
            nohAuxiliar = NULL;
            printf("\nNó removido com sucesso!\n");
        }
        else 
        {
        	//o pai tem dois filhos. 
        	//Substituir pelo nó mais a esquerda da subárvore da direita
            
            tipoNoh *nohAuxiliar = procuraMenor(&(*raiz)->direita);
            (*raiz)->item.valor = nohAuxiliar->item.valor;
            remover(&(*raiz)->direita,(*raiz)->item.valor);
            if(fatorBalanceamento(*raiz)>=2)
            {
                if(alturaNoh((*raiz)->esquerda->direita)<=alturaNoh((*raiz)->esquerda->esquerda))
                    rotacaoDireita(raiz);
                else
                    rotacaoEsquerdaDireita(raiz);
            }
        }
        return 1;
    }
    return controle;
}



int main()
{
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
			inserir(&raiz, valor);
			break;

			case 2:
			printf("\n------REMOVENDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);
			remover(&raiz, valor);
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
