/**
 * @file REV_ex2.c
 * @author Matheus Vanzela (matheusvanzela@alunos.utfpr.edu.br)
 * @brief Exerc¡cios de revisÆo ED1
 * @version 0.1
 * @date 17-08-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @brief  [Arquivos] Fa‡a um programa que receba, por argumento na main, o nome de um arquivo texto. Crie
 * outro arquivo texto de sa¡da contendo o texto do arquivo de entrada original, por‚m substituindo todas
 * as vogais ?a? pelo caractere ?*? e as demais vogais por ?+?. Al‚m disso, mostre na tela quantas linhas
 * esse arquivo possui. Dentro do programa fa‡a o controle de erros, isto ‚, insira comandos que mostre se
 * os arquivos foram abertos com sucesso e, caso contr rio, imprima uma mensagem de erro encerrando o
 * programa.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c;

    FILE *arqOriginal = fopen(*argv, "w+");
    if (arqOriginal == NULL)
    {
        printf("\n!!! ERRO AO ABRIR O ARQUIVO !!!");
        exit(1);
    }

    FILE *arqReescrito = fopen("novoArquivo.txt", "w+");
    if (arqReescrito == NULL)
    {
        printf("\n!!! ERRO AO ABRIR O ARQUIVO !!!");
        exit(1);
    }

    while ((c = fgetc(arqOriginal)) != EOF)
    {
        if (fgetc(arqOriginal) == "a")
        {
            fputc('*', arqReescrito);
        }
        else
        {
            fputc('+', arqReescrito);
        }
    }

    fclose(arqOriginal);

    fclose(arqReescrito);

    return 0;
}
