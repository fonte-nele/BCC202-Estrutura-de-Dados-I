#ifndef QUICKSORT_H
#define QUICKSORT_H
#include<iostream>
using namespace std;

typedef struct
{
	int chave;
}TNumero;

void Inicializar(TNumero**,int);
void Inserir(TNumero*,int);
void QuickSort(TNumero*,int,int*,int*);
void QuickSort_ordena(TNumero*,int,int,int*,int*);
void QuickSort_particao(TNumero*,int,int,int*,int*,int*,int*);
void Imprimir(TNumero*,int);
void Liberar_memoria(TNumero*);
#endif