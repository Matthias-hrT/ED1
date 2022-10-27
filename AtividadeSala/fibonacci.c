#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if(n == 1) return(0);
    if(n == 2) return (1);

    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, resultado;

    printf("\n Digite uma posição da sequência: ");
    scanf("%d", &n);

    resultado = fibonacci(n);

    printf("%d", resultado);

    return 0;
}