# Questão 3: 
## a) Atrav´es da depuração, compreenda como o código funciona.
- Compreendido
## b) Desenhe em formato de uma árvore de recursão os passos para o cálculo da procura dos n´umeros primos de 10 a 20 (usando a depuração).
- Desenhada na Folha. 
## c) Conte a quantidade de chamadas recursivas para realizar o resultado de b).
- 22 chamadas recursivas.
## d) Depure o algoritmo com os valores de entrada de 1000 e 10000. Utilize o depurador para interromper a depuração quando o 240º número primo aparecer.
- é o número 2801.
```
gdb main
(gdb) b 34
(gdb) commands 1
>silent
>set $c = $c + 1
>if ($c == 240)
 >printf "Achou", inicio
 >quit
 >end
>continue
>end
(gdb) set $c = 0
(gdb) run
(gdb) print $c
$1 = 240
(gdb) print inicio
$2 = 2801
```