#ifndef PILHA_H
#define PILHA_H
#define MAX 100
#include <iostream>
using namespace std;

typedef struct
{
	int num_conta;
	double saldo;
	int chave;
}TConta;

typedef struct
{
	TConta item[MAX];
	int topo;
}TPilha;

void Inicializar_TConta(TConta**);
void Inicializar_TPilha(TPilha**);
int Menu();
void TPilha_Inicia(TPilha*);
bool TPilha_EhVazia(TPilha*);
bool TPilha_Push(TPilha*, TConta*);
bool TPilha_Pop(TPilha*, TConta*);
int TPilha_Tamanho(TPilha*);
void TPilha_Limpa(TPilha*);
void TPilha_Imprimir(TPilha*);
void liberar_memoria_TConta(TConta*);
void liberar_memoria_TPilha(TPilha*);

#endif