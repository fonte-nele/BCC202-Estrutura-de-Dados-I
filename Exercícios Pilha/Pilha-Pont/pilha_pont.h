#ifndef PILHA_PONT_H
#define PILHA_PONT_H
#include<iostream>
using namespace std;

typedef struct
{
	int num_conta;
	double saldo;
}TConta;

typedef struct celula
{
	struct celula *prox;
	TConta item;
}TCelula;

typedef struct
{
	TCelula* fundo;
	TCelula* topo;
	int tamanho;
}TPilha;

void Inicializar_TConta(TConta**);
void Inicializar_TPilha(TPilha**);
int Menu();
void TPilha_Inicia(TPilha*);
bool TPilha_EhVazia(TPilha*);
void TPilha_Push(TPilha*, TConta*);
bool TPilha_Pop(TPilha*, TConta*);
int TPilha_Tamanho(TPilha*);
void TPilha_Limpa(TPilha*);
void TPilha_Imprimir(TPilha*);
void liberar_memoria_TConta(TConta*);
void liberar_memoria_TPilha(TPilha*);

#endif