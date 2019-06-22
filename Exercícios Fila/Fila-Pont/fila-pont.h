#ifndef FILA_PONT_H
#define FILA_PONT_H
#include<iostream>
using namespace std;

typedef struct
{
	int num_conta;
	double saldo;
}TConta;

typedef struct celula
{
	struct celula* prox;
	TConta item;
}TCelula;

typedef struct
{
	TCelula* primeiro;
	TCelula* ultimo;
	int tamanho;
}TFila;

void Inicializar_TConta(TConta**);
void Inicializar_TFila(TFila**);
int Menu();
void TFila_Inicia(TFila*);
bool TFila_EhVazia(TFila*);
void TFila_Enfileirar(TFila*, TConta*);
bool TFila_Desenfileirar(TFila*, TConta*);
int TFila_Tamanho(TFila*);
void TFila_Limpa(TFila*);
void TFila_Imprimir(TFila*);
void liberar_memoria_TConta(TConta*);
void liberar_memoria_TFila(TFila*);

#endif