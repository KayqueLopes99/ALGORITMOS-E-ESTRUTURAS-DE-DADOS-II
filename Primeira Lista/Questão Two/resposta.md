# a) Execute o algoritmo em modo de depuração.
- Executado:
- Comandos: 
```
gcc -o main .\t.c -g
gdb main
b operacaoMatematica
run
```
# b) Descubra através da depuração, qual a maior profundidade de (frames) esse código alcan¸ca.
- 

# c) Descubra o que ocorre quando um parâmetro é 0.
- Quando o parâmetro é zero, da varíavel "A", o valor 0 de "A" adquire o Valor da varíavel "B" que é maior que zero.

### Abaixo está os Comandos Usados.
```
gcc -o main .\t.c -g
gdb main
(gdb) b operacaoMatematica
Breakpoint 1 at 0x40131e: file .\t.c, line 7.
(gdb) run
 Digite o primeiro numero : 0
 Digite o segundo numero : 123

Breakpoint 1, operacaoMatematica (a=0, b=123) at .\t.c:7
7        while ( b != 0) {
(gdb) next                
8        r = a % b ;
(gdb) where
#0  operacaoMatematica (a=0, b=123) at .\t.c:8
#1  0x004013a3 in main () at .\t.c:25
(gdb) next 
9        a = b ;
(gdb) where
#0  operacaoMatematica (a=0, b=123) at .\t.c:9
#1  0x004013a3 in main () at .\t.c:25
(gdb) next 
10       b = r ;
(gdb) where
#0  operacaoMatematica (a=123, b=123) at .\t.c:10
#1  0x004013a3 in main () at .\t.c:25
(gdb) next 
7        while ( b != 0) {
(gdb) where
#0  operacaoMatematica (a=123, b=0) at .\t.c:7
#1  0x004013a3 in main () at .\t.c:25
(gdb) next 
13       return a ;
(gdb) next
14       }
(gdb) next
main () at .\t.c:27
27       printf ("A operacao de %d e %d e: %d\n",num1 ,num2 ,res );
(gdb) next
A operacao de 0 e 123 e: 123
29       return 0;
(gdb)
```
- Em casos quo o Parâmetro for zero na varíavel "B", a codição do while é atendida e o código finaliza.

# d) Descubra o que ocorre quando os dois parâmetros apresentados são iguais e maiores que 1.
- O código segue normalmente, na linha 8, o resto da divisão de dois números iguais é 1.
- Depois na linha 10, a varíavel "B" vai ser igual ao resto dessa divisão.
- Após isso as operações são repetidas enquanto "B" for diferente de zero.
- Agora teremos o resto da divisão do valor de "A" pelo valor de "B" que é 1.
- Resultando em restto da divisão  igual a 0, "B" adquire esse valor e loop termina.

### Abaixo está os Comandos Usados.
```
gdb main
(gdb) b operacaoMatematica
(gdb) run
 Digite o primeiro numero : 145
 Digite o segundo numero : 145

Breakpoint 1, operacaoMatematica (a=145, b=145) at .\t.c:7
7        while ( b != 0) {
(gdb) next                
8        r = a % b ;
(gdb) where
#0  operacaoMatematica (a=145, b=145) at .\t.c:8
#1  0x004013a3 in main () at .\t.c:25
(gdb) next 
9        a = b ;
(gdb) where
#0  operacaoMatematica (a=145, b=145) at .\t.c:9
#1  0x004013a3 in main () at .\t.c:25
(gdb) next 
10       b = r ;
(gdb) where
#0  operacaoMatematica (a=145, b=145) at .\t.c:10
#1  0x004013a3 in main () at .\t.c:25
(gdb) next 
7        while ( b != 0) {
(gdb) where
#0  operacaoMatematica (a=145, b=0) at .\t.c:7
10       b = r ;
(gdb) where
#0  operacaoMatematica (a=145, b=145) at .\t.c:10
#1  0x004013a3 in main () at .\t.c:25
(gdb) next
7        while ( b != 0) {
(gdb) where
#0  operacaoMatematica (a=145, b=0) at .\t.c:7
(gdb) where
#0  operacaoMatematica (a=145, b=145) at .\t.c:10
#1  0x004013a3 in main () at .\t.c:25
(gdb) next
7        while ( b != 0) {
(gdb) where
#0  operacaoMatematica (a=145, b=0) at .\t.c:7
#0  operacaoMatematica (a=145, b=145) at .\t.c:10
#1  0x004013a3 in main () at .\t.c:25
(gdb) next
7        while ( b != 0) {
(gdb) where
#0  operacaoMatematica (a=145, b=0) at .\t.c:7
(gdb) next
7        while ( b != 0) {
(gdb) where
#0  operacaoMatematica (a=145, b=0) at .\t.c:7
(gdb) where
#0  operacaoMatematica (a=145, b=0) at .\t.c:7
#0  operacaoMatematica (a=145, b=0) at .\t.c:7
#1  0x004013a3 in main () at .\t.c:25
#1  0x004013a3 in main () at .\t.c:25
(gdb) next
(gdb) next
13       return a ;
(gdb) where
#0  operacaoMatematica (a=145, b=0) at .\t.c:13
#1  0x004013a3 in main () at .\t.c:25
(gdb) next
14       }
(gdb) where
#0  operacaoMatematica (a=145, b=0) at .\t.c:14
#1  0x004013a3 in main () at .\t.c:25
(gdb) next
main () at .\t.c:27
27       printf ("A operacao de %d e %d e: %d\n",num1 ,num2 ,res );      
(gdb) next
A operacao de 145 e 145 e: 145
29       return 0;
(gdb)
```