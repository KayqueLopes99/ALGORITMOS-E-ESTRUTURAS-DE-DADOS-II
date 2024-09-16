Aqui está uma explicação sobre o algoritmo de Huffman para incluir no seu README:

---

### Algoritmo de Huffman

O **algoritmo de Huffman** é uma técnica eficiente de compressão de dados, desenvolvida por David A. Huffman em 1952. Ele é amplamente utilizado para reduzir o tamanho de arquivos ao codificar informações de forma que os caracteres mais frequentes usem menos bits, enquanto os menos frequentes usam mais bits.

#### Como Funciona:

1. **Contagem de Frequências**: O primeiro passo é contar a frequência de cada caractere ou símbolo no conjunto de dados a ser comprimido.

2. **Construção da Árvore de Huffman**:
   - Cada caractere é tratado como um nó folha em uma árvore binária.
   - Crie uma fila de prioridade (normalmente implementada como uma min-heap) onde cada nó é ordenado pela frequência de seu caractere.
   - Os dois nós com as menores frequências são removidos da fila, combinados em um novo nó (com a soma das suas frequências) e esse novo nó é inserido de volta na fila.
   - Esse processo é repetido até que haja apenas um nó na fila, que se torna a raiz da árvore de Huffman.

3. **Geração dos Códigos de Huffman**:
   - A partir da árvore construída, os códigos de Huffman são gerados.
   - Percorra a árvore a partir da raiz: ao mover-se para a esquerda, adicione um `0` ao código, e ao mover-se para a direita, adicione um `1`.
   - Cada folha da árvore terá um código único que é o caminho do nó raiz até a folha.

4. **Codificação**:
   - Substitua cada caractere no conjunto de dados original pelo seu código de Huffman correspondente.

5. **Decodificação**:
   - Para decodificar, utilize a árvore de Huffman para traduzir os códigos binários de volta aos caracteres originais, percorrendo a árvore do nó raiz até as folhas.

#### Vantagens:

- **Compressão Sem Perda**: O algoritmo de Huffman é uma técnica de compressão sem perda, o que significa que o processo de descompressão restaura os dados originais sem qualquer perda de informação.
- **Eficiência**: É particularmente eficiente para conjuntos de dados onde alguns caracteres ocorrem com maior frequência do que outros, permitindo uma significativa redução no tamanho do arquivo.

#### Exemplo Simples:

Imagine que você deseja comprimir a sequência `AAABCC`. As frequências dos caracteres seriam:
- A: 3
- B: 1
- C: 2


#### Árvore:
````
       Todos(ABC - 6)
       /       \
    (BC)       (A)
      3         3
     / \
     C  B 
     1  2
````




A árvore de Huffman seria construída com esses nós, resultando em códigos, por exemplo:
- A: `0`
- B: `10`
- C: `11`

A sequência codificada seria `0001011`.

---

