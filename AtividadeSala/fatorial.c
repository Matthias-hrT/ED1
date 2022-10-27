#include <stdio.h>
#include <stdlib.h>

int fatorial(int n)
{
    if(n == 0) return(1);

    while (n > 0)
    {
        return n * fatorial(n - 1);
    }
}

int main()
{
    int n, resultado;

    printf("\n Digite o número para o fatorial: ");
    scanf("%d", &n);

    resultado = fatorial(n);

    printf("\n\n --->>> O resultado eh %d <<<---", resultado);

    return 0;
}