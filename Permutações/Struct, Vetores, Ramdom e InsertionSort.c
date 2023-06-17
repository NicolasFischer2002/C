#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Vetores {
    int* vetorInicial;
    int* vetorDecrescente;
    int* vetorCrescente;
};

void ImprimePosicoesVetor(int* vetor, int comprimento) {
    if (vetor == NULL || comprimento <= 0) {
        printf("\nVetor inválido ou comprimento inválido.\n");
        exit(1);
    }

    for (int i = 0; i < comprimento; i++) {
        printf("\nPosição %d - %d", i, vetor[i]);
    }
}

void VerificaMemoriaAlocada(int* vetor) {
    if (vetor == NULL) {
        printf("\nFalha ao alocar memória!\n");
        exit(1);
    }
}

int* ClonaVetor(int* vetor, int comprimento) {
    int* vetorClone = (int*)malloc(comprimento * sizeof(int));
    VerificaMemoriaAlocada(vetorClone);

    for (int i = 0; i < comprimento; i++) {
        vetorClone[i] = vetor[i];
    }

    return vetorClone;
}

void InsertionSortDecrescente(struct Vetores* Vetor, int comprimento) {
    int chave;
    int i, j;

    Vetor->vetorDecrescente = ClonaVetor(Vetor->vetorInicial, comprimento);

    for (j = 0; j < comprimento; j++) {
        chave = Vetor->vetorDecrescente[j];
        i = j - 1;

        while (i >= 0 && Vetor->vetorDecrescente[i] < chave) {
            Vetor->vetorDecrescente[i + 1] = Vetor->vetorDecrescente[i];
            i = i - 1;
        }

        Vetor->vetorDecrescente[i + 1] = chave;
    }

    ImprimePosicoesVetor(Vetor->vetorDecrescente, comprimento);
    free(Vetor->vetorDecrescente);
}

void InsertionSortCrescente(struct Vetores* Vetor, int comprimento) {
    int chave;
    int i, j;

    Vetor->vetorCrescente = ClonaVetor(Vetor->vetorInicial, comprimento);

    for (j = 0; j < comprimento; j++) {
        chave = Vetor->vetorCrescente[j];
        i = j - 1;

        while (i >= 0 && Vetor->vetorCrescente[i] > chave) {
            Vetor->vetorCrescente[i + 1] = Vetor->vetorCrescente[i];
            i = i - 1;
        }

        Vetor->vetorCrescente[i + 1] = chave;
    }

    ImprimePosicoesVetor(Vetor->vetorCrescente, comprimento);
    free(Vetor->vetorCrescente);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Vetores Vetor;
    int comprimento;
    int numero;
    int escolha;

    printf("\nDigite o tamanho do vetor, de 1 à 10: ");
    scanf_s("%d", &comprimento);

    if (comprimento > 10 || comprimento < 1) {
        printf("\nComprimento inválido!\n");
        exit(1);
    }

    Vetor.vetorInicial = (int*)malloc(comprimento * sizeof(int));
    VerificaMemoriaAlocada(Vetor.vetorInicial);

    printf("\nEscolha o método de ordenação: ");
    printf("\nInsertion Sort crescente digite 0, Insertion Sort decrescente digite 1: ");
    scanf_s("%d", &escolha);

    if (escolha < 0 || escolha > 1) {
        printf("\nEscolha uma opção válida!\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < comprimento; i++) {
        numero = rand() % 1000;
        Vetor.vetorInicial[i] = numero;
    }

    printf("\nVetor original: \n");
    ImprimePosicoesVetor(Vetor.vetorInicial, comprimento);

    if (escolha == 0) {
        printf("\n\nVetor em ordem crescente:\n");
        InsertionSortCrescente(&Vetor, comprimento);
    }
    else {
        printf("\n\nVetor em ordem decrescente:\n");
        InsertionSortDecrescente(&Vetor, comprimento);
    }

    free(Vetor.vetorInicial);
    printf("\n");

    return 0;
}
