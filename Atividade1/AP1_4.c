/**
 * @file AP1_4.c
 * @author Matheus Vanzela (matheusvanzela@alunos.utfpr.edu.br)
 * @brief Exerc¡cio 4, Atividade Pr tica 1
 * @version 0.1
 * @date 10-09-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define tamanho 10

typedef struct
{
    int chave[tamanho];
    int topo;
} PilhaEst;

void iniciaPilha(PilhaEst *p)
{
    p->topo = -1;
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

void inserePilha(PilhaEst *p, int valor)
{
    if (estaCheia(p) == 1)
    {
        printf("\nA pilha esta cheia!!\n\n");
    }
    else
    {
        p->topo++;
        p->chave[p->topo] = valor;
    }
}

void calcBinario(PilhaEst *p, int numero)
{
    int resultado, resto;

    while (numero > 0)
    {
        resultado = numero / 2;
        resto = numero % 2;
        numero = resultado;
        inserePilha(p, resto);
    }
        inserePilha(p, resultado);
}

void imprimiPilha(PilhaEst *p)
{
    printf("\n");
    for (int i = p->topo; i > -1; i--)
    {
        printf("%d", p->chave[i]);
    }
    printf("\n\n");
}

int main(void)
{
    PilhaEst pilha;

    iniciaPilha(&pilha);
    
    if (estaVazia(&pilha) == 1)
    {
        printf("\nEsta Vazia\n\n");
    }
    else
    {
        printf("\nTamanho da pilha: %d\n\n", pilha.topo);
    }

    int numero;
    printf("Digite um numero decimal: ");
    scanf("%d", &numero);

    calcBinario(&pilha, numero);

    imprimiPilha(&pilha);

    return 0;
}