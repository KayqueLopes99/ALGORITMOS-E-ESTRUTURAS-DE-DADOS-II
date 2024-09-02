# Compressão de dados
## Algoritmo de Huffman:
### Codificação de texto:
- Um texto é composto por uma sequência de caracteres (imprimíveis e não-imprimíveis) sendo, cada caractere representado por uma sequência de bits.
+ Exemplo:
> K − E − N − N − E − D − Y
+ Utilizando a codifica¸cão ASCII pode ser:
> 75 − 101 − 110 − 110 − 101 − 100 − 121
+ Sendo que cada símbolo deste é representado por uma sequência binária com 8 bits da ASCII.
_ Cada caractere possui exatamente 1byte de representa¸cão. Desta forma, o meu nome ocupa: 56 bits. 


+ Vamos considerar um texto maior: Um prato de trigo para tres tigres tristes:
```
U m p r a t o
85 − 109 − 95 − 112 − 114 − 97 − 116 − 111
d e t r i g o
100 − 101 − 95 − 116 − 114 − 105 − 103 − 111
p a r a t r e s
112 − 97 − 114 − 97 − 95 − 116 − 114 − 101 − 115
t i g r e s t r i s t e s
116−105−103−114−101−115−95−116−114−105−115−116−101−115
```

## Primeiro: 
- Vamos considerar um texto maior: Um prato de trigo para tres tigres tristes:
Este texto contem:
+ 42 caracteres.
+ 13 caracteres distintos.
+ O texto ocupa 336 bits = 42 . 8;

## Segundo:
```
Frequência dos caracteres:
U m - p r a t o d e i g s
1 1 7 2 6 3 6 2 1 4 3 2 4
Ordenando as frequências:
U m d p o g a i e s r t -
1 1 1 2 2 2 3 3 4 4 6 6 7
Agrupando as menores frequências:
U {d, m} p o g a i e s r t -
1    2   2 2 2 3 3 4 4 6 6 7
```
> O algoritmo continua (agrupando os menores) até não for mais possível continuar. 

```
Agrupando(U e {d, m}):
{U, d, m} p o g a i e s r t -
3 2 2 2 3 3 4 4 6 6 7
Ordenando:
g p o {U, d, m} a i e s r t -
2 2 2 3 3 3 4 4 6 6 7

g {p, o} {U, d, m} a i e s r t -
2 4 3 3 3 4 4 6 6 7
{g, a} {p, o} {U, d, m} i e s r t -
5 4 3 3 4 4 6 6 7
{g, a} {p, o} {U, d, m, i} e s r t -
5 4 6 4 4 6 6 7
{g, a} {p, o} {U, d, m, i} {e,s} r t -
5 4 6 8 6 6 7

{g, a, p, o} {U, d, m, i} {e,s} r t -
9 6 8 6 6 7
{g, a, p, o} {U, d, m, i} {e,s} {r,t} -
9 6 8 12 7
{g, a, p, o} {U, d, m, i, −} {e,s} {r,t}
9 13 8 12
{g, a, p, o, e,s} {U, d, m, i, −} {r,t}
17 13 12

{g, a, p, o, e,s} {U, d, m, i, −,r,t}
17 25
{g, a, p, o, e,s,U, d, m, i, −,r,t}
42
```

## Terceiro:
- Contrua a árvore:
- EX:
````
              (Todos(42))
            /             \
{g, a, p, o, e,s}         {U, d, m, i, −,r,t}
                  . . . 
- Caderno.
- Percorar a árvore considerando: 
- Esquerda é 0
- Direita é 1.
````

# Quarto:
- Tabela da frequência:
```
char  bin  bits freq total
U   10000   5   1   5
d   1000010   7   1   7
m   1000011   7   1   7
p   0010   4   2   8
o   0011   4   2   8
g   0000   4   2   8
a   0001   4   3   12
i   1001   4   3   12
e   100010   6   4   24
s   011   3   4   12
r   100   3   6   18
t   111   3   6   18
-   100   3   7   21
Comprimido 160
```

# Quinto Cálculos:
````
Imagem anexada.
````

# Sexto: 
- Escrita caso necessário:
```
Antes da compresãao(em binário):
0101010101101101010111110111000001110010011000010111010001101111
0101111101100100011001010101111101110100011100100110100101100111
0110111101011111011100000110000101110010011000010101111101110100
0111001001100101011100110101111101110100011010010110011101110010
0110010101110011010111110111010001110010011010010111001101110100
0110010101110011
Após a compresãao:
1000010000111000010110000111000111001000010010100110110100100000
0111000010000111000011001101100100111001101001000011001001110011
0110100101111001001101010101011011010101111101110000011100100110
00010111010001101111

```