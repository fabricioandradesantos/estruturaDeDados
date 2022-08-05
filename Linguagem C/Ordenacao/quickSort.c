#include <stdio.h>
#include <stdlib.h>


void merge(int *vetor, int inicio, int meio, int tamanhoAux)
{
	int i, j, k;
	int n1 = meio - inicio + 1;
	int n2 = tamanhoAux - meio;

	int L[n1], R[n2];
 
	for (i = 0; i < n1; i++)
		L[i] = vetor[inicio + i];
	for (j = 0; j < n2; j++)
		R[j] = vetor[meio + 1 + j];

	i = 0;
	j = 0;
	k = inicio;
	
    while (i < n1 && j < n2) {
		if (R[j]>= L[i]) {
			vetor[k] = L[i];
			i++;
		}
		else {
			vetor[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		vetor[k] = L[i];
		i++;
		k++;
	}
	
    while (j < n2) {
		vetor[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int *vetor, int inicio, int tamanhoAux)
{
	if (inicio < tamanhoAux) {
		
		// também pode usar (inicio+tamanho)/2 
		int meio = inicio + (tamanhoAux - inicio) / 2;

		// ordena a primeira e a segunda metades 
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, tamanhoAux);
		merge(vetor, inicio, meio, tamanhoAux);
	}
}

int main() {
  int vetor[10]={1,3,2,8,3,4,6,5,9,10};
  

  printf("\nAntes de Ordenar\n");
  for (int i = 0; i < 10; i++) {
    printf("VETOR[%d]\n", vetor[i]);
  }

  mergeSort(vetor, 0, 10 - 1);
  // bubbleSort(vetor, 10);

  printf("\nOrdenado\n");
  for (int i = 0; i < 10; i++) {
    printf("VETOR[%d]\n", vetor[i]);
  }
}
