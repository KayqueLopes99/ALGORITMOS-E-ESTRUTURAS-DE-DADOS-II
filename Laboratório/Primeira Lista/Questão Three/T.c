#include <stdio.h>

// Funcao recursiva para verificar se um numero e primo
int ehPrimoRecursivo(int n, int i)
{
    if (n <= 2)
    {
        return (n == 2);
    }

    if (n % i == 0)
    {
        return 0;
    }
// Para não precisar verificar o restantante quando ele já é primo.
    if (i * i > n)
    {
        return 1;
    }

    return ehPrimoRecursivo(n, i + 1);
}

// Funcao para imprimir numeros primos em um intervalo
void imprimirPrimosIntervalo(int inicio, int fim)
{
    if (inicio > fim)
    {
        return;
    }

    if (ehPrimoRecursivo(inicio, 2))
    {
        printf("%d ", inicio);
    }

    imprimirPrimosIntervalo(inicio + 1, fim);
}
int main()
{
    int inicio, fim;

    printf(" Digite o inicio do intervalo : ");
    scanf("%d", &inicio);

    printf(" Digite o fim do intervalo : ");
    scanf("%d", &fim);

    printf(" Numeros primos entre %d e %d: ", inicio, fim);
    imprimirPrimosIntervalo(inicio, fim);
    printf("\n");

    return 0;
}
