# Tabela de Dispersão: Tabela HASH.
## Motivação:
```

[.] --> Info 0
[.] --> Info 1
[.] --> Info 2
[.] --> Info 3
[.] --> Info 4
[.] --> Info 5
[.] --> Info 6
[.] --> Info 7
[.] --> Info 8
[.] --> Info 9

Info *v[10]
... 
v[5]

```

+ Geralmente as chaves numéricas são grandes.
````
Aluno
int mat;
char nome[81];
char email[61];
````
+ Uma busca por nome ou matrícula em um vetor pode ser muito dispendioso.
+ Muito armazenamento devem ser previamente (e ociosamente)
disponibilizados.

- Exemplo (Caixa Postal):
+ A primeira letra define a caixa onde a informação é adicionada;
+ O endereçamento é realizado por uma função Hash;
- Função Hash:
```
h : [0, N] → [0, m]
x → h(x)
```

## Conceito de Hash
- Geralmente os métodos de busca realizam a comparação direta do valor da chave com o termo procurado. Com função hash outro termo é buscado devido a uma ordenação das entradas.
+ Conceito: Os registros armazenados em uma tabela são endereçados a partir de uma transformação aritmética sobre a chave de pesquisa;
+ Objetivo: Ter eficiência O(1) nas buscas, inserções e remoções. Para isso a escolha do conjunto [0, m] (imagem da função) deve ser escolhido adequadamente.


## Universo:
```
                          h(x) Função Hash
[U - UNIVERSO DAS CHAVES] -----------------> [T POSIÇÕES NA TABELA]

```
### Inserindo: 
- Tudo Vazio.
- h(k) = mod(k, 16)
- k ∈ {61, 90, 21, 32}

```` 
| 15 | ⌀  |
|----|----|
| 14 | ⌀  |
|----|----|
| 13 | ⌀  |
|----|----|
| 12 | ⌀  |
|----|----|
| 11 | ⌀  |
|----|----|
| 10 | ⌀  |
|----|----|
|  9 | ⌀  |
|----|----|
|  8 | ⌀  |
|----|----|
|  7 | ⌀  |
|----|----|
|  6 | ⌀  |
|----|----|
|  5 | ⌀  |
|----|----|
|  4 | ⌀  |
|----|----|
|  3 | ⌀  |
|----|----|
|  2 | ⌀  |
|----|----|
|  1 | ⌀  |
|----|----|
|  0 | ⌀  |

````
+ Inserir o 61, pelo método.
- Elemento/qtd mod.
- 61/16 = 3 E resto 13.
- h(61) = mod(61, 16) = 13.
```` 
| 15 | ⌀  |
|----|----|
| 14 | ⌀  |
|----|----|
| 13 | 61 | 
|----|----|
| 12 | ⌀  |
|----|----|
| 11 | ⌀  |
|----|----|
| 10 | ⌀  |
|----|----|
|  9 | ⌀  |
|----|----|
|  8 | ⌀  |
|----|----|
|  7 | ⌀  |
|----|----|
|  6 | ⌀  |
|----|----|
|  5 | ⌀  |
|----|----|
|  4 | ⌀  |
|----|----|
|  3 | ⌀  |
|----|----|
|  2 | ⌀  |
|----|----|
|  1 | ⌀  |
|----|----|
|  0 | ⌀  |

````
+ Inserir 90.
- 90/16 = 5 e resto 10.
- h(90) = mod(90, 16) = 10.
```` 
| 15 | ⌀  |
|----|----|
| 14 | ⌀  |
|----|----|
| 13 | 61 | 
|----|----|
| 12 | ⌀  |
|----|----|
| 11 | ⌀  |
|----|----|
| 10 | 90 | 
|----|----|
|  9 | ⌀  |
|----|----|
|  8 | ⌀  |
|----|----|
|  7 | ⌀  |
|----|----|
|  6 | ⌀  |
|----|----|
|  5 | ⌀  |
|----|----|
|  4 | ⌀  |
|----|----|
|  3 | ⌀  |
|----|----|
|  2 | ⌀  |
|----|----|
|  1 | ⌀  |
|----|----|
|  0 | ⌀  |

````

+ Inserir o 21.
- 21/16 = 1 resto 5.
- h(21) = mod(21, 16) = 5.

- 
```` 
| 15 | ⌀  |
|----|----|
| 14 | ⌀  |
|----|----|
| 13 | 61 | 
|----|----|
| 12 | ⌀  |
|----|----|
| 11 | ⌀  |
|----|----|
| 10 | 90 | 
|----|----|
|  9 | ⌀  |
|----|----|
|  8 | ⌀  |
|----|----|
|  7 | ⌀  |
|----|----|
|  6 | ⌀  |
|----|----|
|  5 | 21 |
|----|----|
|  4 | ⌀  |
|----|----|
|  3 | ⌀  |
|----|----|
|  2 | ⌀  |
|----|----|
|  1 | ⌀  |
|----|----|
|  0 | ⌀  |

````

+ Inserir o 32.
- 32/16 = 2 e resto 0.
h(32) = mod(32, 16) = 0
```` 
| 15 | ⌀  |
|----|----|
| 14 | ⌀  |
|----|----|
| 13 | 61 | 
|----|----|
| 12 | ⌀  |
|----|----|
| 11 | ⌀  |
|----|----|
| 10 | 90 | 
|----|----|
|  9 | ⌀  |
|----|----|
|  8 | ⌀  |
|----|----|
|  7 | ⌀  |
|----|----|
|  6 | ⌀  |
|----|----|
|  5 | 21 |
|----|----|
|  4 | ⌀  |
|----|----|
|  3 | ⌀  |
|----|----|
|  2 | ⌀  |
|----|----|
|  1 | ⌀  |
|----|----|
|  0 | 32 |

````

## Endereçamento Direto:
- Quando o universo de chaves U é pequeno, podemos alocar uma tabela com uma posição para cada chave. Ou seja:
- |T| = |U|
- Logo, para cada posição da tabela, que pode ser implementada como um vetor, representa uma chave de U e armazena um elemento ou um ponteiro o elemento.

+ Situação Prática: 
Contudo, geralmente |U| não é pequeno.

**Exemplo:** Matrícula do aluno da UFERSA.

- 10 dígitos.
- |U| = 10^10 = 10 bilhões de combinações.
- O primeiro dígito não pode ser 0 (zero), pois não seriam 10 dígitos.
- Os quatro primeiros dígitos referem-se ao ano. Não existe muitas opções:

    - D14 = {2005, 2006, . . . 2021}

Mesmo assim, restam ainda: 16 ∗ 10^6 = 16 milhões de combinações!


### Dimensão: 
**Dimensão da tabela Hash**

Deve ser escolhido adequadamente para diminuir o número de colisões.  
Costuma ser um número primo.

**Valores aceitáveis:**

- A taxa de ocupação não deve ser maior que 75%.
- Uma taxa menor que 25% é considerada um gasto excessivo de memória.
- **Ideal:** Próximo de 50%.

### Exemplo de tabela Hash:
+ **Tipo `aluno` definido como estrutura e criado tipo `Hash` que é um vetor de ponteiros de `aluno`.**

+ A função `hash` indica onde guardar os dados do aluno em função de sua matrícula.

```c
//  Estrutura.
#define N 255

typedef struct aluno {
    int mat;
    char nome[81];
    char email[41];
    char turma;
} * Hash[N];

// Função .
int hash(int mat) {
    return mat % N;
}
```

### Objetivos para Tabelas de Dispersão
+ Desenvolver as funções de Hash;
+ Compreender como ocorre o processo de colisão;
+ Compreender o tratamento de colisões;
+ Apresentar as melhores estuturas para construção de Tabelas de Dispersão.


# Métodos: 
## Método da divisão
- Fácil, elegante e muito empregado;
- Consiste em determina o resto da divisão entre a chave e
- o tamanho da tabela;
> h(x) = x(chave) % M(Tamanho da Tabela).

+ Alguns critérios para escolha:
- Escolher M de modo que seja um número primo n˜ao pr´oximo a uma potência de 2.
- Escolher M tal que n˜ao possua divisores primos menores do que 20.

## Método da Dobra: 
- Suponha a chave como uma sequência de dígitos escritos num pedaço de papel.
- O método consiste em ”dobrar”esse papel, de maneira que os dígitos se sobreponham.
- Estes devem ser somados sem considerar o ”vai um”.
- Pode ser de 3 em 3 ou  2 em 2 e etc.

```
[2][7][9][3][8][4]

279
483 + 
---
652.

- Obs: 9 + 3 = 12, fica o 2 o 1 não vai.
- Segue em tudo essa tecnica acima.
```
+ 3 digitos = 1000 posições.
+ 2 digitos = 100 posições. 
+ ... 

### Método da dobra/Binário:
- Exemplo: Chave 71 = 0001000111.
````
 0 0 0 1 0 | 0 0  1 1 1 

 0 0 0 1 0
 1 1 1 0 0+
------------
 1 1 1 1 0  = 30

+ Iguais: 0.
+ Diferentes: 1.
````

## Método da Multiplicação:
- Existem algumas variações.
**Variação mais conhecida:** "Meio do quadrado":
- A chave é multiplicada por ela mesma;
- O resultado é armazenado em palavra de memória de b bits;
- O número escolhido para encontrar o endereço-base é retirado desse produto:
  - Descartando os bits excessivos da extrema direita e da extrema esquerda.

+ Exemplo: Chaves do conjunto [0, 127], mapeados para [0, 15].

```
[0, 15] = 16/4 = 4 bits
127 = 2^7 -1
1* = 7^2
2* = 49 = 110001 -> binário.
3* = [1] 1 0 0 0 [1].
4* = 1 0 0 0 = 8.


+ (2^7 -1)^2
+ 2^14 + (-1)2.2^7 + 1 = {0 0 0 0} 0 0 0 1 {1 0 0 1}
-> 0 0 0 1 = 1.
```