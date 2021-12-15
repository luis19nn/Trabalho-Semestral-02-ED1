#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "TrabSemEx01.h"

/*
### TYPEDEF DA PILHA DINÂMICA ###
*/

struct ED_PD {
    char operacao;
    float numero;
    struct ED_PD *prox;
};



/*
### CRIAÇÃO E REMOÇÃO DA PILHA DINÂMICA ###
*/

Pilha* criaPilha() {
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));

    if (pi != NULL)
        *pi = NULL;

    return pi;
}

void liberaPilha(Pilha* pi) {
    if (pi != NULL) {
        Nodo* no;

        while ((*pi) != NULL) {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }

        free(pi);
    }
}



/*
### INSERÇÃO NA PILHA DINÂMICA ###
*/

int empilharChar(Pilha* pi, char dadoNovo) {
    if (pi == NULL) return 0;

    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if (no == NULL) return 0;

    no->operacao = dadoNovo;
    no->numero = 0.0;
    no->prox = (*pi);
    *pi = no;

    return 1;
}

int empilharNumero(Pilha* pi, float dadoNovo) {
    if (pi == NULL) return 0;

    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if (no == NULL) return 0;

    no->numero = dadoNovo;
    no->operacao = " ";
    no->prox = (*pi);
    *pi = no;

    return 1;
}



/*
### REMOÇÃO DA PILHA DINÂMICA ###
*/

char desempilharChar(Pilha* pi) {
    if (pi == NULL) return NULL;
    if ((*pi) == NULL) return NULL;

    Nodo *no = *pi;
    *pi = no->prox;

    char c = no->operacao;

    free(no);

    return c;
}

float desempilharNumero(Pilha* pi) {
    if (pi == NULL) return 0;
    if ((*pi) == NULL) return 0;

    Nodo *no = *pi;
    *pi = no->prox;

    float f = no->numero;

    free(no);

    return f;
}



/*
### VALIDAR EXPRESSÃO ###
*/

int validaCaracteres(char *expressao) {
    char c;

    for (int i = 0; i < strlen(expressao); i++) {
        c = expressao[i];

        if (isalpha(c)) {
            printf("\n\n#ERRO# A expressao informada contem letras!\n\n");
            return 0;
        }

        if (!isdigit(c) && !isspace(c)) {
            if (c != '-' && c != '/' && c != '^' && c != '(' && c != ')' && c != '*' && c != '+') {
                printf("\n\n#ERRO# A expressao informada contem caracteres invalidos!\n\n");
                return 0;
            }
        }
    }
    
    return 1;
}

int validaOperacoes(char *expressao) {
    char cAtual;
    char cAnterior;

    for (int i = 0; i < strlen(expressao); i++) {
        if (i != (strlen(expressao) - 1)) cAtual = expressao[i];
        if (i > 0) cAnterior = expressao[i - 1];

        if (cAnterior == NULL) {
            if (cAtual == '*' || cAtual == '/' || cAtual == '^' || cAtual == ')') {
                printf("\n\n#ERRO# O primeiro elemento da expressao informada eh invalido!\n\n");
                return 0;
            }
        }

        if (i == (strlen(expressao) - 1)) {
            if (cAtual == '+' || cAtual == '-' || cAtual == '*' || cAtual == '/' || cAtual == '^' || cAtual == '(') {
                printf("\n\n#ERRO# O ultimo elemento da expressao informada eh invalido!\n\n");
                return 0;
            }
        }

        if (cAnterior != NULL) {
            if ((cAtual == '+' || cAtual == '-' || cAtual == '*' || cAtual == '/' || cAtual == '^') &&
                (cAnterior == '+' || cAnterior == '-' || cAnterior == '*' || cAnterior == '/' || cAnterior == '^')) {
                printf("\n\n#ERRO# Nao pode haver dois caracteres de operacao seguidos!\n\n");
                return 0;
            }
        }
    }

    return 1;
}

int validaParenteses(char *expressao) {
    int contador = 0, cAux = 0;
    char cAtual, cAnterior, cOp;

    for (int i = 0; i < strlen(expressao); i++) {
        cAtual = expressao[i];
        if (i > 0) cAnterior = expressao[i - 1];

        if (cAtual == '(') {
            ++contador;

            if (cAnterior == ')' || isdigit(cAnterior)) {
                printf("\n\n#ERRO# Antes do parentese de abertua, nao pode haver um de fechadura ou um numero\n\n");
                return 0;
            }
        }
        
        if (cAtual == ')') {
            --contador;

            if ((contador == 0 && cAux == 0) ||
                (cAux < 2 && (cOp != '+' && cOp != '-')) ||
                (cAnterior == '+' || cAnterior == '-' || cAnterior == '*' || cAnterior == '/' || cAnterior == '^')) {
                printf("\n\n#ERRO# Verifique o conteudo entre os parenteses!\nNao pode haver parenteses vazios.\nO ultimo caractere dentro dos parenteses nao pode ser uma operacao.\nSe houver apenas um numero dentro dos parenteses, o caractere de operacao so pode ser '+' ou '-'.\n\n");
                return 0;
            }
        }

        if (contador < 0)
            break;
        if (contador > 0) {
            if (isdigit(cAtual)) {
                cAux++;
            } else if (cAtual != '(' && cAtual != ')') {
                cOp = cAtual;
            }
        }
        if (contador == 0)
            cAux = 0;
    }

    if (contador == 0)
        return 1;
    else {
        printf("\n\n#ERRO# Ha erro na quantidade de parenteses!\n\n");
        return 0;
    }
}

int expressaoValida(char *expressao) {
    if (!validaCaracteres(expressao)) return 0;
    if (!validaOperacoes(expressao)) return 0;
    if (!validaParenteses(expressao)) return 0;

    return 1;
}



/*
### CONVERTER INFIXA ###
*/

int prioridade(char elem) {
    switch (elem) {
        case '#': return 0;
        case '(': return 2;
        case '+':
        case '-': return 3;
        case '*':
        case '/': return 4;
        case '^': return 5;
        default: return 1;
    }
}



/*
### CONVERTER INFIXA PARA PÓSFIXA ###
*/
 
void infixaParaPosfixa(Pilha* pi, char *infixa, char *posfixa) {
    empilharChar(pi, '#');

    Nodo *no = *pi;
    char c, removeParenteses;
    int i = 0, k = 0;

    for (int i = 0; i < strlen(infixa); i++) {
        c = infixa[i];

        no = *pi;

        if (c == '(') {
            empilharChar(pi, c);
            
        } else if (isdigit(c)) {
            posfixa[k++] = c;

        } else if (c == ')') {
            while (no != NULL && no->operacao != '(') {
                no = no->prox;
                posfixa[k++] = ' ';
                posfixa[k++] = desempilharChar(pi);
            }
            removeParenteses = desempilharChar(pi);

        } else if (isspace(c)) {
            continue;
        } else {
            while (no != NULL && prioridade(no->operacao) >= prioridade(c)) {
                no = no->prox;
                posfixa[k++] = ' ';
                posfixa[k++] = desempilharChar(pi);
            }
            posfixa[k++] = ' ';
            empilharChar(pi, c);
        }
    }

    while (no != NULL && no->operacao != '#') {
        no = no->prox;
        posfixa[k++] = ' ';
        posfixa[k++] = desempilharChar(pi);
    }
    posfixa[k] = '\0';

    liberaPilha(pi);
}



/*
### CONVERTER INFIXA PARA PRÉFIXA ###
*/

void inverter(char array[50]) {
	int i, j;
	char temp[50];
	
    for (i = strlen(array) - 1, j = 0; i + 1 != 0; --i, ++j) {
        if (array[i] != '\n' && array[i] != '#') {
            temp[j] = array[i];
        } else {
            --j;
        }
	}
    temp[j] = '\0';

    for (i = 0; i < strlen(temp); i++) {
        if (temp[i] == '(') {
            temp[i] = ')';
        } else if (temp[i] == ')') {
            temp[i] = '(';
        }
    }
	
    strcpy(array, temp);
}

void infixaParaPrefixa(Pilha* pi, char *infixa, char *prefixa) {
    inverter(infixa);

    infixaParaPosfixa(pi, infixa, prefixa);

    inverter(prefixa);
}



/*
### CALCULAR A EXPRESSÃO ###
*/

float operacao(float a, float b, char op) {
    switch(op){
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '/':
            return a / b;
            break;
        case '*':
            return a * b;
            break;
        case '^':
            return pow(a, b);
            break;
        default:
            return 0;
    }
}

float calcularExpressao(Pilha* pi, char *expressao) {
    char posfixa[50], *pt;
    float num, n1, n2, ptNum;

    infixaParaPosfixa(pi, expressao, posfixa);
    strcpy(expressao, posfixa);

    pi = criaPilha();

    pt = strtok(expressao, " ");
    while (pt) {
        if (pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*' || pt[0] == '^') {
            n1 = desempilharNumero(pi);
            n2 = desempilharNumero(pi);

            num = operacao(n2, n1, pt[0]);

            empilharNumero(pi, num);
        } else {
            ptNum = strtol(pt, NULL, 10);
            empilharNumero(pi, ptNum);
        }
        pt = strtok(NULL, " ");
    }

    num = desempilharNumero(pi);
    liberaPilha(pi);

    return num;
}
