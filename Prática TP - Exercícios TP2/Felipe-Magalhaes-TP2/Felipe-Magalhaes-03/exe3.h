#ifndef EXE3_H
#define EXE3_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#define n 1000000
using namespace std;

typedef struct
{
	long int chave;
}TNumero;

void Inicializar(TNumero**);
void Copiar_Vetor(TNumero*,TNumero*);
void Bolha(TNumero*,unsigned long int*,unsigned long int*,int);
void Selection(TNumero*,unsigned long int*,unsigned long int*,int);
void Insertion(TNumero*,unsigned long int*,unsigned long int*,int);
void MergeSort(TNumero*,unsigned long int*,unsigned long int*,int);
void MergeSort_ordena(TNumero*,long int,long int,unsigned long int*,unsigned long int*,int);
void MergeSort_intercala(TNumero*,long int,long int,long int,unsigned long int*,unsigned long int*,int);
void QuickSort(TNumero*,unsigned long int*,unsigned long int*,int);
void QuickSort_ordena(TNumero*,long int,long int,unsigned long int*,unsigned long int*,int);
void QuickSort_particao(TNumero*,long int,long int,long int*,long int*,unsigned long int*,unsigned long int*,int);
void ShellSort(TNumero*,unsigned long int*,unsigned long int*,int);
void Liberar_memoria(TNumero*);
#endif