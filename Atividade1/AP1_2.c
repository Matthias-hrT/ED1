/**
 * @file AP1_2.c
 * @author Matheus Vanzela (matheusvanzela@alunos.utfpr.edu.br)
 * @brief Exerc¡cio 2, Atividade Pr tica 1
 * @version 0.1
 * @date 08-09-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct noPilha
{
    int chave;
    struct noPilha *prox;
} NoPilha;

typedef struct
{
    NoPilha *topo;
    int quantidade;
} ObjPilha;

void inicializaPilha(ObjPilha *duracel)
{
    duracel->topo = NULL;
    duracel->quantidade = 0;
}

void empilhaObjeto(ObjPilha *duracel, int numero)
{
    NoPilha *rayovac;
    rayovac = (NoPilha *)malloc(sizeof(NoPilha));
    rayovac->chave = numero;
    rayovac->prox = duracel->topo;
    duracel->topo = rayovac;
    duracel->quantidade++;
}

void desempilha(ObjPilha *duracel)
{
    NoPilha *aux;
    aux = duracel->topo;
    duracel->topo = aux->prox;
    aux->prox = NULL;
}

void imprimiPilha(ObjPilha *duracel)
{
    printf("\n");
    for (NoPilha *alcalina = duracel->topo; alcalina != NULL; alcalina = alcalina->prox)
    {
        printf("%d ", alcalina->chave);
    }
    printf("\n\n");
}

int estaVazia(ObjPilha *duracel)
{
    if (duracel->topo == NULL)
    {
        return 1;
    }
    return 0;
}

int fibonacci(int numero)
{
    if (numero == 0)
    {
        return 0;
    }
    else if (numero == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(numero - 1) + fibonacci(numero - 2);
    }
}

int destroiPilha(ObjPilha *duracel)
{
    for (int i = 0; i < duracel->quantidade; i++)
    {
        desempilha(duracel);
    }
}

int main(void)
{
    ObjPilha duracel;
    int numFibonacci;

    inicializaPilha(&duracel);

    if (estaVazia(&duracel) == 1)
        printf("A pilha est  vazia\n");
    printf("\nTamanho da pilha: %d\n\n", duracel.quantidade);

    printf("Quantos termos de Fibonacci vocˆ deseja\n");
    printf("(Entre 5 e 20): ");
    scanf("%d", &numFibonacci);

    if (numFibonacci < 5 || numFibonacci > 20)
    {
        printf("\n!!Numero invalido!!\n");
        printf("O numero de termos deve ser entre 5 e 20\n\n");
    }
    else
    {
        for (size_t i = 0; i < numFibonacci; i++)
        {
            empilhaObjeto(&duracel, fibonacci(i));
        }
        imprimiPilha(&duracel);
    }

    destroiPilha(&duracel);

    return 0;
}
