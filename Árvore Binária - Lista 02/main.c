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
struct Info criarInfo(char *nome, int mat, int turma, float nota);

// Função: Cria um nó da árvore com a estrutura Info fornecida.
struct Node *criarNode(struct Info info);

// Função: Compara duas estruturas Info.
int comparar(struct Info a, struct Info b);

// Função:  Insere um Info na árvore binária de busca.
struct Node *inserir(struct Node *raiz, struct Info info);

void liberarArvore(struct Node *raiz);
void exibirArvore(struct Node *raiz);

int main()
{
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Declara um ponteiro para a raiz da árvore, inicialmente NULL (árvore vazia).
    struct Node *raiz = NULL;
        
        // Abre o arquivo "Dados.txt" para leitura.
        FILE *arquivo = fopen("Dados.txt", "r");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo");
            exit(1);
        }

        // Varíaves para armazenar a matrícula e a turma do aluno.
        char nome[100];
        int mat, turma;

        // lê uma linha do arquivo e armazena em nome. A função fgets lê até um caractere de nova linha ou até o final do arquivo, com um limite de sizeof(nome) caracteres.
        while (fgets(nome, sizeof(nome), arquivo))
        {
            // Para ajustes.
            nome[strcspn(nome, "\n")] = 0;

            if (fscanf(arquivo, "%d\n%d\n", &mat, &turma) != 2) // Leitura de dois valores. 
            {
                printf("Erro na leitura dos dados do arquivo\n");
                exit(1);
            }

            // Gera a nota aleatoriamente
            float nota = rand() % 10;

            // Cria o registro e insere na árvore
            struct Info info = criarInfo(nome, mat, turma, nota);
            // Insere a nova estrutura Info na árvore binária de busca.
            raiz = inserir(raiz, info);
        }

        fclose(arquivo);
    

    printf("Arvore Binaria de Busca:\n");
    exibirArvore(raiz);
    liberarArvore(raiz);

    return 0;
}

// Função.
struct Info criarInfo(char *nome, int mat, int turma, float nota)
{
    // Aqui, res é uma variável do tipo struct Info. Esta linha aloca memória para uma estrutura Info e declara res como uma variável dessa estrutura.
    struct Info res;

    // Alteração feita para não aparecer "Lixo de memória depois no Nome no GDB." Esta função copia a string nome para o campo nome da estrutura res.
    strncpy(res.nome, nome, sizeof(res.nome) - 1);
    res.nome[sizeof(res.nome) - 1] = '\0'; // Garante que a string está terminada, logo garante a parte de cima.

    // Atribuição a estrutura res.
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

// Uma função para liberar a memória dos lados se não estiver vazia.
void liberarArvore(struct Node *raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

// Função para Impressão.
void exibirArvore(struct Node *raiz)
{
    if (raiz != NULL)
    {
        exibirArvore(raiz->esq);
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n",
               raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
        exibirArvore(raiz->dir);
    }
}
