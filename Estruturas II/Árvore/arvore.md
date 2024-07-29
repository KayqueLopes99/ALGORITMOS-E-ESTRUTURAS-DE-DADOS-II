# Árvore I
### Conceito:
-  Uma árvore é uma estrutura de dados hierárquica composta por nós, onde cada nó pode ter zero ou mais filhos. As árvores são amplamente usadas para organizar dados de maneira eficiente para várias operações, como pesquisa, inserção e exclusão.
- Uma árvore finita ( T ) com elementos chamados nós ou vértices. Esta árvore pode ser vazia, conter um valor e ter subárvores no mesmo formato de ( T ).

- Exemplo:
````
      10
     /  \
    5    15
   / \   / \
  3   7 13  17

````

````
        a
      /  \
     c    b
   / \  \  
  d   f  e
 / \   \ 
 g  h   i
````
- C tem os filhos D,E,F.
- I tem o pai F.

## Árvores Ordenadas:
- Se é considerada a ordem entre os filhos de cada nó, a árvore é ordenada.

- Árvores Isomorfas: São consideradas isomorfas, árvores nas quais uma permutação de suas sub-árvores as tornam coincidentes.

- São isomorfas porque a estrutura de ramificação é idêntica, apesar dos valores dos nós serem diferentes.
- Exemplo:
```
      10
     /  \
    20   30
   / \   / \
  40 50 60  70
```

## Árvores Binárias: 
- Uma árvore binária é uma estrutura hierárquica composta por nós, onde cada nó pode ter no máximo dois filhos, chamados "SUBÁRVORES" de filho esquerdo e filho direito, SENDO DIFERENTES.
- A árvore tem um nó especial chamado de raiz, que é o ponto de partida para todas as operações na árvore.

## Terminologia
- **Nó Raiz**: O nó no topo da árvore. É o ponto de partida para qualquer operação na árvore.
- **Nó Folha**: Um nó que não tem filhos.
- **Nó Interno**: Um nó que tem pelo menos um filho.
- **Filho Esquerdo**: O filho que está localizado à esquerda do nó pai.
- **Filho Direito**: O filho que está localizado à direita do nó pai.
- **Altura da Árvore**: O comprimento do caminho mais longo da raiz até um nó folha. É o número máximo de arestas no caminho da raiz até qualquer folha.
- **Nível do Nó**: A profundidade do nó na árvore, com a raiz sendo o nível 0.

## Tipos de Árvores Binárias

### 1. Árvore Binária Completa

- Uma árvore binária é considerada completa se todos os níveis, exceto possivelmente o último, estão totalmente preenchidos, e todos os nós estão o mais à esquerda possível.
```
      1
     / \
    2   3
   / \ / \
  4  5 6  7

```
### 2. Árvore Binária Cheia

Uma árvore binária é cheia se cada nó tem exatamente 0 ou 2 filhos. Nenhum nó tem apenas um filho.
```
        1
       / \
      2   3
     /|   |\
    4 5   6 7
   / \
  8   9

```
### 3. Árvores Estritamente Binárias

Uma árvore estritamente binária é um tipo específico de árvore binária onde cada nó interno tem exatamente dois filhos. Isso implica que todos os nós internos têm exatamente dois filhos  ou (nós sem filhos) não têm filhos. 
```
        1
       / \
      2   3
          | \
          6  7
         / \
        8   9

```
## O processo de busca de dados em árvores
• Feito a partir da raiz na direção de alguma de suas folhas;
• Busca ágil: Árvore com a menor altura possível são desejáveis;
• Se uma árvore T com n > 0 nós é completa, então ela tem altura mínima;
• É possível reordenar folhas para torná-las completas.

## Altura da Árvore: 
- O comprimento do caminho mais longo da raiz até um nó folha. É o número máximo de arestas no caminho da raiz até qualquer folha.


A fórmula \( h = 1 + \lfloor \log_2(n) \rfloor \) pode ser usada para calcular a altura de uma árvore binária, assumindo que a árvore é uma árvore binária completa ou que o número total de nós \( n \) é suficientemente grande. Esta fórmula é baseada na ideia de que a altura máxima de uma árvore binária com \( n \) nós é aproximadamente igual ao logaritmo base 2 de \( n \), arredondado para baixo, mais um.

Aqui está uma explicação detalhada sobre como usar essa fórmula:

### Fórmula para a Altura

A fórmula é:
h = 1 + piso[log_2(n)] 

Onde:
- h  é a altura da árvore.
- n  é o número total de nós na árvore.
- A função piso (ou parte inteira) de x, que arredonda \( x \) para baixo.

### Explicação da Fórmula

1. **Logaritmo Base 2**: O logaritmo base 2 de \( n \) dá uma ideia de quantos níveis podem existir em uma árvore binária se ela estivesse completamente cheia. Em outras palavras, é uma medida do crescimento exponencial necessário para acomodar \( n \) nós.

2. **Função Piso**: A função piso arredonda o valor do logaritmo para o número inteiro mais próximo que é menor ou igual ao valor do logaritmo.

3. **Adicionar 1**: A fórmula adiciona 1 porque a altura da árvore é contada a partir da raiz. Assim, mesmo uma árvore de altura 0 (com apenas um nó) precisa de 1 na fórmula para refletir o nível da raiz.

### Exemplo de Cálculo

Vamos calcular a altura de uma árvore binária com 15 nós usando a fórmula:

1. Calcule o logaritmo base 2 de \( n \):
- n = 15
- log_2(15) = X = 2^X = 15.
- x = 3
- h = 1 + 3 = 4
- Portanto, a altura da árvore binária com 15 nós é 4.

## Árvores Binárias Implementadas com Vetores

Em uma árvore binária representada por um vetor, a estrutura da árvore é mapeada diretamente em um array (vetor). 

1. **Raiz da Árvore**: O nó raiz da árvore é armazenado no índice 0 do vetor.
2. **Filhos dos Nós**:
   - O filho esquerdo de um nó no índice `i` está no índice `2i + 1`.
   - O filho direito de um nó no índice `i` está no índice `2i + 2`.
3. **Pai dos Nós**:
   - O pai de um nó no índice `i` está no índice `(i - 1) / 2`, onde a divisão é inteira.

### Exemplo
```
      1
     / \
    2   3
   / \ / \
  4  5 6  7
```

- Esta árvore pode ser representada no vetor da seguinte forma:

```
Índice: 0  1  2  3  4  5  6
Valor:  1, 2, 3, 4, 5, 6, 7
```

## Implementação de Ponteiros: 
- Utilizar vetores desperdiça memória;
. Complicado para reordenar os nós;
- Ponteiros são mais utilizados.
- Estrutura de dados para um nó da árvore Valor
- Ponteiro para o nó da esquerda;
- Ponteiro para o nó da direita.
- A árvore é apenas um ponteiro para o nó raiz.

## Relebrando:
```
        1<->Raiz
       / \
      2   3<->Nó/Não termanais
     /|   |\
    4 5   6 7<->folhaas/Nos terminais
   / \
  8   9<->folhaas/ Nos terminais 

```
```
                       1
                      / \
 Filho Esquerdo  <-> 2   3 <->Filho Direito
                    / \ / \
                   4  5 6  7
```

```
           1
     /<-> S-Esq \ <->SubDir
    2            3
   / \          / \
  4  5          6  7
```

```
      1  <-> Nivel 0
     / \
    2   3 <-> Nivel 1
   / \ / \
  4  5 6  7 <-> Nivel 2
```
- Altura 3.
-  Uma árvore Binária é o conjunto vazio.
- Um nó conectado a duas árvores binárias.

# Percorrendo os nós PRÉ-ORDEM.

- A travessia pré-ordem de uma árvore binária visita os nós na seguinte ordem: 

1. **Visita o nó atual** = primeiro visita (processa) a raiz.
2. **Percorre a subárvore esquerda**.
3. **Percorre a subárvore direita**.

### Explicação da Travessia Pré-Ordem

1. **Visite o nó atual**: Comece no nó raiz e o visite (processando seu valor).
2. **Percorra a subárvore esquerda**: Passe para o filho à esquerda e repita o processo de visita.
3. **Percorra a subárvore direita**: Após completar a travessia da subárvore esquerda, passe para o filho à direita e repita o processo de visita.

### Exemplo
```
         2
       /   \
      5     7
     / \   /  \ 
    3   8  1   6
       /   \ 
       4    9
```

A travessia pré-ordem seria: **2,5,3,8,4,7,1,9,6**


# PÓS-ORDEM. 
- A travessia pós-ordem de uma árvore binária visita os nós na seguinte ordem:

1. **Percorre a subárvore esquerda**.
2. **Percorre a subárvore direita**.
3. **Visita o nó atual**.

## Exemplo de Árvore

```
         2
       /   \
      5     7
     / \   /  \ 
    3   8  1   6
       /   \ 
       4    9
```
- Ordem: **3, 4, 8, 5, 9, 1, 6, 7, 2**

# IN-ORDEM
Claro! A travessia em ordem (ou **in-order**) de uma árvore binária visita os nós na seguinte ordem:

1. **Percorre a subárvore esquerda**.
2. **Visita o nó atual**.
3. **Percorre a subárvore direita**.



## Exemplo de Árvore

```
         2
       /   \
      5     7
     / \   /  \ 
    3   8  1   6
       /   \ 
       4    9
```
- Ordem:**3, 5, 4, 8, 9, 2, 9, 1, 7, 6**

## Contéudo menos importante:
#### Notações Aritméticas e Árvores Binárias
## Notação Pré-Fixa (Prefixa)
## Notação Pós-Fixa (Suffixa)
## Notação Infixa

## Como Funciona a Travessia em Largura:
- A travessia em largura (ou **traversal em nível**) é uma forma de percorrer todos os nós de uma árvore binária nivel por nível, da esquerda para a direita. 
1. **Comece pela raiz**: Coloque o nó raiz em uma fila.
2. **Visita os nós por níveis**.
3. **Da Esquerda para a Direita**.
# Travessia em Largura:
- A travessia em largura percorre a árvore nivel por nível, da esquerda para a direita.


```
         2
       /   \
      5     7
     / \   /  \ 
    3   8  1   6
       /   \ 
       4    9
```
- Ordem: **2, 5, 7, 3, 8, 1, 6, 4, 9**
         49 
        /  \
      44    50
     /       \
    12        54
      \       / \
      30    51  61
       \           \
       42         68
      /          /  \
     33        59  87
    /           / 
   27           41
