#ifndef EXE1_H
#define EXE1_H
#include<iostream>
using namespace std;

typedef struct
{
	int num;
}TNumero;

typedef struct celula
{
	struct celula *prox;
	TNumero item;
}TCelula;

typedef struct
{
	TCelula* fundo;
	TCelula* topo;
	int tamanho;
}TPilha;

void Inicializar_TNumero(TNumero**);
void Inicializar_TPilha(TPilha**);
int Menu();
void TPilha_Inicia(TPilha*);
bool TPilha_EhVazia(TPilha*);
void TPilha_Filas(TPilha*,TPilha*,TNumero*);
void TPilha_Push(TPilha*, TNumero*);
bool TPilha_Pop(TPilha*, TNumero*);
int TPilha_Tamanho(TPilha*);
void TPilha_Limpa(TPilha*);
void TPilha_Imprimir(TPilha*);
void liberar_memoria_TNumero(TNumero*);
void liberar_memoria_TPilha(TPilha*);

#endif