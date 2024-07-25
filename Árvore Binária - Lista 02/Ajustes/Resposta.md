PS C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02> gcc -o main Arvore.c -g
PS C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02> gdb main
GNU gdb (GDB) 7.6
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-pc-mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02\main.exe...donThis GDB was configured as "i686-pc-mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02\main.exe...done.
This GDB was configured as "i686-pc-mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02\main.exe...donFor bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02\main.exe...don<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02\main.exe...done.
(gdb) b main
Reading symbols from C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02\main.exe...done.
(gdb) b main
e.
(gdb) b main
(gdb) b main
Breakpoint 1 at 0x401326: file Arvore.c, line 25.
Breakpoint 1 at 0x401326: file Arvore.c, line 25.
(gdb) r
Starting program: C:\Users\kaiqu\OneDrive\Imagens\ALGORITMOS-E-ESTRUTURAS-DE-DADOS-II\Árvore Binária - Lista 02\main.exe
[New Thread 10924.0x2b70]
[New Thread 10924.0x213c]
warning: Can not parse XML library list; XML support was disabled at compile time

Breakpoint 1, main () at Arvore.c:25
25          struct Node *raiz = criarNode("Kayque", 3, 1, rand() % 10);
(gdb) n
26          struct Node *nodeSa = criarNode("Samuel", 4, 1, rand() % 10);
(gdb) n
27          raiz->dir = nodeSa;
(gdb) n
29          return 0;
(gdb) print raiz->dir
$1 = (struct Node *) 0x8c2508
(gdb) print raiz->dir.info
$2 = {
  nome = "Samuel\000º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º\rð­º", mat = 4, turma = 1, nota = 7}
(gdb) printf "%s\n", raiz->dir->info->nome
Samuel