/**
 * @file REV_ex1.c
 * @author Matheus Vanzela (matheusvanzela@alunos.utfpr.edu.br)
 * @brief Exerc¡cios de revisÆo de ED1
 * @version 0.1
 * @date 17-08-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief [RecursÆo] Escreva e programe uma fun‡Æo recursiva 
 * para calcular o valor de um n£mero inteiro de base x 
 * elevada a um expoente inteiro y, 
 * sendo os valores de x>0 e y>0 fornecidos pelo usu rio.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int y)
{
    if(y == 0) return 1;

    return x * potencia(x, y - 1);
}

int main(void)
{
    int x, y, resultado;

    printf("\nDigite um n£mero: ");
    scanf("%d", &x); fflush(stdin);

    printf("\nDigite a potˆncia desse n£mero: ");
    scanf("%d", &y); fflush(stdin);

    resultado = potencia(x, y);

    printf("\n\n--->>> O resultado eh %d <<<---", resultado);

    return 0;
}