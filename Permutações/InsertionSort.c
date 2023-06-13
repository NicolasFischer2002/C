#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimeArrayOrdenado(int* array, int* arrayInsertioSort, int comprimento) {

	int i;

	printf("\nArray original:\n");

	for (i = 0; i < comprimento; i++)
	{
		printf("\nPosição %d - %d", i, array[i]);
	}

	printf("\n");

	printf("\nArray ordenado:\n");

	for (i = 0; i < comprimento; i++)
	{
		printf("\nPosição %d - %d", i, arrayInsertioSort[i]);
	}

	printf("\n");
}

void InsertionSort(int* array, int comprimento) {
	int chave;
	int j, i;
	int* arrayInsertionSort;

	arrayInsertionSort = (int*)malloc(comprimento * sizeof(int));

	for (i = 0; i < comprimento; i++) {
		arrayInsertionSort[i] = array[i];
	}

	for (j = 1; j < comprimento; j++) {
		chave = arrayInsertionSort[j];
		i = j - 1;

		while (i >= 0 && arrayInsertionSort[i] > chave) {
			arrayInsertionSort[i + 1] = arrayInsertionSort[i];
			i = i - 1;
		}

		arrayInsertionSort[i + 1] = chave;
	}

	imprimeArrayOrdenado(array, arrayInsertionSort, comprimento);

	free(arrayInsertionSort);
}

int main() {

	setlocale(LC_ALL, "Portuguese");

	const int comprimento = 6;
	int* array = malloc(comprimento * sizeof(int));
	int valores[] = { 5, 2, 4, 6, 1, 3 };

	for (int i = 0; i < comprimento; i++) {
		array[i] = valores[i];
	}

	printf("Permutações");
	printf("\n");
	printf("Ordenação por inserção - Insertion-Sort");
	printf("\n");

	InsertionSort(array, comprimento);
}