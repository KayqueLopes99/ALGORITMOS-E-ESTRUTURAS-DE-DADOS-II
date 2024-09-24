#include "..\include\medicamentos.h"

int main()
{
    Medicamento *raiz = NULL;
    int op;
    raiz = inicializarBaseDados(raiz);
    char nome[100];
    float preco;
    int estoque;

    printf("\n---------------------------------------\n");
    printf("\033[1;34mSeja Bem vindo a Farmatech\033[0m\n");
    printf("---------------------------------------\n");
    do
    {
        printf("---------------------------------------\n");
        printf("\033[1;34m---- Menu de opcoes ----\033[0m\n");
        printf("---------------------------------------\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Remover cliente\n");
        printf("3 - Buscar cliente\n");
        printf("4 - Imprimir informacoes do cliente\n");
        printf("---------------------------------------\n");
        printf("5 - Cadastrar de medicamento\n");
        printf("6 - Buscar medicamento\n");
        printf("7 - Imprimir medicamentos\n");
        printf("---------------------------------------\n");
        printf("8 - Cadastrar receita\n");
        printf("9 - Buscar Receita\n");
        printf("10 - Imprimir Receitas.\n");
        printf("0 - Sair\n");
        printf("---------------------------------------\n");
        op = lerOpcao();

        if (op == -1)
        {
            printf("---------------------------------------\n");
            continue;
        }

        switch (op)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            printf("Informe o nome do medicamento: ");
            scanf(" %[^\n]s", nome);

            if (!validaNome(nome))
            {
                break;
            }
            printf("Informe o preco: ");
            scanf("%f", &preco);

            printf("Informe o estoque: ");
            if ((scanf(" %d", &estoque)) != 1)
            {
                printf("\033[1;31mPermitido apenas numeros.\033[0m\n");
                while (getchar() != '\n')
                    ;
            }

            raiz = cadastroMedicamento(raiz, nome, preco, estoque);
            printf("Medicamento cadastrado com sucesso!\n");

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;

        case 0:
            printf("\033[1;34mSaindo do sistema. Volte sempre!\033[0m\n");

            break;
        default:
            printf("\033[1;31mOpcao invalida! Por favor, escolha uma opcao valida.\033[0m\n");
            break;
        }
    } while (op != 0);
    return 0;
}
