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
    int tamanho_da_arvore;
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
        if ((valor > no->left->conteudo))
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

// Função Inserir com parametro com m nó raiz e o valor.
No *Inserir_NOVA_VERSAO(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }
    else
    {
        if (valor < raiz->conteudo)
        {
            raiz->left = Inserir_NOVA_VERSAO(raiz->left, valor);
        }
        else if (valor > raiz->conteudo)
        {
            raiz->right = Inserir_NOVA_VERSAO(raiz->right, valor);
        }
        return raiz;
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

// Função que retorna a quantidade de Nós.
int tamanho_arvore(No *raiz){
    if(raiz == NULL){
        return 0;
    }else{
        // Você tem 1 nó na raiz + Left + Right se ouver.
        return 1 + tamanho_arvore(raiz->left) + tamanho_arvore(raiz->right);
    } } 


// Função de Busca.
int Buscar(No *raiz, int chave){
    if(raiz == NULL){
        return 0;// Caso não encontre.
    }
    else{// Se a raiz for o contéudo.
        if(raiz->conteudo == chave){
            return 1;// Caso encontre.
        }
        // Podemos eliminar subárvores dependendo da chave.
        else{
            if(chave < raiz->conteudo){
                return Buscar(raiz->left, chave);
            }
            else{
                return Buscar(raiz->right, chave);
            }
        
        }
}
}


// Função de Remoção. 

No * remover_caso1(No *raiz, int chave){
    // Se a raiz é nula
    if(raiz == NULL){
        printf("Não encontrado");
        return NULL;
    }
    else{
        // 1 Caso: Remover um nó que não possui nenhum filho.
        if(raiz->conteudo == chave){
            // Remover nós folha.
            if(raiz->left == NULL && raiz->right == NULL){
                free(raiz);
                return NULL;
            }
            else{
                // 2 caso com remoção de nós com 1 filho.
                if(raiz->left != NULL || raiz->right != NULL){
                    No *aux;
                    if(raiz->left != NULL ){
                        aux = raiz->left; // salvando o endereço do esquerda.

                    }
                    else{
                        aux = raiz->right; // salvando o endereço do direita.
                    }
                    free(raiz);
                    return aux; // retorna ao filho.

                }
            }

        }
        // Se não ... 
        else{
            // Recursividade para achar, verificando se é maior ou menor que o conteudo.
            if(chave < raiz->conteudo){
                raiz->left = remover_caso1(raiz->left, chave);
            }
            else{
                raiz->right = remover_caso1(raiz->right, chave);
            }
            return raiz;
            }
        }
    }


int main()
{
    int op, valor;
    Binary_Tree arv;
    // Usa o ponto pois não tem ponteiro.
    arv.raiz = NULL;
    // Utilizar apenas o nó.
    No *raiz = NULL;

        do
    {
        printf("\n0 - Sair.");
        printf("\n1 - Inserir.");
        printf("\n2 - Imprimir.");
        printf("\n3 - Buscar.");
        printf("\n4 - Remover.\n");
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
            /// insertion(&arv, valor);
            // Vai recer o retorno do nó
            raiz = Inserir_NOVA_VERSAO(raiz, valor);
            break;
        case 2:
            printf("Impressao da arvore binaria:\n");
            imprime(raiz);
            printf("\n");
            // Passo o nó inicial.
            printf("Tamanho: %d\n", tamanho_arvore(raiz));
            break;
        case 3:
        printf("Qual Valor deseja buscar?\n");
        scanf("%d", &valor);
        printf("Resultado da Busca: %d\n", Buscar(raiz, valor));
        break;
        case 4:
            printf("Digite um Valor a ser removido:\n");
            scanf("%d", &valor);
            raiz = remover_caso1(raiz, valor);
            break;

        default:
            printf("Opcao invalida...");
        }
    }
    while (op != 0)
        ;
}