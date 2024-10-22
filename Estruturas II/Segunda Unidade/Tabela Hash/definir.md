# Tabela hash
- "Busca"
+ Muitos métodos de busca funcionam segundo o mesmo princípio: procurar a informação desejada com base na comparação de suas chaves, isto é com base em algum valor que a compõe.

- "Problema"
+ Algoritmos eficientes exigem que os elementos sejam armazenados de forma ordenada.
+ Custo da ordenação no melhor caso: "O(n log n)"
+ Custo de busca elevados.

- "Busca Ideal"
+ Acesso direto ao elemento procurado, sem nenhuma etapa de comparação de chaves: custo 'O(1)'.

- Programação descomplicada.

- Notas da apresentação:
Buscar em um mesmo conjunto de dados, com acesso direto ao elemento procurado, sem nenhuma etapa de comparação de chaves: custo constante. 
A tabela hash foi escolhida para o gerenciamento de estoque de medicamentos devido à sua eficiência nas operações de busca, inserção e remoção, que possuem complexidade média O(1), ou seja, tempo constante.
 Cada medicamento no sistema é identificado por uma chave única (como um código de barras ou ID) que é mapeada para uma posição específica na tabela usando o método da dispersão da divisão (chave % tamanho da tabela), na hora de buscar o medicamento realiza-se isso para o sistema acessar diretamente aquela posição na tabela. 
Esse método otimiza o uso da memória, evitando desperdícios e alocando os dados de forma eficiente.
A resolução de colisões (quando duas chaves diferentes são mapeadas para a mesma posição) é implementada para garantir que o sistema funcione bem mesmo com grandes volumes de medicamentos na inserção e na busca. Existem várias técnicas para lidar com colisões, como o encadeamento ou o endereçamento aberto, que podem ser aplicadas dependendo do tamanho do estoque e das características da farmácia. Isso garante que o acesso rápido e eficiente aos medicamentos seja mantido à medida que o estoque cresce, sem a necessidade de percorrer grandes listas de dados.
Em comparação com uma árvore binária de busca (BST), onde o crescimento do estoque pode resultar em uma árvore desbalanceada, tornando as operações mais lentas com complexidade O(n) no pior caso, a tabela hash oferece uma solução mais direta e rápida, pois evita a necessidade de percorrer toda a estrutura de dados.
