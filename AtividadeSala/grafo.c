#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

typedef int TIPOPESO;

typedef struct adjacencia
{
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} Adjacencia;

typedef struct vertice
{
    /*Outros dados vao aqui*/
    Adjacencia *cab;
} Vertice;

typedef struct Grafo
{
    int vertices;
    int arestas;
    Vertice *adj;
} Grafo;

Grafo *criaGrafo(int v)
{
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (Vertice *)malloc(v * sizeof(Vertice));
    for (int i = 0; i < v; i++)
    {
        g->adj[i].cab = NULL;
    }
    return g;
}

Adjacencia *criaAdjacencia(int v, int peso)
{
    Adjacencia *temp = (Adjacencia *)malloc(sizeof(Adjacencia));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return (temp);
}

bool criaAresta(Grafo *gr, int vi, int vf, TIPOPESO p)
{
    if (!gr)
    {
        return false;
    }
    if (vf < 0 || vf >= gr->vertices)
    {
        return false;
    }
    if (vi < 0 || vi >= gr->vertices)
    {
        return false;
    }
    Adjacencia *novo = criaAdjacencia(vf, p);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;
    gr->arestas++;
    return true;
}

void visitaP(Grafo *g, int i, int *cor)
{
    cor[i] = AMARELO;
    Adjacencia *v = g->adj[i].cab;
    while (v)
    {
        if (cor[v->vertice] == BRANCO)
        {
            visitaP(g, v->vertice, cor);
            v = v->prox;
        }
    }
    cor[i] = VERMELHO;
}

void profundidade(Grafo *g)
{
    int cor[g->vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        cor[i] = BRANCO;
    }
    for (int i = 0; i < g->vertices; i++)
    {
        if (cor[i] == BRANCO)
        {
            visitaP(g, i, cor);
        }
    }
}

void imprime(Grafo *gr)
{
    printf("Vertices: %d | Arestas: %d\n", gr->vertices, gr->arestas);
    for (int i = 0; i < gr->vertices; i++)
    {
        printf("v%d: ", i);
        Adjacencia *ad = gr->adj[i].cab;
        while (ad)
        {
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}

int main(){
    Grafo *gr = criaGrafo(5);

    criaAresta(gr, 0, 1, 2);
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 14);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);

    imprime(gr);

    return EXIT_SUCCESS;
}