#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para calcular o bad character heuristic de Boyer-Moore
void badCharHeuristic(char *str, int size, int badchar[256]) {
    int i;
    for (i = 0; i < 256; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

// Função para buscar a matrícula usando Boyer-Moore e contar comparações
void searchBoyerMoore(char *txt, char *pat, int *count, int *positions, int *comparisons) {
    int m = strlen(pat); // Comprimento da string padrão
    int n = strlen(txt); // Comprimento da string de texto

    int badchar[256]; // Tabela de bad character
    badCharHeuristic(pat, m, badchar); // Inicializa a tabela

    int s = 0;  // Deslocamento do padrão com relação ao texto
    *count = 0; // Contador de ocorrências encontradas
    *comparisons = 0; // Contador de comparações realizadas

    // Loop externo
    while (s <= (n - m)) {
        int j = m - 1;

        // Loop interno: compara o padrão com o texto
        while (j >= 0 && pat[j] == txt[s + j]) {
            j--;
            (*comparisons)++; // Incrementa comparações para cada caractere que corresponde
        }

        // Se o padrão estiver presente nesta posição
        if (j < 0) {
            positions[*count] = s; // Armazena a posição onde o padrão foi encontrado
            (*count)++;
            // Ajusta o deslocamento s
            s += (s + m < n) ? m - badchar[(int) txt[s + m]] : 1;
        } else {
            // Incrementa comparações para cada caractere que não corresponde
            (*comparisons)++;
            s += (1 > j - badchar[(int) txt[s + j]]) ? 1 : j - badchar[(int) txt[s + j]];
        }
    }
}

int main() {
    FILE *file;
    char *buffer;
    long file_size;
    int count = 0;
    int positions[1000];  // Supondo no máximo 1000 ocorrências
    int comparisons = 0;  // Variável para contar comparações

    char *filename = "Pi.txt";
    char *matricula = "3011415";

    // Abre o arquivo em modo leitura binária
    file = fopen(filename, "rb");
    if (!file) {
        printf("Não foi possível abrir o arquivo");
        return 1;
    }

    // Descobre o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Aloca memória para o buffer
    buffer = (char *) malloc(sizeof(char) * (file_size + 1));
    if (!buffer) {
        printf("Falha ao alocar memória");
        fclose(file);
        return 1;
    }

    // Lê o arquivo inteiro no buffer
    fread(buffer, sizeof(char), file_size, file);
    buffer[file_size] = '\0';  // Adiciona o caractere de terminação

    // Fecha o arquivo
    fclose(file);

    // Realiza a busca usando Boyer-Moore
    searchBoyerMoore(buffer, matricula, &count, positions, &comparisons);

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

    // Imprime o número de comparações realizadas
    printf("Total de comparações realizadas: %d\n", comparisons);

    // Libera a memória alocada
    free(buffer);

    return 0;
}
