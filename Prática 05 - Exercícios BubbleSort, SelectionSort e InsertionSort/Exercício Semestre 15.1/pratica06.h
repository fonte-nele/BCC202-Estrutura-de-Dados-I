#ifndef PRATICA06_H
#define PRATICA06_H
#include<iostream>
using namespace std;

typedef struct
{
	int chave;
}TNumero;

void Inicializar(TNumero**,int);
void Inserir(TNumero*,TNumero*,TNumero*,int);
void Bolha(TNumero*,int,int*,int*);
void Selection(TNumero*,int,int*,int*);
void Insertion(TNumero*,int,int*,int*);
void Imprimir(TNumero*,int);
void Liberar_memoria(TNumero*);
#endif