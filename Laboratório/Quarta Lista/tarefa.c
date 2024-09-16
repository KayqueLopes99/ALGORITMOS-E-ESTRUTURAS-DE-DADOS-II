/*Tarefa de Laboratório*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encontrar sua matricula dentro do número Pi.
// Usando algoritmos KMP
// Boyer_Moore
// Objetivo: encontar sua matricula na sequncia: 2023011415 dos dígitos de PI.
// Tentar com os últimos: 5,6,7,8,9,10 digitos.
// Limitado a 10.000.000 - 50.000.000.


// Função para calcular o bad character heuristic de Boyer-Moore.
// Essa função  é responsável por criar uma tabela de "caracteres ruins", que ajuda a determinar quantos caracteres o padrão pode ser deslocado ao encontrar um caractere que não corresponde durante a busca.
// str é o padrão que procuramos, size é o tamanho da size é o comprimento da string str e badchar é Um array de inteiros de tamanho 256 da ASCII.
void badCharHeuristic(char *str, int size, int badchar[256]) {
    int i;
    // Inicializa todos os elementos do array badchar com o valor -1.
    // Por que 256? O array tem tamanho 256 porque cobre todos os possíveis valores de um caractere ASCII (que varia de 0 a 255).

    // Resultado: Após essa inicialização, qualquer caractere que não está presente na string str terá um valor -1 na tabela badchar, percorrer e coloca -1.
    for (i = 0; i < 256; i++)
        badchar[i] = -1;
// percorrer o padrão:
// Vamos supor que a string str seja "2023011415" e que o size seja 10 (o número de caracteres na string). O loop fará o seguinte:

/*No início, badchar é inicializado com -1 para todos os 256 elementos.
Para cada caractere na string:
Para o primeiro '2' em "2023011415" (índice 0), badchar['2'] (ou badchar[50], já que o valor ASCII de '2' é 50) será definido como 0.
Para o segundo '0' (índice 1), badchar['0'] (ou badchar[48], já que o valor ASCII de '0' é 48) será definido como 1.
O processo continua, substituindo qualquer valor existente no array badchar com a posição mais recente do caractere.
*/
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

// Função para buscar a matrícula usando Boyer-Moore
// Esta função é projetada para procurar uma string padrão (pat) dentro de uma string de texto (txt) e determinar em quais posições o padrão aparece. Ela também conta o número total de ocorrências.
void searchBoyerMoore(char *txt, char *pat, int *count, int *positions) {
    int m = strlen(pat); // O comprimento da string padrão.
    int n = strlen(txt); // O comprimento da string de texto.

    int badchar[256]; // tabela de ruins
    badCharHeuristic(pat, m, badchar); // inicializa.

    int s = 0;  // s é o deslocamento do padrão com relação ao texto
    *count = 0; //  Contador de ocorrências encontradas.



    // Loop externo: Continua enquanto o padrão pode ser totalmente comparado com o texto (s <= n - m).
    // j: Índice da comparação no padrão, começando do final do padrão e movendo para o início.
    
    while (s <= (n - m)) {
        int j = m - 1;

        // Continua movendo o padrão enquanto os caracteres correspondem
        // Loop interno: Compara os caracteres do padrão com o texto começando do final do padrão. O loop continua enquanto os caracteres corresponderem.
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // Se o padrão estiver presente nesta posição
        if (j < 0) {
            positions[*count] = s;//Armazena a posição onde o padrão foi encontrado.
            (*count)++;
            // Ajusta o deslocamento s. Se ainda há texto suficiente para o próximo padrão, o padrão é movido para alinhar com o próximo caractere relevante;
            s += (s + m < n) ? m - badchar[(int) txt[s + m]] : 1;
        } else {
            s += (1 > j - badchar[(int) txt[s + j]]) ? 1 : j - badchar[(int) txt[s + j]];
        }
    }
}

int main() {
    FILE *file;
    char *buffer;
    long file_size;
    int count = 0;
    int positions[1000];  // Supondo que no máximo 1000 ocorrências

    char *filename = "Pi.txt";
    char *matricula = "3011415";

    // Abre o arquivo em modo leitura binária
    file = fopen(filename, "rb");
    if (!file) {
        perror("Não foi possível abrir o arquivo");
        return 1;
    }

    // Descobre o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Aloca memória para o buffer
    buffer = (char *) malloc(sizeof(char) * (file_size + 1));
    if (!buffer) {
        perror("Falha ao alocar memória");
        fclose(file);
        return 1;
    }

    // Lê o arquivo inteiro no buffer
    fread(buffer, sizeof(char), file_size, file);
    buffer[file_size] = '\0';  // Adiciona o caractere de terminação

    // Fecha o arquivo
    fclose(file);

    // Realiza a busca usando Boyer-Moore
    searchBoyerMoore(buffer, matricula, &count, positions);

    // Imprime o número de ocorrências e as posições
    printf("A matrícula %s aparece %d vezes.\n", matricula, count);
    if (count > 0) {
        int i;
        printf("Posições encontradas:\n");
        for (i = 0; i < count; i++) {
            printf("%d ", positions[i]);
        }
        printf("\n");
    }

    // Libera a memória alocada
    free(buffer);

    return 0;
}
