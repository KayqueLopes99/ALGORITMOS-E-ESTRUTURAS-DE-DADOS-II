# Complexidade:
- Conceito por exemplo:
- Ordenar uma pilha de livros
• Imagine uma pilha desorganizada de livros.
• A tarefa e organizá-los em ordem alfabética. 
• A complexidade aumenta a medida que a pilha de livros fica maior.
- A complexidade é usada para medir a velocidade de um algoritmo. Sendo o algoritmo um agrupamento de etapas para se executar uma tarefa, o tempo que leva para um algoritmo ser executado é baseado no número de passos. 

## O que é um algoritmo?
- Um algoritmo e um conjunto finito de passos.
- Entretanto, a existencia de um algoritmo não
garante que possa ser resolvido.
- Condições de tempo e memória devem ser avaliadas.

## Grid: 2x2
T(2) = 6 Passos.
``
[107][24]
[901][53]
``
## Grid: 3x3
T(3) = 36 Passos.
``
[10][758][683]
[852][715][907]
[236][459][692]
``

## Cálculo da Complexidade:
- Tempo de Execuçao:
T(n) = somatorio de n, i=1, tini.
• i índice da instrução; 
• ti o tempo necessario para a excução da instrução i;
• ni o numero de vezes que a instrução i e executada.

## Experimento: 
``
- Init cronometro; 
- Inicialize N=0
|
|
execute o Algoritmo.
|
N > MAX ------não------> N = N + 1 --> Reinicie os parametros

--> Calcule o Tempo.`
``

### Contagem de Frequência - Algoritmo 1:
````c
int main ( ) {
 int x = 0;  // 1 Vez.
 x = x + 1; // 1 Vez.
 return 0; // 1 Vez.
 }
````
- Custo total=O(1)+O(1)+O(1)=O(3)
- Complexidade Contante.

### Contagem de Frequência - Algoritmo 2:
````c
int main() {
    int x = 0, n = 10; // 1 Vez.
    for (int i = 0; i < n; i++) { // N vezes.
        x = x + 1;
    }
    return 0; //1 Vez.
}

````
- Custo total=O(1)+O(n)+O(1)=O(n)
- Complexidade Linear.

### Contagem de Frequência - Algoritmo 3:
````c
float soma(float x, int n) {
    int soma = 0; //1 Vez.
    int i = 0, j = 0; //1 Vez.
    for (i = 0; i <= n; i++) { // n + 2(comparação em <=) Vez.
        int prod = 1;  // N + 1 Vez.
        for (j = 0; j < i; j++) // n(n+1)/2 Vez.
            prod = prod * x; // N + 1 Vez.
        soma + soma + prod; // 1 Vez.
    }
    return soma;
}

````
- Custo total= 1 + 1 + n + 2 + n(n+1)/2 + n + 1 + n + 1 + 
- Resultado = n^2/2 + 7n + 6
- Complexidade O(n^2) quadrática.

### Contagem de Frequência - Algoritmo 4:
````c
float horner(float x, int n) {
    int i = 0, soma = 0; // 1 Vez.
    for (i = 0; i <= n; i++) { // n + 2 vez.
        soma = soma * x + 1; // n + 1Vez.
    }
    return soma; // 1 Vez.
}

````
- Custo total= 1 + n + 2 + n + 1 +1 = 2n + 5.
- Complexidade Linear O(n).

### Contagem de Frequência - Algoritmo 4:
````c
#include <math.h>

float soma(int x, int n) {
    return pow(x, n + 1) / (x - 1);
}

````
- Pow -> O(LOG(n + 1))
- complexidade logarítmica.

### No grafico:
- 1)  Complexidade O(n^2) quadrática.
- 2)  Complexidade Linear O(n).
- 3)  Complexidade logarítmica Olog(n+1)
-> Quanto menor o número mais proximo do eixo y.
-> Complexidade de tempo melhor é a 3)


# Complexidade Assintotica
- Uma função g(n) domina assintoticamente outra função f(n) se existem duas
- constantes positivas c e m tais que, para n ≥ m, tem-se:
-> |f(n)| ≤ c × |g(n)|


- Uma função g(n) domina assintoticamente outra função f(n) se existem duas
constantes positivas c e m tais que, para n ≥ m, tem-se
-> |f(n)| ≤ c × |g(n)|

- Quem domina no gráfico é que fica em cima, dependendo do ponto especificado. 

## Para determinar quais funções são dominantes:
### (a) Comparação entre f(n) = n e g(n) = -n^2
### (b) Comparação entre f(n) = 50n e g(n) = 2n^2

- Para **(a)**: g(n) = -n^2 é dominante sobre f(n) = n.
- Para **(b)**: g(n) = 2n^2 é dominante sobre f(n) = 50n.

## Complexidade Assintotica 
• Na analise de algoritmos, geralmente usa-se a complexidade assintótica.
analisando o algoritmo para n tendendo a infinito;
• Nesse caso, despreza-se constantes e termos de menor crescimento.
- Tipos de Notação: 
O(n) Limitador Estrito Superior.

# Complexidades Tipagens:

### 1. O(1) - Complexidade Constante
**Descrição:** 
- A complexidade constante significa que o tempo de execução do algoritmo não depende do tamanho da entrada. 
- Ele executa uma quantidade fixa de operações, independentemente do tamanho da entrada.

**Exemplos:** 
- Acesso a um elemento específico de um array (`array[index]`).
- Verificação de uma condição (`if (x > 10)`).
- Exemplo:
```c
int funcConstante (int *v , int n ){
 if (V [ 0 ] > V[ n −1]){
 return V[ n − 1 ] ;
 }else{
 return V [ 0 ] ;
}
 }
```
**Como identificar:**
- Verifique se o algoritmo sempre faz um número fixo de operações.
- Não há loops ou chamadas recursivas que dependem do tamanho da entrada.

### 2. O(log(n)) - Complexidade Logarítmica
**Descrição:**
- A complexidade logarítmica significa que o tempo de execução aumenta conforme o logaritmo do tamanho da entrada. 
- É comum em algoritmos que dividem a entrada em partes menores a cada iteração.

**Exemplos:**
- Pesquisa binária em um array ordenado.
- Algoritmo de divisão e conquista que divide o problema ao meio a cada passo.
- Exemplo:
```c
bool funcLog(int v[], int a, int b, int x) {
    if (a > b)
        return false;
    int c = (a + b) / 2;
    if (v[c] == x)
        return true;
    else if (v[c] > x)
        return funcLog(v, a, c - 1, x);
    else
        return funcLog(v, c + 1, b, x);
}
```


**Como identificar:**
- O algoritmo divide a entrada de forma consistente e recursiva, geralmente reduzindo o problema pela metade a cada etapa.
- Procure por loops ou chamadas recursivas que cortam o problema em frações.

### 3. O(n) - Complexidade Linear
**Descrição:** 
- A complexidade linear significa que o tempo de execução é proporcional ao tamanho da entrada. Se a entrada dobra, o tempo de execução também dobra.

**Exemplos:**
- Iteração de loop simples sobre todos os elementos de um array (`for (int i = 0; i < n; i++)`).
- Pesquisa linear em uma lista não ordenada.

**Como identificar:**
- O algoritmo tem um loop que percorre cada elemento da entrada uma vez.
- Não há múltiplos loops aninhados que aumentem o tempo de execução.
- Exemplo:
````c
int funcLinear(int *v, int n) {
    int maior = v[0];
    int cont = 0;
    while (cont < n) {
        if (v[cont] > maior) {
            maior = v[cont];
        }
        cont = cont + 1;
    }
    return maior;
}
````

### 4. O(n log(n)) - Complexidade Log Linear
**Descrição:** 
- A complexidade log-linear é típica de algoritmos que combinam uma operação linear com uma operação logarítmica. - Geralmente é vista em algoritmos eficientes de ordenação.

**Exemplos:**
- Algoritmos de ordenação como Merge Sort e Quick Sort na média dos casos.
- Algoritmos que dividem a entrada em partes menores e então fazem um processamento linear dessas partes.
- Exemplo: 
````c
void funcLogLinear(int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        funcLogLinear(inicio, meio);
        funcLogLinear(meio + 1, fim);
        unir(inicio, meio, fim);
    }
}
````

**Como identificar:**
- O algoritmo realiza uma divisão logarítmica da entrada e faz uma passagem linear em cada divisão.
- Verifique se há um loop que executa `n` vezes e dentro dele há uma operação logarítmica ou recursiva.

### 5. O(n^2) - Complexidade Quadrática
**Descrição:** 
- A complexidade quadrática significa que o tempo de execução é proporcional ao quadrado do tamanho da entrada. Isso ocorre comumente em algoritmos que possuem dois loops aninhados.

**Exemplos:**
- Algoritmo de ordenação por bolha (Bubble Sort).
- Algoritmo de multiplicação de matrizes padrão.
- Exemplo:
```c
void funcQuadratica(int *v, int n) {
    int aux;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

```
**Como identificar:**
- Verifique se o algoritmo possui dois loops aninhados, cada um iterando sobre o tamanho da entrada (`for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) }`).

### 6. O(n^3) - Complexidade Cúbica
**Descrição:** 
- A complexidade cúbica significa que o tempo de execução é proporcional ao cubo do tamanho da entrada. É comum em algoritmos que têm três loops aninhados.

**Exemplos:**
- Algoritmos de multiplicação de matrizes que usam uma abordagem ingênua.
- Algumas soluções para problemas de grafos que verificam todas as combinações possíveis de três elementos.
- Exemplo: 
```c
void funcCubica(int *v, int n) {
    int aux;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                aux = v[i] + v[j] + v[k];
                printf("%d ", aux);
            }
        }
    }
}

```


**Como identificar:**
- Verifique se há três loops aninhados, cada um iterando sobre o tamanho da entrada (`for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { for (int k = 0; k < n; k++) } }`).

### 7. O(2^n) - Complexidade Exponencial
**Descrição:** 
- A complexidade exponencial significa que o tempo de execução dobra com cada aumento unitário no tamanho da entrada. Isso ocorre em problemas onde todas as combinações possíveis devem ser verificadas.

**Exemplos:**
- Algoritmo de força bruta para resolver o problema do caixeiro viajante (Traveling Salesman Problem).
- Algoritmos recursivos que resolvem problemas de maneira exponencial, como a solução de Fibonacci ingênua.
- Exemplo: 
```c
int funcExp(int n) {
    int aux;
    if (n < 2)
        return n;
    else
        return funcExp(n - 1) + funcExp(n - 2);
}

```
**Como identificar:**
- O algoritmo tem uma chamada recursiva que gera dois subproblemas por cada chamada (`T(n) = 2 * T(n-1)`).

### 8. O(n!) - Complexidade Fatorial
**Descrição:** 
- A complexidade fatorial significa que o tempo de execução cresce de forma fatorial com o tamanho da entrada. É típico em problemas que exigem a verificação de todas as permutações possíveis.

**Exemplos:**
- Algoritmo para gerar todas as permutações de uma sequência.
- Problemas de otimização que exigem a consideração de todas as ordens possíveis.

**Como identificar:**
- O algoritmo gera todas as permutações ou combinações possíveis de `n` elementos.
- O tempo de execução aumenta de forma muito rápida conforme a entrada aumenta, devido ao número crescente de permutações.

### Dicas Gerais para Análise:
1. **Contar Operações:** Identifique quantas operações são realizadas em relação ao tamanho da entrada `n`. Use o pior caso para uma análise mais conservadora.
2. **Analisar Estruturas de Controle:** Examine loops, chamadas recursivas e estruturas de controle aninhadas. A estrutura dos loops e a forma como eles se aninham podem revelar a complexidade.
3. **Dividir e Conquistar:** Algoritmos que dividem o problema em partes menores frequentemente têm complexidade logarítmica ou log-linear.
4. **Recursão:** Se um algoritmo usa recursão, analise o número de chamadas recursivas e como a entrada é dividida.



# Casos: 
### 1. **Melhor Caso**

**Conceito:**
- O melhor caso é a situação em que o algoritmo tem o desempenho mais eficiente possível, ou seja, o menor tempo de execução ou o menor número de operações necessárias.

**Como Analisar:**
- Identifique as condições que levam o algoritmo a operar com a menor quantidade de trabalho.
- Geralmente, isso ocorre quando o algoritmo encontra a solução ideal de forma rápida ou realiza menos operações devido a uma entrada específica.

### 2. **Pior Caso**

**Conceito:**
- O pior caso é a situação em que o algoritmo tem o desempenho mais ineficiente, ou seja, o maior tempo de execução ou o maior número de operações necessárias.

**Como Analisar:**
- Determine as condições que levam o algoritmo a executar o maior número de operações.
- Isso pode ocorrer quando o algoritmo precisa processar todos os elementos ou realizar a maior quantidade de trabalho possível.

### 3. **Caso Médio**

**Conceito:**
- O caso médio é a situação que representa o desempenho típico do algoritmo para uma entrada aleatória ou comum.

**Como Analisar:**
- Para analisar o caso médio, você precisa considerar todas as possíveis entradas e calcular uma média ponderada das operações realizadas.
- Isso muitas vezes envolve análise probabilística ou estatística.
minar a média.

# Pontos:
- Pontos importantes:
• A complexidade media é de mais difícil obtenção: Dificuldade maior na 
analise. 
• A complexidade no pior caso e tão importante quanto por apresentar o 
pior cenario possível.
• A complexidade no melhor caso não e tão relevante para análise de 
algoritmos.
• A complexidade do caso medio não e a média entre o pior caso e o 
melhor caso.