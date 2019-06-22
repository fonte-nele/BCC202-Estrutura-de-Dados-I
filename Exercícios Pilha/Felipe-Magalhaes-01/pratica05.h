#ifndef PRATICA05_H
#define PRATICA05_H
#include<iostream>
using namespace std;

typedef struct
{
	double num;
}TCalc;

typedef struct celula
{
	struct celula *prox;
	TCalc item;
}TCelula;

typedef struct
{
	TCelula* fundo;
	TCelula* topo;
	int tamanho;
}TPilha;

void Inicializar_TCalc(TCalc**);
void Inicializar_TPilha(TPilha**);
int Menu();
void TPilha_Inicia(TPilha*);
bool TPilha_EhVazia(TPilha*);
void TPilha_Push(TPilha*, TCalc*);
double TPilha_Pop(TPilha*, TCalc*);
int TPilha_Tamanho(TPilha*);
void TPilha_Limpa(TPilha*);
void TPilha_Imprimir(TPilha*);
void liberar_memoria_TCalc(TCalc*);
void liberar_memoria_TPilha(TPilha*);

#endif