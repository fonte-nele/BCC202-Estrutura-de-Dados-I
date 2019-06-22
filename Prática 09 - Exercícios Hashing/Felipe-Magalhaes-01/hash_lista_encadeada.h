#ifndef HASH_LISTA_ENCADEADA
#define HASH_LISTA_ENCADEADA
#include "contato.h"

typedef struct
{
	TDados contato_hash;
	int chave[10];
}TItem;

typedef struct celula
{
	struct celula *prox;
	TItem item;
}TCelula;

typedef struct
{
	TCelula *primeiro;
	TCelula *ultimo;
}TLista;

typedef struct
{
	int n;
	int num_listas;
	int num_pesos;
	int *vetor_pesos;
	TLista *vetor_listas;
}THash;

void THash_Inicia(THash*,int,int);
int THash_H(THash*,int*);
void THash_Pesquisa(THash*,int*,TItem*);
TCelula* THash_PesquisaCelula(THash*,int*,int*);
bool THash_Insere(THash*,TItem*);
bool TLista_EhVazia(TLista*);
void TLista_Inicia(TLista*);
void TLista_Insere(TLista*,TItem*);

#endif