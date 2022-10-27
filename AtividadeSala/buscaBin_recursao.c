#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int x, int ini, int fim, int vetor[])
{
    int meio = (int) (ini + fim) / 2;

    if (ini > fim) return -1;

    if(vetor[meio] == x) return meio;

    if(vetor[meio] > x) fim = meio - 1;
    
    else ini = meio + 1;

    return buscaBinaria(x, ini, fim, vetor);
}

int main()
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ini = 0, fim = 9, x, posicao;
    
    printf("\nDigite o número que deseja buscar: ");
    scanf("%d", &x);
    
    if ((posicao = buscaBinaria(x, ini, fim, vetor)) == -1)
    {
        printf("\n-->> Número não encontrado <<--\n\n");
    }else{
        printf("\n-->> O número está na posição %d <<--\n\n", posicao);
    }
    
    return 0;
}