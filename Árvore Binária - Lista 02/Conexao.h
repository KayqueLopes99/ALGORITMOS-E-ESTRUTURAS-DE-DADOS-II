#ifndef CONEXAO_H
#define CONEXAO_H

// Declarações das funções
struct Node *criarNode(char *nome, int mat, int turma, float nota);
int comparar(struct Info a, struct Info b);
struct Node *inserir(struct Node *raiz, struct Info info);

#endif 
// Usados para evitar inclusões multiplas e previsão de erros. 