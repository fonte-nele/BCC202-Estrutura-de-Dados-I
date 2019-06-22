#include <iostream>
#include <iomanip>
using namespace std;
void rendimento_final(float saldoA,float saldoB,float rendA,float rendB, int n_meses, float depA)
{
	int i,cont=0;
	//Condicao para verificar se rendimento de A é maior que B.
	if(rendA>rendB)
	{
		cout<<"Rendimento de B invalido.\n";
	}
	else
	{
		for(i=0; i<n_meses; i++)
		{
			saldoA += (saldoA*rendA/100)+depA;
			saldoB += (saldoB*rendB/100);
			if(saldoA>saldoB)
			{
				//Contador para verificar a quantidade de meses para uma conta superar a outra.
				cont++;
			}
		}
		cout<<"Saldo da conta crianca A "<<fixed<<setprecision(2)<<saldoA<<endl;
		cout<<"Saldo da conta crianca B "<<fixed<<setprecision(2)<<saldoB<<endl;
		if(saldoB > saldoA)
		{
			cout<<"O valor da conta B supera a conta A em: "<<cont<<" meses.\n";
		}
		else
		{
			cout<<"O valor da conta B nao supera a conta A";	   
		}
	}
}
int main()
{
	int n_simular,n_meses,cont=0;
	float Xa, Da, Xb, Ra, Rb;
	//cout<<"Digite o numero de simulacoes desejada:\n";
	cin>>n_simular;
	do
	{
		//cout<<"Montante inicial crianca A:\n";
		cin>>Xa;
		//cout<<"Deposito na conta da crianca A:\n";
		cin>>Da;
		//cout<<"Rendimento da conta da crianca A:\n";
		cin>>Ra;
		//cout<<"Montante inicial crianca B:\n";
		cin>>Xb;
		//cout<<"Rendimento da conta da crianca B:\n";
		cin>>Rb;
		//cout<<"Digite a quantidade de meses para fazer a simulacao:\n";
		cin>>n_meses;
		//Procedimento para fazer os calculos de rendimentos.
		rendimento_final(Xa,Xb,Ra,Rb,n_meses,Da);
		cont++;
	}while(cont!=n_simular);
	return 0;
}