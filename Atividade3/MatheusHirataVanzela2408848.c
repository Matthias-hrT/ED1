/**
 * @file codigo.c
 * @author Matheus Mazali Maeda (matheusmazalimaeda@alunos.utfpr.edu.br) RA: 2419963 e Matheus Hirata Vanzela (matheusvanzela@alunos.utfpr.edu.br) RA: 2408848
 * @brief
 * @version 0.1
 * @date 2022-10-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char nome[50];
    char sexo;
    char dataNascimento[20];
    char ultimaConsulta[20];
} Paciente;
typedef struct no
{
    struct no *prox;
    struct no *ant;
    Paciente paciente;
} No;
typedef struct
{
    No *inicio;
    int tamanho;
} Lista;

/**
 * @brief Inicializa a lista, setando o inicio como NULL e o tamanho como 0
 *
 * @param lista
 */
void inicializarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tamanho = 0;
}

/**
 * @brief Retorna um novo elemento, para poupar linhas de código
 *
 * @param paciente
 * @return No*
 */
No *novoElem(Paciente paciente)
{
    No *novo;
    novo = (No *)malloc(sizeof(No));
    novo->paciente = paciente;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

/**
 * @brief Insere um novo paciente na lista em ordem alfabetica
 *
 * @param lista
 * @param paciente
 */
void InserirPacienteListaOrdemAlfabetica(Lista *lista, Paciente paciente)
{
    No *novo = novoElem(paciente);
    No *aux = lista->inicio;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->tamanho++;
    }
    else
    {
        while (aux->prox != NULL && strcmp(aux->paciente.nome, paciente.nome) < 0)
        {
            aux = aux->prox;
        }
        if (strcmp(aux->paciente.nome, paciente.nome) < 0)
        {
            aux->prox = novo;
            novo->ant = aux;
            lista->tamanho++;
        }
        else
        {
            if (aux->ant == NULL)
            {
                novo->prox = aux;
                aux->ant = novo;
                lista->inicio = novo;
                lista->tamanho++;
            }
            else
            {
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;
                lista->tamanho++;
            }
        }
    }
}

/**
 * @brief Insere um novo paciente na lista, em ordem decrescente
 *
 * @param lista
 * @param paciente
 */
void InserirPacienteListaOrdemDecrescente(Lista *lista, Paciente paciente)
{
    No *novo = novoElem(paciente);
    No *aux = lista->inicio;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->tamanho++;
    }
    else
    {
        while (aux->prox != NULL && strcmp(aux->paciente.nome, paciente.nome) > 0)
        {
            aux = aux->prox;
        }
        if (strcmp(aux->paciente.nome, paciente.nome) > 0)
        {
            aux->prox = novo;
            novo->ant = aux;
            lista->tamanho++;
        }
        else
        {
            if (aux->ant == NULL)
            {
                novo->prox = aux;
                aux->ant = novo;
                lista->inicio = novo;
                lista->tamanho++;
            }
            else
            {
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;
                lista->tamanho++;
            }
        }
    }
}

/**
 * @brief Adiciona um novo paciente em uma lista
 *
 * @param listaAndrologista
 * @param listaGinecologista
 */
void adicionarPaciente(Lista *listaAndrologista, Lista *listaGinecologista)
{
    Paciente paciente;
    printf("Digite o nome do paciente: ");
    setbuf(stdin, NULL);
    fgets(paciente.nome, 50, stdin);
    paciente.nome[strlen(paciente.nome) - 1] = '\0';
    do
    {
        printf("Digite o sexo do paciente (M/F): ");
        setbuf(stdin, NULL);
        scanf("%c", &paciente.sexo);
    } while (paciente.sexo != 'M' && paciente.sexo != 'F' && paciente.sexo != 'm' && paciente.sexo != 'f');
    printf("Digite a data de nascimento do paciente (dd/mm/aaaa): ");
    scanf(" ");
    fgets(paciente.dataNascimento, 20, stdin);
    paciente.dataNascimento[strlen(paciente.dataNascimento) - 1] = '\0';
    printf("Digite a data da ultima consulta do paciente (dd/mm/aaaa): ");
    setbuf(stdin, NULL);
    fgets(paciente.ultimaConsulta, 20, stdin);
    paciente.ultimaConsulta[strlen(paciente.ultimaConsulta) - 1] = '\0';
    if (paciente.sexo == 'M' || paciente.sexo == 'm')
    {
        InserirPacienteListaOrdemDecrescente(listaAndrologista, paciente);
        printf("Paciente adicionado com sucesso!\n");
    }
    else if (paciente.sexo == 'F' || paciente.sexo == 'f')
    {
        InserirPacienteListaOrdemAlfabetica(listaGinecologista, paciente);
        printf("Paciente adicionado com sucesso!\n");
    }
    return;
}
/**
 * @brief Concatena as duas listas para fins de busca
 *
 * @param listaAndrologista
 * @param listaGinecologista
 * @return Lista*
 */
Lista *concatenarListas(Lista *listaAndrologista, Lista *listaGinecologista)
{
    Lista *listaConcatenada = (Lista *)malloc(sizeof(Lista));
    inicializarLista(listaConcatenada);
    No *aux = listaAndrologista->inicio;
    while (aux != NULL)
    {
        InserirPacienteListaOrdemAlfabetica(listaConcatenada, aux->paciente);
        aux = aux->prox;
    }
    aux = listaGinecologista->inicio;
    while (aux != NULL)
    {
        InserirPacienteListaOrdemAlfabetica(listaConcatenada, aux->paciente);
        aux = aux->prox;
    }
    return listaConcatenada;
}

/**
 * @brief Calcula a quantos dias foi a ultima consula de um paciente
 *
 * @param paciente
 * @return int
 */
int calculaDiasDesdeAUltimaConsulta(Paciente paciente)
{
    int dia, mes, ano, diaAtual, mesAtual, anoAtual, diaUltimaConsulta, mesUltimaConsulta, anoUltimaConsulta, diasDesdeAUltimaConsulta;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    diaAtual = tm.tm_mday;
    mesAtual = tm.tm_mon + 1;
    anoAtual = tm.tm_year + 1900;
    sscanf(paciente.ultimaConsulta, "%d/%d/%d", &diaUltimaConsulta, &mesUltimaConsulta, &anoUltimaConsulta);
    diasDesdeAUltimaConsulta = (anoAtual - anoUltimaConsulta) * 365 + (mesAtual - mesUltimaConsulta) * 30 + (diaAtual - diaUltimaConsulta);
    return diasDesdeAUltimaConsulta;
}

/**
 * @brief Busca um paciente nas duas lista e mostra suas informações
 *
 * @param listaAndrologista
 * @param listaGinecologista
 */
void buscarPaciente(Lista *listaAndrologista, Lista *listaGinecologista)
{
    char nome[50];
    Lista *listaGeral = concatenarListas(listaAndrologista, listaGinecologista);
    printf("Digite o nome do paciente a ser buscado: ");
    setbuf(stdin, NULL);
    fgets(nome, 50, stdin);
    nome[strlen(nome) - 1] = '\0';
    No *aux = listaGeral->inicio;
    while (aux != NULL)
    {
        if (strcmp(aux->paciente.nome, nome) == 0)
        {
            printf("Nome: %s\nSexo: %c\nData de nascimento: %s\nData da ultima consulta: %s\nDias desde a ultima consulta: %d", aux->paciente.nome, aux->paciente.sexo, aux->paciente.dataNascimento, aux->paciente.ultimaConsulta, calculaDiasDesdeAUltimaConsulta(aux->paciente));
            return;
        }
        aux = aux->prox;
    }
    printf("Paciente nao encontrado!");
}

/**
 * @brief Lê todos os pacientes do arquivo e os adiciona nas listas de acordo com o médico
 *
 * @param listaGinecologista
 * @param listaAndrologista
 * @param fp
 */
void lerPacientes(Lista *listaGinecologista, Lista *listaAndrologista, FILE *fp)
{
    Paciente paciente;
    while (!feof(fp))
    {
        fscanf(fp, "<%[^,], %c, %[^,], %[^>]>\n", paciente.nome, &paciente.sexo, paciente.dataNascimento, paciente.ultimaConsulta);
        paciente.sexo == 'M' ? InserirPacienteListaOrdemDecrescente(listaAndrologista, paciente) : InserirPacienteListaOrdemAlfabetica(listaGinecologista, paciente);
    }
}

/**
 * @brief Imprime os pacientes antigos e os novos pacientes em uma lista final
 * 
 * @param listaGinecologista 
 * @param listaAndrologista 
 * @param saidaGinecologista 
 * @param saidaAndrologista 
 */
void imprimirPacientesArquivo(Lista *listaGinecologista, Lista *listaAndrologista, FILE *saidaGinecologista, FILE *saidaAndrologista)
{
    No *aux = listaGinecologista->inicio;
    fprintf(saidaGinecologista, "Pacientes do ginecologista:\n");
    while (aux != NULL)
    {
        fprintf(saidaGinecologista, "<%s, %c, %s, %s>\n", aux->paciente.nome, aux->paciente.sexo, aux->paciente.dataNascimento, aux->paciente.ultimaConsulta);
        aux = aux->prox;
    }
    aux = listaAndrologista->inicio;
    fprintf(saidaAndrologista, "Pacientes do andrologista:\n");
    while (aux != NULL)
    {
        fprintf(saidaAndrologista, "<%s, %c, %s, %s>\n", aux->paciente.nome, aux->paciente.sexo, aux->paciente.dataNascimento, aux->paciente.ultimaConsulta);
        aux = aux->prox;
    }
}

/**
 * @brief Destroi a lista para evitar memory leak
 *
 * @param l
 */
void destruirLista(Lista *l)
{
    No *aux=l->inicio;
    while(l->inicio!=NULL){
        l->inicio=l->inicio->prox;
        l->tamanho--;
        free(aux);
        aux=l->inicio;
    }
}

/**
 * @brief Função para usar um menu recursivo
 * 
 * @param listaGinecologista 
 * @param listaAndrologista 
 * @param saidaGinecologista 
 * @param saidaAndrologista 
 */
void Menu(Lista *listaGinecologista, Lista *listaAndrologista, FILE *saidaGinecologista, FILE *saidaAndrologista)
{
    int escolha;
    while (escolha != 3)
    {
        printf("\n1 - Adicionar Novo Paciente\n2 - Realizar Uma Busca\n3 - Sair\nSua escolha: ");
        setbuf(stdin, NULL);
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            adicionarPaciente(listaAndrologista, listaGinecologista);
            Menu(listaGinecologista, listaAndrologista, saidaGinecologista, saidaAndrologista);
            break;
        case 2:
            buscarPaciente(listaGinecologista, listaAndrologista);
            Menu(listaGinecologista, listaAndrologista, saidaGinecologista, saidaAndrologista);
            break;
        case 3:
            imprimirPacientesArquivo(listaGinecologista, listaAndrologista, saidaGinecologista, saidaAndrologista);
            fclose(saidaGinecologista);
            fclose(saidaAndrologista);

            destruirLista(listaGinecologista);
            destruirLista(listaAndrologista);
            printf("Listas destruidas!\n");
            exit(1);
            break;
        default:
            printf("Você inseriu uma opção inválida\n");
            break;
        }
    }
}

/**
 * @brief Main
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const *argv[])
{
    FILE *entrada = fopen(argv[1], "r");
    FILE *saidaGinecologista = fopen(argv[2], "w");
    FILE *saidaAndrologista = fopen(argv[3], "w");
    Lista listaGinecologista;
    Lista listaAndrologista;
    int escolha;

    if (entrada == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    if (argc < 4)
    {
        printf("Argumentos Insuficientes!");
        exit(1);
    }

    inicializarLista(&listaGinecologista);
    inicializarLista(&listaAndrologista);

    lerPacientes(&listaGinecologista, &listaAndrologista, entrada);
    fclose(entrada);

    Menu(&listaGinecologista, &listaAndrologista, saidaGinecologista, saidaAndrologista);
    return 0;
}
