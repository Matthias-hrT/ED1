#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, *vetor, soma;
    printf("\n Informe o tamanho do vetor: ");
    scanf("%d", &N); fflush(stdin);

    vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro de alocação");
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        printf("\n Digite o elemento vetor[%d] = ", i);
        scanf("%d", &vetor[i]); fflush(stdin);
    }

    for (int i = 0; i < N; i++)  soma += vetor[i];
    
    printf("\n\n--->>> A soma eh %d <<<---", soma);

    free(vetor);

    return 0;
}