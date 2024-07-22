# Exercício
- Considere os seguintes tempos para o algoritmo abaixo:
+ Chamada Recursiva: 2ns
+ Retorno da chamada recursiva: 1 ns
+ Atribuição e soma 0.5ns
+ divisão e multiplicação: 1.5ns
- Algoritmo 
```c
int f(int n){
    if(n == 0){
        return 1;
    }
    return f(n-1) + 1/f(n-1);
}
```
- Midifique o código e/ou use o GDB para calcular os tempos deste algoritmo para n = 30.