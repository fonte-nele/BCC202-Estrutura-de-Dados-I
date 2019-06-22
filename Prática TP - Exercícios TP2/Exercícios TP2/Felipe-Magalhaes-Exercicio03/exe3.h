#ifndef EXE3_H
#define EXE3_H
#include<iostream>
using namespace std;

typedef struct
{
	int chave;
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

void TPilha_Inicia(TPilha*);
bool TPilha_EhVazia(TPilha*);
void TPilha_Empilha(TPilha*, int);
void TPilha_Desempilha(TPilha*, int*);
void Inicializar(TNumero**,int);
void Inserir(TNumero*,int);
void QuickSort_iter(TNumero*,int);
void QuickSort_particao(TNumero*,int,int,int*,int*);
void Imprimir(TNumero*,int);
void Liberar_memoria(TNumero*);
#endif