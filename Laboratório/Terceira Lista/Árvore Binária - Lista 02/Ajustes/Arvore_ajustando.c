#include "Conexao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Info {
    /* Informações */
    char nome[100];
    int mat;
    int turma;
    float nota;
};

struct Node {
    struct Info info;
    struct Node *esq;
    struct Node *dir;
};

struct Node *criarNode(char *nome, int mat, int turma, float nota);
int comparar(struct Info a, struct Info b);
struct Node *inserir(struct Node *raiz, struct Info info);

int main(void) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    struct Node *raiz = criarNode("Kayque", 3, 1, (float)(rand() % 100) / 10.0);

    struct Info info_satur;
    strcpy(info_satur.nome, "Samuel");
    info_satur.mat = 4;
    info_satur.turma = 1;
    info_satur.nota = (float)(rand() % 100) / 10.0;
    
    raiz = inserir(raiz, info_satur);

    return 0;
}

struct Node *criarNode(char *nome, int mat, int turma, float nota) {
    struct Node *novoNode = (struct Node *)malloc(sizeof(struct Node));
    if (novoNode == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    strcpy(novoNode->info.nome, nome);
    novoNode->info.mat = mat;
    novoNode->info.turma = turma;
    novoNode->info.nota = nota;
    novoNode->esq = NULL;
    novoNode->dir = NULL;
    return novoNode;
}

int comparar(struct Info a, struct Info b) {
     int nomeComp = strcmp(a.nome, b.nome);
    if (nomeComp != 0) {
        return nomeComp;
    }
    if (a.mat != b.mat) {
        return a.mat - b.mat;
    }
    return a.turma - b.turma;
}



struct Node *inserir(struct Node *raiz, struct Info info) {
     if (raiz == NULL) {
        return criarNode(info.nome, info.mat, info.turma, info.nota);
    } else if (comparar(info, raiz->info) < 0) {
        raiz->esq = inserir(raiz->esq, info);
    } else {
        raiz->dir = inserir(raiz->dir, info);
    }
    return raiz;
}
