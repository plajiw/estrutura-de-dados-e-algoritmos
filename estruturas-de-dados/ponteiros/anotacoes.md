# Ponteiros em C

Em um programa, cada variável tem um **endereço**, que indica sua localização na memória do computador, e um **conteúdo**, que é o valor armazenado. Geralmente os valores armazenados são escalares (inteiros, reais ou caracteres) ou não-escalares (vetores, matrizes e estruturas).

Variáveis do tipo **ponteiro** armazenam **endereços de memória** de outras variáveis; em outras palavras, ponteiros são variáveis que referenciam outras variáveis.

## Declaração

Um ponteiro é declarado através do modificador `*`, seguindo este modelo:

```c
<tipo_base> * <nome_do_ponteiro>;
```

```c
int   *pi;  // pi é um ponteiro para inteiros
float *pf;  // pf é um ponteiro para floats
char  *pc;  // pc é um ponteiro para caracteres
```

**Observação**: O ponteiro também é uma variável: ele tem tipo, tamanho, ocupa uma posição na memória (possui endereço próprio) e armazena um valor (o endereço de outra variável).

## Utilização

Ponteiros são usados principalmente de três formas:

- **Atribuir**: atribuir um valor (endereço) ao ponteiro
- **Ler**: ler o endereço armazenado no ponteiro
- **Desreferenciar**: ler ou modificar o valor da posição de memória apontada pelo ponteiro (\*p)

## Exemplo

```c
#include <stdio.h>

int main()
{
    int *p;                       // ponteiro para inteiros
    int a = 231;
    int b = 7680;

    printf("&a vale %p\n", &a);
    printf("&b vale %p\n", &b);
    printf("&p vale %p\n", &p);
    printf("p vale %p\n", p);     // valor inicial (lixo ou NULL)

    p = &a;
    printf("p vale %p\n", p);
    printf("*p vale %d\n", *p);

    p = &b;
    printf("p vale %p\n", p);
    printf("*p vale %d\n", *p);

    *p = 500;
    printf("b vale %d\n", b);

    return 0;
}
```

## Evolução dos valores na memória

| Estado          | a        | b        | p        |
| --------------- | -------- | -------- | -------- |
| Endereço        | 0x...890 | 0x...894 | 0x...898 |
| Valor inicial   | 231      | 7680     | (nil)    |
| Após `p = &a`   | 231      | 7680     | 0x...890 |
| Após `p = &b`   | 231      | 7680     | 0x...894 |
| Após `*p = 500` | 231      | 500      | 0x...894 |

## Ponteiros nulos

Um ponteiro nulo é aquele que aponta para nada, ou seja nenhum endereço válido. A macro `NULL` define o valor de ponteiros nulos, que equivalem a zero (0) no C ANSI. A tentativa de desreferenciar um ponteiro nulo resulta em erro de acesso à memória, que geralmente leva à interrupção da execução com uma mensagem de _Segmentation Fault_ ou similar.

## Ponteiros e vetores

Um vetor pode ser visto como um ponteiro para uma área de memória que contém uma sequência de valores do mesmo tipo.

```c
short int valor[5];
```

O nome `valor` é equivalente a `&valor[0]`, ou seja, o endereço do primeiro elemento do vetor.

Dessa forma, o nome de um vetor pode ser visto como um ponteiro para dados do tipo definido no vetor e aponta para o endereço do primeiro elemento do vetor. Em consequência, as seguintes declarações são equivalentes:

```c
int *ptr;   // ponteiro para inteiros
int ptr[];  // endereço de um vetor de inteiros (não alocado)
```

## Aritmética de ponteiros

Ponteiros são valores numéricos e portanto podem sofrer algumas operações aritméticas simples. Considerando T o tamanho em bytes do tipo apontado por um ponteiro, temos:

- `++`: o valor do ponteiro é incrementado de T bytes.
- `--`: o valor do ponteiro é decrementado de T bytes.
- `+`: somando n ao ponteiro, seu valor é incrementado de n × T bytes.
- `-`: subtraindo n do ponteiro, seu valor é decrementado de n × T bytes.

Além disso, ponteiros podem ser comparados (<, >, >=, <=, ==, !=, etc).

```c
int nota[5] = { 45, 78, 92, 73, 87 };
int *p;

p = nota; // p aponta para nota[0]
printf ("p: %p, *p: %d\n", p, *p);

p++;      // p aponta para nota[1]
printf ("p: %p, *p: %d\n", p, *p);

p += 3;   // p aponta para nota[4]
printf ("p: %p, *p: %d\n", p, *p);
```

A evolução do ponteiro `p` do código acima pode ser representada graficamente:

![alt text](../assets/image.png)

Dessa forma, a manipulação de vetores pode ser feita usando aritmética de ponteiros:

```c
#define SIZE 100

int v[SIZE];
int i, *p;

// preenchimento usando []
for (i = 0; i < SIZE; i++)
  v[i] = 0;

// preenchimento usando aritmética de ponteiros
for (p = v; p < v + SIZE; p++)
  *p = 0;

// ou ainda...
for (i = 0; i < SIZE; i++)
  *(v + i) = 0;
```

## Ponteiros para ponteiros

Como visto acima, um ponteiro é uma variável que pode conter o endereço (“apontar”) de outras variáveis. Nada impede um ponteiro de conter o endereço de outro ponteiro, o que chamados de referencia indireta, ponteiro duplo ou ponteiro para ponteiro.

```c
#include <stdio.h>

int main ()
{
  int a = 231;
  int *pd;  // ponteiro direto
  int **pi; // ponteiro indireto, equivale a int *(*p)

  pd = &a;  // pd recebe o endereço de um int
  pi = &pd; // pi recebe o endereço de um ponteiro para int

  printf ("a  está em %p e vale %d\n", &a, a);
  printf ("pd está em %p e vale %p\n", &pd, pd);
  printf ("pi está em %p e vale %p\n", &pi, pi);

  printf ("*pd  vale %d\n", *pd);
  printf ("*pi  vale %p\n", *pi);
  printf ("**pi vale %d\n", **pi);

  return 0;
}
```

## Ponteiros void

Um ponteiro de tipo `void` é considerado um ponteiro genérico, que pode referenciar qualquer endereço de memória independente de seu tipo. Ponteiros `void` são muito usados para trasferir parâmetros genéricos para funções, ou para construir estruturas de dados genéricas, que podem armazenar/referenciar dados de diversos tipos.

```c
void *ptr;
```

Por não terem um tipo predefinido, ponteiros `void` não podem ser desreferenciados. As operações aritméticas sobre ponteiros `void` consideram como tamanho básico 1 byte.

```c
#include <stdio.h>

int main ()
{
  int a = 34;
  int b;
  void *p;

  p = &a;
  b = *p;  // erro de compilação!

  printf ("p vale %p\n", p);
  p++;
  printf ("p vale %p\n", p);

  return 0;
}
```

## Referências

<https://wiki.inf.ufpr.br/maziero/doku.php?id=prog1:cronograma_2024_2>

<https://wiki.inf.ufpr.br/maziero/doku.php?id=c:ponteiros>

<https://embarcados.com.br/ponteiro-em-c-aritmetica-de-ponteiro/>

<https://www.inf.pucrs.br/~pinho/PRGSWB/Ponteiros/ponteiros.html>

<https://www.w3schools.com/c/c_pointers.php>

<https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Pointers.html>

<https://www.ime.usp.br/~pf/algorithms/chapters/pointers.html>

<https://www.bosontreinamentos.com.br/programacao-em-linguagem-c/ponteiros-em-c-aritmetica-de-ponteiros/>
