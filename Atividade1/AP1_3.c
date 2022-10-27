/**
 * @file AP1_3.c
 * @author Matheus Vanzela (matheusvanzela@alunos.utfpr.edu.br)
 * @brief Exerc¡cio 3, Atividade Pratica 1
 * @version 0.1
 * @date 12-09-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 4
#define QTDPILHA 5

typedef struct
{
    int topo;
    int vetor[TAM];
} PilhaEst;

void initPilha(PilhaEst p[])
{
    for (int i = 0; i < 5; i++)
    {
        p[i].topo = -1;
    }
}

/**
int estaVazia(PilhaEst p[], int i)
{

    if (p[i].topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int estaCheia(PilhaEst p[], int i)
{

    if (p[i].topo == TAM - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
*/

int maiorPalete(PilhaEst p[])
{
    int i = 0;

    for (i = 0; i < QTDPILHA - 1; i++)
    {
        if (p[i].topo != p[i + 1].topo)
        {
            return i + 1;
            break;
        }
    }
    return 0;
}

int menorPalete(PilhaEst p[])
{
    int i = 0;

    for (i = 0; i < QTDPILHA - 1; i++)
    {
        if (p[i].topo != p[i + 1].topo)
        {
            return i + 1;
        }
    }
    return 0;
}

void adicionaPalete(PilhaEst p[], int palete)
{
    int menorPilha = menorPalete(p);
    p[menorPilha].topo++;
    p[menorPilha].vetor[p->topo] = palete;
    printf("\nPilha [%d] -> Tamanho: %d\n\n", menorPilha + 1, p[menorPilha].topo + 1);
}

void removePalete(PilhaEst p[])
{
    int maiorPilha = maiorPalete(p);
    p[maiorPilha].topo--;
    printf("\nPilha [%d] -> Tamanho: %d\n\n", maiorPilha + 1, p[maiorPilha].topo + 1);
}

int main(void)
{
    PilhaEst pilhas[5];

    initPilha(pilhas);

    char opcao;
    int repete = 0;

    while (repete == 0)
    {
        printf("A -> Add Novo Palete\n");
        printf("B -> Remover Palete\n");
        printf("C -> Sair\n");
        printf("Opcao: ");
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 'A':
        case 'a':
            adicionaPalete(pilhas, 1);
            break;

        case 'B':
        case 'b':
            removePalete(pilhas);
            break;

        case 'C':
        case 'c':
            repete = 1;
            break;

        default:
            break;
        }
    }
    return 0;
}