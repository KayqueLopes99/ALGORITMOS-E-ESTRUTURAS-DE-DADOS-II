#include <stdio.h>
#include <stdlib.h>
#define TAM 31 // 2 * 15(primo) = 31.
/*----- Tabela Hash -----*/
/*----- Linear com vetor -----*/

// Função para inicalizar a tabela para vazia.
// Parêmetros t = tabela
void inicializarTabela(int t[])
{
    int i;
    // Percorrer todas as posições.
    for (i = 0; i < TAM; i++)
    {
        t[i] = 0; // Acessamos as posições colocando 0, lembrando que zero não está sendo colocado no cojunto de chaves.
    }
}

// Função hash para associar as posições.
// valor a ser descoberta suas posição.
int funcaoHash(int chave)
{
    // Operação resto da divisão.
    return chave % TAM;
}

// Função para inserir números inteiros.
// Parêmetros t = tabela e valor a ser inserido.
void inserir(int t[], int valor)
{
    int id = funcaoHash(valor); // Vai adicionar a posição ao valor.

    // Enquanto a poisção na tabela for diferente de zero/vazio. Isso significa que tem alguém na posição.
    while (t[id] != 0)
    {
        // Imagine que id = 3, logo 3 + 1 = 4, qual o resto da dicisão de 4/31 é 4, fomos para o indice seguinte.
        id = funcaoHash(id + 1); //
    }
     t[id] = valor; // Insere o valor na posição encontrada.
}

// Função para buscar o inteiro se achar retorna ao interio se não a zero.
// Prâmetros tem t = tabela e a chave que é elemento procurado.
int busca(int t[], int chave)
{
    // Achar o indice.
    int id = funcaoHash(chave);
    // Enquanto for diferente de zero na posição, se sim tem alguém.
    printf("\nIndice Gerado: %d\n", id);
    while (t[id] != 0)
    {
        // É a chave que está nessa posição?
        if (t[id] == chave)
        {
            // se sim, retorna a posição.

            return t[id];
        }
        else
        {                            // se não for o elemento procurado.
            id = funcaoHash(id + 1); // Verificar a posição seguinte.
        }
    }
    return 0; // todo o vetor está vazio.
}

// Função para Impressão.
void imprimir(int t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]); // indice e depois o elemento.
    }

}
int main()
{
    int opcao, valor, retorno, tabela[TAM]; // Tamanho da tabela.
    inicializarTabela(tabela); // inicializar a tabela.
    do{
        printf("\n\t1 - Inserir.");
        printf("\n\t2 - Buscar");
        printf("\n\t3 - Imprimir");
        printf("\n\t0 - Sair");
        printf("\n\tInforme: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\tQual valor deseja Inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tQual valor deseja Buscar? ");
            scanf("%d", &valor);
            retorno = busca(tabela, valor);
            // se for diferente de zero ele foi encontrado
            if(retorno != 0){
                printf("\tValor encontrado: %d\n", retorno);
            }
            else{
                printf("\tValor nao Encontrado!\n");
            }

            break;
        case 3:
            imprimir(tabela);
            break;
        
        default:
            printf("Invalido");
        }

    }while(opcao != 0);
   
    
    return 0;
}