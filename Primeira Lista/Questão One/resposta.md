# Questão 1 (A):
## a) Depure o código para descobrir quantas vezes o fibonacci(5) é calculado (requisitado).
- Resultado fibonacci(5) é requisitado 89 Vezes.

### Abaixo está os Comandos Usados.
PS C:\Users\kaiqu\OneDrive\Imagens\ED2> gdb main
(gdb) b fibonacci 
Breakpoint 1 at 0x40131f: file .\pri.c, line 3.
(gdb) run
(gdb) command 
>set $c = 0
>commands 1
 >silent
 >if n == 5
  >set $c = $c + 1    
  >end
 >cont
 >end
>end
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
(gdb) next
(gdb) next
(gdb) continue
The program is not being run.
(gdb) print $c
$1 = 89

# Questão 1 (B):
## b) Descubra através da depuração, qual a maior quantidade de n´ıveis (frames) esse código alcança.
- 16 frames é a maior quantidade.

### Abaixo está os Comandos Usados.
gdb main
(gdb) b fibonacci 
(gdb) run
where
continue até o ultimo número que é o zero. 
15 frames + 0 frame = 16 frames. 
Questão 1 (C):


# Questão 1 (C):
## c) Depure o código até o momento que o primeiro fibonacci(14) é calculado e o executável ira começar a calcular o fibonacci(13).
- Realizada com sucesso. 
### Abaixo está os Comandos Usados.
 gdb main
(gdb) b fibonacci
(gdb) run
Breakpoint 1, fibonacci (n=15) at .\pri.c:3
warning: Source file is more recent than executable.
3        int fibonacci (int n ) {
(gdb) next
7        else {
warning: Source file is more recent than executable.
3        int fibonacci (int n ) {
(gdb) next
7        else {
(gdb) next
7        else {
7        else {
(gdb) next

Breakpoint 1, fibonacci (n=14) at .\pri.c:3
3        int fibonacci (int n ) {
(gdb) print n
$1 = 14
(gdb) next
7        else {
(gdb) next

Breakpoint 1, fibonacci (n=13) at .\pri.c:3
3        int fibonacci (int n ) {
(gdb) quit