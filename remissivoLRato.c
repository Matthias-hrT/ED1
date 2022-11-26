/**
 * @file remissivo.c
 * @author João Vitor Levorato de Souza (2419890) // Matheus Hirata Vanzela (2408848)
 * @brief Um  ́ındice remissivo lista os termos (e t ́opicos) que aparecem em um determinado documento (normal-
 * mente, em livros), conjuntamente com a(s) p ́agina(s) em que estes aparecem. O arquivo remissivo.xlsx
 * guarda o termo em sua primeira coluna e a respectiva p ́agina na segunda coluna; estes termos aparecem
 * em um determinado livro de pedagogia. Para que o livro seja colocado `a venda em meios digitais, pede-se
 * que o programador implemente as quatro op ̧c ̃oes listadas abaixo, utilizando Arvore AVL como estrutura  ́
 * de dados para organizar alfabeticamente os termos. Assim, o leitor poder ́a ter ́a uma previa do conte ́udo
 * a ser abordado no livro a ser comprado.
 *
 * O programa tamb ́em dever ́a oferecer quatro op ̧c ̃oes:
 * 1.) usu ́ario/bibliotec ́ario pode adicionar um novo termo e sua respectiva p ́agina, n ̃ao contido na base de dados antiga,
 * 2.) realizar a pesquisa por termo, devolvendo a p ́agina onde este se encontra;
 * 3.) mostrar todos os termos e suas respectivas p ́aginas em ordem alfab ́etica (A-Z);
 * 4.) encerrar a execu ̧c ̃ao quando solicitado pelo usu ́ario.
 *
 * @version 0.1
 * @date 2022-11-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    char termo[25];
    int pagina;
} Objeto;

typedef struct noAvl {
    Objeto obj;
    struct noAvl *esquerda;
    struct noAvl *direita;
    int altura;
} NoAVL;

/**
 * @brief Funcao que inicia a arvore AVL retornando NULL para ela
 *
 * @return NoAVL*
 */
NoAVL *iniciarArvoreAvl(){
    return NULL;
}

/**
 * @brief Retorna arvoreAvl NULL
 *
 * @param arvoreAvl
 * @return int
 */
int estaVaziaAVL(NoAVL **arvoreAvl){
    return ((*arvoreAvl) == NULL) ;
}

/**
 * @brief Atualiza o valor da altura do no passado por parametro
 *
 * @param arvoreAvl
 * @return int
 */
int maxAlturaFilho(NoAVL **arvoreAvl){
    if((*arvoreAvl)->esquerda == NULL && (*arvoreAvl)->direita == NULL) { //Se esquerda for NULL e direita NULL retorna valor da alura -1
        return (-1);
    } else if((*arvoreAvl)->esquerda == NULL) { //Se so esquerda for NULL retorna altura da direita
        return ((*arvoreAvl)->direita->altura);
    } else if((*arvoreAvl)->direita == NULL) { //Se so direeita for NULL retorna altura da esquerda
        return ((*arvoreAvl)->esquerda->altura);
    }
    return((*arvoreAvl)->direita->altura > (*arvoreAvl)->esquerda->altura ? (*arvoreAvl)->direita->altura : (*arvoreAvl)->esquerda->altura); //Se altura da direeita for maior que altura da esquerda retorna altura da dirita, se nao for rtorna da esquerda
}

/**
 * @brief Funcao que aplica rotacao para a esquerda e atualiza a altura
 *
 * @param arvoreAvl
 */
void rotacaoEsquerda(NoAVL **arvoreAvl){
    NoAVL *aux = NULL;
    aux = (*arvoreAvl)->direita; //u = p direita
    (*arvoreAvl)->direita = aux->esquerda; //p direita = u esquerda
    aux->esquerda = (*arvoreAvl); //u esquerda = p
    (*arvoreAvl) = aux; //p = u
    (*arvoreAvl)->esquerda->altura = maxAlturaFilho(&(*arvoreAvl)->esquerda) + 1; //Att altura esquerda
    (*arvoreAvl)->altura = maxAlturaFilho(arvoreAvl) + 1; //Att altura
}

/**
 * @brief Funcao que aplica rotacao para a direita e atualiza a altura
 *
 * @param arvoreAvl
 */
void rotacaoDireita(NoAVL **arvoreAvl){
    NoAVL *aux = (*arvoreAvl)->esquerda; //u = p direita
    (*arvoreAvl)->esquerda = aux->direita; //p esquerda = u direita
    aux->direita = (*arvoreAvl); //u direita = p
    (*arvoreAvl) = aux; //p = u
    (*arvoreAvl)->direita->altura = maxAlturaFilho(&(*arvoreAvl)->direita) + 1; //Att altura direita
    (*arvoreAvl)->altura = maxAlturaFilho(arvoreAvl) + 1; //Att altura
}

/**
 * @brief Retorna o valor da altura do no passado por parametro
 *
 * @param arvoreAvl
 * @return int
 */
int alturaArvoreAVL(NoAVL **arvoreAvl){
    if((*arvoreAvl) == NULL) return -1;
    return ((*arvoreAvl)->altura);
}

/**
 * @brief Funcao para insercao de objetos na arvore AVL de forma dos nomes de A - Z
 *
 * @param arvoreAvl
 * @param termos
 */
void inserirArvoreAVL(NoAVL **arvoreAvl, Objeto termos){
    if((*arvoreAvl) == NULL) {
        (*arvoreAvl) = (NoAVL*) malloc(sizeof(NoAVL));
        (*arvoreAvl)->obj = termos;
        (*arvoreAvl)->direita = (*arvoreAvl)->esquerda = NULL;
        (*arvoreAvl)->altura=0;
        return;
    }
    if (strcmp((*arvoreAvl)->obj.termo, termos.termo) == 0 && (*arvoreAvl)->obj.pagina == termos.pagina) { //Previne palavras iguais mas com paginas diferentes
        printf("\nElemento repetido\n");
        return;
    }
    strcmp((*arvoreAvl)->obj.termo, termos.termo) > 0 ? inserirArvoreAVL(&((*arvoreAvl)->esquerda), termos) : inserirArvoreAVL(&((*arvoreAvl)->direita), termos); //Se chave atual da arvore for maior que a chave insre na esquerda se nao for insere na direita
    //Obs: altura + direita | altura - esquerda | balanceado +1, 0, -1
    (*arvoreAvl)->altura = maxAlturaFilho(arvoreAvl) + 1;
    if (alturaArvoreAVL(&(*arvoreAvl)->direita) - alturaArvoreAVL(&(*arvoreAvl)->esquerda) == 2) { //direita - esquerda == 2 -> rotacao direita -> rotacao esquerda
        if(alturaArvoreAVL(&(*arvoreAvl)->direita->direita) - alturaArvoreAVL(&(*arvoreAvl)->direita->esquerda) < 0) { //Se altura da direita->direita - altura direita->esquerda for menor que 0 -> rotacaoDireita
            rotacaoDireita(&(*arvoreAvl)->direita);
        }
        rotacaoEsquerda(arvoreAvl);
    } else if (alturaArvoreAVL(&(*arvoreAvl)->direita) - alturaArvoreAVL(&(*arvoreAvl)->esquerda) == -2) { //Diferença da direita - esquerda == -2 -> rotacao esquerda -> rotacao esquerda
        if (alturaArvoreAVL(&(*arvoreAvl)->esquerda->direita) - alturaArvoreAVL(&(*arvoreAvl)->esquerda->esquerda) > 0) { //Se altura da direita->direita - altura direita->esquerda for menor que 0 -> rotacaoDireita
            rotacaoEsquerda(&(*arvoreAvl)->esquerda);
        }
        rotacaoDireita(arvoreAvl);
    }
}

/**
 * @brief Imprime a arvore de forma ordenada
 *
 * @param arvoreAvl
 */
void emOrdemAVL(NoAVL **arvoreAvl) {
    if(*arvoreAvl == NULL) return;
    emOrdemAVL(&((*arvoreAvl)->esquerda));
    printf("%s | %d\n", (*arvoreAvl)->obj.termo, (*arvoreAvl)->obj.pagina);
    emOrdemAVL(&((*arvoreAvl)->direita));
}

/**
 * @brief Destroi a arvore AVL liberando a memoria de cada no (free)
 *
 * @param arvoreAvl
 */
void destruirArvoreAVL(NoAVL **arvoreAvl) {
    if((*arvoreAvl) == NULL) return;
    destruirArvoreAVL(&((*arvoreAvl)->esquerda));
    destruirArvoreAVL(&((*arvoreAvl)->direita));
    free(*arvoreAvl);
    (*arvoreAvl) = NULL;
}

/**
 * @brief Funcao recursiva para pesquisa de um termo no livro printando sua página caso encontrado
 *
 * @param arvore
 * @param termo
 * @return int
 */
void pesquisarAVL(NoAVL **arvore, char *termo) {
    if ((*arvore) == NULL) { //Se arvore for NULL final do loop de recursao
        printf("Termo nao encontrado\n");
        return;
    }
    if (strstr((*arvore)->obj.termo, termo) != NULL) { //strstr ira comparar uma substring dentro da string desejada, util caso usuario for pesquisar uma palavra que contenha um /<outra_palavra> dessa forma sera encontrado a palavra que ele deseja
        printf("Termo encontrado pagina %d\n", (*arvore)->obj.pagina);
        return;
    }
    if (strcmp((*arvore)->obj.termo, termo) > 0) { //Termo atual da arvore é maior que termo pesquisado
        return (pesquisarAVL(&(*arvore)->esquerda, termo)); //Recursao com arvore->esquerda
    } else {
        return (pesquisarAVL(&(*arvore)->direita, termo)); //Recursao com arvore->direita
    }
}

///////////////////////////////////////////////////////////////////
// FUNCOES ARQUIVOS

/**
 * @brief Open file - funcao para abrir arquivo com nome passado por parametro em formato de leitura (read)
 *
 * @param name
 * @return FILE*
 */
FILE *op_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("error: fail to open file\n");
        exit(1);
    }
    return file;
}

/**
 * @brief Create file - funcao para criar arquivos com o nome que foi passado por parametro
 *
 * @param name
 * @return FILE*
 */
FILE *cr_file(char *name) {
    FILE *file = fopen(name, "w+");
    if (file == NULL) {
        printf("error: fail to create file\n");
        exit(1);
    }
    return file;
}

/**
 * @brief Read file - funcao para ler arquivo e armazenar seus dados em uma variavel
 *
 * @param file
 * @param termos
 */
void rd_file(FILE *file, NoAVL **termos) {
    Objeto aux;
    while (1) { // acaba o loop ao final do arquivo
        if (feof(file)) break;
        fscanf(file, "%s \t %d\n", &aux.termo, &aux.pagina);
        inserirArvoreAVL(termos, aux);
    }
}

/**
 * @brief Funcao para salvar novos dados da base de dados
 *
 * @param saida
 * @param arvoreAvl
 * @return FILE
 */
FILE sv_file(FILE *saida, NoAVL **arvoreAvl) {
    if(*arvoreAvl == NULL) return;
    sv_file(saida, &((*arvoreAvl)->esquerda));
    fprintf(saida, "%s \t %d\n", (*arvoreAvl)->obj.termo, (*arvoreAvl)->obj.pagina);
    sv_file(saida, &((*arvoreAvl)->direita));
}

///////////////////////////////////////////////////////////////////
// FUNCOES DO PROGRAMA

/**
 * @brief Adiciona novo termo a base de dados
 *
 * @param termos
 */
void adicionarTermo(NoAVL **termos) {
    Objeto aux;
    printf("Termo: ");
    setbuf(stdin, NULL);
    fgets(aux.termo, 25, stdin);
    //Modifica a primeira letra do termo inserido para maiusculo
    aux.termo[strcspn(aux.termo, "\n")] = '\0';
    aux.termo[0] = toupper(aux.termo[0]);
    printf("Pagina: ");
    scanf("%d", &aux.pagina);
    if (aux.pagina < 0) {
        printf("Pagina invalida!!! Digite novamente\n");
        return;
    }
    inserirArvoreAVL(termos, aux);
}

/**
 * @brief Menu do sistema com cada funcionalidade
 *
 * @param arvoreAvl
 * @param saida
 */
void menuSistema(NoAVL **arvoreAvl, FILE *saida) {
    while (1) {
        int op;
        printf("Digite sua opcao:\n 1.) Adicionar novo termo e pagina\n 2.) Psquisar termo\n 3.) Mostrar termos paginas\n 4.) Sair do programa\n");
        scanf("%d", &op);
        switch (op) {
        case 1: //Adicionar novo termo
            adicionarTermo(&(*arvoreAvl));
            break;
        case 2: //Pesquisar termo
            printf("Digite o termo que deseja buscar: ");
            char *termo = (char*) malloc(25);
            //char termo[25];
            setbuf(stdin, NULL);
            fgets(termo, 25, stdin);
            termo[strcspn(termo, "\n")] = '\0';
            pesquisarAVL(&(*arvoreAvl), termo);
            free(termo);
            break;
        case 3: //Imprimiir termos e paginas (A - Z)
            emOrdemAVL(&(*arvoreAvl));
            break;
        case 4: //Sair do programa
            sv_file(saida, &(*arvoreAvl));
            return;
            break;
        default:
            printf("Opcao invalida, digite novamente\n");
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *entrada = op_file(argv[1]);
    FILE *saida = cr_file(argv[2]); //Nao é pedido para salvar os novos dados inseridos
    NoAVL *arvore = iniciarArvoreAvl();
    rd_file(entrada, &arvore);
    menuSistema(&arvore, saida);
    destruirArvoreAVL(&arvore);
    fclose(entrada);
    fclose(saida);
    return EXIT_SUCCESS;
}