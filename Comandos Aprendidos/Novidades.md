## CTRNCPY: 
- O comando `strncpy` é uma função da biblioteca padrão `string.h`, usada para copiar um número especificado de caracteres de uma string para outra. 

### Sintaxe

```c
char *strncpy(char *dest, const char *src, size_t n);
```

- `dest`: Ponteiro para o array de destino onde a string será copiada.
- `src`: Ponteiro para a string de origem que será copiada.
- `n`: Número máximo de caracteres a serem copiados da string de origem.

### Comportamento
- `strncpy` copia até `n` caracteres da string `src` para `dest`.

### Exemplo:


```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, world!";
    char dest[20];

    // Copia os primeiros 5 caracteres de src para dest
    strncpy(dest, src, 5);

    // Adiciona o caractere nulo de terminação manualmente
    dest[5] = '\0';

    printf("String copiada: %s\n", dest);

    return 0;
}
```

**Saída:**
```
String copiada: Hello
```
