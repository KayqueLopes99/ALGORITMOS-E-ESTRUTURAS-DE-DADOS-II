# Exercício
- Considere os seguintes tempos para o algoritmo abaixo:
+ Chamada Recursiva: 2ns X 1048575 = 2097150ns
+ Retorno da chamada recursiva: 1 ns X 1048575 =  1048575ns
+ Atribuição e soma 0.5ns X 1048575 = 524287.5ns
+ divisão e multiplicação: 1.5ns X 1048575 = 1572862.5 ns
- Algoritmo 
```c
int f(int n){
    if(n == 0){
        return 1;
    }
    return f(n-1) + 1/f(n-1);
}
```
- Midifique o código e/ou use o GDB para calcular os tempos deste algoritmo para n = 20.
Resposta : 1048575