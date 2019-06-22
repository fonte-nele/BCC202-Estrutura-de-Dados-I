#include <iostream>
#include "contabancaria.h"

int main ()
{
	int nconta;
	double saldo_inicial,dep,saque;
	ContaBancaria *conta;
	//cout<<"Digite o numero da conta:\n";
	cin>>nconta;
	//cout<<"Digite o saldo inicial da conta:\n";
	cin>>saldo_inicial;
	conta = Inicializar(nconta, saldo_inicial);
	//cout<<"Qual o valor para deposito?\n";
	cin>>dep;
	Depositar (conta, dep);
	//cout<<"Qual o valor para saque?\n";
	cin>>saque;
	Sacar (conta, saque);
	cout<<"\nDados do cliente:\n";
	Imprimir (conta);
	Liberar_memoria(conta);
	return 0;
}