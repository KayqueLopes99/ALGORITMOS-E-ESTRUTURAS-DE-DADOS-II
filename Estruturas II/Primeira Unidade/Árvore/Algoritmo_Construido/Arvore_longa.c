#include <stdio.h>
#include <stdlib.h>
// Para evitar que repetições coloque condições para seguir para um único local nas funções de Inserção com IF.
// Estrtura 1:Armazenar Informações.
typedef struct no
{
    // Informação em cada nó.
    int conteudo;
    // Dois ponteiros para quem está a esquerda = Left e a Direita = Right.
    struct no *left, *right;

} No;

typedef struct Bi_Tree
{
    // Ponteiro para a Raiz(Começo).
    No *raiz;
} Binary_Tree;

void Insertion_left(No *no, int valor);
void Insertion_right(No *no, int valor);

// Função para inserir a esquerda, com parâmetros para um nó ou raiz da árvore e  o valor.
void Insertion_left(No *no, int valor)
{
    // Verificar se tem alguém na esquerda dele.
    if (no->left == NULL)
    { // Se tá vazio.
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->left = NULL;
        novo->right = NULL;
        // Recebe este novo nó.
        no->left = novo;
    }
    else
    { // Se tver alguém.
        // Se o valor for menor que o nó esquerda
        if (valor < no->left->conteudo)
        {
            // Recursividade para colocar a esquerda.
            Insertion_left(no->left, valor);
        }
        if((valor > no->left->conteudo))
        {
            // Coloca a direita, EVITANDO REPETIÇÃO DE NÚMEROS.
            Insertion_right(no->left, valor);
        }
        
    }
}

// Função para inserir a direita, com parâmetros para um nó ou raiz da árvore e  o valor.
// Segue a mesma lógica da Insertion_Left.
void Insertion_right(No *no, int valor)
{
    if (no->right == NULL)
    {
        // Se tá vazio.
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->left = NULL;
        novo->right = NULL;
        // Recebe este novo nó.
        no->right = novo;
    }
    else
    {
        if (valor > no->right->conteudo)
        {
            Insertion_right(no->right, valor);
        }
        if (valor < no->right->conteudo)
        {
            // Coloca a esquerda.
            Insertion_left(no->right, valor);
        }
    }
}

// Função para Inserir, com um ponteiro para a árvore e um valor a ser colocado.
void insertion(Binary_Tree *arv, int valor)
{
    // Se a raiz é nula.
    if (arv->raiz == NULL)
    {
        // Alocamos espaço para um nó pelo tamanho no sizeof com ponteiro "No*" para essa região.
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->left = NULL;
        novo->right = NULL;
        // A árvore recebe o novo nó nulo.
        arv->raiz = novo;
    }
    // Se tem alguém na raiz que não é nulo.
    else
    {
        // Se o valor for menor que a raiz avalia a esquerda.
        if (valor < arv->raiz->conteudo)
        {
            // Mandei a subarvore  sendo um "No" e valor a ser inserido.
            Insertion_left(arv->raiz, valor);
        }
        if (valor > arv->raiz->conteudo)
        { // Se não vai para direita.
            Insertion_right(arv->raiz, valor);
        }
    }
}

// Função para Imprimir a árvore com um ponteiro para a árvore.
void imprime(No *raiz)
{
    // Se a raiz não estiver Vazia, vai imprimir até o fim.
    if (raiz != NULL)
    {
        imprime(raiz->left);
        printf("%d ", raiz->conteudo);
        imprime(raiz->right);
    }
}

int main()
{
    int op, valor;
    Binary_Tree arv;
    // Usa o ponto pois não tem ponteiro.
    arv.raiz = NULL;

    do
    {
        printf("\n0 - Sair.");
        printf("\n1 - Inserir.");
        printf("\n2 - Imprimir.\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("Digite um Valor:\n");
            scanf("%d", &valor);
                // Mandei o endereço da minha árvore.
                insertion(&arv, valor);
            break;
        case 2:
            printf("Impressao da arvore binaria:\n");
            imprime(arv.raiz);
            break;
        default:
            printf("Opcao invalida...");
        }

    } while (op != 0);
}