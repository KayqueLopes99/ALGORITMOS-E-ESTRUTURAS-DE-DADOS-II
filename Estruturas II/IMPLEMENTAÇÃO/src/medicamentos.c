#include "..\include\medicamentos.h"

struct info
{
    char nome[100];
    float preco;
    int estoque;
};

struct medicamento
{
    Info info;
    Medicamento *dir;
    Medicamento *esq;
    int altura;
};

/*
Retorna o maior dentre dois valores a,b ->altura de dois nós da árvore.
- Determinar a altura maior entre duas subárvores durante o cálculo da altura de um nó e é frequentemente empregada para garantir o balanceamento da árvore.
*/
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/*A primeira linha da função verifica se o ponteiro node é NULL. Isso é importante porque em uma árvore, um ponteiro NULL pode representar uma ausência de nó, como em um filho de uma folha ou um nó inexistente.

Se o nó não é NULL, a função retorna o valor armazenado no campo altura do nó. Este campo representa a altura do nó na árvore. */
int altura(Medicamento *node)
{
    if (node == NULL)
        return 0;
    return node->altura;
}

// FB = HESQUERDA- HDIREIRA.
// Retornando o resultado.
int fatorBalanco(Medicamento *node)
{
    if (node == NULL)
        return 0;
    return (altura(node->esq) - altura(node->dir));
}

// Ponteiro para o nó raiz da subárvore que precisa ser rotacionada com  fb positivo.
Medicamento *rotacaoDir(Medicamento *root)
{
    // t1 é o filho esquerdo de root. Esse nó se tornará a nova raiz após a rotação.
    // t2 é o filho direito de t1. Esse nó se tornará o novo filho esquerdo de root após a rotação.
    Medicamento *t1 = root->esq;
    Medicamento *t2 = t1->dir;
    /*t1->dir = root: O nó t1 (novo raiz) passa a ter o nó root como seu filho direito.
    root->esq = t2: O nó root passa a ter o nó t2 como seu filho esquerdo. t2 pode ser NULL ou uma subárvore, dependendo da estrutura da árvore.
    */
    t1->dir = root;
    root->esq = t2;
    /*
    root->esq: Após a rotação, o filho esquerdo de root pode ter mudado, e o nó root agora pode ter uma nova subárvore esquerda.
    root->dir: A subárvore direita de root pode ter sido movida para t1->dir. Portanto, sua altura pode ser recalculada corretamente com o valor da altura atual.
    */
    // +1 : Inclui o Próprio Nó.
    root->altura = 1 + max(altura(root->esq), altura(root->dir));

    // t1->esq: A subárvore esquerda de t1 antes da rotação pode ser qualquer coisa, e depois da rotação, pode ter mudado.
    // t1->dir: O filho direito de t1 (que agora é root) pode precisar de atualização.

    t1->altura = 1 + max(altura(t1->esq), altura(t1->dir));

    return t1; // Retorno da Nova Raiz:
}

Medicamento *rotacaoEsq(Medicamento *root)
{
    // Medicamento *root: Ponteiro para o nó que precisa de reequilíbrio, fb negativo.

    /*
    t1 é o filho direito de root, que se tornará a nova raiz após a rotação.
t2 é o filho esquerdo de t1, que será movido para a nova subárvore direita de root.
    */
    Medicamento *t1 = root->dir;
    Medicamento *t2 = t1->esq;
    /*
t1->esq = root: O nó t1 se torna a nova raiz e tem root como seu filho esquerdo.
root->dir = t2: O nó root passa a ter t2 como seu novo filho direito.
    */
    t1->esq = root;
    root->dir = t2;
    /*
    Altura do Nó root:

    root->altura = 1 + max(altura(root->esq), altura(root->dir));
    A altura de root é recalculada como 1 (para incluir o próprio nó) mais a altura máxima entre suas novas subárvores esquerda e direita.
    Altura do Nó t1:

    t1->altura = 1 + max(altura(t1->esq), altura(t1->dir));
    A altura de t1 é recalculada da mesma forma, considerando suas novas subárvores esquerda e direita.
    */
    root->altura = 1 + max(altura(root->esq), altura(root->dir));
    t1->altura = 1 + max(altura(t1->esq), altura(t1->dir));

    return t1;
}

// Medicamento *root: Um ponteiro para o nó, que é a posição onde o novo nó será criado.
Medicamento *criaNo(Medicamento *root, char *nome, float preco, int estoque)
{
    // Aloca memória para um novo nó da estrutura Medicamento.
    //  O tipo de retorno de malloc é convertido para Medicamento *.
    root = (Medicamento *)malloc(sizeof(Medicamento));
    strcpy(root->info.nome, nome);
    /*
    strcpy é usado para copiar o nome do medicamento para o campo nome do novo nó.
O preço e o estoque são diretamente atribuídos aos campos preco e estoque do novo nó.
    */
    root->info.preco = preco;
    root->info.estoque = estoque;

    /*
    root->altura = 1: Define a altura inicial do nó como 1. Em uma árvore AVL, um novo nó é inicialmente uma folha, então sua altura é 1.
root->dir = NULL e root->esq = NULL: Inicializa os ponteiros para os filhos direito e esquerdo como NULL, indicando que o nó não tem filhos ainda.
    */
    root->altura = 1;
    root->dir = NULL;
    root->esq = NULL;
    return root; // retorna o ponteiro para o no criado.
}

//  Ela também é responsável por manter a árvore balanceada após a inserção, aplicando rotações quando necessário para manter as propriedades da árvore AVL.
// Medicamento *root Este é um ponteiro para um nó da árvore AVL. Ele representa a raiz da subárvore na qual o novo medicamento será inserido.
Medicamento *insereNo(Medicamento *root, char *nome, float preco, int estoque)
{
    /*
Como Funciona a Recursividade
Caso Base:

Quando root é NULL, significa que encontramos o local apropriado na árvore para inserir o novo medicamento.

*/
    if (root == NULL)
    {
        // Se a árvore estiver vazia (ou se estamos em uma folha), criamos um novo nó usando criaNo e o retornamos.
        root = criaNo(root, nome, preco, estoque);
        return root;
    }
    /*
    Compara o nome do medicamento com o nome no nó atual (root->info.nome):
    Se o nome for menor, a inserção é feita na subárvore esquerda (root->esq).
    Se o nome for maior, a inserção é feita na subárvore direita (root->dir).
    Se o nome for igual, o produto já está cadastrado e não há inserção.
    Vai colocando em ordem alfabetica comparando os nomes
    */

    if (strcmp(nome, root->info.nome) < 0)
    {
        /*
        Recursão à Esquerda:

Se strcmp(nome, root->info.nome) < 0, isso significa que o nome do novo medicamento é menor do que o nome do medicamento no nó atual (root->info.nome).
Nesse caso, a função recursivamente chama insereNo para a subárvore esquerda (root->esq).

A função insereNo continua sendo chamada recursivamente até encontrar um NULL na subárvore esquerda onde o novo nó deve ser inserido.

        */
        root->esq = insereNo(root->esq, nome, preco, estoque);
    }
    else if (strcmp(nome, root->info.nome) > 0)
    {
        /*
        Recursão à Direita:

Se strcmp(nome, root->info.nome) > 0, isso significa que o nome do novo medicamento é maior do que o nome do medicamento no nó atual (root->info.nome).
Nesse caso, a função recursivamente chama insereNo para a subárvore direita (root->dir). Isso é feito com o seguinte

A função insereNo continua sendo chamada recursivamente até encontrar um NULL na subárvore direita onde o novo nó deve ser inserido.
        */
        root->dir = insereNo(root->dir, nome, preco, estoque);
    }
    else
    {
        // Se o nome for igual, o produto já está cadastrado e não há inserção.
        printf("produto ja cadastrado");
        return root;
    }

    root->altura = 1 + max(altura(root->esq), altura(root->dir));
    // Calcula o fator de balanceamento (fb) do nó atual para verificar se a árvore está desbalanceada.
    int fb = fatorBalanco(root);
    /*
    fb > 1: O nó está desbalanceado para a esquerda (a subárvore esquerda é mais alta).
strcmp(nome, root->esq->info.nome) < 0: O nome do novo medicamento é menor que o nome no nó da subárvore esquerda.
Descrição: Isso indica um caso de desbalanceamento "à esquerda-esquerda". A árvore está desbalanceada porque há uma inserção na subárvore esquerda da subárvore esquerda. Para corrigir isso, uma rotação à direita (rotacaoDir) é necessária.
    */
    if (fb > 1 && strcmp(nome, root->esq->info.nome) < 0)
    {

        return rotacaoDir(root);
    }

    if (fb < -1 && strcmp(nome, root->dir->info.nome) > 0)
    {
        /*
        fb < -1: O nó está desbalanceado para a direita (a subárvore direita é mais alta).
strcmp(nome, root->dir->info.nome) > 0: O nome do novo medicamento é maior que o nome no nó da subárvore direita.
Descrição: Isso indica um caso de desbalanceamento "à direita-direita". A árvore está desbalanceada porque há uma inserção na subárvore direita da subárvore direita. Para corrigir isso, uma rotação à esquerda (rotacaoEsq) é necessária.
        */
        return rotacaoEsq(root);
    }

    if (fb > 1 && strcmp(nome, root->esq->info.nome) > 0)
    {
        /*
        fb > 1: O nó está desbalanceado para a esquerda.
strcmp(nome, root->esq->info.nome) > 0: O nome do novo medicamento é maior que o nome no nó da subárvore esquerda.
Descrição: Isso indica um caso de desbalanceamento "à esquerda-direita". A árvore está desbalanceada porque houve uma inserção na subárvore direita da subárvore esquerda. Primeiro, uma rotação à esquerda na subárvore esquerda (rotacaoEsq) é feita, seguida por uma rotação à direita (rotacaoDir) na raiz do subárvore afetada.
        */
        root->esq = rotacaoEsq(root->esq);
        return rotacaoDir(root);
    }

    if (fb < -1 && strcmp(nome, root->dir->info.nome) < 0)
    {
        /*
        fb < -1: O nó está desbalanceado para a direita.
strcmp(nome, root->dir->info.nome) < 0: O nome do novo medicamento é menor que o nome no nó da subárvore direita.
Descrição: Isso indica um caso de desbalanceamento "à direita-esquerda". A árvore está desbalanceada porque houve uma inserção na subárvore esquerda da subárvore direita. Primeiro, uma rotação à direita na subárvore direita (rotacaoDir) é feita, seguida por uma rotação à esquerda (rotacaoEsq) na raiz do subárvore afetada.
        */
        root->dir = rotacaoDir(root->dir);
        return rotacaoEsq(root);
    }
    // Após a inserção e possíveis rotações, retorna o ponteiro para a raiz da subárvore.
    return root;
}

// Medicamento *root: Ponteiro para um nó da árvore AVL (Medicamento).
Medicamento *cadastroMedicamento(Medicamento *root, char *nome, float preco, int estoque)
{
    // Inserir o novo medicamento na árvore AVL.
    root = insereNo(root, nome, preco, estoque);

    FILE *data = fopen("data/medicamentos.txt", "a");
    if (data == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return root;
    }
    // Escrever as informações do medicamento no arquivo.
    fprintf(data, "%s\t%.2f\t%d\n", nome, preco, estoque);

    fclose(data);
    //  Retornar a raiz da árvore AVL atualizada.
    return root;
}

Medicamento *inicializarBaseDados(Medicamento *root)
{
    // Abrir o arquivo medicamentos.txt no modo de leitura ("r").
    FILE *data = fopen("data/medicamentos.txt", "r");
    if (data == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return root;
    }
    int caractere;
    int qtdMed = 0;
    /*
    Como Funciona: fgetc lê o arquivo caractere por caractere. Cada vez que um caractere de nova linha ('\n') é encontrado, o contador qtdMed é incrementado. Esse contador será usado para saber quantas linhas (e, portanto, quantos medicamentos) precisam ser lidas e processadas.
    */
    while ((caractere = fgetc(data)) != EOF)
    {
        if (caractere == '\n')
        {
            qtdMed++;
        }
    }
// Objetivo: Reposicionar o ponteiro de leitura do arquivo para o início e ler os dados de cada linha.
//rewind(data) reinicializa o ponteiro de leitura do arquivo data para o começo do arquivo. Isso é necessário porque, após contar o número de linhas.
    rewind(data);
    int i = 0;
    while (i < qtdMed)
    // O loop irá executar qtdMed vezes, uma para cada linha do arquivo.
    {
        Info temp; // Declara uma variável temp do tipo Info para armazenar os dados lidos da linha atual.
        // temp é para não perder os dados durante a leitura 
        if (fscanf(data, "%[^\t]\t%f\t%d\n", temp.nome, &temp.preco, &temp.estoque) == 3)
        {
            root = insereNo(root, temp.nome, temp.preco, temp.estoque);
        }
        else
        {
            fprintf(stderr, "Erro ao ler os dados do medicamento na linha %d\n", i + 1);
        }
        i++;
    }
    fclose(data);

    return root;
}



int lerOpcao() {
    char opcao[10];
    int i;

    printf("\033[1;34mDigite a opcao desejada:\033[0m\n");
    scanf("%s", opcao);

    // Verifica se todos os caracteres são dígitos
    for (i = 0; opcao[i] != '\0'; i++) {
        if (!isdigit(opcao[i])) {
            printf("\033[1;31mOpcao invalida. Informe um numero correspondente com as opcoes do menu.\033[0m\n");
            return -1;
        }
    }

    // Converte a string para inteiro
    int escolha = atoi(opcao);
    if (escolha < 0 || escolha > 6) {  // Ajuste o intervalo conforme o seu menu
        printf("\033[1;31mOpcao invalida! Por favor, escolha uma opçao valida.\033[0m\n");
        return -1; 
    }

    return escolha;
}

int validaNome(char *nome)
{
    int i; 
    int espacamento = 1; // Flag para indicar se o próximo caractere pode ser o início de uma nova palavra

    // Percorre cada caractere da string
    for (i = 0; nome[i]; i++)
    {
        // Verifica se o caractere é alfabético ou um espaço
        if (!isalpha(nome[i]) && nome[i] != ' ')
        {
            printf("\033[1;31mO nome deve conter apenas letras.\033[0m\n"); 
            return 0; 
        }

        // Se o caractere segue um espaço ou é o início da string, deve ser uma letra maiúscula
        if (espacamento && !isupper(nome[i])) 
        {
            printf("\033[1;31mA primeira letra do nome deve ser maiuscula, tente novamente.\033[0m\n"); 
            return 0; 
        }

        if (nome[i] == ' ')
        {
            espacamento = 1; 
        }
        else
        {
            espacamento = 0; 
        }
    }

    return 1; 
}
