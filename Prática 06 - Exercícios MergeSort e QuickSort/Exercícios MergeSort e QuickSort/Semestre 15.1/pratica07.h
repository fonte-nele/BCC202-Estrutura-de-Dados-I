#ifndef PRATICA07_H
#define PRATICA07_H
#include<iostream>
using namespace std;

typedef struct
{
	int chave;
}TNumero;

void Inicializar(TNumero**,int);
void Inserir(TNumero*,TNumero*,TNumero*,TNumero*,TNumero*,int);
void Bolha(TNumero*,int,int*,int*);
void Selection(TNumero*,int,int*,int*);
void Insertion(TNumero*,int,int*,int*);
void MergeSort(TNumero*,int,int*,int*);
void MergeSort_ordena(TNumero*,int,int,int*,int*);
void MergeSort_intercala(TNumero*,int,int,int,int*,int*);
void QuickSort(TNumero*,int,int*,int*);
void QuickSort_ordena(TNumero*,int,int,int*,int*);
void QuickSort_particao(TNumero*,int,int,int*,int*,int*,int*);
void Imprimir(TNumero*,int);
void Liberar_memoria(TNumero*);
#endif