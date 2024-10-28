#include <stdio.h>
#define TAM_MATRIZ 10 // Tamanho da matriz de adjacência

// Inicializando a matriz com zeros
void INICIALIZAR(int matrizarr[][TAM_MATRIZ]) {
    int i, j;
    for (i = 0; i < TAM_MATRIZ; i++)
        for (j = 0; j < TAM_MATRIZ; j++)
            matrizarr[i][j] = 0;
}

// Adicionando aresta
void ADICIONANDO_ARESTAS(int matrizarr[][TAM_MATRIZ], int i, int j) {
    if (matrizarr[i][j] == 0) { // Verifica se a aresta já existe
        matrizarr[i][j] = 1;
        matrizarr[j][i] = 1;
    } else {
        printf("Aresta já existe entre %d e %d.\n", i, j);
    }
}

// Imprimindo a matriz de adjacência
void PRINT_ADJMATRIZ(int matrizarr[][TAM_MATRIZ]) {
    int i, j;
    printf("Matriz de Adjacência:\n");
    for (i = 0; i < TAM_MATRIZ; i++) {
        printf("%d: ", i);
        for (j = 0; j < TAM_MATRIZ; j++) {
            printf("%d ", matrizarr[i][j]);
        }
        printf("\n");
    }
}

// Verificando se a matriz está cheia (todos os elementos são 1)
int verifica(int arr[][TAM_MATRIZ]) {
    int i, j;
    for (i = 0; i < TAM_MATRIZ; i++)
        for (j = 0; j < TAM_MATRIZ; j++)
            if (arr[i][j] != 1)
                return 0; // Não está cheia
    return 1; // Está cheia
}

int main() {
    int adjMatrix[TAM_MATRIZ][TAM_MATRIZ];
    int op, num1, num2;

    INICIALIZAR(adjMatrix);

    do {
        printf("\n*====* MENU *====*\n");
        printf("1 - Adicionar aresta\n");
        printf("2 - Imprimir matriz de adjacência\n");
        printf("0 - Finalizar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if (verifica(adjMatrix) == 1) {
                    printf("A matriz está cheia. Não é possível adicionar mais arestas.\n");
                } else {
                    printf("Informe a linha: ");
                    scanf("%d", &num1);
                    printf("Informe a coluna: ");
                    scanf("%d", &num2);

                    // Verificando se os índices estão dentro dos limites
                    if (num1 >= 0 && num1 < TAM_MATRIZ && num2 >= 0 && num2 < TAM_MATRIZ) {
                        ADICIONANDO_ARESTAS(adjMatrix, num1, num2);
                        printf("Aresta adicionada entre %d e %d.\n", num1, num2);
                    } else {
                        printf("Índices inválidos! Por favor, insira valores entre 0 e %d.\n", TAM_MATRIZ - 1);
                    }
                }
                break;

            case 2:
                PRINT_ADJMATRIZ(adjMatrix);
                break;

            case 0:
                printf("Finalizando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (op != 0);

    return 0;
}
