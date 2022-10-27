#include <stdio.h>
#include <stdlib.h>

typedef struct objeto
{
    int chave;
    struct objeto* prox;
}NoLista;

typedef struct ListaEncadeada
{
    NoLista* inicio;
    int numElem;
}Lista;

void inicializa(Lista *l)
{
    l->inicio = NULL;
    l->numElem = 0;
}

int estaVazia(Lista *l)
{
    return(l->numElem == 0);
}

int qtdElem(Lista *l)
{

}

int main()
{
    Lista *lista;
    inicializa(&lista);

    return 0;
}