/*Tarefa de Laboratório*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 256
// Encontrar sua matricula dentro do número Pi.
// Usando algoritmos KMP
// Boyer_Moore
// Objetivo: encontar sua matricula na sequncia: 2023011415 dos dígitos de PI.
// Tentar com os últimos: 5,6,7,8,9,10 digitos.
// Limitado a 10.000.000 - 50.000.000.

int BMH(char *T, char *P)
{
    int i, j, k;
    int n = strlen(T);
    int m = strlen(P);
    int d[MAXCHAR];
    // pré-processamento
    for (j = 0; j < MAXCHAR; j++)
    {
        d[j] = m;
    }
    for (j = 1; j < m; j++)
    {
        d[P[j]] = m - j;
    }
    i = m;
    // busca
    while (i <= n)
    {
        k = i;
        j = m;
        while (T[k - 1] == P[j - 1] && j > 0) 
        {
            k--;
            j--;
        }
        if(j == 0){
            return k+1;
        i += d[T[i -1]];

        }
        return -1;

    }