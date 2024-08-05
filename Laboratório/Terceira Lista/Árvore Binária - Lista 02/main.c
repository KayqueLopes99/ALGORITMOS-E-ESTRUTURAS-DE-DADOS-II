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
void Andar_na_Arvore_PREORDEM(struct Node *raiz, int profundidade);
void Andar_na_Arvore_INORDEM(struct Node *raiz);
int main()
{
    srand(time(NULL)); 

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
        // Cria uma estrutura Info com os dados lidos, incluindo uma nota gerada aleatoriamente.
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

    // Percorrer as Informções lidas.
    for (index = 0; index < quantidade; index++)
    {
        // Insere cada informação na árvore binária de busca usando a função inserir.
        raiz = inserir(raiz, informacao[index]);
    }

    printf("Percurso na Arvore PRE-ORDEM:\n");
    Andar_na_Arvore_PREORDEM(raiz, 0);

    printf("\nPercurso na Arvore IN-ORDEM:\n");
    Andar_na_Arvore_INORDEM(raiz);
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
// Função.
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

// Função - > Pré_Ordem.
// struct Node *raiz, aponta para o nó atual da árvore. 
void Andar_na_Arvore_PREORDEM(struct Node *raiz, int profundidade)
{

    if (raiz == NULL)
    {
        return;
    }
    printf("Nome: %s, Mat: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
    // Recursão para a Subárvore com incremento da profundidade. 
    Andar_na_Arvore_PREORDEM(raiz->dir, ++profundidade);
    Andar_na_Arvore_PREORDEM(raiz->esq, ++profundidade);
}


// Função: in-Ordem
// Subárvore esquerda, nó atual e subárvore direita.
void Andar_na_Arvore_INORDEM(struct Node *raiz) {
    if (raiz == NULL) {
        return;
    }
    Andar_na_Arvore_INORDEM(raiz->esq);
    printf("Nome: %s, Mat: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
    Andar_na_Arvore_INORDEM(raiz->dir);
}


// Precisa Fazer Uma função: Pos-Ordem

// Respostas: 
// parada no pai do elemento procurado (gdb) b percorrer_arvores_preordem if raiz != 0 && ((raiz->dir && raiz->dir->info.mat == 17 && raiz->dir->info.turma == 3) || (raiz->esq && raiz->esq->info.mat == 17 && raiz->esq->info.turma == 3))
// Ver o PAI: P *raiz
// elemento procurado (gdb) p raiz->dir->info.nome    
// filho direito do elemento procurado (gdb) p raiz->dir->dir->info.nome 
// filho esquerdo do elemento procurado (gdb) p raiz->dir->esq->info.nome 