#include <stdio.h>
#include <stdlib.h>

int randomInRange(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void gerarNumerosAleatorios()
{
    int i;
    for (i = 0; i < 100; i++)
    {
        int px = randomInRange(-50, 50);
        int py = randomInRange(-50, 50);
        printf("P = (%d, %d)\n ", px, py);
    }
    printf("\n");
}

int main()
{
    srand(42);
    gerarNumerosAleatorios();
}
