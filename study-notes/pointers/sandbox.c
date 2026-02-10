#include <stdio.h>

int main()
{
    // VARIÁVEL SIMPLES
    // Uma variável comum ocupa um endereço de memória e guarda um valor.

    int myAge = 22;

    printf("%d\n", myAge);   // Valor armazenado na variável
    printf("%p\n", &myAge);  // Endereço de memória da variável (operador &)

    // PONTEIRO
    // Um ponteiro é uma variável cujo valor é um endereço de memória.
    // Aqui, ptr guarda o endereço de myAge.

    int *ptr = &myAge;

    printf("%d\n", myAge);   // Valor original
    printf("%p\n", &myAge);  // Endereço da variável
    printf("%p\n", ptr);     // Endereço armazenado no ponteiro

    // A desreferenciação (*ptr) acessaria o valor contido nesse endereço.

    // ARRAY
    // Um array é um bloco contíguo de memória.
    // Cada elemento ocupa posições sequenciais.

    int arr[4] = {25, 50, 75, 100};
    int arrSize = sizeof(arr) / sizeof(int);

    for (int i = 0; i < arrSize; i++)
    {
        printf("%d\n", arr[i]);   // Valor do elemento
        printf("%p\n", &arr[i]);  // Endereço de cada elemento
    }

    // sizeof
    // sizeof retorna o tamanho em bytes do tipo ou da variável.

    int myInt;
    printf("%zu\n", sizeof(myInt));

    // ARRAY COMO PONTEIRO
    // Em expressões, o nome do array "decai" para um ponteiro
    // para o primeiro elemento do array.
    // - array NÃO é um ponteiro
    // - mas em muitos contextos, ele se comporta como um ponteiro

    int myNumbers[4] = {25, 50, 75, 100};
    int myNumbersSize = sizeof(myNumbers) / sizeof(int);

    printf("%p\n", myNumbers);        // Endereço base do array
    printf("%p\n", &myNumbers[0]);    // Endereço do primeiro elemento

    // Como myNumbers aponta para o primeiro elemento,
    // a desreferenciação acessa myNumbers[0].

    printf("%d\n", *myNumbers);
    printf("%d\n", *(myNumbers + 1));
    printf("%d\n", *(myNumbers + 2));

    // ITERAÇÃO COM ARITMÉTICA DE PONTEIROS
    // *(myNumbers + i) é equivalente a myNumbers[i]

    for (int i = 0; i < myNumbersSize; i++)
    {
        printf("%d\n", *(myNumbers + i));
    }

    // DESREFERENCIAÇÃO PARA ESCRITA
    // Aqui, *myNumbers acessa diretamente myNumbers[0].
    // A atribuição altera o valor no array.

    *myNumbers = 13;

    for (int i = 0; i < myNumbersSize; i++)
    {
        printf("%d\n", *(myNumbers + i));
    }

    return 0;
}
