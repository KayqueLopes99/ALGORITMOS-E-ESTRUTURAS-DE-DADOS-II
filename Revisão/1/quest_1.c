#include <stdio.h>
// Ano Bissexto - Questão 07.

int bissexto(int ano);
int main()
{
    int ano = 1900;
    if (bissexto(ano) == 1)
    {
        printf("Bissexto");
    }
    return 0;
}


int bissexto(int ano)
{
    if (ano % 4==0 && ano%100==0)
    {
        if(ano % 400 == 0){
            return 1;
        }
        return 0;
    }
    if(ano%4 == 0){
        return 1;
    }
}