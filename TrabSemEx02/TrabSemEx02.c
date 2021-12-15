/* tipo de dados "lista"
  implementar as suas funcoes
*/
#include "TrabSemEx02.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// implementacao da struct elemento do arquivo .h
struct elemento
{
    struct paciente dadosPaciente;
    struct elemento *proximo;
};

typedef struct elemento Elem;

// CRIA LISTA
Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
    {
        *li = NULL;
    }
    return li;
}

// LIBERA LISTA
void libera_lista(Lista *li)
{
    if (li != NULL)
    {
        Elem *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->proximo;
            free(no);
        }
        free(li);
    }
}

// RETORNA TAMANHO DA LISTA PARA EXIBIR
int tamanho_lista(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }
    int count = 0;
    Elem *no = *li;
    while (no != NULL)
    {
        count++;
        no = no->proximo;
    }
    return count;
}

// RETORNA SE A LISTA ESTA VAZIA
int lista_vazia(Lista *li)
{
    if (li == NULL)
    {
        return 1; // se a lista for nula, se ela estiver vazia, true
    }
    if (*li == NULL)
    {
        return 1; // se o ponteiro for null, ou seja, o inicio da lista aponta para null, a lista esta vazia, true
    }
    return 0; // se nao executei nenhum dos dois if acima, retorno 0 (false), ou seja, a lista nao esta vazia. O return encerra a funcao, se um dos if for executado, nao vai chegar a executar essa linha.
}

// FAZ INSERCAO ORDENADA
int insere_lista_ordenada(Lista *li, struct paciente dados_Paciente)
{
    char phone[30];
    char nome[50];

    //Verifica se a lista ou no esta null

    if (li == NULL)
    {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
    {
        return 0;
    }

    //insere dados do paciente

    printf("\n[ Escala do grau de urgencia: (5) Muito urgente; (4) Urgente; (3) Medio; (2) Pouco urgente; (1) Sem urgencia; ]\n");

    int test=0;

    //loop para digitar o grau de urgencia

    do
    {
        printf("\nInforme o grau de urgencia do paciente: ");
        fflush(stdin);
        scanf("%d", &dados_Paciente.grauUrgencia);
        fflush(stdin);

        if(dados_Paciente.grauUrgencia > 5 || dados_Paciente.grauUrgencia < 1)
        {
            printf("\nInforme um grau de urgencia valido!\n");
            test=1;
        }
        else
        {
            test=2;
        }

    }
    while (test==1);

    fflush(stdin);
    printf("\nInforme o nome do paciente (Nao use caracteres especiais): ");
    fgets(nome, 50, stdin);
    strcpy(dados_Paciente.nome, nome);
    fflush(stdin);

    printf("\nDigite o telefone do paciente: ");
    fgets(phone, 30, stdin);
    strcpy(dados_Paciente.phone, phone);
    fflush(stdin);

    no->dadosPaciente = dados_Paciente;

    //Se a lista estiver vazia, insere no inicio da lista
    if (lista_vazia(li))
    {
        no->proximo = (*li);
        *li = no;
        return 1;
    }
    //Caso contrario, insere ordenado (grau de urgencia)
    else
    {

        Elem *ant, *atual = *li;
        //corre a lista para encontrar o grau de urgencia menor que o atual
        while (atual != NULL && atual->dadosPaciente.grauUrgencia >= dados_Paciente.grauUrgencia)
        {
            ant = atual;
            atual = atual->proximo;
        }
        if (atual == *li)
        {
            //insere inicio
            no->proximo = (*li);
            *li = no;
        }
        else
        {
            //insere ordenado
            no->proximo = ant->proximo;
            ant->proximo = no;
        }
        return 1;
    }
}

// FAZ REMOCAO NO INICIO E CRIA TXT
int remove_lista_inicio(Lista *li)
{

    //ve se esta null
    if (li == NULL)
    {
        return 0;
    }
    if ((*li) == NULL)
    {
        // lista vazia
        return 0;
    }

    // criacao de um novo elemento nó, que vai receber o valor do elemento no inicio da lista
    Elem *no = *li;
    // inicio da lista passa a apontar pro elemento srguinte ao no
    *li = no->proximo;

    //mostra na tela o que vai ser excluido
    printf("\nProximo paciente a ser operado: \n");
    printf("\nNome: %s", no->dadosPaciente.nome);
    printf("\nTelefone: %s", no->dadosPaciente.phone);
    printf("Grau de urgencia: %d\n", no->dadosPaciente.grauUrgencia);

    //abre arquivo txt
    FILE *f = fopen("pacienteTransplante.txt", "a");
    if (f == NULL)
    {
        printf("Ocorreu um erro ao abrir o arquivo!\n");
        exit(1);
    }

    //coloca o texto no txt
    fprintf(f, "\nNome: %s", no->dadosPaciente.nome);
    fprintf(f, "Grau de urgencia: %d\n", no->dadosPaciente.grauUrgencia);
    fprintf(f, "Telefone: %s", no->dadosPaciente.phone);
    fprintf(f, "\n==================\n");

    //fecha txt
    fclose(f);

    // removemos o no
    free(no);

    return 1;

}

// CONSULTA POSICAO DO VALOR (NOME)
int consulta_lista_value(Lista *li, struct paciente *dados_Paciente)
{
    if (li == NULL)
    {
        return 0;
    }

    Elem *no = *li;
    int pos = 1;
    char nomeP[50];

    fflush (stdin);
    printf("\nDigite o nome do paciente que deseja visualizar (Nao use caracteres especiais): ");
    fgets(nomeP, 50, stdin);
    fflush (stdin);

    //busca nome na lista
    while (no != NULL && strcmp(no->dadosPaciente.nome, nomeP))
    {
        no = no->proximo;
        pos++;
    }

    if (no == NULL)
    {
        return 0;
    }
    else
    {
        //exibe informacoes do paciente se achar
        *dados_Paciente = no->dadosPaciente;

        printf("\nEste paciente esta na posicao: %d\n", pos);
        printf("Este paciente tem urgencia: %d\n", no->dadosPaciente.grauUrgencia);

        return pos;
    }
}

