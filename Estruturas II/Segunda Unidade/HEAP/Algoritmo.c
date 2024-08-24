// Este Algoritmo controi uma Heap Maxima e coloca para ordenar o vetor no fim.
// Acesso:
// p a[0] ou p *a
// p a[1], p a[2] ...
#include <stdio.h>
#include <stdlib.h>

// Função para ler o vetor:
// *p é o vetor apontando para o contéudo passado e o tamanho dela.
// Essa função lê t inteiros do usuário e armazena esses valores no vetor apontado por p.
void lerVet(int *p, int t) {
    int i;
    // Enquanto i for menor que o tamanho.
    for (i = 0; i < t; i++) {
    // Vai lendo os número do usuário e armazenando na posição correte
        scanf("%d", &p[i]);
    }
}

// Função para exibir o conteúdo do vetor na tela.
void mostrarVet(int *p, int t) {
    int i;
    // Ler o contéudo que está inserido na posição adequada.
    for (i = 0; i < t; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}


// Essa função é responsável por garantir que uma subárvore com raiz no índice i obedeça à propriedade da Max-Heap (ou seja, que o nó pai seja maior que seus filhos).
// int *a: O array que representa a Heap.
// int n: O tamanho atual da Heap.
// int i: O índice do nó que está sendo verificado.
void heapify(int *a, int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    // Verifica se o filho esquerdo é maior que o nó pai
    if (esq < n && a[esq] > a[maior])
        maior = esq;

    // Verifica se o filho direito é maior que o nó pai (ou o filho esquerdo, se já foi atualizado)
    if (dir < n && a[dir] > a[maior])
        maior = dir;

    // Se o maior valor não é o valor atual (nó pai), faz a troca e chama heapify recursivamente
    if (maior != i) {
        int temp = a[i];
        a[i] = a[maior];
        a[maior] = temp;

        // Chamada recursiva de heapify para garantir que a subárvore afetada respeite a propriedade Max-Heap
        heapify(a, n, maior);
    }
    // Tipo depois dele ajustar o maior valor e subir ele para cima, ele vai denovo recursivamente para colocar o segundo maior valor para cima.
}

// Explicação:
/*
Construção da Max-Heap: O loop começa no meio do array (índice n / 2 - 1) e move-se para trás até o índice 0. A função heapify é chamada para garantir que a subárvore com raiz em cada índice obedeça à propriedade da Max-Heap.

Impressão da Max-Heap: Após construir a Max-Heap, o vetor é impresso para mostrar a sua estrutura.

Ordenação: O maior elemento (raiz da Max-Heap) é trocado com o último elemento do vetor. A função heapify é então chamada no novo primeiro elemento para manter a propriedade da Heap no restante do array. Esse processo se repete até o vetor estar ordenado.
*/
void heapSort(int *a, int n) {
    int i;

    // Constrói a Max-Heap
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Imprime a Max-Heap construída
    printf("Max-Heap após construção:\n");
    mostrarVet(a, n);

    // Ordena o array
    for (i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main() {
    int *p, tamanho_da_HEAP;

    printf("Quantidade de elementos do vetor? ");
    scanf("%d", &tamanho_da_HEAP);

    p = (int *)malloc(tamanho_da_HEAP * sizeof(int));

    printf("\nDigite o conteudo do vetor:\n");
    lerVet(p, tamanho_da_HEAP);

    printf("\nConteudo digitado para o vetor:\n");
    mostrarVet(p, tamanho_da_HEAP);

    printf("\nConstruindo a Max-Heap...\n");
    heapSort(p, tamanho_da_HEAP);

    printf("\nConteudo do vetor já ordenado:\n");
    mostrarVet(p, tamanho_da_HEAP);

    free(p);

    return 0;
}
