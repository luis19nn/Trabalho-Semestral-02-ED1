#ifndef TrabSemEx02.h
#define TrabSemEx02.h
#endif
#include "TrabSemEx02.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

Lista *li;

int main()
{
    int opc, x, y;
    struct paciente dados_Paciente;

    li = cria_lista();
    if (li == NULL)
    {
        printf("Ocorreu um erro ao iniciar o programa! Lista nao inicializada. \n");
        exit(0);
    }
    else
    {
        printf("Programa iniciado com sucesso!\n");

    }

    while (opc != 5)
    {
        printf("\n==========================================================\n");
        printf("\nMENU DE CADASTRO - DOACAO DE CORACAO:\n");
        printf("1. Cadastrar paciente (Nome, telefone e grau de urgencia)\n");
        printf("2. Buscar paciente (informar a posicao do paciente na fila e o seu grau de urgencia)\n");
        printf("3. Proximo paciente a ser operado (retorna os dados do paciente e exclui da lista)\n");
        printf("4. Verificar tamanho da fila\n");
        printf("5. Sair\n");
        printf("\n==========================================================\n");
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &opc);
        switch (opc)
        {

        case 1:

            x = insere_lista_ordenada(li, dados_Paciente);
            if (x == 1)
            {
                printf("Paciente inserido na fila!\n");
            }
            else
            {
                printf("Ocorreu um erro ao inserir o paciente na fila!\n");
            }
            break;

        case 2:

            x = consulta_lista_value(li, &dados_Paciente);
            if (x == 0)
            {
                printf("Paciente nao encontrado na fila!\n");
            }
            break;

        case 3:

            x = remove_lista_inicio(li);
            if (x == 1)
            {
                printf("\nPaciente removido da fila!\n");
            }
            else
            {
                printf("Ocorreu um erro ao remover o paciente da fila! Provavelmente nao ha pacientes cadastrados. \n");
            }
            break;

        case 4:

            x = tamanho_lista(li);
            printf("A fila atualmente possui %d pacientes.\n", x);
            break;

        case 5:

            libera_lista(li);
            printf("Lista liberada com sucesso!\n");
            printf("Programa encerrado!\n");
            break;

        default:

            printf("Opcao inexistente, escolha uma opcao valida!\n");
            break;
        }
    }
    return 1;
}
