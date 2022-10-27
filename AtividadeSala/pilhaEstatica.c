#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

typedef struct
{
    int RA;
    char nome[50];
} Aluno;

typedef struct pilEst
{
    Aluno aluno[N];
    int topo;
} PilhaEstatica;

void inicializaPilha(PilhaEstatica *p)
{
    p->topo = 0;
}

bool pilhaCheia(PilhaEstatica *p)
{
    if (p->topo == N) return true;
    return false;
}

int inserirElem(PilhaEstatica *p, Aluno a)
{
    if (pilhaCheia(p) == 1)
    {
        printf("A pilha está cheia, o elemento não foi inserido");
        return 0;
    }
    p->aluno[p->topo] = a;
    p->topo++;
}

int main(void)
{
    PilhaEstatica pilha;
    Aluno a = {123, "Matthias"};
    int i = 0;

    inicializaPilha(&pilha);

    inserirElem(&pilha, a);

    for (i = 0; i < pilha.topo; i++)
    {
        printf("\n Aluno[%d] = %s \n", i, pilha.aluno[i].nome);
    }

    return 0;
}