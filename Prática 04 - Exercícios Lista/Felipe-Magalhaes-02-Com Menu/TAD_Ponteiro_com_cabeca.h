#ifndef TAD_PONTEIRO_COM_CABECA_H
#define TAD_PONTEIRO_COM_CABECA_H
#include <iostream>
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

void Inicializar_TLista(TLista**);
void Inicializar_TConta(TConta**);
int Menu();
void TLista_Inicia(TLista*);
bool TLista_EhVazia(TLista*);
void TLista_Inserir_Final(TLista*,TConta*);
void TLista_Inserir_Primeiro(TLista*,TConta*);
void TLista_RetiraPrimeiro(TLista*,TConta*);
void TLista_RetiraUltimo(TLista*,TConta*);
void TLista_Imprimir(TLista*);
void liberar_memoria_TConta(TConta*);
void liberar_memoria_TLista(TLista*);

#endif