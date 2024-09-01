#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 16

typedef struct Dado {
  char nome[20];
  char email[30];
  int matricula;
} dado;

typedef struct Aluno {
  dado *info;
} hashAluno[N];

void initHash(hashAluno);
void print(dado);
void printHash(hashAluno);
int toInt(dado);
int h(dado);
int adicionar(hashAluno hash, dado *A);
dado *criarDado(char *nome, char *email, int mat);
int reverterBits(int, int);

int main() {
  dado d[2];
  d[0] = *criarDado("Kennedy", "kennedy.lopes@ufersa.edu.br", 1);
  d[1] = *criarDado("Kennedy2", "kennedy.lopes@ufersa.edu.br", 2);

  hashAluno hash;
  initHash(hash);

  adicionar(hash, &d[0]);
  adicionar(hash, &d[1]);

  // printHash(hash);
  int x = reverterBits(206, 8);
  printf("%d\n", x);
  return 0;
}

void print(dado A) {
  printf("Aluno: %s\n", A.nome);
  printf("Email: %s\n", A.email);
  printf("Matricula: %d\n", A.matricula);
  int x = h(A);
}

void printHash(hashAluno hash) {
  int i=0;
  for (i = 0; i < N; i++) {
    if (hash[i].info != NULL) {
      printf("Pos: %d\n", i);
      print(*hash[i].info);
    }
  }
}

int toInt(dado A) {
  char *r = A.nome;
  int s = 0, i = 0;
  while (r[i] != '\0') {
    s += r[i++];
  }
  return s;
}

int h(dado A) { return toInt(A) % N; }

void initHash(hashAluno hash) {
  int i=0;
  for (i = 0; i < N; i++) {
    hash[i].info = NULL;
  }
}

int adicionar(hashAluno hash, dado *A) {
  int x = h(*A);
  if (hash[x].info == NULL) {
    hash[x].info = (dado *)malloc(sizeof(dado));
    *(hash[x].info) = *A;
    return 1;
  }
  return 0;
}

dado *criarDado(char *nome, char *email, int mat) {
  dado *d = (dado *)malloc(sizeof(dado));
  strcpy(d->nome, nome);
  strcpy(d->email, email);
  d->matricula = 1;
  return d;
}

int reverterBits(int num, int numBits) {
  int invertido = 0;
  int i=0;
  for (i = 0; i < numBits; i++) {
    invertido = invertido << 1;
    if (num & 1) {
      invertido = (invertido | 1);
    }
    num = num >> 1;
  }
  return invertido;
}