#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noPilha
{
    int chave;
    /*Informações*/
    struct noPilha *prox;
} NoPilha;

typedef struct pilhaDin
{
    NoPilha *topo;
    int quant;
} PilhaDinamica;

void inicializaPilha(PilhaDinamica *p)
{
    p->topo = NULL;
    p->quant = 0;
}

int estaVazia(PilhaDinamica p)
{
    if (p.quant == 0)
        return 1;
    return 0;
}

int tamanhoPilha(PilhaDinamica p)
{
    return p.quant;
}

NoPilha *novoElemento(void)
{
    NoPilha *novo = NULL;
    novo = (NoPilha *)malloc(sizeof(NoPilha));

    if (novo == NULL) return NULL;

    return novo;
}

void insere(PilhaDinamica *p, int ch)
{
    NoPilha *aux;
    aux = novoElemento();
    aux->chave = ch;
    aux->prox = p->topo;
    p->topo = aux;
    p->quant++;
}

void desempilha(PilhaDinamica *p)
{
    NoPilha *aux;
    aux = p->topo;
    p->topo = p->topo->prox;
    p->quant--;
    free(aux);
}

int main()
{
    PilhaDinamica pilha;
    inicializaPilha(&pilha);

    printf("Tamanho da pilha: %d\n", tamanhoPilha(pilha));

    insere(&pilha, 5);
    printf("\n\n --->>> Topo = %d <<<---\n", pilha.topo->chave);
    desempilha(&pilha);

    if (estaVazia(pilha) == 1)
    {
        printf("Está Vazia\n");
    }
    else
    {
        printf("Não está vazia\n");
    }

    if(pilha.topo == NULL) printf("--->>>Topo é NULL <<<---\n");
    

    return 0;
}