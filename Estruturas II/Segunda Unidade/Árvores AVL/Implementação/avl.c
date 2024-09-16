#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    /* Informações: */
    int valor;               // Valor a ser Inserido.
    struct no *left, *right; // Ponteiro para as subárvores.
    int altura;              // altura da árvore.
} No;

/*
Função que cria um novo nó.
x -> valor a ser inserido no nó.
Retorna: o endereço do nó criado.
*/
// Passammos o elemento a ser inserido.
No *NewNO(int x)
{
    // Alocamos memória para o novo nó.
    No *novo = malloc(sizeof(No));

    if (novo) // se a alocação de certo.
    {
        novo->valor = x;
        novo->left = NULL;
        novo->right = NULL;
        novo->altura = 0; // Altura de um nó folha.
    }
    else
    {
        printf("\nERRO ao alocar o novo nó!\n");
    }
    return novo; // Retorno do Ponteiro para o Nó Criado.
}

/*
Retorna o maior dentre dois valores a,b ->altura de dois nós da árvore.
- Determinar a altura maior entre duas subárvores durante o cálculo da altura de um nó e é frequentemente empregada para garantir o balanceamento da árvore.




*/
// Recebe o parâmetro de duas subárvores.
// Estrutura
int maior(int a, int b)
{
    // Se a for maior b retorna a A se não retorna a B.
    return (a > b) ? a : b;
}

// Retorna a altura de um nó ou -1 caso ele seka null.
int alturaDoNo(No *no)
{
    if (no == NULL)
    {
        return -1;
    }
    else
    {
        return no->altura;
    }
}

// calcula e retorna o fator de balanceamento de um nó.
int fatorDeBalanceamento(No *no)
{
    if (no)
    {
        // FB = HESQUERDA- HDIREIRA.
        // Retornando o resultado.
        return (alturaDoNo(no->left) - alturaDoNo(no->right));
    }
    return 0; // Retorna 0 se no for NULL
}
// função para a rotação à esquerda.
No *rotacaoEsquerda(No *r) // Ponteiro para o nó desbalanceado, com FB = NEGATIVO.
{
    // Dois ponteiros auxiliares.
    No *y, *f;
    // Eles recebem:
    y = r->right; // Para a raiz.
    f = y->left;  // Para o filho a esquerda.

    y->left = r;  // O ponteiro a esquerda vai apontar para a raiz.
    r->right = f; // O ponteiro da raiz vai apontar para f que é o filho do ponteiro a esquerda.

    // Recalcular a altura:
    // retorna as alturas + 1.
    r->altura = maior(alturaDoNo(r->left), alturaDoNo(r->right)) + 1;
    y->altura = maior(alturaDoNo(y->left), alturaDoNo(y->right)) + 1;

    return y; // Retorna a nova raiz.
}

// função para a Rotação à Direita.
No *rotacaoDireita(No *r) // Ponteiro para o nó desbalanceado, com FB = POSITIVO.
{
    // Dois ponteiros auxiliares.
    No *y, *f;
    // Eles recebem:
    y = r->left;  // Para a raiz.
    f = y->right; // Para o filho a Direita.

    y->right = r; // O ponteiro a Direita vai apontar para a raiz.
    r->left = f;  // O ponteiro da raiz vai apontar para f que é o filho do ponteiro a Direita.

    // Recalcular a altura:
    // retorna as alturas + 1.
    r->altura = maior(alturaDoNo(r->left), alturaDoNo(r->right)) + 1;
    y->altura = maior(alturaDoNo(y->left), alturaDoNo(y->right)) + 1;

    return y; // Retorna a nova raiz.
}

// Função de Rotação Direita Esquerda.
// Ponteiro para o nó desbalanceado.
No *rotacaoDireitaEsquerda(No *r)
{
    // Recebe o retorno da rotação direita.
    r->right = rotacaoDireita(r->right);
    // Retorna a rotação a esquerda.
    return rotacaoEsquerda(r);
}

// Função de Rotação Esquerda Direita.
// Ponteiro para o nó desbalanceado.
No *rotacaoEsquerdaDireita(No *r)
{
    // Recebe o retorno da rotação esquerda.
    r->left = rotacaoEsquerda(r->left);
    // Retorna a rotação a esquerda.
    return rotacaoDireita(r);
}

/*Função para realizar o balanceamento da árvore após uma inserção ou remoção Recebe o nó que está desbanlanceado e retorna a nova raiz após o balanceamento. */
No *balancear(No *raiz)
{
    // FB = NEGATIVO(DIREITA) E POSITIVO(ESQUERDA).
    int fb = fatorDeBalanceamento(raiz);
    // Rotação à esquerda
    if (fb < -1 && fatorDeBalanceamento(raiz->right) <= 0)
    { // Tende a direita, totalmente negativo ou zero.
        raiz = rotacaoEsquerda(raiz);
    }
    // Rotação à direita
    else if (fb > 1 && fatorDeBalanceamento(raiz->left) >= 0)
    { // Tende a esquerda, totalmente negativo ou zero.
        raiz = rotacaoDireita(raiz);
    }
    // Rotação dupla à esquerda
    else if (fb > 1 && fatorDeBalanceamento(raiz->left) < 0)
    { // Tende a esquerda, totalmente positivo.
        raiz = rotacaoEsquerdaDireita(raiz);
    }
    // Rotação dupla à direita
    else if (fb < -1 && fatorDeBalanceamento(raiz->right) > 0)
    { // Tende a direita, totalmente positivo.
        raiz = rotacaoDireitaEsquerda(raiz);
    }
    return raiz;
}

/*
Insere um novo nó na árvore.
raiz -> raiz da árvore.
x -> valor a ser inserido.
Retorno: endereço do novo nó ou nova raiz após o balanceamento.
*/
No *inserir(No *raiz, int x)
{
    if (raiz == NULL)
    { // árvore vazia, criei um nó.
        return NewNO(x);
    }
    else
    {                        // inserção será à esquerda ou à direita
        if (x < raiz->valor) // vai para esquerda recursivamente.
        {
            raiz->left = inserir(raiz->left, x);
        }
        else if (x > raiz->valor) // vai para direita recursivamente.
        {
            raiz->right = inserir(raiz->right, x);
        }
        else
        {
            printf("\nInsercao nao realizada!\no elemento %d a existe!\n", x);
        }
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->left), alturaDoNo(raiz->right)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);
    return raiz;
}

// Função para Imprimir.
// Recebe a raiz da árvore e o nível.
void imprimir(No *raiz, int nivel)
{
    int i;
    if (raiz) // enquanto não for vazio.
    {
        imprimir(raiz->right, nivel + 1); // Ir a extrema direita.
        // vai indo para direita sempre, ao encontra NULL, volta para ultima chamada recursiva anterior
        printf("\n\n");
        for (i = 0; i < nivel; i++)
            printf("\t"); // nivel 1 = 1 tabulação e etc.

        printf("%d", raiz->valor);
        // Ir a extrema esquerda.
        imprimir(raiz->left, nivel + 1);
    }
}

// Função remoção.
// Retorna a um nó, com valor sendo o dado a ser removido.
/* Remove um nó da árvore */
No *remover(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else
    { // Procura o nó a remover.
        if (raiz->valor == chave)
        {
            // Remove nós folhas (nós sem filhos).
            if (raiz->left == NULL && raiz->right == NULL)
            {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else
            {
                // Remove nós que possuem 2 filhos.
                if (raiz->left != NULL && raiz->right != NULL)
                {
                    // precisamos salvalos.
                    // o elemento a remover é trocado com um dos filhos, tornado um filho ou folha.
                    No *aux = raiz->left;
                    while (aux->right != NULL)
                    {
                        aux = aux->right;
                    }
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->left = remover(raiz->left, chave);
                }
                else
                {
                    // Remove nós que possuem apenas 1 filho.
                    // salvar o filho a direita ou a esquerda.
                    No *aux = (raiz->left != NULL) ? raiz->left : raiz->right; //
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        }
        else
        { // recursividade
            if (chave < raiz->valor)
            {
                raiz->left = remover(raiz->left, chave);
            }
            else
            {
                raiz->right = remover(raiz->right, chave);
            }
        }
        // recalcular a altura de todos os nos entre a raiz e o nó inserido.
        raiz->altura = maior(alturaDoNo(raiz->left), alturaDoNo(raiz->right)) + 1;
        // verifica se a necessidade de balancear.
        raiz = balancear(raiz);
        return raiz;
    }
}

// Main com o menu.
int main()
{
    int opcao, valor;
    No *raiz = NULL; // Ponteiro inicial nulo.
    do
    {
        printf("\n\n\to - Sair\n\t1 Inserir\n\t2 Imprimir\n\t3 Remover\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            printf("Saindo!!!\n");
            break;
        case 1:
            printf("\tDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            imprimir(raiz, 1);
            break;
        case 3:
            printf("\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            printf("\nOpção inválida!!!\n");
        }
    } while (opcao != 0);
    return 0;
}
