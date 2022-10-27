#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#define TAM 10

// Structs das Filas e Objetos =================================================

/**
 * @brief Struct do Objeto da Fila Estatica
 * 
 */
typedef struct
{
    int id;
    char nome[50];
    char rua[50];
    int numero;
} ObjetoArq;

/**
 * @brief Struct do Objeto da Fila Dinamica
 * 
 */
typedef struct objDinamico
{
    struct objDinamico *prox;
    int id;
    char nome[50];
    char rua[50];
    int numero;
} ObjetoDinam;

/**
 * @brief Struct da Fila Dinamica
 * 
 */
typedef struct filaDinamica
{
    ObjetoDinam *inicio;
    ObjetoDinam *fim;
    int tamanho;
} FilaDinamica;

/**
 * @brief Struct da Fila Estatica
 * 
 */
typedef struct filaEst
{
    ObjetoArq array[TAM];
    int qtdeElem;
    int inicio;
    int fim;
} FilaEstatica;

// Fim Structs ================================================================

// Funá‰es ===============================================================

/**
 * @brief Inicializa a Fila Estatica
 * 
 * @param estatica 
 */
void inicializaFilaEstatica(FilaEstatica *estatica)
{
    estatica->qtdeElem = 0;
    estatica->fim = estatica->inicio = -1;
}

/**
 * @brief Inicializa a Fila Dinamica
 * 
 * @param concret 
 * @param naoConcret 
 */
void inicializaFilaDinamica(FilaDinamica *concret, FilaDinamica *naoConcret)
{
    concret->inicio = NULL;
    concret->fim = NULL;
    concret->tamanho = 0;

    naoConcret->inicio = NULL;
    naoConcret->fim = NULL;
    naoConcret->tamanho = 0;
}

/**
 * @brief Verifica se a Fila Dinamica esta vazia
 * 
 * @param concret 
 * @param naoConcret 
 * @return true 
 * @return false 
 */
bool estaVaziaDinamica(FilaDinamica *fila)
{
    return (fila->inicio == NULL);
}

/**
 * @brief Verifica se a Fila Estatica esta vaiza
 * 
 * @param estatica 
 * @return true 
 * @return false 
 */
bool estaVaziaEstatica(FilaEstatica *estatica)
{
    return (estatica->qtdeElem == 0);
}

/**
 * @brief Verifica se a Fila Estatica esta cheia
 * 
 * @param estatica 
 * @return true 
 * @return false 
 */
bool estaCheiaEstatica(FilaEstatica *estatica)
{
    return (estatica->qtdeElem == TAM);
}

/**
 * @brief Insere um endereco no final da Fila Estatica
 * 
 * @param estatica 
 * @param objeto 
 */
void insereFilaEstatica(FilaEstatica *estatica, ObjetoArq objeto)
{
    if (estaVaziaEstatica(estatica) == true)
    {
        estatica->fim = estatica->inicio = 0;
        estatica->array[estatica->fim] = objeto;
        estatica->qtdeElem++;
        return;
    }
    if (estaCheiaEstatica(estatica) == true)
    {
        printf("Fila Cheia!");
        return;
    }
    estatica->fim = (estatica->fim + 1) % TAM;
    estatica->array[estatica->fim] = objeto;
    estatica->qtdeElem++;
}

/**
 * @brief Adiciona os dez primeiro enderecos na Fila Estatica
 * 
 * @param estatica 
 * @param arqVisitas 
 * @param objeto 
 */
void preencheFilaEstatica(FilaEstatica *estatica, FILE *arqVisitas, ObjetoArq objeto)
{
    for (int i = 0; i < TAM; i++)
    {
        fscanf(arqVisitas, "{ %d; %[^;]; %[^;]; %d }\n", &objeto.id, objeto.nome, objeto.rua, &objeto.numero);
        insereFilaEstatica(estatica, objeto);
    }
}

/**
 * @brief Remove um endereco da Fila Estatica
 * 
 * @param estatica 
 */
void removeFilaEstatica(FilaEstatica *estatica)
{
    if (estaVaziaEstatica(estatica))
    {
        return;
    }
    estatica->inicio = (estatica->inicio + 1) % TAM;
    estatica->qtdeElem--;
}

/**
 * @brief Adiciona um novo endereco na Fila Estatica
 * 
 * @param estatica 
 * @param arqVisitas 
 * @param objeto 
 */
void adicionaFilaEstatica(FilaEstatica *estatica, FILE *arqVisitas, ObjetoArq objeto)
{
    if (!feof(arqVisitas))
    {
        fscanf(arqVisitas, "{ %d; %[^;]; %[^;]; %d }\n", &objeto.id, objeto.nome, objeto.rua, &objeto.numero);
        insereFilaEstatica(estatica, objeto);
    }
}

/**
 * @brief Insere um objeto na Fila Dinamica
 * 
 * @param fila 
 * @param objeto 
 */
void enfilerarDinamica(FilaDinamica *fila, ObjetoDinam *objeto)
{
    if (estaVaziaDinamica(fila))
    {
        fila->inicio = objeto;
        fila->fim = objeto;
        fila->tamanho++;
        return;
    }
    fila->fim->prox = objeto;
    fila->fim = objeto;
    fila->tamanho++;
}

/**
 * @brief Cria um Objeto Dinamico
 * 
 * @param objeto 
 * @return ObjetoDinam* 
 */
ObjetoDinam *criaObjetoDinamico(ObjetoArq objeto)
{
    ObjetoDinam *objetoDinamico = (ObjetoDinam *)malloc(sizeof(ObjetoDinam));
    objetoDinamico->id = objeto.id;
    strcpy(objetoDinamico->nome, objeto.nome);
    strcpy(objetoDinamico->rua, objeto.rua);
    objetoDinamico->numero = objeto.numero;
    objetoDinamico->prox = NULL;
    return objetoDinamico;
}

/**
 * @brief Remove o primeiro elemento da Fila Dinamica
 * 
 * @param concret 
 * @param naoConcret 
 */
void removerFilaDinamica(FilaDinamica *concret, FilaDinamica *naoConcret)
{
    ObjetoDinam *aux = concret->inicio;
    aux = concret->inicio;
    concret->inicio = concret->inicio->prox;
    free(aux);
    concret->tamanho--;

    ObjetoDinam *aux2 = naoConcret->inicio;
    aux2 = naoConcret->inicio;
    naoConcret->inicio = naoConcret->inicio->prox;
    free(aux2);
    naoConcret->tamanho--;
}

/**
 * @brief Destroi as Filas Dinamicas chamando a funá∆o removerFilaDinamica 
 *  atÇ que as Filas Dinamicas estejam vazias
 * 
 * @param concret 
 * @param naoConcret 
 */
void destroiFilaDinamica(FilaDinamica *concret, FilaDinamica *naoConcret)
{
    while (concret->tamanho != 0 && naoConcret->tamanho != 0)
    {
        removerFilaDinamica(concret, naoConcret);
    }
}

/**
 * @brief Verifica se a visita se concreticou ou n∆o
 *  Se concretizou remove o endereáo da Fila Estatica e o adiciona na Fila Dinamica de visitas concretizadas
 *  Se n∆o concretizou remove o endereáo da Fila Estatica e o adiciona na Fila Dinamica de visitas n∆o concretizadas
 *  e adiciona um novo endereáo no final da Fila Estatica
 * 
 * @param estatica 
 * @param concret 
 * @param naoConcret 
 * @param arqVisitas 
 * @param objeto 
 */
void verificaVisita(FilaEstatica *estatica, FilaDinamica *concret, FilaDinamica *naoConcret, FILE *arqVisitas, ObjetoArq objeto)
{
    int concretizou = 0;
    int concretizadas = 0;

    while (concretizadas < 10 && !estaVaziaEstatica(estatica))
    {
        printf("\nCasa a visitar: { %d; %s; %s; %d }\n", estatica->array[estatica->inicio].id, estatica->array[estatica->inicio].nome, estatica->array[estatica->inicio].rua, estatica->array[estatica->inicio].numero);
        printf("Concretizou visita? (1 - Sim, 0 - Nao): ");
        do
        {
            scanf("%d", &concretizou);
            fflush(stdin);
            if (concretizou == 1)
            {
                enfilerarDinamica(concret, criaObjetoDinamico(estatica->array[estatica->inicio]));
                removeFilaEstatica(estatica);
                concretizadas++;
                break;
            }
            else if (concretizou == 0)
            {
                enfilerarDinamica(naoConcret, criaObjetoDinamico(estatica->array[estatica->inicio]));
                removeFilaEstatica(estatica);
                adicionaFilaEstatica(estatica, arqVisitas, objeto);
                break;
            }
            else
            {
                printf("!!Opcao invalida!!\n Digite novamente: ");
                scanf("%d", &concretizou);
                fflush(stdin);
            }
            
        } while (concretizou != 1 || concretizou != 0);
        system("cls");
    }

    if (concretizadas == 10)
    {   
        printf("Voce conseguiu concretizar 10 visitas!\n");
        int sml = 2;
        printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",  sml, sml, sml, sml, sml,
                        sml, sml, sml, sml, sml, sml, sml, sml, sml, sml, sml, sml, sml);
    }
    else
    {
        printf("Voce nao conseguiu concretizar 10 visitas!");
    }
}

/**
 * @brief Gera o relatorio de visitas
 * 
 * @param concret 
 * @param naoConcret 
 * @param nome 
 */
void arquivoSaida(FilaDinamica *concret, FilaDinamica *naoConcret, char nome[])
{
    FILE *resultado = fopen(nome, "w");

    ObjetoDinam *aux = concret->inicio;

    fprintf(resultado, "Visitas concretizadas:\n");

    while (aux != NULL)
    {
        fprintf(resultado, "{ %d; %s; %s; %d }\n", aux->id, aux->nome, aux->rua, aux->numero);
        aux = aux->prox;
    }

    fprintf(resultado, "\nVisitas nao concretizadas:\n");

    aux = naoConcret->inicio;
    while (aux != NULL)
    {
        fprintf(resultado, "{ %d; %s; %s; %d }\n", aux->id, aux->nome, aux->rua, aux->numero);
        aux = aux->prox;
    }

    if (concret->tamanho < TAM)
    {
        fprintf(resultado, "\n!!!VOCE NAO CONCRETIZOU 10 VIZITAS!!!\n");
    }
    else if (concret->tamanho == TAM)
    {   
        fprintf(resultado, "\n!!!VOCE CONCRETIZOU 10 VIZITAS!!!\n");
    }
    fclose(resultado);
}

// Final Funá‰es =================================================================================================

int main(int argc, char const *argv[])
{
    ObjetoArq objeto;
    FilaEstatica estatica;
    FilaDinamica concret, naoConcret;
    FILE *arqVisitas = fopen(argv[1], "r");

    char nome[20];
    strcpy(nome, argv[2]);

    inicializaFilaEstatica(&estatica);
    inicializaFilaDinamica(&concret, &naoConcret);

    preencheFilaEstatica(&estatica, arqVisitas, objeto);

    verificaVisita(&estatica, &concret, &naoConcret, arqVisitas, objeto);

    arquivoSaida(&concret, &naoConcret, nome);

    fclose(arqVisitas);

    destroiFilaDinamica(&concret, &naoConcret);

    return 0;
}