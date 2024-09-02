# Tabela de Dispersão 
## Funções Hash e tratamento de Colisões: 
+ 1. Mundo Ideal
- 1.1 Hashing perfeito! Função sempre fornecerá posiçães diferentes para cada chave inserida.
+ 2. Mundo Real
- 2.1 Independente da função Hash, ocorrerá colisões. Inevitavelmente uma posição pode ter duas entradas.

## Tratamento:
+ Dois fatores reduzem a quantidade de colisões numa tabela Hash. São elas:
- Escolha do tamanho da tabela Hash.
- Escolha adequada da função Hash.
+ Mas e quando nada mais pode ser feito? Uso de Tratamento de colisões:
- Endereçamento Aberto:
- Endereçamento Encadeado:

## Endereçamento aberto
+ Caso ocorra uma colisão, percorre a tabela Hash em busca de um espaço vazio. Os elementos são armazenados diretamente na tabela (sem listas encadeadas).
- Tipos de Endereçamento Aberto:
+ Sondagem Linear
+ Sondagem quadrática
+ Duplo Hash

## Endereçamento aberto
### Sondagem Linear
- Na sondagem linear, quando uma colisão ocorre (ou seja, quando duas chaves diferentes geram o mesmo índice usando a função de dispersão), a estratégia é procurar a próxima posição disponível na tabela, movendo-se de forma linear.

- (h(x)+j)mod m
- m é o tamanho da tabela.
- x = Chave. 
- h(x) = x mod m. 
- h(x)  = h(x) + 1, se ela ta cheia vai para .
- h(x)  = h(x) + 2, se ela ta cheia vai para ...

+ Algoritmo:

- 1. Posição da chave c é calculada por uma função hash.
- px = pc = hash(c)
- 2. Chave é armazenada na posição px se estiver livre e Fim do algoritmo.
- 3. px ← px + 1 e volta para o passo 2.
- Vai verificando px se está livre. 


+ Características:
+ Estratégia Simples;
+ Provoca o Agrupamento Primário:
- A medida que a tabela hash fica cheia, o tempo para incluir ou buscar um elemento aumenta;
- A medida que os elementos são inseridos surgem longas sequdências de posições ocupadas;
- A ocorrdência desses agrupamentos aumenta o tempo de pesquisa, diminuindo o desempenho.

- Tenta espalhar os elementos de forma sequencial a partir da posição calculada utilizando a **"função de hashing"**

#### Funcionamento

- Primeiro elemento `(i = 0)` é colocado na **"posição"** obtida pela **"função de hashing"**: **"pos"**
- Segundo elemento **(colisão)** é colocado na posição **"pos+1"**
- Terceiro elemento **(nova colisão)** é colocado na posição **"pos+2"**

### Sondagem Quadrática: 
- Tenta espalahar os elementos utilizando uma equação do segundo grau.
- pos + (cl * i) + c2 * i^2)
onde
- "pos" é a posição obtida pela fungão hash. 
- i é  a tentativa atual.
- c1 e c2 são constates dadas.
- Tenta espalhar as chaves utilizando uma função do segundo grau. Utiliza quase o mesmo algoritmo da Sondagem Linear com a diferença que a sondagem é realiza pela fórmula:
- px ← px + c1(i − 1) + c2(i − 1)^2
- Onde i representa a tentativa de inserir a chave na posição pc .
- Quando não há colisão, px = pc .
- Sendo c1 e c2 coeficientes quaisquer escolhidos de forma a varrer a tabela Hash.

### Características:
- Resolve o problema do agrupamento prim´aria;
- Cria o problema do agrupamento secund´ario.
- As chaves com mesmo pc tamb´em terão os mesmos px, CHAVES PRODUZEM A MESMA POSIÇÃO .
- A degradação do secund´ario ´e menor do que o prim´ario.

#### Funcionamento:
- Primeiro elemento `(i = 0)` é colocado na **"posição"** obtida pela **"função de hashing"**: **"pos"**
- Segundo elemento **(colisão)** é colocado na posição **"pos + (c1 * 1) + (c2 * 1^2)"**
- Terceiro elemento **(nova colisão)** é colocado na posição **"pos + (c1 * 2) + (c2 * 2^2)"**

## Saltos comparação:
### Comparação Gráfica dos Saltos

- **Sondagem Linear**: 1 -> 2 -> 3 -> 4 -> 5 -> ...
- **Sondagem Quadrática**: 1 -> 4 -> 9 -> 16 -> 25 -> ...

A sondagem linear avança de forma constante, enquanto a sondagem quadrática avança com incrementos cada vez maiores, o que pode evitar agrupamentos, mas também pode deixar mais espaços em branco na tabela de dispersão.

## Duplo Hash
- Espalhamento duplo. 
- Espalhar os elementos utilizando duas "funções de hashing"
- Fórmula: "H1 + i * H2", com i tentativa.
- (h(k)+j×h2(k))mod m
Onde:
- "H1" é utilizada para calcular a "posição inicial" do elemento. 
- "H2" é utilizada para calcular os "deslocamentos" em relação a posição inicial no caso de uma "colisão"

#### Funcionamento:
- Primeiro elemento (i = 0) é colocado na
"posição" obtida por "H1"
- Segundo elemento (colisão) é colocado na
posição "H1 + 1 * H2"
- Terceiro elemento (nova colisão) é colocado na posição "H1 + 2 * H2"

## Tratamento de Colisão - Endereçamento Encadeado:
+ O endereço base pode ser encontrado para chaves diferentes como resultado da função de dispersão.

+ Uma ideia para tratar colisões consiste em armazenar chaves sinônimas em listas encadeadas:
- Encadeamento Exterior
- Encadeamento Interior

### Endereçamento Exterior: 
- Consiste em manter m listas encadeadas, uma para cada possível endereço base;
- Um campo para o encadeamento dever ser acrescentado a cada nó;
- O nós correspondentes ao endereço-base serão apenas nós-cabeças para essas listas.
- Geralmente uma lista encadeada, que armazena todas as chaves que geram colisão naquela posição.

-> Exemplo: 
```
0 [    ]---> [item][ ]
1 [ ] 
2 [ ] —> [item][ ] —> [item][ ] 
3 [ ] 
4 [ ] 
5 [ ] —> [item][ ] —> [item][ ] —> [item][ ] 
6 [ ] 
7 [ ]  
8 [ ] —> [item][ ]
9 [ ] —> [item][ ] 
10 [ ] —> [item][ ] 
11 [ ] —> [item][ ]
...   ...  ... 
```
## Endereçamento Interior:
- Não queremos adicionar m listas externas á tabela.
- Resolve-se o problema da colisão mediante o emprego de listas encadeadas, desde que estas compartilhem o mesmo espaço de memória que a tabela de dispersão.
- O encadeamento interior prevê a divisão da tabela T em duas zonas, uma de endereço-base, de tamanho p, e outra reservada aos sinônimos, de tamanho s.
- Naturalmente a tabela tem tamanho m = p + s. Os valores de p e s são fixos.
- A função de dispersão deve obter endereços-base na faixa.
- [0, p − 1] apenas.

#### Exemplo:
- Número de chaves: N = 5; (48 03 80 31 20);
- Tamanho da tabela Hash: m = 7
- Destinos endereçaveis pela função Hash: p = 4.
- Expansão: s = 3
- Imagem