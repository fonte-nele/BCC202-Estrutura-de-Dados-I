#ifndef TAD_ARRAY_H
#define TAD_ARRAY_H
#define BEGIN 0
#define MAXTAM 1000
#include<iostream>
using namespace std;

typedef struct
{
	int num_conta;
	double saldo;
	int chave;
}TConta;

typedef struct
{
	TConta item[MAXTAM];
	int primeiro;
	int ultimo;
}TLista;

void Inicializar_TConta(TConta**);
void Inicializar_TLista(TLista**);
void TLista_Faz_Vazia(TLista*);
bool TLista_Eh_Vazia(TLista*);
void Preencher_Lista(TLista*,TConta*);
bool TLista_Insere(TLista*,TConta*);
bool TLista_Retira(TLista*,int,TConta*);
void TLista_Imprimir(TLista*);
void TLista_Pesquisar(TLista*,int);
void Concatenar_Listas(TLista*,TLista*);
void liberar_memoria_TConta(TConta*);
void liberar_memoria_TLista(TLista*);

#endif