#include <iostream>
#include "contabancaria.h"

int main ()
{
	int nconta;
	double saldo_inicial,dep,saque;
	ContaBancaria* conta;
	//cout<<"Digite o numero da conta:\n";
	cin>>nconta;
	//cout<<"Digite o saldo inicial da conta:\n";
	cin>>saldo_inicial;
	Inicializar(&conta,nconta, saldo_inicial);
	//cout<<"Qual o valor para deposito?\n";
	cin>>dep;
	Depositar (&conta, dep);
	//cout<<"Qual o valor para saque?\n";
	cin>>saque;
	//Condição para verificar se valor do saque é superior ao disponível.
	if(saque <= (saldo_inicial+dep))
	{
		Sacar (&conta, saque);
		cout<<"\nDados do cliente:\n";
		//Nao preciso passar por referencia para imprimir.
		Imprimir(*conta);
	}
	else
	{
		cout<<"\nNAO PERMITIDO.Valor desejado para saque superior ao saldo."<<endl;
		cout<<"\nDados do cliente:\n";
		Imprimir(*conta);
	}
	Liberar_memoria(&conta);
	return 0;
}