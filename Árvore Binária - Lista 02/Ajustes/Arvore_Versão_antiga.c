#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Info
{
    /* Informações */
    char nome[100];
    int mat;
    int turma;
    float nota;
};

struct Node
{
    struct Info info;
    struct Node *esq;
    struct Node *dir;
};

struct Node *criarNode(char *nome, int mat, int turma, float nota);
int comparar(struct Info a, struct Info b);


int main(void)
{
    struct Node *raiz = criarNode("Kayque", 3, 1, rand() % 10);
    //Antes:  struct Node *nodeSa = criarNode("Samuel", 4, 1, rand() % 10);

    struct Info Info_satur;
    strcpy(Info_satur.nome, "Samuel");
    Info_satur.mat = 4;
    Info_satur.turma = 1;
    Info_satur.nota = rand() % 10;
    raiz = inserir(raiz, Info_satur);

    return 0;
}

struct Node *criarNode(char *nome, int mat, int turma, float nota)
{
    struct Node *raiz = (struct Node *)malloc(sizeof(struct Node));

    strcpy(raiz->info.nome, nome); // \0
    raiz->info.mat = mat;
    raiz->info.turma = turma;
    raiz->info.nota = nota;
    raiz->esq = NULL;
    raiz->dir = NULL;
    return raiz;
    
}

struct Node *criarNode(char *nome, int mat, int turma, float nota)
{
    struct Node *raiz = (struct Node *)malloc(sizeof(struct Node));

    strcpy(raiz->info.nome, nome); // \0
    raiz->info.mat = mat;
    raiz->info.turma = turma;
    raiz->info.nota = nota;
    
}

int comparar(struct Info a, struct Info b){
    return strcmp(a.nome, b.nome);
}

struct Node *inserir(struct Node *raiz, struct Info info) {
    if (raiz == NULL) {
        raiz = criarNode(info.nome, info.mat, info.turma, info.nota);
    } else if (comparar(raiz->info, info) > 0) {
        raiz->esq = inserir(raiz->esq, info);
    } else if (comparar(raiz->info, info) < 0) {
        raiz->dir = inserir(raiz->dir, info);
    }
    return raiz;
}