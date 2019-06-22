#ifndef PRATICA07QUESTAO1_H
#define PRATICA07QUESTAO1_H
#include<iostream>
#include<ctime>
using namespace std;

typedef struct
{
	int chave;
}TNumero;

void Inicializar(TNumero**,int);
void Inserir(TNumero*,int);
void Copiar_Vetores(TNumero*,TNumero*,int);
void Bolha(TNumero*,int,int*,int*);
void Selection(TNumero*,int,int*,int*);
void Insertion(TNumero*,int,int*,int*);
void MergeSort(TNumero*,int,int*,int*);
void MergeSort_ordena(TNumero*,int,int,int*,int*);
void MergeSort_intercala(TNumero*,int,int,int,int*,int*);
void QuickSort(TNumero*,int,int*,int*);
void QuickSort_ordena(TNumero*,int,int,int*,int*);
void QuickSort_particao(TNumero*,int,int,int*,int*,int*,int*);
void ShellSort01(TNumero*,int,int*,int*);
void ShellSort02(TNumero*,int,int*,int*);
void ShellSort03(TNumero*,int,int*,int*);
void Imprimir(TNumero*,int);
void Liberar_memoria(TNumero*);
#endif