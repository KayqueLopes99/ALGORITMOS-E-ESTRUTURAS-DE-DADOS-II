# Questão 4:
## a) Através da depuração, realize a interrupção do algoritmo toda vez queas duas coordenadas são maiores que 0.
- Realizada com sucesso, os comandos estão abaixo.
```
PS  gdb main
(gdb) b 16 if px > 0 && py > 0
(gdb) run

Breakpoint 1, gerarNumerosAleatorios () at F.c:16
16              printf("P = (%d, %d)\n ", px, py);
(gdb) continue
Continuing.
P = (24, 47)
(gdb) quit
```

## b) Utilize a depuração para realizar interrupções no algoritmo somente quando os pontos estiver na região externa ao círculo.
- Sabemos será gorado pontos neste espaço, para pontos externos ao circulo, podemos usar a equação da circuferência e altera-la:
- Antes: x^2 + y^2 = r^2 
- Depois: x^2 + y^2 > r^2
```
(gdb) gdb main
(gdb) break 13 if px * px + py * py > 2500
(gdb) run

```

## c) Utilize a depura¸c˜ao para realizar interrup¸c˜oes no algoritmo somente quando os pontos estiver na região interna ao círculo.
- Sabemos será gorado pontos neste espaço, para pontos internos ao circulo, podemos usar a equação da circuferência e altera-la:
- Antes: x^2 + y^2 = r^2 
- Depois: x^2 + y^2 <= r^2
```
(gdb) gdb main
(gdb) break 13 if px * px + py * py <= 2500
(gdb) run
```