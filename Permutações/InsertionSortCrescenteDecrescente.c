#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimeArray(int* array, int comprimento) {

	for (int i = 0; i < comprimento; i++)
	{
		printf("\nPosição %d - %d", i, array[i]);
	}

}

void clonaArray(int* arrayOriginal, int* arrayClone, int comprimento) {

	for (int i = 0; i < comprimento; i++)
	{
		arrayClone[i] = arrayOriginal[i];
	}

}

void InsertionSortCrescente(int* array, int comprimento) {
	int i, j;
	int chave;

	for (j = 0; j < comprimento; j++)
	{
		chave = array[j];

		i = j - 1;

		while (i >= 0 && array[i] > chave)
		{
			array[i + 1] = array[i];

			i = i - 1;

		}

		array[i + 1] = chave;

	}

	imprimeArray(array, comprimento);

}

void InsertionSortDecrescente(int* array, int comprimento) {

	int i, j;
	int chave;

	for (j = 0; j < comprimento; j++)
	{
		chave = array[j];

		i = j - 1;

		while (i >= 0 && array[i] < chave)
		{
			array[i + 1] = array[i];

			i = i - 1;

		}

		array[i + 1] = chave;

	}

	imprimeArray(array, comprimento);

}

int main() {
	
	setlocale(LC_ALL, "Portuguese");

	const int comprimento = 6;
	int* array;
	int valores[] = {31, 41, 59, 26, 41, 58};
	int escolha;

	array = (int*)malloc(comprimento * sizeof(int));

	clonaArray(valores, array, comprimento);

	printf("===== Permutações =====");
	printf("\n\nDeseja ordenar o array de forma crescente ou decrescente?");
	printf("\nDigite 0 para 'Crescente', Digite 1 para 'Decrescente'\n\n");
	printf("Opção desejada: ");  scanf_s("%d", &escolha);

	if (escolha == 0)
	{
		printf("\nArray ordenado de forma crescente:");
		InsertionSortCrescente(array, comprimento);
	}
	else if (escolha == 1)
	{
		printf("\nArray ordenado de forma decrescente:");
		InsertionSortDecrescente(array, comprimento);
	}
	else
	{
		printf("\n\nDigite um valor válido!\n\n");
		free(array);
		return 1;
	}

	printf("\n");

	free(array);

}