// Comandos GDB:
// b inserir
// b 102 ou main.
// run
// p *raiz
// p*raiz ->dir
// p*raiz ->esq
// p *raiz->dir->dir...
#include <stdio.h>
#include <stdlib.h>

// Estrutura Nó.
typedef struct No {
  int chave; // Informação a ser inserida.
  // Dois Ponteiros para as subárvore.
  struct No *esq;
  struct No *dir;
  int altura; // Pra a Altura.
} No;

// Retorna a altura de um nó ou -1 caso ele seka null.
int altura(No *n) {
  if (n == NULL)
    return 0;
  return n->altura;
}
/*
Retorna o maior dentre dois valores a,b ->altura de dois nós da árvore.
*/
// Recebe o parâmetro de duas subárvores.
 // Se a for maior b retorna a A se não retorna a B.
int maximo(int a, int b) { return (a > b) ? a : b; }

/*
Função que cria um novo nó.
chave -> valor a ser inserido no nó.
Retorna: o endereço do nó criado.
*/
// Recebe o elemento a ser inserido.
No *novoNo(int chave) {
  // Aloco memória para o novo nó
  No *no = (No *)malloc(sizeof(No));
  no->chave = chave; // coloca o elemento.
  no->esq = NULL;
  no->dir = NULL;
  no->altura = 1; // altura do nó folha.
  return (no); // Retorno do Ponteiro para o Nó Criado.
}


// função para a Rotação à Direita.
No *rotacaodir(No *y) {
  No *x = y->esq;
  No *aux = x->dir;

  x->dir = y;
  y->esq = aux;

  y->altura = maximo(altura(y->esq), altura(y->dir)) + 1;
  x->altura = maximo(altura(x->esq), altura(x->dir)) + 1;

  return x;
}

// função para a rotação à esquerda.
// Ponteiro para o nó desbalanceado. 
No *rotacaoesq(No *x) {
  No *y = x->dir;
  No *aux = y->esq;

  y->esq = x;
  x->dir = aux;

  x->altura = maximo(altura(x->esq), altura(x->dir)) + 1;
  y->altura = maximo(altura(y->esq), altura(y->dir)) + 1;

  return y;
}

// Calcula e retorna o fator de balanceamento de um nó.
int obterBalanceamento(No *n) {
  if (n == NULL) // se tá vazio.
    return 0;
  // FB = HESQUERDA- HDIREIRA.
  // Retornando o resultado.
  return altura(n->esq) - altura(n->dir);
}
// Função de inserir balanceado
No *inserir(No *no, int chave) {
  if (no == NULL)
    return (novoNo(chave));

  if (chave < no->chave)
    no->esq = inserir(no->esq, chave);
  else if (chave > no->chave)
    no->dir = inserir(no->dir, chave);
  else {
    return no;
  }

  no->altura = 1 + maximo(altura(no->esq), altura(no->dir));

  int balanceamento = obterBalanceamento(no);

  if (balanceamento > 1 && chave < no->esq->chave)
    return rotacaodir(no);

  if (balanceamento < -1 && chave > no->dir->chave)
    return rotacaoesq(no);

  if (balanceamento > 1 && chave > no->esq->chave) {
    no->esq = rotacaoesq(no->esq);
    return rotacaodir(no);
  }
  if (balanceamento < -1 && chave < no->dir->chave) {
    no->dir = rotacaodir(no->dir);
    return rotacaoesq(no);
  }
  return no;
}

void preOrdem(No *raiz) {
  if (raiz != NULL) {
    printf("%d ", raiz->chave);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
  }
}

int main() {
  No *raiz = NULL;
  raiz = inserir(raiz, 10);
  raiz = inserir(raiz, 20);
  raiz = inserir(raiz, 30);
  raiz = inserir(raiz, 40);
  raiz = inserir(raiz, 50);
  raiz = inserir(raiz, 60);
  raiz = inserir(raiz, 55);

  printf("Preordem da árvore AVL é: \n");
  preOrdem(raiz);

  return 0;
}