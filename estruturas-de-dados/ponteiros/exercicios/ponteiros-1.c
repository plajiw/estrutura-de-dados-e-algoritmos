#include <stdio.h>

int main()
{
    int vetor[10];
    int* p = vetor;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", p);
        printf("Endereco: %p e Valor: %d\n", p, *p);
        p++;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Endereco: %p e Valor: %d\n", p, *p);
        p--;
    }
}
