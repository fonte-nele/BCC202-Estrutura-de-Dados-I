#ifndef MERGESORT_H
#define MERGESORT_H
#include<iostream>
using namespace std;

typedef struct
{
	int chave;
}TNumero;

void Inicializar(TNumero**,int);
void Inserir(TNumero*,int);
void MergeSort(TNumero*,int,int*,int*);
void MergeSort_ordena(TNumero*,int,int,int*,int*);
void MergeSort_intercala(TNumero*,int,int,int,int*,int*);
void Imprimir(TNumero*,int);
void Liberar_memoria(TNumero*);
#endif