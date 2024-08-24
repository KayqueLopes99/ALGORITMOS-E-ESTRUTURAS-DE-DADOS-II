# Conceito:
- É uma estrutura de dados organizada como uma árvore binária completa, ou seja, uma árvore binária onde cada nível é preenchido da esquerda para a direita e deve estar cheio antes que o próximo nível seja iniciado.

- Além disso, há uma restrição especial: cada nó de haep deve conter um valor maior(ou menor) do que todos os valores contidos por nós descendentes dele.
## árvore binária completa:
- Perfeitamente balanceada, exceto pelo último nível.

- Altura de uma árvore binária completa com n nós é igual a (log n).
- Sua altura apenas aumenta quando n chegar na próxima potência de 2.
- Podem "faltar" nós no último nível da árvore, mas eles devem ser os nós mais a direita. A árvore é sempre preenchida de cima pra baixo, da esquerda pra direita.

## O que é uma Heap?
- Em outras palavras, é uma árvore binária completa com uma regra particular:
- Em qualquer nó, o valor armazenado nele deve ser ≥ aos valores armazenados em seus nós filhos.
- Essa restrição garante que o maior estará sempre no topo, ou seja, na raiz.
> Nesse caso, é chamada de "heap de máximo".
> Em nossa implementação do heap sort, a raiz da árvore sempre conterá o maior elemento, mas poderia ser diferente (uma heap de mínimo).
- Heaps são, muitas vezes, implementadas como filas de prioridade.

## Estrura no Vetor:
- A regularidade de uma árvore binária completa facilita sua implementação utilizando vetor.
> Os nós da árvore possuem uma ordem natural:
- Linha por linha, de cima para baixo, começando da raiz, e movendo-se da esquerda para a direita em cada linha.
> Se houver n nós, essa ordem especifica suas posições 0, 1, 2, ..., n dentro do vetor.
- Mover-se para cima ou para baixo na árvore é facilmente simulado no vetor, usando o fato de que o nó j tem: pai na posição ((j-1)/2] e filhos em [2j+1] e [2j+2].