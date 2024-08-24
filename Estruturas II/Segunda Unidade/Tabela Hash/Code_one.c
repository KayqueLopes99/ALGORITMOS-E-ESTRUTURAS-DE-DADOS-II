#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define N 255

typedef struct Aluno{
    char nome[20];
    char email[30];
    int matricula;
} *hashAluno[N];

void print(struct Aluno);
int toInt(struct Aluno);//Converter o nome do aluno em
int h(struct Aluno);
int add(hashAluno hash, struct Aluno A);

int main(){
    hashAluno hash;
    int i;
    for(i=0; i<N; i++){
        hash[i] = (struct Aluno*)malloc(sizeof(struct Aluno));
        hash[i] = 0;
    }
    strcpy((*hash[0]).nome, "Kennedy2");
    strcpy(hash[0]->email, "kennedy.lopes@ufersa.edu.br");
    hash[0]->matricula = 1;
    print(*hash[0]);
    toInt(*hash[0]);
    add(hash, *hash[0]);
}

void print(struct Aluno A){
    printf("Aluno: %s\n", A.nome);
    printf("Email: %s\n", A.email);
    printf("Matricula: %d\n", A.matricula);
    int x = h(A);
}

int toInt(struct Aluno A){
    char* r = A.nome;
    int s = 0, i = 0;
    while (r[i] != '\0'){
        s += r[i++];
    }
    return s;
}

int h(struct Aluno A){
    return toInt(A) % N;
}

int add(hashAluno hash, struct Aluno A){
    int x = h(A);
    if(hash[x] == 0){
        *hash[x] = A;
        return 1;
    }
    return 0;
}