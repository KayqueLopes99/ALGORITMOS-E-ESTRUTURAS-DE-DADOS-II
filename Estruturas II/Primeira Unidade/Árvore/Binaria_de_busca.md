# Árvore binária de Busca: 
- Uma Árvore Binária de Busca é uma estrutura de dados em forma de árvore que possui as seguintes propriedades:

+ 1. **Nó Raiz**: É o nó principal da árvore. A partir desse nó, os outros nós estão organizados.

+ 2. **Subárvores à Esquerda e à Direita**: Cada nó na árvore tem até dois filhos. O nó à esquerda contém um valor menor que o nó pai, e o nó à direita contém um valor maior que o nó pai. Isso se aplica recursivamente a todos os nós na árvore.

+ 3. **Propriedade da Busca**: Devido à organização dos nós (menores à esquerda e maiores à direita), a BST facilita a busca eficiente de elementos. Para buscar um elemento:
   - Comece na raiz.
   - Compare o valor a ser buscado com o valor do nó atual.
   - Se o valor for menor, mova-se para o filho à esquerda; se for maior, mova-se para o filho à direita.
   - Repita esse processo até encontrar o elemento ou chegar a um nó sem filhos, indicando que o elemento não está na árvore.

+ 4. **Operações Básicas**:
   - **Inserção**: Insere um novo nó seguindo a mesma lógica de busca. O valor é comparado com os nós existentes, movendo-se para a esquerda ou direita até encontrar uma posição vazia.
   - **Busca**: Encontra um valor na árvore, seguindo o processo descrito acima.
   - **Remoção**: Para remover um nó, três casos são considerados:
     1. **Nó sem filhos**: O nó é simplesmente removido.
     2. **Nó com um filho**: O nó é removido e seu único filho substitui sua posição.
     3. **Nó com dois filhos**: O nó é substituído pelo seu sucessor (o menor nó da subárvore à direita) ou pelo seu predecessor (o maior nó da subárvore à esquerda).

+ 5. **Eficiência**: Em uma BST bem balanceada, a altura da árvore é logarítmica em relação ao número de nós, resultando em operações de busca, inserção e remoção com complexidade de tempo \(O(\log n)\). No entanto, se a árvore estiver desbalanceada, especialmente se degenerar para uma lista encadeada (todos os nós tendo apenas um filho), a eficiência cai para \(O(n)\).

