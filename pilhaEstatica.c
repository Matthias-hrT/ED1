#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 10

typedef struct aluno
{
    int RA;
    char nome[50];
} Aluno;

typedef struct pil
{
    Aluno aluno[10];
    int topo;
} PilhaEstatica;

void inicializaPilha(PilhaEstatica *p)
{
    p->topo = 0;
}

bool estaCheia(PilhaEstatica *p)
{
    if (p->topo == N)
        return true;
    return false;
}

void empilhar(PilhaEstatica *p, Aluno a)
{
    if (estaCheia(p) == 1)
    {
        printf("\n\n Pilha cheia, nao consigo inserir\n");
        return;
    }
    p->aluno[p->topo] = a;
    p->topo++;
}

void imprimirPilha(PilhaEstatica p)
{
    int i;
    for (i = 0; i < p.topo; i++)
    {
        printf("\npilha[%d] = %d / %s", i, p.aluno[i].RA, p.aluno[i].nome);
    }
}

int main(void)
{
    PilhaEstatica pilha;
    Aluno a = {69, "Matheus"};

    inicializaPilha(&pilha);
    empilhar(&pilha, a);
    //----
    a.RA = 321;
    strcpy(a.nome, "Joao");
    empilhar(&pilha, a);
    //----
    a.RA = 721;
    strcpy(a.nome, "Maria");
    empilhar(&pilha, a);
    //----
    a.RA = 567;
    strcpy(a.nome, "Jose");
    empilhar(&pilha, a);
    //----

    imprimirPilha(pilha);

    printf("\n\n Topo=%d \n\n", pilha.topo);

    printf("\n\n Odeio ED1\n\n");

    return 0;
}
