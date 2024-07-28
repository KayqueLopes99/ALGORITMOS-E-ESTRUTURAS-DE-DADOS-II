# Recursão: 
## Conceito: 
- Chamamos de recursividade ou recursão quando uma função chama a si mesma.
- Toda recursividade é composta por um caso base e pelas chamadas recursivas,.

- Caso base: é o caso mais simples. É usada uma condição em que se resolve o problema com facilidade.

- Chamadas Recursivas: procuram simplificar o problema de tal forma que convergem para o caso base.
## Vantagens:
- Simplicidade e Clareza:

- **Código Mais Limpo** Para muitos problemas, especialmente os que envolvem estruturas de dados recursivas (como árvores e grafos), a solução recursiva pode ser mais intuitiva e simples de entender.
- **Redução de Código** Problemas que envolvem divisão e conquista podem ser mais concisamente resolvidos com recursividade.

-**Facilita Soluções Elegantes**
-**Problemas Naturais Recursivos** Alguns problemas têm uma natureza recursiva, como percorrer árvores ou resolver subproblemas em algoritmos de busca. Recursividade pode tornar esses problemas mais naturais de implementar.

-**Facilidade de Implementação**
-**Algoritmos Complexos** Algoritmos como o de busca binária, mergesort e quicksort são mais fáceis de implementar de forma recursiva. A abordagem recursiva pode simplificar a lógica do algoritmo

## Desvantagens: 
- Definicões recursivas de sequˆencias tem uma desvantagem: Para determinar o
valor de um elemento, e necess´ario conhecer todos os outros elementos anteriores.
Como soluc¸˜ao, deve-se encontrar uma express˜ao iterativa para a resoluc¸˜ao sem
que seja conhencido os termos anteriores.



## Exemplo Clássico: 
- Cálculo Fatorial.
### O que é o Fatorial?
- O fatorial de um número inteiro não-negativo \( n \) é o produto de todos os inteiros positivos menores ou iguais a \( n \). É representado por \( n! \). 

- Por exemplo:
- \( 5! = 5 * 4 * 3 * 2 * 1 = 120 \)
- \( 0! = 1 \) (por definição)


### Implementação Recursiva do Cálculo Fatorial

```c
#include <stdio.h>

// Função recursiva para calcular o fatorial
int fatorial(int n) {
    // Condição de parada: o fatorial de 0 é 1
    if (n == 0) {
        return 1;
    } else {
        // Chamada recursiva: n! = n * (n-1)!
        return n * fatorial(n - 1);
    }
}

int main() {
    int num = 5; // Número para calcular o fatorial
    printf("O fatorial de %d é %d\n", num, fatorial(num));
    return 0;
}
```

### Como Funciona?

1. **Condição de Parada**: Toda função recursiva precisa de uma condição de parada para evitar chamadas infinitas. No exemplo acima, a condição de parada é quando **n** é 0. Nesse caso, o fatorial de 0 é retornado como 1.
   
2. **Chamada Recursiva**: Se **n** não é 0, a função se chama novamente com o argumento **n - 1**. Cada chamada recursiva multiplica **n** pelo resultado da chamada recursiva com **n - 1**.

### Exemplo de Execução

- Se chamarmos `fatorial(5)`, a execução será a seguinte:

1. `fatorial(5)` chama `fatorial(4)`
2. `fatorial(4)` chama `fatorial(3)`
3. `fatorial(3)` chama `fatorial(2)`
4. `fatorial(2)` chama `fatorial(1)`
5. `fatorial(1)` chama `fatorial(0)`
6. `fatorial(0)` retorna 1

- Então, cada chamada retorna e multiplica o valor:

- `fatorial(1) = 1 * 1 = 1`
- `fatorial(2) = 2 * 1 = 2`
- `fatorial(3) = 3 * 2 = 6`
- `fatorial(4) = 4 * 6 = 24`
- `fatorial(5) = 5 * 24 = 120`

## Exemplo do cálculo da potência: 
- pot(x, n) = x^n
```c
#include <stdio.h>

// Função recursiva para calcular a potência
double potencia(double base, int expoente) {
    // Caso base: qualquer número elevado a 0 é 1
    if (expoente == 0) {
        return 1;
    }
    // Caso base para expoente negativo: 1 / base^|expoente|
    else if (expoente < 0) {
        return 1 / potencia(base, -expoente);
    }
    // Caso recursivo: base * (base^expoente-1)
    else {
        return base * potencia(base, expoente - 1);
    }
}

int main() {
    double base;
    int expoente;

    printf("Digite a base: ");
    scanf("%lf", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    printf("%.2lf^%d = %.6lf\n", base, expoente, potencia(base, expoente));

    return 0;
}
```



### Exemplo

Para calcular \( 2^{-3} \):

- A chamada inicial é `potencia(2, -3)`.
- A função entra na condição para expoente negativo e chama `potencia(2, 3)`.
- A chamada inicial é `potencia(2, 3)`.
- A função entra no caso recursivo e chama `potencia(2, 2)`.
- `potencia(2, 2)` chama `potencia(2, 1)`.
- `potencia(2, 1)` chama `potencia(2, 0)`.
- `potencia(2, 0)` retorna 1 (caso base).
- `potencia(2, 1)` calcula `2 * 1 = 2` e retorna 2.
- `potencia(2, 2)` calcula `2 * 2 = 4` e retorna 4.
- `potencia(2, 3)` calcula `2 * 4 = 8` e retorna 8.
- Finalmente, `potencia(2, -3)` calcula `1 / 8.0 = 0.125` e retorna 0.125.

### Explicação

1. **Caso Base**:
   - Quando o expoente é 0, o resultado é 1. Isso porque qualquer número elevado a 0 é 1. Este é o caso base que encerra a recursão.

2. **Caso Recursivo**:
   - Se o expoente não é 0.
   - O caso recursivo lida com expoentes não-zero. Dependendo do valor do expoente, a função faz uma chamada recursiva para resolver o problema de forma mais simples.

### Como Funciona
- Esse processo divide o problema até que o caso base seja alcançado, depois combina os resultados das chamadas recursivas para obter a solução final.

# Exemplo Torre de Hanoi:
- MOVER(N, ORIGEM, DESTINO, AUXILIAR).

- Passo 1: MOVER(N-1, ORIGEM, AUXILIAR, DESTINO).

- Passo 2: MOVER O DISCO DA ORIGEM PARA O DESTINO.

- Passo 3: MOVER(N-1, AUXILIAR, DESTINO, ORIGEM).

# Tipagens:
## Recursão de Calda:  
- A recursão de cauda é definida pelo uso somente de uma chamada recursiva no final de uma implementacão de funcão.

- Na recursão de cauda, a chamada recursiva é a última operação executada pela função antes de retornar o resultado. Em outras palavras, não há trabalho a ser feito após a chamada recursiva retornar.

- O resultado da chamada recursiva é diretamente retornado sem necessidade de qualquer processamento adicional.

Vamos analisar os exemplos de funções recursivas fornecidos, distinguindo entre recursão de cauda e recursão que não é de cauda.

#### Exemplo: Recursão de Cauda

```c
void tail(int i) {
    if (i > 0) {
        printf("%d", i);
        tail(i - 1);
    }
}
```

1. **Caso Base**: Quando `i <= 0`, a função não faz nada (não imprime nada e não chama a função recursivamente).

2. **Caso Recursivo**:
   - **Operação**: Primeiro, imprime o valor de `i` e depois chama a função `tail` com `i - 1`.
   - **Recursão de Cauda**: A chamada recursiva `tail(i - 1)` é a última operação executada dentro do bloco `if`. Após a chamada recursiva, a função `tail` não realiza mais nenhum processamento antes de retornar.


## Recursão que Não é de Cauda

- Na recursão que não é de cauda, a função realiza alguma operação adicional após a chamada recursiva antes de retornar. Isso geralmente envolve manipulação dos resultados da chamada recursiva ou execução de código adicional.
- Ocupam mais espac¸o na execuc¸˜ao;
Demandam mais tempo;
- O algoritmo tem um tempo de vida
menor:
- Por ocupar mais espac¸o na
mem´oria, o programa ´e finalizado
antecipadamente.
- Poss´ıvel erro 1: Mem´oria
totalmente ocupada;
- Poss´ıvel erro 2: Programa
executado compromente a
execuc¸˜ao dos sistema
#### Exemplo: Recursão que Não é de Cauda

```c
void nonTail(int i) {
    if (i > 0) {
        nonTail(i - 1);
        printf("%d", i);
    }
}
```

1. **Caso Base**: Quando `i <= 0`, a função não faz nada (não imprime nada e não chama a função recursivamente).

2. **Caso Recursivo**:
   - **Operação**: Primeiro, chama a função `nonTail(i - 1)`, e após a chamada recursiva retornar, imprime o valor de `i`.
   - **Recursão que Não é de Cauda**: A chamada recursiva `nonTail(i - 1)` não é a última operação; após retornar da chamada recursiva, a função imprime o valor de `i`. Portanto, a função realiza processamento adicional (a impressão) após a chamada recursiva.


### Comparação:
- **Recursão de Cauda**:
  - **Exemplo**: A função `tail` imprime números de forma decrescente, começando pelo valor de `i`.

- **Recursão Não de Cauda**:
  - **Exemplo**: A função `nonTail` imprime números de forma crescente após a chamada recursiva, começando pelo valor de `i`.


# Conversão de recursão de calda em uma função não recursiva:

- Substituídas por loops iterativos.

### Recursão de Cauda e Iteração
- Na recursão de cauda, a chamada recursiva é a última operação realizada 
- antes de retornar, permitindo que a recursão possa ser convertida em um 
- loop iterativo. Vamos ver como isso é feito.

#### Função Recursiva de Cauda
```c
void tail(int i) {
    if (i > 0) {
        printf("%d", i);
        tail(i - 1);
    }
}
```
- **Conversão para Iteração**: 
- Como a chamada recursiva é a última operação e não há processamento adicional 
- após ela, podemos converter isso diretamente em um loop.

#### Conversão para Iterativo
- Função Iterativa Equivalente com `for`:

```c
void iterativoTail_1(int i) {
    for (; i > 0; i--) {
        printf("%d", i);
    }
}
```

**Explicação**:
- O loop `for` executa enquanto `i > 0`, decrementando `i` a cada iteração e imprimindo o valor de `i`.
- O comportamento é equivalente ao da função recursiva de cauda, imprimindo os números de `i` até 1.

- Função Iterativa Equivalente com `while`:

```c
void iterativoTail_2(int i) {
    while (i > 0) {
        printf("%d", i++);
    }
}
```

**Explicação**:
- O loop `while` executa enquanto `i > 0`, incrementando `i` a cada iteração e imprimindo o valor de `i`.
- Note que o valor de `i` é incrementado em vez de decrementado, o que resulta em uma impressão crescente, ao contrário do exemplo original.

## Comparação:
- Pense no fatorial de 3!
- Fatorial recursivo:
```c
1 int fatorial (int n ) {
2 if ( n == 0) {
3 return 1;
4 } else {
5 return n *
6 fat ( n - 1);
7 }
8 }
```
- Fatorial Iterativo:
```c
1 int fat2 (int n ) {
2 int i = n , res = 1;
3 while ( i > 1) {
4 res = res * i - -;
5 }
6 return res ;
7 }
```


# Recursão Indireta

-  uma função `A` chama uma função `B`, e a função `B` chama de volta a função `A`. 
- Em outras palavras, a recursão não acontece diretamente na função que se chama a 
- si mesma, mas através de uma cadeia de chamadas de funções.

### Exemplo Simples em C
```c
#include <stdio.h>

void funcaoA(int n);
void funcaoB(int n);

void funcaoA(int n) {
    if (n <= 0) {
        printf("funcaoA: n = %d\n", n);
        return;
    }
    printf("funcaoA: n = %d\n", n);
    funcaoB(n - 1);  // Chama funcaoB, que vai chamar funcaoA novamente
}

void funcaoB(int n) {
    if (n <= 0) {
        printf("funcaoB: n = %d\n", n);
        return;
    }
    printf("funcaoB: n = %d\n", n);
    funcaoA(n - 1);  // Chama funcaoA, que vai chamar funcaoB novamente
}

int main() {
    funcaoA(3);  // Começa o ciclo de chamadas
    return 0;
}
```

### Como Funciona

1. **`main()`** começa chamando `funcaoA(3)`.
2. **`funcaoA(3)`** imprime o valor de `n` e chama `funcaoB(2)`.
3. **`funcaoB(2)`** imprime o valor de `n` e chama `funcaoA(1)`.
4. **`funcaoA(1)`** imprime o valor de `n` e chama `funcaoB(0)`.
5. **`funcaoB(0)`** imprime o valor de `n` e não chama mais nenhuma função, pois a condição de parada é alcançada.

- A execução desse código resultará na impressão das mensagens intercaladas
- entre `funcaoA` e `funcaoB` até que `n` chegue a zero e as funções parem de se chamar.

### Por Que Usar Recursão Indireta?

A recursão indireta pode ser útil para dividir um problema em subproblemas que são naturalmente relacionados entre si. Pode tornar o código mais modular e permitir que funções especializadas lidem com diferentes aspectos de um problema, trabalhando em conjunto.

# Recursão Infinita:
- provocada por inexistência de caso base.
- Pode ser que o caso base seja inalcancável;
- O programa ir´a alcançar o limite da pilha, havendo um estouro da mem´oria.
``` c
// Algoritmo com recursão infinita
1 int fat (int n ){
2 return n * fat (n -1);
3 }
```
# Recursão Extensiva: 
- Recursão extensiva refere-se a uma abordagem de recursão em que uma função recursiva faz chamadas a várias instâncias de si mesma, muitas vezes com diferentes parâmetros ou em diferentes contextos. Em outras palavras, a função não só se chama repetidamente, mas também realiza muitas operações recursivas antes de terminar.
- Exemplo Fibonacci.
``` c
fibonacci(5)
 ├─ fibonacci(4)
 │   ├─ fibonacci(3)
 │   │   ├─ fibonacci(2)
 │   │   │   ├─ fibonacci(1)
 │   │   │   └─ fibonacci(0)
 │   │   └─ fibonacci(1)
 │   └─ fibonacci(2)
 │       ├─ fibonacci(1)
 │       └─ fibonacci(0)
 └─ fibonacci(3)
     ├─ fibonacci(2)
     │   ├─ fibonacci(1)
     │   └─ fibonacci(0)
     └─ fibonacci(1)
```

# Recursão Aninhada: 
- A função recursiva faz chamadas para outras funções (ou para si mesma) de maneira aninhada. 
- Isso significa que dentro do corpo de uma função recursiva, há chamadas para outras funções
- (que podem também ser recursivas), e essas funções podem fazer chamadas adicionais, formando
- um "ninho" de chamadas recursivas.

```c
#include <stdio.h>

int auxiliar(int n) {
    if (n <= 0) {
        return 1;
    }
    return auxiliar(n - 1) * 2;  // Recursão aninhada
}

int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    // Chama auxiliar recursivamente
    return n * auxiliar(n - 1) * fatorial(n - 1);
}

int main() {
    int num = 4;
    printf("Resultado: %d\n", fatorial(num));
    return 0;
}

```
