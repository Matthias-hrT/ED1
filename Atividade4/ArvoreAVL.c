#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

typedef struct
{
    char palavra[50];
    int pagina;
} Objeto;

typedef struct noArvore
{
    int altura;
    Objeto obj;
    struct noArvore *esq;
    struct noArvore *dir;
} NoAVL;

NoAVL *inicializaAVL()
{
    return NULL;
}

bool estaVazia(NoAVL **no)
{
    return ((*no) == NULL);
}

int alturaMaxFilho(NoAVL **no)
{
    if ((*no)->esq == NULL && (*no)->dir == NULL)
    {
        return (-1);
    }
    else if ((*no)->esq == NULL)
    {
        return ((*no)->dir->altura);
    }
    else if ((*no)->dir == NULL)
    {
        return ((*no)->esq->altura);
    }
    return ((*no)->dir->altura > (*no)->esq->altura ? (*no)->dir->altura : (*no)->esq->altura);
}

void rotacaoEsq(NoAVL **no)
{
    NoAVL *aux = NULL;
    aux = (*no)->dir;
    (*no)->dir = aux->esq;
    aux->esq = (*no);
    (*no) = aux;
    (*no)->esq->altura = alturaMaxFilho(&(*no)->esq) + 1;
    (*no)->altura = alturaMaxFilho(no) + 1;
}

void rotacaoDir(NoAVL **no)
{
    NoAVL *aux = (*no)->esq;
    (*no)->esq = aux->dir;
    aux->dir = (*no);
    (*no) = aux;
    (*no)->dir->altura = alturaMaxFilho(&(*no)->dir) + 1;
    (*no)->altura = alturaMaxFilho(no) + 1;
}

int alturaArvore(NoAVL **no)
{
    if ((*no) == NULL)
    {
        return -1;
    }
    return ((*no)->altura);
}

void imprimeEmOrdem(NoAVL **no)
{
    if (*no == NULL)
        return;
    imprimeEmOrdem(&(*no)->esq);
    printf("\nPalavra: %-25s | Pagina: %d", (*no)->obj.palavra, (*no)->obj.pagina);
    imprimeEmOrdem(&(*no)->dir);
}

void insereElem(NoAVL **no, Objeto obj)
{
    if ((*no) == NULL)
    {
        (*no) = (NoAVL *)malloc(sizeof(NoAVL));
        (*no)->obj = obj;
        (*no)->dir = (*no)->esq = NULL;
        (*no)->altura = 0;
        return;
    }
    if (strcmp((*no)->obj.palavra, obj.palavra) == 0)
    {
        printf("Elemento Repetido\n");
        Sleep(1000);
        return;
    }
    if (strcmp((*no)->obj.palavra, obj.palavra) == 1)
    {
        insereElem(&((*no)->esq), obj);
    }
    else
    {
        insereElem(&((*no)->dir), obj);
    }
    (*no)->altura = alturaMaxFilho(no) + 1;

    if (alturaArvore(&(*no)->dir) - alturaArvore(&(*no)->esq) == 2)
    {
        if (alturaArvore(&(*no)->dir->dir) - alturaArvore(&(*no)->dir->esq) < 0)
        {
            rotacaoDir(&(*no)->dir);
        }
        rotacaoEsq(no);
    }
    else if (alturaArvore(&(*no)->dir) - alturaArvore(&(*no)->esq) == -2)
    {
        if (alturaArvore(&(*no)->esq->dir) - alturaArvore(&(*no)->esq->esq))
        {
            rotacaoEsq(&(*no)->esq);
        }
        rotacaoDir(no);
    }
}

void inicializaObj(NoAVL **no, FILE *arqEntrada)
{
    Objeto aux;

    while (!feof(arqEntrada))
    {
        fscanf(arqEntrada, "%s \t %i\n", aux.palavra, &aux.pagina);
        insereElem(no, aux);
    }
}

void pesquisaElem(NoAVL **no, char termo[])
{
    if (*no == NULL)
        return;
    pesquisaElem(&((*no)->esq), termo);
    if (strcmp((*no)->obj.palavra, termo) == 0)
    {
        printf("Palavra: %-25s - Pagina: %d\n", (*no)->obj.palavra, (*no)->obj.pagina);
    }
    pesquisaElem(&((*no)->dir), termo);
}

void removeElem(NoAVL **no, Objeto obj)
{
    if ((*no) == NULL)
    {
        printf("--->>> Palavra n∆o encontrada <<<---\n");
        return;
    }
    if (strcmp((*no)->obj.palavra, obj.palavra) == 0)
    {
        free(*no);
        *no = NULL;
    }
    else if ((*no)->esq == NULL)
    {
        NoAVL *aux = *no;
        *no = (*no)->dir;
        free(aux);
    }
    else if ((*no)->dir == NULL)
    {
        NoAVL *aux = *no;
        *no = (*no)->esq;
        free(aux);
    }
    else
    {
        NoAVL *aux = (*no);
        NoAVL *anterior = (*no);
        *no = (*no)->esq;
        while ((*no)->dir == NULL)
        {
            anterior = (*no);
            *no = (*no)->dir;
        }
        (*no)->dir = aux->dir;
        anterior->dir = (*no)->esq;
        if (aux != anterior)
            (*no)->esq = aux->esq;
        free(aux);
    }
    return;
}

void geraSaida(NoAVL **no, FILE *arqSaida)
{
    if (*no == NULL)
        return;
    geraSaida(&((*no)->esq), arqSaida);
    fprintf(arqSaida, "%-25s \t %d\n", (*no)->obj.palavra, (*no)->obj.pagina);
    geraSaida(&((*no)->dir), arqSaida);
}

void destroiArvore(NoAVL **no)
{
    if ((*no) == NULL)
        return;
    destroiArvore(&(*no)->esq);
    destroiArvore(&(*no)->dir);
    free(*no);
    (*no) == NULL;
}

void menu(NoAVL **no)
{
    Objeto obj;
    char termo[50];
    int opcao = 9;

    while (opcao != 0)
    {
        Sleep(500);
        printf("\nEscolha uma opcao:\n");
        printf("1 - Inserir nova palavra\n");
        printf("2 - Pesquisar termo\n");
        printf("3 - Mostrar todos os termos\n");
        printf("4 - Remover termo\n");
        printf("0 - Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite a nova palavra: ");
            setbuf(stdin, NULL);
            fgets(obj.palavra, 50, stdin);
            obj.palavra[strcspn(obj.palavra, "\n")] = '\0';
            printf("Digite a pagina em que ela se encontra: ");
            setbuf(stdin, NULL);
            scanf("%d", &obj.pagina);
            insereElem(no, obj);
            break;
        case 2:
            printf("Digite o termo que deseja pesquisar: ");
            setbuf(stdin, NULL);
            fgets(termo, 50, stdin);
            termo[strcspn(termo, "\n")] = '\0';
            setbuf(stdin, NULL);
            pesquisaElem(no, termo);
            break;
        case 3:
            imprimeEmOrdem(no);
            break;
        case 4:
            printf("Digite o termo que deseja remover: ");
            setbuf(stdin, NULL);
            fgets(obj.palavra, 50, stdin);
            obj.palavra[strcspn(obj.palavra, "\n")] = '\0';
            setbuf(stdin, NULL);
            removeElem(no, obj);
            break;
        default:
            break;
        }
    }
}

int main(int argc, const char *argv[])
{
    NoAVL *arvoreAVL = inicializaAVL();

    FILE *arqEntrada = fopen(argv[1], "r");
    if (arqEntrada == NULL)
    {
        printf("Erro!! Falha ao abrir o arquivo!\n");
        exit(1);
    }
    FILE *arqSaida = fopen(argv[2], "w");
    if (arqSaida == NULL)
    {
        printf("Erro!! Falha ao abrir o arquivo!\n");
        exit(1);
    }

    inicializaObj(&arvoreAVL, arqEntrada);
    fclose(arqEntrada);
    menu(&arvoreAVL);
    geraSaida(&arvoreAVL, arqSaida);
    fclose(arqSaida);
    destroiArvore(&arvoreAVL);

    return EXIT_SUCCESS;
}