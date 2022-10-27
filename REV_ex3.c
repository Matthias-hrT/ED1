/**
 * @file REV_ex3.c
 * @author Matheus Vanzela (matheusvanzela@alunos.utfpr.edu.br)
 * @brief Exerc¡cios de revisÆo ED1
 * @version 0.1
 * @date 17-08-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @brief  [Aloca‡Æo Dinƒmica] Fa‡a um programa que leia um valor N e crie dinamicamente um vetor com essa
 * quantidade de elementos. Em seguida, passe esse vetor para um procedimento que vai preencher os
 * elementos desse vetor com n£meros aleat¢rios de 0 at‚ N. Depois, no programa principal, imprima os
 * valores do vetor preenchido. Al‚m disso, antes de finalizar o programa, lembre-se de liberar a  rea de
 * mem¢ria alocada.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void preencheVetor(int N, int *vetor)
{
    for (int i = 0; i < N; i++)
    {
        vetor[i] = (rand() % N); 
    }
}

int main(void)
{
    int N, *vetor;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &N); fflush(stdin);

    vetor = (int*) malloc (N * sizeof(int));

    preencheVetor(N, vetor);

    for (int i = 0; i < N; i++)
    {
        printf("\nVetor[%d]: [%d]", i, vetor[i]);
    }
    
    free(vetor);

    return 0;
}