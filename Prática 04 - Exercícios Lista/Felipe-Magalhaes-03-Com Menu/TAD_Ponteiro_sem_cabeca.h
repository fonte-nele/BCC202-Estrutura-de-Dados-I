#ifndef TAD_PONTEIRO_SEM_CABECA_H
#define TAD_PONTEIRO_SEM_CABECA_H
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
	TCelula *primeiro;
	TCelula *ultimo;
}TLista;

void Inicializar_TConta(TConta**);
void Inicializar_TLista(TLista**);
int Menu();
void TLista_Inicia(TLista*);
bool TLista_EhVazia(TLista*);
bool TLista_Insere(TLista*,TConta*);
bool TLista_RetiraPrimeiro(TLista*,TConta*);
void TLista_Imprimir(TLista*);

void liberar_memoria_TLista(TLista*);
void liberar_memoria_TConta(TConta*);

#endif