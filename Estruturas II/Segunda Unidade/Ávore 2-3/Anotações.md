# Árvores 2-3
- Em ciência da computação, uma árvore 2-3 é uma árvore em que cada nó interno tem dois ou três filhos e todos os nós externos (folhas) não têm filhos. 
- Resumidamente, árvore 2-3 é uma árvore na qual os nós podem ter até 3 filhos.

```
        [30 | 40]  <- Nivel 1>
      /     |     \  
   [18] [32 | 38] [50]  <- Nivel 2>
   / \   /  |  \    / \  
[5][15][31][35][42][55][44] <- Nivel 2>

- Informações
> [5][15][31][35][42][55][44]: Todos os nós folhas no último nível.
> Neste formato [18]: NÓ simples.
> Neste formato [32 | 38]: NÓ duplo.

```

## Propiedades:
- A árvore 2-3 não binária obedece as seguintes propriedades:
+ Cada nó contem uma ou duas chaves;
+ Cada nó interno tem dois (se tem uma chave), ou três (se tem duas chaves) filhos;
+ Todas as folhas estão no mesmo nível.
- Características:
+ Estrutura alternativa para uma busca eficiente.
+ Existem um grande número de registros;
+ Elementos são procurados em uma faixa de valores.

## Características
- Possuem organização semelhante a uma árvore binária de busca:
+ 1. Os filhos da esquerda são menores que o nó pai;
+ 2. Os filhos da direita são maiores que o nó pai;
+ 3. Os filhos centrais, se existirem, são valores entre as duas chaves do nó pai.

```c
typedef struct No23 {
int chave_esq ;
int chave_dir ;
int num_chaves ;
struct No23 * esq ;
struct No23 * dir ;
struct No23 * central ;
} no23 ;
```

## Busca(raiz, key):
- Busca é similar à busca binária, navegando pela árvore até encontrar ou não a chave.

## Inserção: 
- Inserção envolve encontrar o local correto, inserindo a chave e dividindo o nó se necessário.
- Tipo:
+ Inserção em um nó simples:
- (Inserir o elemento K): Caderno.
+ Inserção em um nó duplo isolado:
- (Inserir o elemento S): Caderno.
+ Inserção em um nó duplo com pai em um nó simples:
- (Inserir o elemento Z): Caderno.
+ Inserção em um nó duplo cujo pai em um nó duplo, sucessivamente até a raiz: 
- (Inserir o elemento D): Caderno.

## Detalhes:
### Inserção em um Nó Simples (Nó com uma chave)

1. **Descrição**: Um nó simples contém apenas uma chave.
2. **Procedimento**: Se o nó simples é uma folha, basta inserir a nova chave diretamente e ordená-las. O nó se torna um nó duplo com duas chaves.
3. **Resultado**: O nó agora contém duas chaves, sem necessidade de divisão.

### Inserção em um Nó Duplo Isolado (Nó com duas chaves)

1. **Descrição**: Um nó duplo contém duas chaves.
2. **Procedimento**: Ao tentar inserir uma nova chave em um nó duplo, ocorre um **overflow**.
   - O nó é dividido em dois nós simples.
   - A chave do meio é promovida ao pai.

### Inserção em um Nó Duplo com Pai em um Nó Simples

1. **Descrição**: O nó duplo que sofre overflow tem um pai que é um nó simples (com uma única chave).
2. **Procedimento**:
   - A chave do meio do nó duplo é promovida ao pai.
   - O pai, que é um nó simples, agora se torna um nó duplo.

### Inserção em um Nó Duplo cujo Pai é um Nó Duplo (Propagação até a Raiz)

1. **Descrição**: O nó duplo que sofre overflow tem um pai que também é um nó duplo.
2. **Procedimento**:
   - A chave do meio é promovida ao pai, que já é um nó duplo.
   - Isso causa um overflow no pai, resultando na divisão do nó pai.
   - A chave do meio do pai é promovida ao nível superior.

## Observações: 
+ As transformações envolvem modificações locais,
portanto tem complexidade constante.
+ Na pior hipótese, temos todos os pais como nós duplos,
a complexidade seria portanto O(h) = O(logn).
+ As transformações preservam as propriedades globais
da árvore. A árvore se mantem em ordem e
balanceada.


## Remoção: 
- Removemos um elemento.
- Remoção de um nó duplo interno: (Remover o 70): Caderno.
- Remoção de um nó folha: (Remover o 100): Caderno.
- Remoção de um nó simples interno: (Remover o 80)
+ Rebaixar os nós ancestrais;
+ Processo contrário a promoção de um termo central.

## Algoritmo da remoção:
- Algoritmo: (Remover o elemento X)
1. Localizar o nó N que contem o X;
2. Se não é folha:
Trocar X por seu sucessor;
Remoção sempre será pelas folhas;
3. Se N contem outro item, apague X, senão:
Tente redistribuir os nós irmãos;
Caso contrário, proceda com a união dos irmãos.
