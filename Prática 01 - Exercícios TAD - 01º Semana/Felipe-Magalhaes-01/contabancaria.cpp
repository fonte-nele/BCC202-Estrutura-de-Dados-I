#include <iostream>
#include "contabancaria.h"

ContaBancaria* Inicializar(int numero, double saldo)
{
	ContaBancaria *pconta = new ContaBancaria;
	pconta -> numero = numero;
	pconta -> saldo = saldo;
	return pconta;
}

void Depositar(ContaBancaria* pconta, double valor)
{
	pconta -> saldo += valor;
}

void Sacar(ContaBancaria* pconta, double valor)
{
	pconta -> saldo -= valor;
}

void Imprimir(ContaBancaria* conta)
{
	cout<<"\nNumero da conta: "<<conta->numero<<endl;
	cout<<"\nSaldo bancario: "<<conta->saldo<<endl;
}

void Liberar_memoria (ContaBancaria* pconta)
{
	delete pconta;
}
