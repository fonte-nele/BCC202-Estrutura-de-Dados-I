#ifndef HASH_ENDER_ABERTO_H
#define HASH_ENDER_ABERTO_H
#include "contato.h"

typedef struct
{
	TDados cont_hash_aberto;
	int chave[10];
}TItemEnd;

typedef TItemEnd Enderecamento[tam];
typedef int pesos[tam2];

void Hash_Inicia_Aberto(Enderecamento,pesos);
int h(int*,int*);
int Enderecamento_Pesquisa(Enderecamento,int*,pesos);
void Enderecamento_Pesquisa2(Enderecamento,int*,pesos);
int Enderecamento_Insere(Enderecamento,TItemEnd,int*);

#endif