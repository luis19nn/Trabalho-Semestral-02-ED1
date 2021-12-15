#include <stdio.h>
#include <stdlib.h>
#include "TrabSemEx01.h"
#include "TrabSemEx01.c"

int main() {
    Pilha *pi;

    char entrada, infixa[50], expressao[50];;
    int piExpressaoValida;

    while (1) {
        printf("\n==========Calculadora de Expressoes Numericas==========");
        printf("\n 1) Transforma uma expressao Infixa em Posfixa");
        printf("\n 2) Transforma uma expressao Infixa em Prefixa");
        printf("\n 3) Le uma expressao e informa se a expressao eh valida");
        printf("\n 4) Le uma expressao e informa o resultado da expressao");
        printf("\n 5) Sair");
        printf("\n=======================================================");
        printf("\n\nOpcao: ");
        scanf("%c", &entrada);
        fflush(stdin);

        pi = criaPilha();
        
        switch (entrada) {
            case '1': ;
                printf("\nInforme uma expressao infixa para converter para posfixa: ");
                fgets(infixa, 50, stdin);
                fflush(stdin);

                piExpressaoValida = expressaoValida(infixa);

                if (piExpressaoValida) {
                    char posfixa[50];
                    
                    infixaParaPosfixa(pi, infixa, posfixa);
                    
                    printf("\n\nA expressao informada, convertida em posfixa, eh igual a:\n%s\n\n", posfixa);
                }

                break;
            case '2':
                printf("\nInforme uma expressao infixa para converter para prefixa: ");
                fgets(infixa, 50, stdin);
                fflush(stdin);

                piExpressaoValida = expressaoValida(infixa);

                if (piExpressaoValida) {
                    char prefixa[50];
                    
                    infixaParaPrefixa(pi, infixa, prefixa);
                    
                    printf("\n\nA expressao informada, convertida em prefixa, eh igual a:\n%s\n\n", prefixa);
                }

                break;
            case '3': ;
                printf("\nInforme uma expressao para verificar se eh valida: ");
                fgets(expressao, 50, stdin);
                fflush(stdin);

                piExpressaoValida = expressaoValida(expressao);

                if (piExpressaoValida) {
                    printf("\n\nExpressao valida!\n\n");
                }

                break;
            case '4': ;
                float resultado;

                printf("\nInforme uma expressao para descobrir seu resultado: ");
                fgets(expressao, 50, stdin);
                fflush(stdin);

                piExpressaoValida = expressaoValida(expressao);

                if (piExpressaoValida) {
                    resultado = calcularExpressao(pi, expressao);

                    printf("\n\nO resultado da expressao informada eh: %.3f\n\n", resultado);
                }

                break;
            case '5': ;
                if (pi != NULL) {
                    liberaPilha(pi);
                }
                
                exit(0);
            default:
                printf("\n\n###ERRO!\nOpcao de menu invalida.\n\n");
        }
    }

    return 0;
}