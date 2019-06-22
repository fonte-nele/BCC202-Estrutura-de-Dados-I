#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include <iostream>
using namespace std;
typedef struct
{
	int numero;
	double saldo;
}ContaBancaria;

ContaBancaria* Inicializar(int, double);
void Depositar(ContaBancaria*, double);
void Sacar(ContaBancaria*, double);
void Imprimir(ContaBancaria*);
void Liberar_memoria (ContaBancaria*);

#endif