#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Varíaves para manipular os Dados.
struct Info
{
    char nome[100];
    int mat;
    int turma;
    float nota;
};

// Definição e uma estrutura para os nós da árvore.
struct Node
{
    struct Info info; // Conjunto de Informações do aluno
    struct Node *esq;
    struct Node *dir;
};

// Declaração de funções utilizadas no programa.
// Função: Cria uma estrutura Info a partir dos parâmetros fornecidos.
struct Info criarInfo(int mat, char *nome, int turma, float nota);

// Função: Cria um nó da árvore com a estrutura Info fornecida.
struct Node *criarNode(struct Info info);

// Função: Compara duas estruturas Info.
int comparar(struct Info a, struct Info b);

// Função:  Insere um Info na árvore binária de busca.
struct Node *inserir(struct Node *raiz, struct Info info);

// Função para percorrer a árvore.
void andar_na_arvore(struct Node *raiz, int profundidade);

int main()
{
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Abre o arquivo "Dados.txt" para leitura.
    FILE *arquivo = fopen("Dados.txt", "rt");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //  Declara um array de 100 elementos do tipo Info para armazenar as informações lidas do arquivo.
    struct Info informacao[100];
    int index = 0;
    // Variável para contar quantas informações foram lidas.
    int quantidade = 0;
    int mat, turma;
    char nome[100];

    while (fscanf(arquivo, "%d - %[^-] - %d\n", &mat, nome, &turma) == 3)
    {
        // Cria uma estrutura Info com os dados lidos, incluindo uma nota gerada aleatoriamente
        informacao[quantidade] = criarInfo(mat, nome, turma, rand() % 10);
        quantidade++;
        if (quantidade >= 100)
        {
            break;
        }
    }

    fclose(arquivo);

    // Declara um ponteiro para o nó raiz da árvore, inicialmente nulo.
    struct Node *raiz = 0;
    for (index = 0; index < quantidade; index++)
    {
        raiz = inserir(raiz, informacao[index]);
    }
    andar_na_arvore(raiz, 0);
}

// Função.
struct Info criarInfo(int mat, char *nome, int turma, float nota)
{
    // Aqui, res é uma variável do tipo struct Info. Esta linha aloca memória para uma estrutura Info e declara res como uma variável dessa estrutura.
    struct Info res;
    // Atribuição a estrutura res.
    strcpy(res.nome, nome);
    res.mat = mat;
    res.turma = turma;
    res.nota = nota;
    return res;
}

// Função.
struct Node *criarNode(struct Info info)
{
    // Aloca memória para um novo nó.
    struct Node *res = (struct Node *)malloc(sizeof(struct Node));
    // Atribui a estrutura Info ao novo nó.
    res->info = info;
    // Inicializei o esq e o dir
    res->dir = 0;
    res->esq = 0;
    return res;
}

// Função.
int comparar(struct Info a, struct Info b)
{
    // Comparar primeiro pelo nome
    int cmpNome = strcmp(a.nome, b.nome);
    // Se os nomes forem diferentes, retorna o resultado da comparação.
    if (cmpNome != 0)
    {
        return cmpNome;
    }

    // Se os nomes forem iguais, comparar pela matrícula
    if (a.mat != b.mat)
    {
        return a.mat - b.mat;
    }

    // Se a matrícula também for igual, comparar pela turma
    return a.turma - b.turma;
}

// A função recebe dois parâmetros:
// struct Node *raiz: Um ponteiro para o nó raiz da árvore ou subárvore.
// struct Info info: A estrutura Info contendo os dados que devem ser inseridos na árvore.
struct Node *inserir(struct Node *raiz, struct Info info)
{
    // se está vazia.
    if (raiz == NULL)
    {
        return criarNode(info);
    }
    // A função comparar é usada para comparar os dados do nó atual (raiz->info) com os novos dados (info).
    int x = comparar(raiz->info, info);

    // comparar retorna um valor:
    // Negativo: Se info deve ir à direita (é maior).
    // Positivo: Se info deve ir à esquerda (é menor).
    // Zero: Se os dados são iguais (nesta função, não faz nada neste caso)
    if (x < 0)
    {
        raiz->dir = inserir(raiz->dir, info);
    }
    else if (x > 0)
    {
        raiz->esq = inserir(raiz->esq, info);
    }
    return raiz;
}

void andar_na_arvore(struct Node *raiz, int profundidade)
{

    if (raiz == NULL)
    {
        return;
    }
    printf("Nome: %s, Mat: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
    andar_na_arvore(raiz->dir, ++profundidade);
    andar_na_arvore(raiz->esq, ++profundidade);
}
