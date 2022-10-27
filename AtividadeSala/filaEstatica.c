#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 8

typedef struct obj
{
    int chave;
} Objeto;

typedef struct filaEst
{
    Objeto array[N];
    int qtdeElem;
    int inicio;
    int fim;
} FilaEstatica;

void inicializarFila(FilaEstatica *f)
{
    f->fim = -1;
    f->inicio = -1;
    f->qtdeElem = 0;
}

bool estaVazia(FilaEstatica *f)
{
    return (f->qtdeElem == 0);
}

bool estaCheia(FilaEstatica *f)
{
    return (f->qtdeElem == N);
}

void inserirElem(FilaEstatica *f, int aux)
{
    if (estaCheia(f))
    {
        printf("\n\nA fila esta cheia\n\n\n");
        return;
    }
    if (estaVazia(f))
    {
        f->inicio = f->fim = 0;
        f->qtdeElem++;
        f->array[0].chave = aux;
        return;
    }
    f->fim = (f->fim + 1) % N;
    f->array[f->fim].chave = aux;
    f->qtdeElem++;
}

void impremiFila(FilaEstatica f)
{
    for (int i = 0; i < f.qtdeElem; i++)
    {
        printf("Pos[%d] = %d\n", i, f.array[(f.inicio + i) % N].chave);
    }
    
}

int main(void)
{
    FilaEstatica fila;
    Objeto objeto;
    inicializarFila(&fila);

    if (estaVazia(&fila) == true)
        printf("\n\n!!!!!ESTA VAZIA!!!!!\n");

    inserirElem(&fila, 69);
    inserirElem(&fila, 696);
    inserirElem(&fila, 6969);

    impremiFila(fila);

    return 0;
}