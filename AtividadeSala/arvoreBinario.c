#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct noArvore
{
    int chave;
    struct noArvore *dir;
    struct noArvore *esq;
} NoArvore;

NoArvore *inicializaArvore()
{
    return NULL;
}

bool estaVazia(NoArvore **no)
{
    return ((*no) == NULL);
}

void insereArvore(NoArvore **no, int chave)
{
    if ((*no) == NULL)
    {
        (*no) = (NoArvore *)malloc(sizeof(NoArvore));
        (*no)->chave = chave;
        (*no)->dir = (*no)->esq = NULL;
        return;
    }
    if ((*no)->chave == chave)
    {
        printf("\nElemento repetido");
        return;
    }
    (*no)->chave > chave ? insereArvore(&((*no)->esq), chave) : insereArvore(&((*no)->dir), chave);
}

void imprimeEmOrdem(NoArvore **no)
{
    if (*no == NULL)
        return;
    imprimeEmOrdem(&((*no)->esq));
    printf("\n--> %d ", (*no)->chave);
    imprimeEmOrdem(&((*no)->dir));
}

void destroiArvore(NoArvore **no)
{
    if ((*no) == NULL)
        return;
    destroiArvore(&((*no)->esq));
    destroiArvore(&((*no)->dir));
    free(*no);
    (*no) = NULL;
}

NoArvore *maiorNoSubArvEsq(NoArvore **no)
{
    if ((*no)->dir == NULL)
    {
        NoArvore *aux = (*no);
        if ((*no)->esq != NULL)
            *no = (*no)->esq;
        *no = NULL;
        return (aux);
    }
    return maiorNoSubArvEsq(&(*no)->dir);
}

NoArvore *menorNoSubArvDir(NoArvore **no)
{
    if ((*no)->esq == NULL)
    {
        NoArvore *aux = *no;
        if ((*no)->dir != NULL)
            *no = (*no)->dir;
        else
            *no = NULL;
        return aux;
    }
    return menorNoSubArvDir(&(*no)->esq);
}

void excluiElem(NoArvore **no, int chave)
{
    if (*no == NULL)
    {
        printf("\n\n------------\n\n\t Chave nao encontrada \n\n----------------\n");
        return;
    }
    if ((*no)->chave == chave)
    {
        if ((*no)->esq == NULL && (*no)->dir == NULL)
        {
            free(*no);
            (*no) = NULL;
            return;
        }
        if ((*no)->esq == NULL)
        {
            NoArvore *remove = *no;
            *no = (*no)->dir;
            free(remove);
            return;
        }
        if ((*no)->dir == NULL)
        {
            NoArvore *remove = *no;
            *no = (*no)->esq;
            free(remove);
            return;
        }
        NoArvore *elem = maiorNoSubArvEsq(&(*no)->esq);
        // NoArvore *elem = menorNoSubArvDir(&(*no)->dir);
        NoArvore *remove = *no;
        elem->dir = (*no)->dir;
        elem->esq = (*no)->esq;
        *no = elem;
        free(remove);
        return;
    }
    if ((*no)->chave > chave)
        excluiElem(&(*no)->esq, chave);
    else
        excluiElem(&(*no)->dir, chave);
}

NoArvore *buscaElem(NoArvore **no, int chave)
{
    if (*no == NULL)
        return false;
    if ((*no)->chave == chave)
        return *no;
    if ((*no)->chave > chave)
        return buscaElem(&(*no)->esq, chave);
    else
        return buscaElem(&(*no)->dir, chave);
}

int main(void)
{

    NoArvore *raiz = inicializaArvore();

    insereArvore(&raiz, 10);
    insereArvore(&raiz, 15);
    insereArvore(&raiz, 13);
    insereArvore(&raiz, 16);
    insereArvore(&raiz, 12);
    insereArvore(&raiz, 14);
    insereArvore(&raiz, 5);
    insereArvore(&raiz, 3);
    insereArvore(&raiz, 7);
    insereArvore(&raiz, 6);
    insereArvore(&raiz, 19);
    insereArvore(&raiz, 20);

    printf("\n\n-----------------INICIO------------------\n\n");
    imprimeEmOrdem(&raiz);
    printf("\n\n-----------------FIM------------------\n\n");

    excluiElem(&raiz, 10);

    printf("\n\n-----------------Inicio------------------\n\n");
    imprimeEmOrdem(&raiz);
    printf("\n\n-----------------Fim------------------\n\n");

    excluiElem(&raiz, 7);

    printf("\n\n-----------------Inicio------------------\n\n");
    imprimeEmOrdem(&raiz);
    printf("\n\n-----------------Fim------------------\n\n");

    (&raiz, 15);

    printf("\n\n-----------------Inicio------------------\n\n");
    imprimeEmOrdem(&raiz);
    printf("\n\n-----------------Fim------------------\n\n");

    int numero;
    printf("\n\nDigite um numero para buscar: ");
    scanf("%d", &numero);

    if (buscaElem(&raiz, numero) != NULL)
        printf("\n\nElemento encontrado\n\n");
    else
        printf("\n\nElemento nao encontrado\n\n");

    destroiArvore(&raiz);
}