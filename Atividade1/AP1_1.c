/**
 * @file AP1_1.c
 * @author Matheus Vanzela (matheusvanzela@alunos.utfpr.edu.br)
 * @brief Exerc¡cio 1, Atividade Pr tica 1
 * @version 0.1
 * @date 08-09-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define tamanho 10

typedef struct PilhaEstatica
{
    int topo;
    int vetor[tamanho];
} PilhaEst;

void initPilha(PilhaEst *p)
{
    p->topo = -1;
}

void empilha(PilhaEst *p, int valor)
{
    p->topo++;
    p->vetor[p->topo] = valor;
}

int estaVazia(PilhaEst *p)
{
    if (p->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int estaCheia(PilhaEst *p)
{
    if (p->topo == tamanho - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    FILE *arq = fopen(argv[1], "r");
    if (arq == NULL)
    {
        printf("!!!Erro ao abrir o arquivo!!!\n");
        exit(1);
    }

    PilhaEst pPar;
    PilhaEst pImpar;

    initPilha(&pPar);
    initPilha(&pImpar);

    int aux;
    while (!feof(arq))
    {
        fscanf(arq, "%d\n", &aux);
        if ((aux % 2) == 0)
        {
            empilha(&pPar, aux);
        }
        else
        {
            empilha(&pImpar, aux);
        }
    }
    fclose(arq);

    arq = fopen(argv[2], "w");
    for (int i = pPar.topo; i > -1; i--)
    {
        fprintf(arq, "%d\n", pPar.vetor[i]);
    }
    fclose(arq);

    arq = fopen(argv[3], "w");
    for (int i = pImpar.topo; i > -1; i--)
    {
        fprintf(arq, "%d\n", pImpar.vetor[i]);
    }
    fclose(arq);
    return 0;
}
