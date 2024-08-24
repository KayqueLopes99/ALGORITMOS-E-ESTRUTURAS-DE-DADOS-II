# Heap - Lista de Prioridades.
## Definição: 
- Representa uma tabela, na qual cada um de seus dados está
associado a uma prioridade;
- Objetivo: Descrever uma estrutura de dados que realize as
operações abaixo eficientemente:
- Seleção do elemento de maior prioridade;
- Inserção de um elemento com prioridade específica;
- Remoção do dado de maior prioridade;
- Alteração de prioridade de um dado.

## Prioridades: 
- Algumas aplicações precisam recuperar rapidamente um dado de maior prioridade.
- Exemplo: Lista de tarefas
* A cada momento, deve-se executar a tarefa com maior prioridade;
* Selecionar a tarefa mais prioritária de uma lista e retirá-la da lista;
* Prioridades podem mudar;
* Novas tarefas podem chegar e precisam ser acomodadas.
- Nova estrutura idealizada:
* Os dados possuem prioridades de acesso;
* Essa prioridade modifica com o decorrer do tempo;
* Seria interessante manter o dado mais acessado em
posição de destaque.

## Complexidades em Lista:
### Não-Ordenada:
- Seleção: O(n), pois percorre a tabela inteira. 
- inserção: O(1), pois coloca em qualquer local.
- Remoção: O(n), pois vamos percorrer tudo até achar.
- Alteração: O(n), pois vamos ter que procurar.
- Construção: O(n), vamos colocando os elementos. 
### Ordenada: 
- Seleção: O(1), pois já sabemos parte do local. 
- inserção: O(n), pois colocar em um determinada parte, passando pelos demais elementos.
- Remoção: O(1), pois já sabemos o local, segundo a prioridade. 
- Alteração: O(n), pois vamos ter que procurar.
- Construção: O(n log n).
### Heap:
- Seleção: O(1), pois já sabemos parte do local pelo indice dado. 
- inserção: O(log n),
- Remoção:
- Alteração: 

## Definições de Heap:
- Lista Linear (vetor) composta de elementos com chaves
s1,s2, . . .sn;
- As chaves representam as prioridades;
- Não existem dois elementos com a mesma prioridades;

### Max Heap e Min Heap:
- No Max Heap, os pais têm valores maiores que ou iguais aos dos filhos.
- Heap Máximo: Chaves s1, . . .sn, sendo si ≤ ⌊si/2⌋^1.
- Min Heap, os pais têm valores menores que ou iguais aos dos filhos.
- Heap Mínimo: Chaves s1, . . .sn, sendo si ≥ ⌊si/2⌋.
- ⌋, significa arrendonda para baixo.
- ], O oposto dele , significa arrendonda para cima.

### Visualização: 
- Conceito de HEAP max e min.
- Construir a árvore.
- Verificar cada valor. 
-Exemplo-1:
```
Indices:   1  2   3   4    5   6   7  8    9.
Valores: [33][32][28][31][29][26][25][30][27].

Árvore: Aqui é uma Heap.
          33
        /    \
      32     28
      / \    / \ 
    31  29  26  25
    / \
   30 27


Indices:   1  2   3   4    5   6   7  8    9.
Valores: [33][32][28][31][26][29][25][30][27].
Árvore: Aqui Não é uma Heap.
          33
        /    \
      32     28
      / \    / \ 
    31  26  29  25
    / \
   30 27
```

### Identificando: 
- i é o indice.
- Para um determinado elemento i:
- Pai de i é ⌊i/2⌋;
- Filho esquerdo é i ∗ 2;
- Filho direito é i ∗ 2 + 1;


## Alteração: 
- Ao alterar a prioridade de um nó, é
necessário re-arrumar a Heap para
que ela respeite as prioridades.
- Um nó que tem a prioridade
aumentada precisa subir na
árvore.
- Um nó que tem a prioridade
diminuída precisa descer na
árvore.

- Exemplo: Mudar a prioridade de 66 para
98.
```
- Este exemplo está do Caderno EDII.
```

- Exemplo: Mudar a prioridade de 95 para
37.
```
- Este exemplo está do Caderno EDII.
```

## Inserção
- Procedimentos:
* Tabela com n elementos;
* Inserir novo elemento na posição (n + 1);
* Compare o elemento no final do heap e faça-o subir até sua posição correta:
* Se estiver em ordem, a inserção terminou;
* Se não estiver em ordem, troque com o pai e repita o processo até terminar ou chegar à raiz.

-Inserir o elemento 15 na Heap abaixo.
```
- Este exemplo está do Caderno EDII.

```

## Remoção
- Procedimento:
* Retira-se sempre a raiz (elemento com maior prioridade):
* Coloque na raiz o último elemento da Heap e faça-o descer até a posição correta.
* Compare o elemento com seus filhos:
* Se estiver em ordem, a remoção terminou.
* Se não estiver em ordem, troque com o maior filho e
* repita o processo até terminar ou chegar a um nó folha.

-Remova o elemento da Heap abaixo.
```
- Este exemplo está do Caderno EDII.

```

## Construção de Lista de Prioridades
- Dado uma lista L de elementos para o qual se deseja construir uma
- heap H, há três alternativas:
* 1. Considerar uma heap vazia e inserir elemento a elemento;
* 2. Considerar que a lista L já representa uma Heap, e corrigir as
prioridades:
* 2.1 Considerar os nós folhas corretos;
2.2 Corrigir os nós internos realizando descidas.
* 3. Corrigir (subir) os nós a partir dos nós folhas. Incluindo processo de ordenação.


-Remova o elemento da Heap abaixo.
```
- Este exemplo está do Caderno EDII.
- Construa uma Heap a partir da lista L abaixo:
- L = {28, 33, 39, 60, 66, 70, 78, 95}

```

## Ordenação a partir de uma Heap (HEAPSORT)
- A partir de uma heap, é possível ordenar os dados fazendo trocas:
* O maior elemento(raiz) é trocado com o último elemento;
* Esse elemento já se encontra ordenado!
* Considerar que o vetor possui agora (n + 1) posições e descer a nova raiz até sua posição correta na Heap;
* Repetir os passos anteriores (n + 1) vezes.
* Complexidade dessa ordenação é de O(n log n).

| Operação    | Lista    | Lista Ordenada | Árvore Balanceada | Heap   |
|-------------|----------|-----------------|-------------------|--------|
| Seleção^2   | O(n)     | O(1)            | O(log(n))         | O(1)   |
| Inserção    | O(1)     | O(n)            | O(log(n))         | O(log(n)) |
| Remoção^3   | O(n)     | O(1)            | O(log(n))         | O(log(n)) |
| Construção^4| O(n)     | O(n log(n))     | O(log(n))         | O(n)   |

- 2 Sempre se refere a seleção do elemento com maior prioridade;
- 3 Considerando que se pretende remover um elemento arbitrário;
- 4 Construção com ordenação;