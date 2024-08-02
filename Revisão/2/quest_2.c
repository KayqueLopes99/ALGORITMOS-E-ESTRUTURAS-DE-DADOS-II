#include <stdio.h>
// Ano Bissexto - Questão 07.

int funcp(int);
int funcaux(int, int);
int main(){
int raio = funcp(5);
printf("%d\n", raio);
}

int funcp(int n)
{
    return funcaux(n, 1);
}
int funcaux(int n, int acc)
{
    if (n == 0)
    {
        return acc;
    }
    return funcaux(n - 1, acc * n);
}