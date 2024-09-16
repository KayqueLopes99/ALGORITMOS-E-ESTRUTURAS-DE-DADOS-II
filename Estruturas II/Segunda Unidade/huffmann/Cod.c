#include <stdio.h>
#include <stdlib.h>
/*Algoritmo de Huffman*/
// Aula com a parte 2 continuar futuramente.
#define TAM 256

// Parametro é a tabela.
void inicializa_tabela_com_zero(unsigned int tab[])
{
    int i;
    // Colocar zero em cada posição.
    for (i = 0; i < TAM; i++)
    {
        tab[i] = 0;
    }
}

// Preencher.
void preenche_tabela_frequencia(unsigned char texto[], unsigned int tab[])
{
    int i = 0;
    // percorrer o texto até o fim.
    // enquanto não for o fim da string '\0'.
    while (texto[i] != '\0')
    {
        /* code */
        // Pegar um caractere e avançar.
        // Cractere segundo a asci pegando o numero para acessar o vetor.
        tab[texto[i]]++;
        i++;
    }
}

// Imprime.
void imprime_tabela_frenquencia(unsigned int tab[])
{
    int i;
    printf("========= TABELA DE FREQUÊNCIA ========\n");
    for (i = 0; i < TAM; i++)
    {
        // Indice, qauntidade, caractere na posição representado por esse número.
        // Condição so para imprimir os que tem.
        if (tab[i] > 0){
        printf("\t%d = %u = %c\n", i, tab[i], i);
    }
    }
}

int main()
{

    // Unsigned para só armazena valores positivos, isso é necessário para ASCII 0-255.
    unsigned char texto[] = "Vamos aprender a programar";
    // Um vetor de inteiro + com tamanho 256.
    unsigned int tabela_frenquencia[TAM];

    inicializa_tabela_com_zero(tabela_frenquencia);
    preenche_tabela_frequencia(texto, tabela_frenquencia);
    imprime_tabela_frenquencia(tabela_frenquencia);

    return 0;
}

/*
OBS:
o do-while sempre executa o bloco de comandos pelo menos uma vez, enquanto o while só executa se a condição for verdadeira.
*/