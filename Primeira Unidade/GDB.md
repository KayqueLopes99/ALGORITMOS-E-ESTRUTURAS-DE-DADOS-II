# O Gdb
- É uma forma de depurar códigos para facilitar as demandas.
## Comandos:
### Inicialização:
``` 
gcc -o main .\pri.c -g
```
- -o (Cria o executavel)
- main (Nome do executavel)
- pri.c (Nome do arquivo)
- -g (Depuracao)

- gdb Nome_do_Programa.
### list
- Coloca o seu código fonte na Tela.
- Podemos listar apartir de um linha especifica.
- list ou list linha.

### Break
- Breakpoints significa, quando eu chegar nesta linha 
- Forma abreviada: b.
- Sintaxe:
- b nome_da_função ou b linha.
- Podemos colocar condições para silazinar onde será o Breakpoint como:
- b nome_da_função if variável == valor.

### Print
- Imprime a Variável.
- print varíavel.
-Abreviação p.

### Run
- Executar ou Rodar
- Abreviação r.

### continue
- continua a execução até o próximo breakponit.
- Abreviação c: continua a execução do programa até a próxima parada.

### step
- Executar uma linha de código.
- Abreviação s.

### Where
-  Mostra a sequência de funções que levaram à posição atual no código.
- Cada função corresponde a um frame na pilha. Portanto,  podemos contar quantas funções estão listadas no resultado do where para determinar o número de frames envolvidos.

### frame
- frame indice do where.
- Descreve o frame atual.

### Info breakpoints
- Lista os breakponits.

### delete 
- Remover os breakponits
- delete ou d: remove todos os breakpoints.

### Next
- next ou n: igual ao s, porém, não entra em funções.

### command
- Colocar comandos para pontuar.

#### Declarar varíaveis:
- set $variavel = inicialização_opcional.
- o set cria a varíavel.
- para imprimila usa p $varíavel.

#### Especificar uma lista de comandos:
- comands número_breakpoint

#### Sem interrupção:
- silent.
- útil para que o GDB execute automaticamente alguns comandos sem interrupção quando um breakpoint é atingido.

#### cont:
- Continua a execução até o final do programa, se não houver mais breakpoints.

#### Exemplo: 
```
set $contador = 0
commands 1
silent
if n == 5
set $contador = $contador + 1
end
cont
end
```

### quit 
- Encerrar

# O gcc
# gcc compiler
0. dir. verificação se os arquivos estão.
1. Compile o arquivo `operacao.c` para gerar o arquivo de objeto `operacao.o`:
```bash
gcc -c operacao.c
```
2. Compile o arquivo `TAREFAmain.c` para gerar o arquivo de objeto `TAREFAmain.o`:
```bash
gcc -c TAREFAmain.c
```
3. Vincule os arquivos de objeto `operacao.o` e `TAREFAmain.o` para criar um executável chamado `programa`:
```bash
gcc -o programa operacao.o TAREFAmain.o -lm
```
4. ./programanomeescolhido. sem espaços e _.

O `-lm` é necessário para vincular a biblioteca matemática devido ao uso da biblioteca `<math.h>` no seu código. 
