# Ponteiros e Arrays em C — Anotações Básicas

## Variável simples
- Uma variável comum ocupa **um endereço de memória** e armazena **um valor**.
- O operador `&` retorna o endereço da variável.

```c
int myAge = 22;
printf("%d\n", myAge);   // valor
printf("%p\n", &myAge); // endereço
Ponteiro
Um ponteiro é uma variável que armazena um endereço de memória.

O tipo do ponteiro indica o tipo do dado apontado.

int *ptr = &myAge;

printf("%d\n", myAge);  // valor
printf("%p\n", &myAge); // endereço da variável
printf("%p\n", ptr);    // endereço armazenado no ponteiro
*ptr (desreferenciação) acessa o valor contido no endereço.

Array
Um array é um bloco contíguo de memória.

Cada elemento ocupa posições sequenciais.

int arr[4] = {25, 50, 75, 100};
Endereços dos elementos são consecutivos:

printf("%d\n", arr[i]);   // valor
printf("%p\n", &arr[i]);  // endereço
sizeof
sizeof retorna o tamanho em bytes de um tipo ou variável.

int myInt;
printf("%zu\n", sizeof(myInt));
Array como ponteiro (decay)
O nome do array não é um ponteiro, mas:

Em expressões, ele decai para um ponteiro para o primeiro elemento.

int myNumbers[4] = {25, 50, 75, 100};

printf("%p\n", myNumbers);     // endereço base
printf("%p\n", &myNumbers[0]); // mesmo endereço
Aritmética de ponteiros
myNumbers[i] é equivalente a *(myNumbers + i).

printf("%d\n", *myNumbers);       // myNumbers[0]
printf("%d\n", *(myNumbers + 1)); // myNumbers[1]
printf("%d\n", *(myNumbers + 2)); // myNumbers[2]
Iteração:

for (int i = 0; i < size; i++)
{
    printf("%d\n", *(myNumbers + i));
}
Escrita via desreferenciação
É possível modificar o array acessando o valor apontado.

*myNumbers = 13; // altera myNumbers[0]

## Referências

- https://www.w3schools.com/c/c_pointers.php
- https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Pointers.html
- https://www.ime.usp.br/~pf/algorithms/chapters/pointers.html