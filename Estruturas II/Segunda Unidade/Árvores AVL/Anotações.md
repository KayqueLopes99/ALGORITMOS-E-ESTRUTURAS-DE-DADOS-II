# Árvore AVL:

## Introdução: 
- A complexidade de busca em árvores binárias são dependentes da ordem que os elementos são inseridos ou removidos das estrutura de dados.

- Isto ocorre devido ao fato das árvores poderem se comportar no pior caso como filas.

- Surge o conceito de árvores com alturas balanceadas, conhecidas como AVL.

## Definição:
- Uma árvore é definida como sendo:
+ Uma árvore vazia é uma árvore AVL;
+ Sendo T uma árvore binária de busca cujas sub-árvores esquerda e direita são L e R, respectivamente, T será uma AVL contando que:
+ L e R sejam AVL’s;
+ |hL − hR| ≤ 1. hL e hR são as alturas das sub-árvores L e R.

## Objetivo:
- O termo balanceado pode ser entendido como sinônimo de equilibrado.
- O objetivo é manter as subárvores esquerda e direita com a menor diferença possível.
- A menor diferença possível é 1.

## Fator de Balanceamento: 
+ FB = ALTURA_ESQUERDA - ALTURA_DIREITA <= 1.
- O fator de balanceamentoou fator de equilíbrio de um nó T em uma árvore binária é definido como sendo hL˘hR.
- Para qualquer nó Tnuma árvore AVL, o fator de balanceamento assume o valor -1, 0 ou +1.
+ O FB de uma folha é 0.

````
# AVL Tree (Altura 5)

```
                     (-1) 60
                       /     \
                  (1) 30      (0) 90
                  /     \     /    \
            (0)20    (0)50  (1)80   (-1) 100
            /    \            /  \      /   \
        (0) 10  (0)25    (0)40  (0)55 (0)85 (0)110
                            / \              / \
                         (0)95 (0)120     (0)130 (0)135
````

- Fator=0 indica que as alturas das subárvores esquerda e direita são iguais.
- Fator=+1 indica que a altura da subárvore esquerda é maior que da direita.
- Fator=−1 indica que a altura da subárvore esquerda é menor que da direita.

## Rotações:
- As rotações em árvores AVL são usadas para manter o balanceamento após operações de inserção ou remoção de nós. 
- Existem quatro tipos de rotações: rotação simples à direita, rotação simples à esquerda, rotação dupla à direita (direita-esquerda) e rotação dupla à esquerda (esquerda-direita). 

### 1. **Rotação Simples à Direita (RIGHT) - (R)** 
+ A rotação simples à direita é usada para corrigir um desbalanceamento causado por uma inserção na subárvore esquerda de um nó. 
+ Esse desbalanceamento ocorre quando o fator de balanceamento de um nó é -2 e o fator de balanceamento de seu filho à esquerda é -1 ou 0.

- **Cenário**: Inserção na subárvore esquerda da subárvore esquerda.
- **Resultado**: O nó esquerdo se torna a nova raiz da subárvore, e o nó original se torna o filho direito da nova raiz.

```
Antes da rotação:
       y
      /
     x
    /
   z

Após a rotação:
      x
     / \
    z   y
```

### 2. **Rotação Simples à Esquerda (LEFT) - (L)**
+ A rotação simples à esquerda é usada para corrigir um desbalanceamento causado por uma inserção na subárvore direita de um nó. 
+ Esse desbalanceamento ocorre quando o fator de balanceamento de um nó é 2 e o fator de balanceamento de seu filho à direita é 1 ou 0.

- **Cenário**: Inserção na subárvore direita da subárvore direita.
- **Resultado**: O nó direito se torna a nova raiz da subárvore, e o nó original se torna o filho esquerdo da nova raiz.

```
Antes da rotação:
     y
      \
       x
        \
         z

Após a rotação:
      x
     / \
    y   z
```

### 3. **Rotação Dupla à Direita (Direita-Esquerda)**
+ A rotação dupla à direita é usada para corrigir um desbalanceamento causado por uma inserção na subárvore direita de um nó da subárvore esquerda.
+  Esse desbalanceamento ocorre quando o fator de balanceamento de um nó é -2 e o fator de balanceamento de seu filho à esquerda é 1.

- **Cenário**: Inserção na subárvore direita da subárvore esquerda.
- **Resultado**: Primeiro, uma rotação simples à esquerda é realizada na subárvore esquerda, seguida de uma rotação simples à direita.

```
Antes da rotação:
       y
      /
     x
      \
       z

Após a rotação:
      z
     / \
    x   y
```

### 4. **Rotação Dupla à Esquerda (Esquerda-Direita) - (LR)**
+ A rotação dupla à esquerda é usada para corrigir um desbalanceamento causado por uma inserção na subárvore esquerda de um nó da subárvore direita. 
+ Esse desbalanceamento ocorre quando o fator de balanceamento de um nó é 2 e o fator de balanceamento de seu filho à direita é -1.

- **Cenário**: Inserção na subárvore esquerda da subárvore direita.
- **Resultado**: Primeiro, uma rotação simples à direita é realizada na subárvore direita, seguida de uma rotação simples à esquerda.

```
Antes da rotação:
     y
      \
       x
      /
     z

Após a rotação:
      z
     / \
    y   x
```

### Resumo:
- Rotações
O balanceamento é conduzido utilizando 4 tipos de rotações: LL, LR, RL e RR.
+ RR e LR são simétricos em relação a LL e RL.
+ O ancestral mais novo de A do novo nó inserido Y caracteriza o desbalanceamento. Pode ter os valores de +2 e -2.
+ Identificando rotações:
-  A B Tipo
- +2 +1 LL
- −2 −1 RR
- +2 −1 LR
- −2 +1 RL

## Rotação LL: 
+ Assumindo pA e pB ponteiros para
as subárvores com raízes A e B:
+ pB = pA->LeftNode;
+ pA->LeftNode = pB->RightNode;
+ pB->RightNode = pA;
+ pA = pB;
- CADERNO.

## Rotação RR:
+ Assumindo pA e pB ponteiros para
as subárvores com raízes A e B:
+ pB = pA->RightNode;
+ pA->RightNode = pB->LeftNode;
+ pB->LeftNode = pA;
+ pA = pB;
- CADERNO.

## Rotação LR:
- Assumindo pA, pB e pC ponteiros
para as subárvores com raízes A, B
e C:
+ pB = pA->LeftNode;
+ pC = pB->RightNode;
+ pB->RightNode = pC->LeftNode;
+ pC->LeftNode = pB;
+ pA->LeftNode = pC->RightNode;
+ pC->RightNode = pA;
+ pA = pC;


## Inserção:
- As árvores AVL são árvores binárias de busca balanceadas, onde a diferença entre as alturas das subárvores de qualquer nó não pode ser maior que 1.
- Durante a inserção, a árvore é ajustada (se necessário) por rotações (simples ou duplas) para manter essa propriedade de balanceamento.
- Após inserir um nó na árvore, a altura dos nós ancestrais é ajustada e, se a propriedade AVL for violada, uma rotação (direita ou esquerda) é executada para restaurar o balanceamento.

## Remoção:
- A remoção segue as regras básicas de remoção em árvores binárias de busca (remoção de folhas, nós com um filho ou dois filhos).
- Após remover um nó, é necessário verificar e ajustar o balanceamento dos nós ancestrais.
- Se o balanceamento for violado, uma ou mais rotações são aplicadas para restaurar a propriedade AVL.
- Essas rotações garantem que as operações de inserção e remoção continuem sendo realizadas em tempo O(log n), mantendo a eficiência da estrutura.