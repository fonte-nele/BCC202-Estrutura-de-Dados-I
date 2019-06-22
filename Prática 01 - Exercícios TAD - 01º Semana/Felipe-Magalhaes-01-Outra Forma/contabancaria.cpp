#include <iostream>
#include "contabancaria.h"

void Inicializar(ContaBancaria **conta,int numero, double saldo)
{
	(*conta) = new ContaBancaria;
	(*conta) -> numero = numero;
	(*conta) -> saldo = saldo;
}

void Depositar(ContaBancaria **conta, double valor)
{
	(*conta) -> saldo += valor;
}

void Sacar(ContaBancaria **conta, double valor)
{
	(*conta) -> saldo -= valor;	
}

void Imprimir(ContaBancaria conta)
{
	cout<<"\nNumero da conta: "<<conta.numero<<endl;
	cout<<"Saldo bancario: "<<conta.saldo<<endl;
}

void Liberar_memoria (ContaBancaria **conta)
{
	delete (*conta);
}