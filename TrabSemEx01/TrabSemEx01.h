#ifndef TRABSEMEX01_H_INCLUDED
#define TRABSEMEX01_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
### TYPEDEF DA PILHA DINÂMICA ###
*/

typedef struct ED_PD* Pilha;
typedef struct ED_PD Nodo;



/*
### CRIAÇÃO E REMOÇÃO DA PILHA DINÂMICA ###
*/

Pilha* criaPilha();
void liberaPilha(Pilha* pi);



/*
### INSERÇÃO NA PILHA DINÂMICA ###
*/

int empilharChar(Pilha* pi, char dadoNovo);

int empilharNumero(Pilha* pi, float dadoNovo);



/*
### REMOÇÃO DA PILHA DINÂMICA ###
*/

char desempilharChar(Pilha* pi);

float desempilharNumero(Pilha* pi);



/*
### VALIDAR EXPRESSÃO ###
*/

int validaCaracteres(char *expressao);

int validaOperacoes(char *expressao);

int validaParenteses(char *expressao);

int expressaoValida(char *expressao);



/*
### CONVERTER INFIXA ###
*/

int prioridade(char elem);



/*
### CONVERTER INFIXA PARA PÓSFIXA ###
*/

void infixaParaPosfixa(Pilha* pi, char *infixa, char *posfixa);



/*
### CONVERTER INFIXA PARA PRÉFIXA ###
*/

void inverter(char array[30]);

void infixaParaPrefixa(Pilha* pi, char *infixa, char *prefixa);



/*
### CALCULAR A EXPRESSÃO ###
*/

float operacao(float a, float b, char op);

float calcularExpressao(Pilha* pi, char *expressao);



#endif // TRABSEMEX01_H_INCLUDED
