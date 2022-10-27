#include <stdio.h>
#include <stdlib.h>

typedef struct obj
{
    int chave;
    struct obj *prox;
} Objeto;

typedef struct filaDinamica
{
    Objeto *inicio;
    Objeto *fim;
    int tamanho;
} FilaDinamica;

void inicializaFila(FilaDinamica *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

int estaVazio(FilaDinamica *f)
{
    if (f->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int tamanhoFila(FilaDinamica *f)
{
    return (f->tamanho);
}

void insereFila(FilaDinamica *f, int chave)
{
    Objeto *novo;
    novo = (Objeto *)malloc(sizeof(Objeto));
    novo->chave = chave;
    novo->prox = NULL;

    if (estaVazio(f) == 1)
    {
        f->inicio = f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->tamanho++;
}

void imprimeFila(FilaDinamica *f)
{   
    int pos = 0;

    for (Objeto* aux = f->inicio; aux != NULL; aux = aux->prox)
    {
        printf("\n->Pos %d ==>> Chave %d\n", ++pos, aux->chave);
    }
}

void desFila(FilaDinamica *f)
{
    Objeto *aux;
    aux = f->inicio;
    f->inicio = f->inicio->prox;
    free(aux);
    f->tamanho--;
}

void destroiFila(FilaDinamica *f)
{
    while (f->tamanho != 0)
    {
        desFila(f);
    }
    
}

int main(void)
{
    FilaDinamica fila;
    Objeto *novo;
    //==========================
    inicializaFila(&fila);
    //==========================
    insereFila(&fila, 10);
    insereFila(&fila, 24);
    insereFila(&fila, 69);
    insereFila(&fila, 51);
    //==========================
    imprimeFila(&fila);
    //==========================
    desFila(&fila);
    //==========================
    printf("\n--x--x--x--x--x--x--x--x--x--x--\n");
    //==========================
    imprimeFila(&fila);
    //==========================
    destroiFila(&fila);

    return 0;
}